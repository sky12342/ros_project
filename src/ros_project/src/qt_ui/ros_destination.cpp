#include"ros_destination_send.h"
#include <fstream>
using namespace std;
    RosDestinationSender::RosDestinationSender(int argc,char ** argv ,string name):argc_(argc),argv_(argv),node_name_(name){
        boost::uuids::uuid ros_id_uuid = boost::uuids::random_generator()();
        string ros_id_ = boost::uuids::to_string(ros_id_uuid);   
    }
    RosDestinationSender::~RosDestinationSender(){
            if(ros::isStarted())
    {
        ros::shutdown();
        ros::waitForShutdown();
    }   if(umap.isExist(node_name_))
        umap.del(ros_id_);
    }
    string RosDestinationSender::getID(){
        return ros_id_;
    }
    void RosDestinationSender::getPbMsg(const QString &msg){
        lock_guard<mutex> lock(mtx_);
        QStringList parts = msg.split(",");
        destination_x_ = parts[0].toInt();
        destination_y_ = parts[1].toInt();
        pbmsg_.set_destination_x(destination_x_);
        pbmsg_.set_destination_y(destination_y_);
        pbmsgs_.emplace(pbmsg_);
        std::ofstream logFile("debug_log.txt", std::ios::app);
        logFile<<"pubmsg is add to pubmsg"<<pbmsg_.destination_x()<<pbmsg_.destination_y()<<endl;
        cv_.notify_one();
    }
    void RosDestinationSender::run(){
        ros::Rate rate(10);
        std::ofstream logFile("debug_log.txt", std::ios::app);
        while(ros::ok){
            unique_lock<mutex> lock(mtx_);
            cv_.wait(lock,[this](){
                return !pbmsgs_.empty();
            });
            if(!pbmsgs_.empty()){
                
                pbmsg_ = pbmsgs_.front();
                pbmsgs_.pop();
            }
            pb_.publish(pbmsg_);
            logFile<<"pubmsg is published"<<pbmsg_.destination_x()<<pbmsg_.destination_y()<<endl;
            ros::spinOnce();
            rate.sleep();
        }
    }
    void RosDestinationSender::init(){
        ros::init(argc_,argv_,node_name_);
        if(!ros::master::check()){
            cout<<"Error:master node is not start!"<<endl;
            exit(1);
        }
        nh_=make_shared<ros::NodeHandle>();
        pb_ = nh_->advertise<Destination::site::PublishInfo>(topic_name_,1000);
    }
    void RosDestinationSender::setTopic(const std::string & name,const int len,const bool latch  ){
        topic_name_ = name;
        topic_queue_len_ = len;
        latch_ = latch;
    }
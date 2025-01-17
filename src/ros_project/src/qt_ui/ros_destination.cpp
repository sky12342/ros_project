#include"ros_destination_send.h"
#include <fstream>
using namespace std;
    RosDestinationSender::RosDestinationSender(int argc,char ** argv ,string name)
    :argc_(argc),argv_(argv),node_name_(name),stop_flag_(false),origin_buffer_(DestinationSiteBuffer::getInstance()){
        boost::uuids::uuid ros_id_uuid = boost::uuids::random_generator()();
        string ros_id_ = boost::uuids::to_string(ros_id_uuid);
        th_ = std::thread(&RosDestinationSender::getPbMsg,this);
    }
    RosDestinationSender::~RosDestinationSender(){
    if(ros::isStarted())
    {
        stop_flag_.store(true,memory_order_release);
        queue_cv_.notify_all();
        cv_.notify_all();
        th_.join();
        ros::shutdown();
        ros::waitForShutdown();
    }   if(umap.isExist(node_name_))
        umap.del(ros_id_);
    }
    string RosDestinationSender::getID(){
        return ros_id_;
    }
    void RosDestinationSender::call(){
    queue_cv_.notify_one();
    }
    void RosDestinationSender::getPbMsg(){
        while(true){
            unique_lock<mutex> lock(mtx_);
            queue_cv_.wait(lock,[this](){
            return !stop_flag_.load(memory_order_acquire) || !site_buffer_.empty();
            });
            if(stop_flag_.load(memory_order_relaxed)) {
            while(!site_buffer_.empty()){
                std::pair<int,int> tmp = site_buffer_.front();
                site_buffer_.pop();
                destination_x_ = tmp.first;
                destination_y_ = tmp.second;
                pbmsg_.set_destination_x(destination_x_);
                pbmsg_.set_destination_y(destination_y_);
                pbmsgs_.emplace(pbmsg_);
            }
                cv_.notify_one();
                break;
            }
            while(!site_buffer_.empty()){
                std::pair<int,int> tmp = site_buffer_.front();
                site_buffer_.pop();
                destination_x_ = tmp.first;
                destination_y_ = tmp.second;
                pbmsg_.set_destination_x(destination_x_);
                pbmsg_.set_destination_y(destination_y_);
                pbmsgs_.emplace(pbmsg_);
            }
                cv_.notify_one();
                origin_buffer_->swap(site_buffer_);
        }
    }
    void RosDestinationSender::run(){
        ros::Rate rate(10);
        std::ofstream logFile("debug_log.txt", std::ios::app);
        while(ros::ok){
            unique_lock<mutex> lock(mtx_);
            cv_.wait(lock,[this](){
                return !stop_flag_.load(memory_order_acquire)||!pbmsgs_.empty();
            });
            if(stop_flag_.load(memory_order_relaxed)){
                while(!pbmsgs_.empty()){
                    
                    pbmsg_ = pbmsgs_.front();
                    pbmsgs_.pop();
                    pb_.publish(pbmsg_);
                }
                break;           
            }
            while(!pbmsgs_.empty()){
                pbmsg_ = pbmsgs_.front();
                pbmsgs_.pop();
                pb_.publish(pbmsg_);
            }
            queue_cv_.notify_one();
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
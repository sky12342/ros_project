#include"ros_worker.h"
#include<std_msgs/String.h>
// #include"Log.h"
// #include"common.h"
#include<string>
#include<iostream>
#include<boost/uuid/uuid.hpp>
#include<boost/uuid/random_generator.hpp>
#include<boost/uuid/uuid_io.hpp>
#include"QMessageBox"
#include <fstream>

using namespace std;
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

RosWorker::RosWorker(int argc,char ** argv ,string name):argc_(argc),argv_(argv),node_name_(name){
        boost::uuids::uuid ros_id_uuid = boost::uuids::random_generator()();
        string ros_id_ = boost::uuids::to_string(ros_id_uuid);   
}
RosWorker::~RosWorker(){
    if(ros::isStarted())
    {
        ros::shutdown();
        ros::waitForShutdown();
    }
    if(umap.isExist(node_name_))
    umap.del(ros_id_);
}
string RosWorker::getID(){
    return ros_id_;
}
void RosWorker::onPbCallback(const ros::MessageEvent<Destination::site::PublishInfo> &msg){
    std::lock_guard<mutex> lock(mtx_);
    std::ofstream logFile("debug_log.txt", std::ios::app);
    bool flag =false;
    if(pbmsgs.empty()){
        flag = true;
    }
    if(pbmsgs.size()>MAX_SITE_LENTH){
    logFile<<"protobuf is receive length is over"<<MAX_SITE_LENTH<<"over message is be given up"<<endl;
    return ;
    }
    pbmsgs.emplace(msg.getMessage());
    auto msgs = msg.getMessage();
    logFile<<"protobuf is receive"<<msgs->destination_x()<<msgs->destination_y()<<endl;
    if(!flag){
    return ; 
    }
    cv_.notify_one();
}
void RosWorker::setNodeName(const std::string & name){    
    node_name_ = name;
}
void RosWorker::init(){
    ros::init(argc_,argv_,node_name_);
    if(!ros::master::check()){
        cout<<"Error:master node is not start!"<<endl;
        // LOG(INFO)<<"Error:master node is not start"<<endl;
        exit(1);
    }
    nh_=make_shared<ros::NodeHandle>();
    ac_=make_shared<MoveBaseClient>("move_base",true);
    goal_.target_pose.header.frame_id = "map";
    goal_.target_pose.header.stamp = ros::Time::now();
    goal_.target_pose.pose.position.x = 0;
    goal_.target_pose.pose.position.y = 0;
    goal_.target_pose.pose.orientation.w = 1;
    sub_ = nh_->subscribe(topic_name_,1000,&RosWorker::onPbCallback,this);
    // LOG(INFO)<<"RosWorker init sucess!!!!\n"<<endl;
}
void RosWorker::setTopic(const string & name,const int len,const bool latch ){
    topic_name_ = name;
    topic_queue_len_ = len;
    latch_ = latch;
}
void RosWorker::pubMsg(const QString & msg){
    std_msgs::String pub_msg ;
    pub_msg.data= msg.toStdString();
    pb_.publish(pub_msg);
}
void RosWorker::callback_strMsg(const std_msgs::String & msg){
    emit signal_strMsg(QString::fromStdString(msg.data));
}
void RosWorker::spin(){
ros::Rate rate(10);
while(ros::ok()){
ros::spin();
rate.sleep();
}
}
void RosWorker::run()
{   std::ofstream logFile("debug_log.txt", std::ios::app);
    ros::Rate rate(10); // 10Hz 频率
    logFile << "run is running!!!goal_received: " << destination_x_ << ", " << destination_y_ << std::endl;
    while(ros::ok()) 
    {  
        unique_lock<mutex>lock(mtx_,std::defer_lock) ;
        lock.lock();
        cv_.wait(lock,[this](){
            return !pbmsgs.empty();
        });
        // 等待 move_base action server 准备就绪
        auto tmp = pbmsgs.front();
        pbmsgs.pop();
        
        destination_x_ = tmp->destination_x();
        destination_y_ = tmp->destination_y();
        logFile << "protobufmsg is seted: " << destination_x_ << ", " << destination_y_ << std::endl;
        

        lock.unlock();
        while (!ac_->waitForServer(ros::Duration(5.0))) {
            ROS_INFO("Waiting for the move base action server to come up!!!\n");
        }

        // 设置目标位置
        goal_.target_pose.pose.position.x = destination_x_;
        goal_.target_pose.pose.position.y = destination_y_;
        goal_.target_pose.pose.orientation.w = 1.0;  // 设置姿态方向，通常默认为1，表示目标是朝上的
        logFile << "goal_.target_pose.pose.position: " << goal_.target_pose.pose.position.x << ", " << goal_.target_pose.pose.position.y << std::endl;
        // 发送目标
        ac_->sendGoal(goal_);

        // 等待结果
        bool finished_before_timeout = ac_->waitForResult(ros::Duration(30.0)); // 等待最多30秒
        
        if (finished_before_timeout) {
            // 成功到达目标
            ROS_INFO("Successfully reached the destination.");
        } else {
            // 超时未到达目标
            ROS_WARN("The move base action timed out.");
        }

        // 继续执行ros回调处理

        rate.sleep(); // 保持10Hz频率)
    }
    logFile.close();
}
void RosWorker::destination_site(const QString &msg){
    QStringList parts = msg.split(",");
    destination_x_ = parts[0].toInt();
    destination_y_ = parts[1].toInt();
    std::ofstream logFile("debug_log.txt", std::ios::app);
if (logFile.is_open()) {
    logFile << "received: " << destination_x_ << ", " << destination_y_ << std::endl;
    logFile.close();
}
}
void RosWorker::notify_map(const QString &msg){
    goal_.target_pose.header.frame_id = msg.toStdString();
}
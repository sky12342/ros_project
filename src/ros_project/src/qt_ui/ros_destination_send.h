#pragma once
#include"rosFcuntionbase.h"
#include<ros/ros.h>
#include<string>
#include<thread>
#include<boost/uuid/uuid.hpp>
#include<boost/uuid/random_generator.hpp>
#include<boost/uuid/uuid_io.hpp>
#include<queue>
#include<memory>
#include<mutex>
#include<atomic>
#include"destinatoinSiteBuffer.h"
#include<condition_variable>
#include"../protobuf_msg/Build/publish_info.pb.h"
#include"../protobuf/include/ssr_pkg/protobuf_traits.h"
#include"../protobuf/include/ssr_pkg/ros_protobuf.h"
class RosDestinationSender:public RosFunBase{
public:
    RosDestinationSender(int argc,char ** argv ,std::string name);
    ~RosDestinationSender();
    void run();
    void init();
    void setTopic(const std::string & name,const int len,const bool latch = false );
    std::string getID();
    void spin(){};
    void call();
    void getPbMsg();
private:
    ros::Publisher pb_;
    ros::Subscriber sub_;
    std::string node_name_;
    int topic_queue_len_;
    bool latch_;
    int argc_;
    char** argv_;
    std::string topic_name_; 
    std::string ros_id_;
    std::shared_ptr<ros::NodeHandle> nh_;
    int destination_x_ =0;
    int destination_y_= 0;
    Destination::site::PublishInfo pbmsg_;
    std::queue<Destination::site::PublishInfo> pbmsgs_;
    std::mutex mtx_;
    std::mutex mtx2_;
    std::condition_variable cv_;
    std::condition_variable queue_cv_;
    std::queue<std::pair<int, int>> site_buffer_;
    std::atomic<bool> stop_flag_;
    std::shared_ptr<DestinationSiteBuffer> origin_buffer_;
    std::thread th_;
};
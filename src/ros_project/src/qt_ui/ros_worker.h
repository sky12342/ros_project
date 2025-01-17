#pragma once
#include<ros/ros.h>
#include"rosFcuntionbase.h"
#include"rosWorkList.h"
#include<queue>
#include <move_base_msgs/MoveBaseAction.h>
#include<actionlib/client/simple_action_client.h>
#include"../protobuf_msg/Build/publish_info.pb.h"
#include<mutex>
#include<condition_variable>
#include"const.h"
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
class RosWorker:public RosFunBase,public std::enable_shared_from_this<RosWorker>{
    Q_OBJECT
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
    std::shared_ptr<MoveBaseClient> ac_;
    move_base_msgs::MoveBaseGoal goal_;
    int destination_x_ =0;
    int destination_y_= 0;
    std::queue<boost::shared_ptr<Destination::site::PublishInfo>> pbmsgs;
    void onPbCallback(const ros::MessageEvent<Destination::site::PublishInfo> &msg);
    std::mutex mtx_;
    std::mutex mtx2_;
    std::condition_variable cv_;
public:
    RosWorker(int argc,char ** argv ,std::string name);
    virtual ~RosWorker();
    void init();
    std::string getID();
    void sendMessage();
    void setTopic(const std::string & name,const int len,const bool latch = false );
    void setNodeName(const std::string & name);
    void callback_strMsg(const std_msgs::String &msg);
    void run();
    void spin();
public slots:
    void pubMsg(const QString &msg );
    void destination_site(const QString &msg);
    void notify_map(const QString &msg);
Q_SIGNALS:
    void signal_destination_site(const QString &msg);
    void signal_test(const QString &msg);

};

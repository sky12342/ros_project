#include<ros/ros.h>
#include<std_msgs/String.h>
#include<iostream>
using namespace std;
int main(int argc,char** argv){
ros::init(argc,argv,"my_message");
ros::NodeHandle nh;
ros::Publisher pub = nh.advertise<std_msgs::String>("test",10);
while(ros::ok()){
cout<<"connect is start "<<endl;
std_msgs::String message;
message.data = "hello my name is djt";
pub.publish(message);
}
return 0;
}
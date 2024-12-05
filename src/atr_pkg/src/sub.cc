#include<ros/ros.h>
#include<std_msgs/String.h>
#include<iostream>

using namespace std;
void come_back(std_msgs::String msg){
printf(msg.data.c_str());
printf("\n");



}
int main(int argc,char **argv){
    ros::init(argc,argv,"sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("test",10,come_back);
    while(ros::ok()){
    ros::spinOnce();
    }
    return 0;






}

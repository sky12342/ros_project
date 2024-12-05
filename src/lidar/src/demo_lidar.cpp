#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>
int count=0;
ros::Publisher pb;
void cb(const sensor_msgs::LaserScan msg){
float num = msg.ranges[180];
ROS_INFO("The distance of front obstacles is %f",num);

geometry_msgs::Twist msgs;
if(count>0){
--count;
return ;
}
if(num<1.5){
 msgs.angular.z = 0.6;
 count = 50;
}else{
    msgs.linear.x = 0.1;
}
pb.publish(msgs);
}

int main(int argc,char **argv){
setlocale(LC_ALL,"");
ros::init(argc,argv,"my_lidar");
ros::NodeHandle n;
ros::Subscriber sub = n.subscribe("/scan",10,&cb);
pb = n.advertise<geometry_msgs::Twist>("/cmd_vel",10);
ros::spin();
return 0;

}
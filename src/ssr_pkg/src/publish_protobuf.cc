#include"/root/catkin_ws/src/ssr_pkg/include/ssr_pkg/protobuf_traits.h"
#include "/root/catkin_ws/src/ssr_pkg/include/ssr_pkg/ros_protobuf.h"
#include "ros/ros.h"
#include "/root/Protobuf/Build/publish_info.pb.h"
int main(int argc, char **argv) {
  ros::init(argc, argv, "protobuf_talker");
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                 ros::console::levels::Debug);
  ros::NodeHandle n;

  ros::Publisher pub =n.advertise<D::sample::PublishInfo>("/DD", 1000);

  ros::Rate loop_rate(10);
  
  D::sample::PublishInfo proto_msg_info;
  proto_msg_info.set_name("duanjitnao");
  proto_msg_info.set_message_type("test_message");
  proto_msg_info.set_publish_msg("hello ");
  int count = 0;
  while (ros::ok()) {
    pub.publish(proto_msg_info);
    std::cerr << "DebugMsg: " << proto_msg_info.DebugString() << std::endl;
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
  return 0;
}
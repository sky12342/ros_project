#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/topic/Topic.hpp>
#include <fastdds/dds/core/Time_t.hpp>
#include <iostream>
#include <thread>
#include <fastdds/dds/core/ReturnCode.hpp>
#include</root/catkin_ws/src/ros_project/src/dds/dds_xtypes/destination/destination.hpp> 
#include</root/catkin_ws/src/ros_project/src/dds/dds_xtypes/destination/destinationPubSubTypes.hpp>

using namespace eprosima::fastdds::dds;

int main()
{
    // 创建 DomainParticipant
    DomainParticipantQos participant_qos = PARTICIPANT_QOS_DEFAULT;
    DomainParticipant* participant = DomainParticipantFactory::get_instance()->create_participant(0, participant_qos);
    if (!participant)
    {
        std::cerr << "Failed to create DomainParticipant!" << std::endl;
        return 1;
    }

    // 注册类型
    TypeSupport type_support(new Destination::Destination_sitePubSubType());
    participant->register_type(type_support); 

    // 创建 Topic
    TopicQos topic_qos = TOPIC_QOS_DEFAULT;
    topic_qos.reliability().kind = RELIABLE_RELIABILITY_QOS;
    topic_qos.lifespan().duration = eprosima::fastdds::dds::Duration_t(5); // 5 秒寿命
    Topic* topic = participant->create_topic(
        "/DDSDESTINATIONDJT", // 与接收者的 Topic 名称一致
        type_support.get_type_name(),
        topic_qos);
    if (!topic)
    {
        std::cerr << "Failed to create Topic!" << std::endl;
        DomainParticipantFactory::get_instance()->delete_participant(participant);
        return 1;
    }dds_destination

    // 创建 Publisher
    Publisher* publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT);
    if (!publisher)
    {
        std::cerr << "Failed to create Publisher!" << std::endl;
        DomainParticipantFactory::get_instance()->delete_participant(participant);
        return 1;
    }

    // 创建 DataWriter
    DataWriterQos writer_qos = DATAWRITER_QOS_DEFAULT;
    writer_qos.reliability().kind = RELIABLE_RELIABILITY_QOS;
    DataWriter* writer = publisher->create_datawriter(topic, writer_qos);
    if (!writer)
    {
        std::cerr << "Failed to create DataWriter!" << std::endl;
        participant->delete_publisher(publisher);
        DomainParticipantFactory::get_instance()->delete_participant(participant);
        return 1;
    }

    // 创建并发布数据
    Destination::Destination_site data;
    data.x(0);
    data.y(0);

    std::cout << "Publisher running. Sending data..." << std::endl;

    for (int i = 1; i <= 10; ++i) // 发布 10 次数据
    {
        data.x(i);                // 设置数据 x
        data.y(i * 10);           // 设置数据 y

        writer->write(&data);
 

        std::this_thread::sleep_for(std::chrono::seconds(1)); // 每秒发送一次
    }

    // 清理资源
    std::cout << "Stopping Publisher..." << std::endl;
    publisher->delete_datawriter(writer);
    participant->delete_publisher(publisher);
    participant->delete_topic(topic);
    DomainParticipantFactory::get_instance()->delete_participant(participant);

    return 0;
}

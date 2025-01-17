#pragma once 
#include"../dds_xtypes/destination/destination.hpp"
#include"../dds_xtypes/destination/destinationPubSubTypes.hpp"
#include"../..//qt_ui/destinatoinSiteBuffer.h" 
#include<fastdds/dds/domain/DomainParticipantFactory.hpp>
#include<fastdds/dds/domain/DomainParticipant.hpp>
#include<fastdds/dds/core/Time_t.hpp>
#include<fastdds/dds/subscriber/DataReader.hpp>
#include<fastdds/dds/topic/TypeSupport.hpp>
#include<fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include<fastdds/dds/subscriber/DataReaderListener.hpp>
#include<fastdds/dds/core/ReturnCode.hpp>
#include<fastdds/dds/topic/Topic.hpp>
#include<fastdds/dds/core/policy/QosPolicies.hpp>
#include<fastdds/dds/subscriber/qos/SubscriberQos.hpp>
#include<fastdds/dds/subscriber/Subscriber.hpp>
#include<iostream>
#include<thread>
#include<memory>

class DestinationListener:public  eprosima::fastdds::dds::DataReaderListener{
public:
    DestinationListener();
    virtual void on_data_available(eprosima::fastdds::dds::DataReader* reader);
    virtual void on_subscription_matched(eprosima::fastdds::dds::DataReader* reader,const eprosima::fastdds::dds::SubscriptionMatchedStatus& info);
private:
    std::shared_ptr<DestinationSiteBuffer> origin_buffer_;
};

class DestinationSubscrip{
public:
    DestinationSubscrip();
    void init();
    void run();
    virtual ~DestinationSubscrip();
private:
    Destination::Destination_site* destination_site_;
    eprosima::fastdds::dds::DomainParticipant* dp_;
    eprosima::fastdds::dds::Subscriber* sub_;
    eprosima::fastdds::dds::DataReader* data_reader_;
    eprosima::fastdds::dds::Topic* topic_;
    DestinationListener dl_;
    eprosima::fastdds::dds::TypeSupport type_support_;
    
};
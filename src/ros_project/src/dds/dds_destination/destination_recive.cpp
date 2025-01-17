#include"destination_receive.h"

using namespace std;
using namespace eprosima::fastdds::dds;

void DestinationListener::on_data_available(eprosima::fastdds::dds::DataReader* reader){
    Destination::Destination_site ds;
    SampleInfo info;
    if(reader->take_next_sample(&ds,&info)){
        if (info.valid_data)
        {
            cout<<ds.x()<<ds.y()<<endl;
            origin_buffer_->push(ds.x(),ds.y());
        }
        else
        {
            std::cout << "Invalid data received." << std::endl;
        }
    }
}
void DestinationListener::on_subscription_matched(eprosima::fastdds::dds::DataReader* reader,const eprosima::fastdds::dds::SubscriptionMatchedStatus& info){
    if (info.current_count_change == 1){
            std::cout << "Publisher matched." << std::endl;
    }
    else if (info.current_count_change == -1){
            std::cout << "Publisher unmatched." << std::endl;
    }
}
DestinationListener::DestinationListener():origin_buffer_(DestinationSiteBuffer::getInstance()){};
DestinationSubscrip::DestinationSubscrip():dp_(nullptr),data_reader_(nullptr),sub_(nullptr),topic_(nullptr){}

void DestinationSubscrip::init(){
    DomainParticipantQos participant_qos = PARTICIPANT_QOS_DEFAULT;
    dp_ = DomainParticipantFactory::get_instance()->create_participant(0, participant_qos);
    if (dp_ == nullptr){
            std::cerr << "Failed to create participant!" << std::endl;
            return ;
    }
    type_support_= eprosima::fastdds::dds::TypeSupport(new Destination::Destination_sitePubSubType());
    dp_->register_type(type_support_);
    TopicQos topic_qos = TOPIC_QOS_DEFAULT;
    topic_qos.reliability().kind = RELIABLE_RELIABILITY_QOS;
    topic_qos.lifespan().duration =eprosima::fastdds::dds::Duration_t(5);
    topic_ = dp_->create_topic(
    "/DDSDESTINATIONDJT",
    type_support_.get_type_name(),
    topic_qos
    );
    sub_ = dp_->create_subscriber(SUBSCRIBER_QOS_DEFAULT);
    if(sub_==nullptr){
        cerr<<"Failed to create Subscriber!"<<endl;
    }
    DataReaderQos reader_qos;
    sub_->get_default_datareader_qos(reader_qos);
    data_reader_ = sub_->create_datareader(topic_,reader_qos,&dl_);

}
void DestinationSubscrip::run(){
    std::cout << "Subscriber running. Waiting for data..." << std::endl;
    while (true){
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

}

DestinationSubscrip::~DestinationSubscrip(){
    if (data_reader_ != nullptr){
        sub_->delete_datareader(data_reader_);
    }
    if (topic_ != nullptr){
        dp_->delete_topic(topic_);
    }
    if (sub_ != nullptr){
        dp_->delete_subscriber(sub_);
    }
    DomainParticipantFactory::get_instance()->delete_participant(dp_);

}
#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <iomanip>
#include <cstring>

#define SAMPLE_SERVICE_ID   0x1234
#define SAMPLE_INSTANCE_ID  0x5678
#define SAMPLE_METHOD_ID    0x9ABC

class SimpleClient {
public:
    SimpleClient() : app_(vsomeip::runtime::get()->create_application()) {}

    bool init() {
        if (!app_->init()) {
            std::cerr << "Couldn't initialize application" << std::endl;
            return false;
        }

        // 注册消息处理器
        app_->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID,
                                       std::bind(&SimpleClient::on_message, this, std::placeholders::_1));

        // 设置服务请求
        request_ = vsomeip::runtime::get()->create_request(false);  // 非可靠请求
        request_->set_service(SAMPLE_SERVICE_ID);
        request_->set_instance(SAMPLE_INSTANCE_ID);
        request_->set_method(SAMPLE_METHOD_ID);

        // 创建负载数据（例如，发送一个错误码作为示例）
        std::vector<vsomeip::byte_t> payload_data(sizeof(int));
        int error_code = 1001;  // 示例错误码
        std::memcpy(payload_data.data(), &error_code, sizeof(int));

        std::shared_ptr<vsomeip::payload> payload = vsomeip::runtime::get()->create_payload();
        payload->set_data(payload_data);
        request_->set_payload(payload);

        // 注册服务的可用性处理器
        app_->register_availability_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID,
                                            std::bind(&SimpleClient::on_availability, this,
                                                      std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

        return true;
    }

    void start() {
        app_->start();  // 启动应用程序
    }

    void send_request() {
        app_->send(request_);  // 向服务端发送请求
        std::cout << "Request sent to Service [" << SAMPLE_SERVICE_ID << "." << SAMPLE_INSTANCE_ID << "]" << std::endl;
    }

    void on_message(const std::shared_ptr<vsomeip::message>& response) {
        std::cout << "Received response from Service ["
                  << std::setw(4) << std::setfill('0') << std::hex << response->get_service()
                  << "." << std::setw(4) << std::setfill('0') << std::hex << response->get_instance()
                  << "] to Client/Session ["
                  << std::setw(4) << std::setfill('0') << std::hex << response->get_client()
                  << "/" << std::setw(4) << std::setfill('0') << std::hex << response->get_session()
                  << "]" << std::endl;
    }

    // 处理服务的可用性
    void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
        if (_is_available) {
            std::cout << "Service [" << std::hex << _service << "] is now available." << std::endl;
            send_request();  // 发送请求
        } else {
            std::cout << "Service [" << std::hex << _service << "] is no longer available." << std::endl;
        }
    }

private:
    std::shared_ptr<vsomeip::application> app_;
    std::shared_ptr<vsomeip::message> request_;
};

int main() {
    SimpleClient client;

    if (client.init()) {
        client.start();
    } else {
        std::cerr << "Failed to initialize client." << std::endl;
        return 1;
    }

    return 0;
}

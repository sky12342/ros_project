#include <vsomeip/vsomeip.hpp>
#include <iostream>

#define SAMPLE_SERVICE_ID   0x1234
#define SAMPLE_INSTANCE_ID  0x5678
#define SAMPLE_METHOD_ID    0x9ABC

class SimpleServer {
public:
    SimpleServer() : app_(vsomeip::runtime::get()->create_application()) {}

    bool init() {
        if (!app_->init()) {
            std::cerr << "Couldn't initialize application" << std::endl;
            return false;
        }

        // 注册服务并设置消息处理器
        app_->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID,
                                       std::bind(&SimpleServer::on_message, this, std::placeholders::_1));

        // 启动服务发现
        app_->offer_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
        std::cout << "Service is offering at " << SAMPLE_SERVICE_ID << "." << SAMPLE_INSTANCE_ID << std::endl;

        return true;
    }

    void start() {
        app_->start();  // 启动应用程序
    }

    void on_message(const std::shared_ptr<vsomeip::message>& request) {
        std::cout << "Received request from client" << std::endl;

        // 处理请求并发送响应
        std::shared_ptr<vsomeip::message> response = vsomeip::runtime::get()->create_response(request);
        app_->send(response);
    }

private:
    std::shared_ptr<vsomeip::application> app_;
};

int main() {
    SimpleServer server;

    if (server.init()) {
        server.start();
    } else {
        std::cerr << "Failed to initialize server." << std::endl;
        return 1;
    }

    return 0;
}

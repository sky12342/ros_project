#pragma once

#include "rosWorkList.h"
#include <memory>
#include <string>

template <typename T>
class RosNodeManager {
public:
    RosNodeManager(int argc, char** argv, const std::string& node_name);
    ~RosNodeManager() {}
    void run();
    void init(std::string name,int max_len);
    std::shared_ptr<RosFunBase> getNode() const;
    void spin();
private:
    FunList& fl_;
    int argc_;
    char** argv_;
    std::string node_name_;
    std::shared_ptr<T> node_; // 泛化节点类型
};


template <typename T>
RosNodeManager<T>::RosNodeManager(int argc, char** argv, const std::string& node_name)
    : fl_(FunList::getInstance()), argc_(argc), argv_(argv), node_name_(node_name){
}


template <typename T>
void RosNodeManager<T>::spin(){
    node_->spin();
}

template <typename T>
void RosNodeManager<T>::init(std::string name,int max_len) {
    node_ = std::make_shared<T>(argc_, argv_, node_name_);
    fl_.add(node_->getID(), std::static_pointer_cast<RosFunBase>(node_));
    fl_.addStringname(node_name_, node_->getID());
    node_->setTopic(name, max_len);
    node_->init();
}
template <typename T>
void RosNodeManager<T>::run() {
    node_->run();
}

template <typename T>
std::shared_ptr<RosFunBase> RosNodeManager<T>::getNode() const {
    return fl_.get(node_name_);
}

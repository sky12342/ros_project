#include "SignalSlotProxy.h"
#include <QDebug>

SignalSlotProxy::SignalSlotProxy(std::shared_ptr<RosFunBase> rosNode, QObject* parent)
    : QObject(parent), rosNode_(rosNode) {
    if (rosNode_) {
        
    }
}

void SignalSlotProxy::publishMessage(const QString& msg) {
    if (rosNode_) {
        rosNode_->pubMsg(msg);
    } else {
        qWarning() << "ROS Node is not initialized!";
    }
}
void SignalSlotProxy::setDestinationSite(const QString& msg){
    if (rosNode_) {
        rosNode_->destination_site(msg);
    } else {
        qWarning() << "ROS Node is not initialized!";
    }
}
void SignalSlotProxy::pubDestinationSite(const QString& msg){
    if (rosNode_) {
        rosNode_->getPbMsg(msg);
    } else {
        qWarning() << "ROS Node is not initialized!";
    }
}
void SignalSlotProxy::setMap(const QString& msg){
    if (rosNode_) {
        rosNode_->notify_map(msg);
    } else {
        qWarning() << "ROS Node is not initialized!";
    }
}


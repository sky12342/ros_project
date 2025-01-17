#include "SignalSlotProxy.h"
#include <QDebug>

SignalSlotProxy::SignalSlotProxy(std::shared_ptr<RosFunBase> rosNode, QObject* parent)
    : QObject(parent), rosNode_(rosNode),origin_buffer_(DestinationSiteBuffer::getInstance()) {
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
            QStringList parts = msg.split(",");
            int x = parts[0].toInt();
            int y = parts[1].toInt();
            origin_buffer_->push(x,y);
            rosNode_->call();
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


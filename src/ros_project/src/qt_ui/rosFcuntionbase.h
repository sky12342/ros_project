#pragma once
#include <QCoreApplication>
#include <QThread>
#include <QString>
#include<string>
#include<std_msgs/String.h>
#include <ros/ros_protobuf.h>
#include <ros/protobuf_traits.h>
#include"./rosWorkList.h"
class RosFunBase:public QObject{
Q_OBJECT
public: 
    virtual void init(){};
    void sendMessage(){};
    virtual void setTopic(const std::string & name,const int len,const bool latch =false ){};
    virtual void setNodeName(const std::string & name){};
    virtual void callback_strMsg(const std_msgs::String &msg){};
    virtual std::string getID(){};
    virtual void run()=0;
    virtual void spin(){};
    RosFunBase() : umap(FunList::getInstance()) {
    // 构造函数实现
}
virtual ~RosFunBase(){};
protected:
    FunList& umap;
public slots:
    virtual void getPbMsg(const QString &msg ){};
    virtual void pubMsg(const QString &msg ){};
    virtual void destination_site(const QString &msg){};
    virtual void notify_map(const QString &msg){};
Q_SIGNALS:
    void signal_rosShutdown();
    void signal_strMsg(const QString&);
};
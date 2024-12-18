#pragma once

#include <QObject>
#include <memory>
#include "ros_worker.h"

class SignalSlotProxy : public QObject {
    Q_OBJECT

public:
    explicit SignalSlotProxy(std::shared_ptr<RosFunBase> rosNode, QObject* parent = nullptr);
    ~SignalSlotProxy() {}

public slots:
    void publishMessage(const QString& msg);
    void setDestinationSite(const QString& msg);
    void setMap(const QString& msg);
    void pubDestinationSite(const QString& msg);
signals:
    void messageReceived(const QString& msg);

private:
    std::shared_ptr<RosFunBase> rosNode_;
};
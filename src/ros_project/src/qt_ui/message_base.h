#pragma once

#include<ros/ros.h>
#include<list>
#include<memory>

class TransferBase
{
protected:
    TransferBase();
    ~TransferBase();
private:
    TransferBase(const TransferBase&) =delete;
    TransferBase& operator= (const TransferBase&) =delete;
public:
    void sendMessage();
    void init();
};


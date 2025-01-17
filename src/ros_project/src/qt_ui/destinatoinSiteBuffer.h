#pragma once
#include"Singleton.h"
#include<queue>
#include<utility>
#include<mutex>
#include<atomic>
#include"const.h"
class DestinationSiteBuffer:public Singleton<DestinationSiteBuffer>{
// friend class Singleton<DestinationSiteBuffer>;
public:
    DestinationSiteBuffer()=default;
    void push(int x,int y);
    void swap(std::queue<std::pair<int,int>> &tmp);
private:
    static std::queue<std::pair<int,int>> site_buffer_;
    std::mutex mtx_;
    std::atomic<bool> flag_;
};



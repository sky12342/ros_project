#pragma once
#include <memory>
#include <mutex>
#include <iostream>
using namespace std;

template<typename T>
class Singleton{

public:
    static shared_ptr<T> getInstance(){
        static std::once_flag s_flag;
        std::call_once(s_flag,[&]{
            instance_ = make_shared<T>();
        });
        return instance_;
    }
    
protected:
    Singleton()=default;
    Singleton(const Singleton& ) = delete;
    Singleton& operator= (const Singleton& ) = delete;
    static shared_ptr<T> instance_; 
};
template<typename T>
shared_ptr<T> Singleton<T>::instance_ = nullptr;
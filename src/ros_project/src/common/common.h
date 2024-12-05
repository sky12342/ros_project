#pragma once

#include<iostream>
#include<string>
#include<stdio.h>
#include<unistd.h>
#include<mutex>

class Common{
public:
    Common();
    ~Common();
    std::string getCurrentPath();
    std::string getLogPath();
    void creatMulPath(const std::string & path_name);
    static Common* getCommonInstance();

private:
    std::string current_path_;
    std::string log_path_;
    static std::mutex lock_;
    static Common* instance_;
};
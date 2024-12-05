#pragma once


#include<map>
#include<memory>
#include<string>
#include<vector>
#include<thread>
class RosFunBase;
class FunList{

protected:
    FunList();
    ~FunList();
public:
    static FunList& getInstance();
    void add(const std::string &name,std::shared_ptr<RosFunBase> base);
    void del(const std::string &name);
    std::shared_ptr<RosFunBase> get(std::string name);
    void addStringname(const std::string &name1,const std::string &name2);
    bool isExist(const std::string &name);
    static std::vector<std::shared_ptr<std::thread>> threads_;
private:
    static std::map<std::string, std::shared_ptr<RosFunBase>> ros_fun_map;
    static std::map<std::string, std::string> ros_name_map;
    FunList(const FunList &) =delete;
    FunList& operator= (const FunList &) =delete;
};


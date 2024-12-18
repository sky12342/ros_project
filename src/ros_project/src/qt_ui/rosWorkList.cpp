#include"rosWorkList.h"


std::map<std::string, std::shared_ptr<RosFunBase>> FunList::ros_fun_map; 
std::map<std::string, std::string> FunList::ros_name_map; 
std::vector<std::shared_ptr<std::thread>> FunList::threads_;
    FunList::FunList(){}
    FunList::~FunList(){
        for(auto &th:threads_){
            if (th->joinable()) {
                th->join();  // 等待线程结束
            }
        }
        for(auto& th:ros_fun_map)
            th.second.reset();
    }
    FunList& FunList::getInstance(){
            static FunList umap;
            return umap;
    }
    void FunList::add(const std::string &name,const std::shared_ptr<RosFunBase> base){
        ros_fun_map[name] = base;
    }
    void FunList::del(const std::string &name){
        ros_fun_map.erase(name);
    }
std::shared_ptr<RosFunBase> FunList::get(std::string name) {
    if (ros_name_map.find(name) == ros_name_map.end()) {
        return nullptr;  // 如果没有找到，返回 nullptr
    }

    std::string ros_id = ros_name_map[name];
    if (ros_fun_map.find(ros_id) == ros_fun_map.end()) {
        return nullptr;  // 如果没有找到对应的 ros_id，返回 nullptr
    }
    return ros_fun_map[ros_id];
}
    void FunList::addStringname(const std::string &name1,const std::string &name2){
        ros_name_map.insert(std::make_pair(name1,name2));
    }
    bool FunList::isExist(const std::string &name) {
        return ros_name_map.find(name) != ros_name_map.end();
    }

#include "common.h"

using namespace std;

Common::Common(){}
Common::~Common(){

}

mutex Common::lock_;
Common* Common::instance_(nullptr);

void Common::creatMulPath(const string & path_name){
    const string command = "mkdir -p " + path_name;
    system(command.c_str());
}

string Common::getCurrentPath(){
    char * path = getcwd(NULL,0);
    string spath(path);
    current_path_ = spath;
    return spath;
}

string Common::getLogPath(){
    unique_lock<mutex>(lock_);
    string cur_path = getCurrentPath();
    int end_index = cur_path.find_last_of("/");
    string log_path = cur_path.substr(0,end_index)+"/logs";
    log_path_ = log_path;
    if(access(log_path_.c_str(),0)){
        cout<< "log is not exist!\n now this logpath is creating!!!!"<<endl;
        creatMulPath(log_path_);
        return log_path_;
    }
    return log_path_;
}

Common* Common::getCommonInstance(){
    if(instance_ == nullptr){
        unique_lock<mutex>(lock_);
        if(instance_ == nullptr){
            instance_ = new Common();
        }
    }
    return instance_;
}
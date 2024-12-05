#include"Log.h"
#include"common.h"
using namespace std;

int main(int argc,char ** argv){

Common* test_comm = Common::getCommonInstance();
MyLog* log = new MyLog(test_comm->getLogPath(),"testLog");
LOG(INFO)<<"test this log"<<endl;

delete log;
return 0;
}
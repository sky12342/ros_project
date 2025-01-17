#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "rosWorkList.h"
int main(int argc, char *argv[])
{   

    QApplication a(argc, argv);
    MainWindow w(argc,argv);
    w.show();
    a.exec();
    auto& funlist = FunList::getInstance();
    for(auto &th:funlist.threads_){
        if (th->joinable()) {
            th->join();  // 等待线程结束
        }
    }
    return 0;

}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QPointer>
#include<QProcess>
#include "rosNodeManager.h"
#include "SignalSlotProxy.h"
#include "ros_destination_send.h"
#include "../dds/dds_destination/destination_receive.h"
// #include "common.h"
// #include "Log.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget* parent = nullptr);
    ~MainWindow();
public slots:
    void slot_btn_send();
    void slot_send_textEdit(const QString&);

signals:
    void signal_rosPub(const QString&);
    void signal_Destination_site(const QString&);
    void signal_map(const QString&);

private slots:
    
    void on_Start_SE_clicked();


    void on_Start_Navigation_clicked();

    void on_Destination_clicked();

    void on_Destination_map_clicked();


    void on_RvizStart_clicked();

    void on_navigateion_to_point_clicked();

private:
    Ui::MainWindow* ui_;
    std::unique_ptr<RosNodeManager<RosWorker>> ros_manager_;
    std::unique_ptr<RosNodeManager<RosDestinationSender>> Destinatoin_node_manager_;
    std::unique_ptr<SignalSlotProxy> signal_slot_proxy_;  // 代理类
    std::shared_ptr<DestinationSubscrip> dds_sub_;
    // Common common_log_;
    // MyLog* myLog_;
    FunList& rosmap_;
    QProcess* process1;
    QProcess* process2;
    QProcess* process3;
    bool nv_point=true;
};

#endif // MAINWINDOW_H

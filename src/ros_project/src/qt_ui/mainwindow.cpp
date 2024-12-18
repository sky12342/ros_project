#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"QMessageBox"
#include <QDebug>
#include<unistd.h>
#include<ros/ros.h>
MainWindow::MainWindow(int argc, char** argv, QWidget* parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , ros_manager_(std::make_unique<RosNodeManager<RosWorker>>(argc, argv, "testnode"))
    , Destinatoin_node_manager_(std::make_unique<RosNodeManager<RosDestinationSender>>(argc, argv, "Destination_node"))
    , rosmap_(FunList::getInstance())
{
    ui_->setupUi(this);

    // 初始化 ROS 节点
        if(!ros::master::check()){
        process3 = new QProcess(this);
        process3->start("roscore");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        process1 = nullptr;  
        process2 = nullptr;

        ros_manager_->init("/Destination", 1024);
        Destinatoin_node_manager_->init("/Destination",1024);
        auto ros_worker = ros_manager_->getNode();
        auto ros_destination_node = Destinatoin_node_manager_->getNode();
        // 创建 SignalSlotProxy 实例，负责管理信号和槽的连接
        signal_slot_proxy_ = std::make_unique<SignalSlotProxy>(ros_destination_node);
        // 连接信号和槽，通过代理类来管理
        // QObject::connect(ui_->RvizStart, &QPushButton::clicked, this, &MainWindow::on_RvizStart_clicked);
        // QObject::connect(ui_->Start_SE, &QPushButton::clicked, this, &MainWindow::on_Start_SE_clicked);
        // QObject::connect(ui_->Start_Navigation, &QPushButton::clicked, this, &MainWindow::on_Start_Navigation_clicked);
        // QObject::connect(ui_->navigateion_to_point, &QPushButton::clicked, this, &MainWindow::on_navigateion_to_point_clicked);
        // QObject::connect(ui_->Destination, &QPushButton::clicked, this, &MainWindow::on_Destination_clicked);
        QObject::connect(this, &MainWindow::signal_Destination_site, signal_slot_proxy_.get(), &SignalSlotProxy::pubDestinationSite);
        // QObject::connect(ui_->Destination_map, &QPushButton::clicked, this, &MainWindow::on_Destination_map_clicked);
        QObject::connect(this, &MainWindow::signal_map, signal_slot_proxy_.get(), &SignalSlotProxy::setMap);        
        // std::string log_path = common_log_.getLogPath();
        // myLog_ = new MyLog(log_path, "mainWindow");
        // LOG(INFO) << "mainWindow Log Hello World!!!";
        QMessageBox::information(this, tr("Success"), tr("step1 open navigation\nstep2 open se\nstep3 open rviz\nstep4 open navigation to point\n."));
}

MainWindow::~MainWindow() {
    delete ui_;
    // delete myLog_;
}

void MainWindow::slot_btn_send() {
    QString send_msg = ui_->lineEdit_input->text();
    qDebug() << send_msg;
    QProcess *process = new QProcess(this);
    process->start("roscore");
    process->start("roslaunch wpr_simulation wpb_stage_robocup.launch");
    emit signal_rosPub(send_msg);  // 发送信号，由 SignalSlotProxy 来处理发布
}

/**
 * 槽函数
 */
void MainWindow::slot_send_textEdit(const QString& msg) {
    ui_->textEdit_sub->append(msg);
}



void MainWindow::on_Start_SE_clicked()
{    // 设置 ROS 环境变量
    qDebug() << "Start Start_SE clicked!";
    process1 = new QProcess(this);
    process1->start("roslaunch wpr_simulation wpb_stage_robocup.launch");
    // 在 Qt 窗口中显示消息
    QMessageBox::information(this, tr("Success"), tr(" SE have started successfully."));
    
}



void MainWindow::on_Start_Navigation_clicked()
{   
    rosmap_.threads_.emplace_back(std::make_shared<std::thread>([]{
        system("roslaunch nav_pkg nav.launch");  // 启动 roslaunch 命令
    }));
    QMessageBox::information(this, tr("Success"), tr("ROS nv started successfully."));
}

void MainWindow::on_Destination_clicked()
{
    QString send_msg = ui_->lineEdit_input->text();
    qDebug() << send_msg;
    emit signal_Destination_site(send_msg);
    auto ret = QMessageBox::information(this,tr("information"),send_msg+"is emit success",QMessageBox::Yes);
}

void MainWindow::on_Destination_map_clicked()
{
    QString send_msg = ui_->lineEdit_input_2->text();
    qDebug() << send_msg;
    emit signal_map(send_msg);
}



void MainWindow::on_RvizStart_clicked()
{   

    process2 = new QProcess(this);
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("ROS_MASTER_URI", "http://localhost:11311");
    process2->setProcessEnvironment(env);
    process2->start("rosrun", QStringList() << "rviz" << "rviz");
    QMessageBox::information(this, tr("Success"), tr(" rviz have started successfully."));

    qDebug() << "Rviz is already running.";

}



void MainWindow::on_navigateion_to_point_clicked()
{   if(nv_point){
    rosmap_.threads_.emplace_back(std::make_shared<std::thread>([this]() {
    ros_manager_->run();  
}));
    rosmap_.threads_.emplace_back(std::make_shared<std::thread>([this]() {
    Destinatoin_node_manager_->run();  
}));
    rosmap_.threads_.emplace_back(std::make_shared<std::thread>([this]() {
    ros_manager_->spin();  
}));
    nv_point = false;
}
QMessageBox::information(this, tr("Success"), tr("ROS nv_to_point started successfully."));
}

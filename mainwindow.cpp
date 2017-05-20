#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ledState=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_EnviarDatos_clicked()
{
    enviar(ui->datos->text());
}

void MainWindow::on_datos_returnPressed()
{
    on_EnviarDatos_clicked();
}

void MainWindow::on_led_clicked()
{
    if(ledState==true){
        enviar("gpio/?estado=OFF");
        ledState=false;
        ui->led->setIcon(QIcon(":/red.png"));
    }
    else{
        enviar("gpio/?estado=ON");
        ledState=true;
        ui->led->setIcon(QIcon(":/green.png"));
    }
}

void MainWindow::enviar(QString datos)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ui->hostIp->text(),ui->Puerto->value());
    if(socket->waitForConnected(1000)){
        socket->write(datos.toUtf8());
        socket->waitForBytesWritten(100);
        socket->waitForReadyRead(2000);
        ui->RespuestaServidor->append(socket->readAll());
        socket->close();

    }
    else{
        ui->RespuestaServidor->append("<font color = red>Faild conect :(</font>");

    }
}



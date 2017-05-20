#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_EnviarDatos_clicked();
    void on_datos_returnPressed();
    void on_led_clicked();
    void enviar(QString datos);
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    bool ledState;
};

#endif // MAINWINDOW_H

#include <QApplication>
#include "mainwindow.h"
#include "dialog.h"
#include "network.h"
#include <math.h>

int main(int argc, char** argv) {
    bool resetCheck;
    bool dialogResetCheck;
    QString ip;
    int port;
    User user;
    writeIpToFile("127.0.0.1:2323");
    do {
        QApplication app(argc, argv);
        resetCheck = false;
        do {
            dialogResetCheck = false;

            QString ipText = readIpFromFile();
            QStringList splits = ipText.split(":");
            ip = splits.at(0);
            QString portText = splits.at(1);
            qDebug() << "/// ip = " << ip;
            qDebug() << "/// portText = " << portText;
            port = portText.toInt();

            Dialog dg(ip, port);

            dg.openDialog();
            if (dg.isLogined() == true) {
                qDebug() << "logined";
            }

            dialogResetCheck = dg.getResetCheck();
            if (dg.finished()) {

                ip = dg.getIp();
                port = dg.getPort();

                user = dg.getUser();
                if (dg.isLogined() != true && dialogResetCheck == false) {
                    return 0;
                }
//                ipText = ip + ":" + QString::number(port);
//                writeIpToFile(ipText);
                dg.close();
            }
        } while (dialogResetCheck == true);

        MainWindow client(ip, port);
        client.show();
        client.setUser(user);
        client.sendCommandToServer(userConnected);
        app.exec();
        if (client.close() == true) {
            resetCheck = client.getResetCheck();

        }
    } while (resetCheck == true);
    return 0;
}



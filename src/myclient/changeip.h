#ifndef CHANGEIP_H
#define CHANGEIP_H

#include <QDialog>

namespace Ui {
class ChangeIp;
}

class ChangeIp : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeIp(QString ip, int port, QWidget *parent = 0);
    ~ChangeIp();
    bool getResetCheck();
    QString getIp();
    int getPort();
private slots:
    void on_changeServerButton_clicked();

private:
    Ui::ChangeIp *ui;
    bool resetCheck;
    QString changedIp;
    QString ip;
    int port;
};

#endif // CHANGEIP_H

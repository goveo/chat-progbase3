//#include "myclient.h"
//#include "ui_myclient.h"

//#include <QTcpServer>
//#include <QMessageBox>
//#include <QTextEdit>
//#include <QVBoxLayout>
//#include <QLabel>
//#include <QTcpSocket>
//#include <QTime>
//#include <QTextEdit>
//#include <QLineEdit>
//#include <QPushButton>

//MyClient::MyClient(const QString& strHost,
//                   int            nPort,
//                   QWidget        *parent /*=0*/
//                  ) : QMainWindow(parent),
//    ui(new Ui::MyClient),
//                      m_nNextBlockSize(0)
//{
//    ui->setupUi(this);

//    m_pTcpSocket = new QTcpSocket(this);

//    m_pTcpSocket->connectToHost(strHost, nPort);
//    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
//    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
//    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
//            this,         SLOT(slotError(QAbstractSocket::SocketError))
//           );

//    m_ptxtInfo  = new QTextEdit;
//    m_ptxtInput = new QLineEdit;

//    connect(m_ptxtInput, SIGNAL(returnPressed()),
//            this,        SLOT(slotSendToServer())
//           );
//    m_ptxtInfo->setReadOnly(true);

//    //QPushButton* sendMessage = new QPushButton("&Send");
//    QPushButton * sendMessage = this->findChild<QPushButton*>("sendButton");
//    connect(sendMessage, SIGNAL(clicked()), SLOT(slotSendToServer()));

//    QPushButton* setUsername = new QPushButton("&Set Name");
//    connect(setUsername, SIGNAL(clicked()), SLOT(slotSetName()));


//    //Layout setup
//    QVBoxLayout* pvbxLayout = new QVBoxLayout;
//    pvbxLayout->addWidget(new QLabel("<H1>Client</H1>"));
//    pvbxLayout->addWidget(m_ptxtInfo);
//    pvbxLayout->addWidget(m_ptxtInput);
//    pvbxLayout->addWidget(sendMessage);
//    pvbxLayout->addWidget(setUsername);
//    setLayout(pvbxLayout);

//    slotSendToServer();
//}

//MyClient::~MyClient() {
//    delete ui;
//}

//void MyClient::slotReadyRead()
//{
//    QDataStream in(m_pTcpSocket);
//    in.setVersion(QDataStream::Qt_4_2);
//    for (;;) {
//        if (!m_nNextBlockSize) {
//            if (m_pTcpSocket->bytesAvailable() < sizeof(quint16)) {
//                break;
//            }
//            in >> m_nNextBlockSize;
//        }

//        if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize) {
//            break;
//        }
//        QTime   time;
//        QString str;
//        in >> time >> str;

//        m_ptxtInfo->append(time.toString() + " " + str);
//        m_nNextBlockSize = 0;
//    }
//}

//void MyClient::slotError(QAbstractSocket::SocketError err)
//{
//    QString strError =
//        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
//                     "The host was not found." :
//                     err == QAbstractSocket::RemoteHostClosedError ?
//                     "The remote host is closed." :
//                     err == QAbstractSocket::ConnectionRefusedError ?
//                     "The connection was refused." :
//                     QString(m_pTcpSocket->errorString())
//                    );
//    m_ptxtInfo->append(strError);
//}

//void MyClient::slotSendToServer()
//{
//    QByteArray  arrBlock;
//    QDataStream out(&arrBlock, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_4_2);
//    out << quint16(0) << QTime::currentTime() << m_ptxtInput->text();

//    out.device()->seek(0);
//    out << quint16(arrBlock.size() - sizeof(quint16));

//    m_pTcpSocket->write(arrBlock);
//    m_ptxtInput->setText("");
//}

//void MyClient::slotSetName()
//{
//    QByteArray  arrBlock;
//    QDataStream out(&arrBlock, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_4_2);
//    out << quint16(0) << QTime::currentTime() << "dob";

//    out.device()->seek(0);
//    out << quint16(arrBlock.size() - sizeof(quint16));

//    m_pTcpSocket->write(arrBlock);

//    //m_ptxtInput->setText("");
//}

//void MyClient::slotConnected()
//{
//    m_ptxtInfo->append("Received the connected() signal");
//}

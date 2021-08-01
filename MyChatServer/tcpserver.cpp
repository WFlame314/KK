#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

void TcpServer::dataReceived()
{
    while(bytesAvailable()>0)
    {
        int length = bytesAvailable();
        char buf[length];
        read(buf,length);
        QString msg=buf;
        emit updataClients(msg,length,this->socketDescriptor());
    }
}

void TcpServer::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}

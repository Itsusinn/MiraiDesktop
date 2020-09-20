#include "websocketclient.h"

WebsocketClient::WebsocketClient(QObject *parent) : QObject(parent)
{
    //对接相应的信号槽与方法
    websocket = new QWebSocket();

    connect(websocket,SIGNAL(connected()),
        this,SLOT(onConnected()),Qt::UniqueConnection);

    connect(websocket,SIGNAL(disconnected()),
        this,SLOT(onDisconnected()),Qt::UniqueConnection);

    connect(websocket, SIGNAL(binaryMessageReceived(QByteArray)),
        this, SLOT(onBinaryMessageReceived(QByteArray)),Qt::UniqueConnection);
}

void WebsocketClient::onDisconnected(){
    qDebug()<<"websocket is disconnected";
    reconnect();
}

void WebsocketClient::onConnected(){
    qDebug()<<"connect successful";
}

void WebsocketClient::onBinaryMessageReceived(QByteArray message){
}

void WebsocketClient::reconnect(){
    qDebug()<<"websocket reconnected";
}
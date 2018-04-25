#pragma once
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "Target.h"

class NetworkServer : public QObject
{
	Q_OBJECT
public:
	explicit NetworkServer(QObject *parent = 0);
	~NetworkServer();

public slots:
	void accept_connection();
	void read_data();
	void display_error(QAbstractSocket::SocketError socket_error);

private:
	void start_server();

	Target *m_target;
	QTcpServer *m_tcp_server;
	QTcpSocket *m_server_socket;
};


#include "NetworkServer.h"
#include <iostream>

NetworkServer::NetworkServer(QObject *parent) : QObject(parent) {
	m_tcp_server = new QTcpServer();
	m_target = new Target();

	connect(m_tcp_server, SIGNAL(newConnection()), this, SLOT(accept_connection()));
	start_server();
}

NetworkServer::~NetworkServer() {
	delete m_server_socket;
	delete m_tcp_server;
}

void NetworkServer::accept_connection() {
	m_server_socket = m_tcp_server->nextPendingConnection();
	connect(m_server_socket, SIGNAL(readyRead()), this, SLOT(read_data()));
	connect(m_server_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(display_error(QAbstractSocket::SocketError)));
}

void NetworkServer::read_data() {
	QByteArray rx_buffer = m_server_socket->readAll();
	std::cout << "Command: " << rx_buffer.toStdString() << std::endl;
	QString command = QString(rx_buffer);
	if (command.compare("out")) {
		//TODO: Richtung korrekt bestimmen

	}

	if (command.compare("away")) {
		//TODO: Richtung korrekt bestimmen
		
	}

	if (command.compare("awayout")) {
		//TODO: Richtung korrekt bestimmen

	}
}

void NetworkServer::display_error(QAbstractSocket::SocketError socket_error) {
	std::cout << "Error: " << socket_error << std::endl;
	m_server_socket->close();
}

void NetworkServer::start_server() {
	while (!m_tcp_server->isListening() && !m_tcp_server->listen(QHostAddress::Any, 8888)) {
		std::cout << "Loopback" << std::endl;
		std::cout << "Unable to start the test: " << m_tcp_server->errorString().toStdString() << std::endl;
	}
}

#include <QtCore/QCoreApplication>
#include "NetworkServer.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	NetworkServer server;
	return a.exec();
}

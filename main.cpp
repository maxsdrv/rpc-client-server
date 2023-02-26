#include <QDebug>


#include "Server.h"


int main(int argc, char** argv) {
	qDebug("Server test");
	MKOServer s;
	s.run_server("hello");

	return 0;
}

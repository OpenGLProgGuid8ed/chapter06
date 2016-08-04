#include "statictex.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	staticTex w;
	w.show();
	return a.exec();
}

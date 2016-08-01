#include "loadtex.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoadTex w;
	w.show();
	return a.exec();
}

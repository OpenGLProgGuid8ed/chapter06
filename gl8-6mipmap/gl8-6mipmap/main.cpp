#include "mipmap.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mipMap w;
	w.show();
	return a.exec();
}

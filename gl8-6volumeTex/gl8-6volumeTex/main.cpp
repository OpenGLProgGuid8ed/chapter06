#include "volumetex.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	volumeTex w;
	w.show();
	return a.exec();
}

#include "mipfilter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mipFilter w;
	w.show();
	return a.exec();
}

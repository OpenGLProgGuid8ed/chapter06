#include "txwrap.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	txWrap w;
	w.show();
	return a.exec();
}

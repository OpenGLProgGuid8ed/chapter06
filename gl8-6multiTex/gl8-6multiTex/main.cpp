#include "multitex.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	multiTex w;
	w.show();
	return a.exec();
}

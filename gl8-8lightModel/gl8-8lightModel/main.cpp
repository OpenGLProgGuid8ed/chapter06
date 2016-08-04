#include "lightmodel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LightModel w;
	w.show();
	return a.exec();
}

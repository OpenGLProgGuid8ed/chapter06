#include "lightmodel.h"

LightModel::LightModel(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	pVolumeRgb = ui.dockWidgetContents;
	connectActions();
}

LightModel::~LightModel()
{

}
void LightModel::connectActions()
{
}

void LightModel::SetR(int value)
{
	r = value;
	emit RChanged(float(r)/255);
}
void LightModel::SetG(int value)
{
	g = value;
	emit RChanged(float(g)/255);
}
void LightModel::SetB(int value)
{
	b = value;
	emit RChanged(float(b)/255);
}
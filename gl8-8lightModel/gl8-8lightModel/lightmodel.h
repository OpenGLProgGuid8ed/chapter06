#ifndef LIGHTMODEL_H
#define LIGHTMODEL_H

#include <QtWidgets/QMainWindow>
#include "ui_lightmodel.h"
#include "volumeRgb.h"
class LightModel : public QMainWindow
{
	Q_OBJECT

public:
	LightModel(QWidget *parent = 0);
	~LightModel();
	void connectActions();
public slots:
	void SetR(int value);
	void SetG(int value);
	void SetB(int value);
signals:
	void RChanged(float);
private:
	Ui::LightModelClass ui;
	VolumeRgb *pVolumeRgb;
	int r,g,b;
};

#endif // LIGHTMODEL_H

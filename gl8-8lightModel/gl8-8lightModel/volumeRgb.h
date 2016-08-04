#ifndef VOLUMERGB_H
#define VOLUMERGB_H

#include <QtWidgets/QWidget>
#include "ui_volumeRgb.h"

class VolumeRgb : public QWidget
{
	Q_OBJECT

public:
	VolumeRgb(QWidget *parent = 0);
	~VolumeRgb();

public slots:
	void setR(int r);
	void setG(int g);
	void setB(int b);

private:
	Ui::Form ui;


};

#endif // VOLUMEINFO_H

#ifndef SMALLGRID_H
#define SMALLGRID_H

#include <QWidget>

class QColor;

class SmallGrid : public QWidget
{
	Q_OBJECT
public:
	explicit SmallGrid(QWidget *parent = 0);
	
signals:
	
public slots:
	void setScale(int s);
	
protected:
	
	virtual void paintEvent(QPaintEvent * evt);
	
private:
	
	QColor m_array [3];
	
	int m_scale;
};

#endif // SMALLGRID_H

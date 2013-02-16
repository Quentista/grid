#ifndef SMALLGRID_H
#define SMALLGRID_H

#include <QWidget>

class QColor;

class SmallGrid : public QWidget
{
	Q_OBJECT
public:
	explicit SmallGrid(QWidget *parent = 0);
	void recreate(int width, int height);
	~SmallGrid();
	
signals:
	
public slots:
	
protected:
	
	virtual void paintEvent(QPaintEvent * evt);
	virtual void wheelEvent(QWheelEvent *evt);
	
private:

	
	QColor m_array [3][2];
	int m_scale;
	int m_width;
	int m_height;
};

#endif // SMALLGRID_H

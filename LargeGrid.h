#ifndef LARGEGRID_H
#define LARGEGRID_H

#include <QWidget>

class QColor;

class LargeGrid : public QWidget
{
	Q_OBJECT
public:
	explicit LargeGrid(QWidget *parent = 0);
	~LargeGrid();
	void recreate(int width, int height);
	
signals:
	
public slots:
	
protected:
	
	virtual void paintEvent(QPaintEvent *evt);
	virtual void wheelEvent(QWheelEvent *evt);
	virtual void mousePressEvent(QMouseEvent *evt);
	
private:
	int m_scale;
	int m_width;
	int m_height;
	int x_pos;
	int y_pos;

};

#endif // LARGEGRID_H

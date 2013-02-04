#include "SmallGrid.h"

#include <QPainter>
#include <QColor>
#include <QWheelEvent>

SmallGrid::SmallGrid(QWidget *parent) :
	QWidget(parent)
{
	m_array[0][0] = QColor(Qt::yellow);
	m_array[0][1] = QColor(Qt::green);
	m_array[1][0] = QColor(Qt::black);
	m_array[1][1] = QColor(Qt::blue);
	m_array[2][0] = QColor(Qt::red);
	m_array[2][1] = QColor(Qt::darkBlue);
	
	m_scale = 10;
}

/*virtual*/ void SmallGrid::paintEvent(QPaintEvent *evt)
{
	QPainter painter;
	painter.begin(this);
	
	
	for(int i =0; i<3; ++i)
	{
		for(int j=0; j<2; ++j)
		{			
			painter.setBrush(QBrush(m_array[i][j]));
			painter.drawRect(QRect(i*m_scale, j*m_scale, m_scale, m_scale));
			
		}
	}
	painter.end();
}

/*virtual*/ void SmallGrid::wheelEvent(QWheelEvent *evt)
{
	m_scale += evt->delta()/100;
	if (m_scale<1) m_scale = 1;
	this->repaint();
}

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
	m_width = 3;
	m_height = 2;
	

	

}

SmallGrid::~SmallGrid()
{
}

/*virtual*/ void SmallGrid::paintEvent(QPaintEvent *evt)
{
	QPainter painter;
	painter.begin(this);
	
	
	for(int i =0; i<m_width; ++i)
	{
		for(int j=0; j<m_height; ++j)
		{			

			painter.setBrush(QBrush(m_array[0][0]));
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

void SmallGrid::recreate(int width, int height)
{
	m_width = width;
	m_height = height;
	

	
	this->repaint();
}

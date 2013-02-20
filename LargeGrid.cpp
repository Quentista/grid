#include "LargeGrid.h"

#include <QPainter>
#include <QWheelEvent>
#include <QColor>

LargeGrid::LargeGrid(QWidget *parent) :
	QWidget(parent)
{
	m_scale = 10;
	m_width = 3;
	m_height = 2;
	m_array = new int [6];

	
}
LargeGrid::~LargeGrid()
{
	delete [] m_array;
}

/*virtual*/ void LargeGrid::paintEvent(QPaintEvent *evt)
{
	QPainter painter;
	painter.begin(this);

	for(int i =0; i<m_width; ++i)
	{
		for(int j=0; j<m_height; ++j)
		{			
			//if(i==x_pos && j==y_pos)
			if (m_array[i*m_width +j]==1)
			{
				painter.setBrush(QBrush(Qt::red));
				painter.drawRect(QRect(i*m_scale, j*m_scale, m_scale, m_scale));
			}
			else
			{
			painter.setBrush(QBrush(Qt::NoBrush));
			painter.drawRect(QRect(i*m_scale, j*m_scale, m_scale, m_scale));
			}
		}
	}
	painter.end();
}

/*virtual*/ void LargeGrid::wheelEvent(QWheelEvent *evt)
{
	m_scale += evt->delta()/100;
	if (m_scale<1) m_scale = 1;
	this->repaint();
}

/*virtual*/ void LargeGrid::mousePressEvent(QMouseEvent *evt)
{
	x_pos = evt->x()/m_scale;
	y_pos = evt->y()/m_scale;
	
	m_array[x_pos*m_width +y_pos] = 1;
	
	this->update();
}

void LargeGrid::recreate(int width, int height)
{
	m_width = width;
	m_height = height;
	
	m_array = new int[m_width*m_height];

	this->repaint();
}

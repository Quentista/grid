#include "LargeGrid.h"

#include <QPainter>
#include <QWheelEvent>
#include <QColor>
#include <QPixmap>

LargeGrid::LargeGrid(QWidget *parent) :
	QWidget(parent)
{
	m_scale = 10;
	m_width = 3;
	m_height = 2;
	m_array = new int [6];
	
	pix = new QPixmap("./1.jpg");

}
LargeGrid::~LargeGrid()
{
	delete [] m_array;
}

/*virtual*/ void LargeGrid::paintEvent(QPaintEvent *evt)
{
	QPainter painter;
	painter.begin(this);

	for(int i =0; i<m_height; ++i)
	{
		for(int j=0; j<m_width; ++j)
		{			
			if (m_array[i*m_width +j]==1)
			{
				painter.drawPixmap(i*m_scale,j*m_scale,m_scale,m_scale, *pix);
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
	for (int w=0; w<(m_width*m_height); ++w)
	{
		m_array[w] =0;
	}

	this->repaint();
}

#include "SmallGrid.h"

#include <QPainter>
#include <QColor>

SmallGrid::SmallGrid(QWidget *parent) :
	QWidget(parent)
{
	m_array[0] = QColor(Qt::yellow);
	m_array[1] = QColor(Qt::green);
	m_array[2] = QColor(Qt::black);
	
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
			painter.setBrush(QBrush(m_array[i]));
			painter.drawRect(QRect(i*m_scale, j*m_scale, m_scale, m_scale));
		}
	}
	painter.end();
}

void SmallGrid::setScale(int s)
{
	if (m_scale != s)
	{
		m_scale = s;
		SmallGrid::repaint();
	}
}

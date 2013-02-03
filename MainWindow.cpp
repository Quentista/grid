#include "MainWindow.h"

#include "SmallGrid.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
	, m_SGrid(new SmallGrid)
	, m_createButton(new QPushButton("create"))
	, m_mapper(new QSignalMapper(this))
{
	m_newScale = 50;
	this->connect(m_mapper, SIGNAL(mapped(int)), m_SGrid, SLOT(setScale(int)));
	m_mapper->setMapping(m_createButton, m_newScale);
	this->connect(m_createButton, SIGNAL(clicked()), m_mapper, SLOT(map()));
	//Layout setup
	
	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->setMargin(0);
	mainLayout->addWidget(m_SGrid);
	mainLayout->addWidget(m_createButton);
	this->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
	
}

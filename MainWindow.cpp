#include "MainWindow.h"

#include "SmallGrid.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
	, m_SGrid(new SmallGrid)
	, m_createButton(new QPushButton("create"))
{
	m_newScale = 50;

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

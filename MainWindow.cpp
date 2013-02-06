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
	, m_newWidth(new QLineEdit)
	, m_newHeight(new QLineEdit)
{
	m_newScale = 50;
	
	this->connect(m_createButton, SIGNAL(clicked()), this, SLOT(createNew()));

	//Layout setup
	
	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->setMargin(0);
	mainLayout->addWidget(m_SGrid);
	mainLayout->addWidget(m_newWidth);
	mainLayout->addWidget(m_newHeight);
	mainLayout->addWidget(m_createButton);
	this->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::createNew()
{
	bool ok = false;
	int width = m_newWidth->text().toInt(& ok);
	if (!ok) return;
	
	int height = m_newHeight->text().toInt(& ok);
	if (!ok) return;
	
	m_SGrid->recreate(width, height);
}

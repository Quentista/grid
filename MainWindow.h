#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class SmallGrid;
class QPushButton;
class QLineEdit;
class QSignalMapper;

class MainWindow : public QWidget
{
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	
	int m_newScale;
	
public slots:
	
private:
	
	SmallGrid* m_SGrid;
	
	QPushButton* m_createButton;
	QSignalMapper* m_mapper;
};

#endif // MAINWINDOW_H

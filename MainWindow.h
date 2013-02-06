#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class SmallGrid;
class QPushButton;
class QLineEdit;

class MainWindow : public QWidget
{
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	
	int m_newScale;
	
public slots:
	
	void createNew();
	
private:
	
	SmallGrid* m_SGrid;
	QPushButton* m_createButton;
	QLineEdit* m_newWidth;
	QLineEdit* m_newHeight;
};

#endif // MAINWINDOW_H

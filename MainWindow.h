#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class LargeGrid;
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
	
	LargeGrid* m_LGrid;
	QPushButton* m_createButton;
	QPushButton* m_colorButton;
	QLineEdit* m_newWidth;
	QLineEdit* m_newHeight;
};

#endif // MAINWINDOW_H

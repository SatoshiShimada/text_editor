
#include "editor.h"

#include <QtGui>

Editor::Editor(QWidget *parent)
	: QMainWindow(parent)
{

	createMenu();
	createStatusBar();
	createTextEdit();

	setWindowTitle("The Text Editor");
}

void Editor::createMenu()
{
	file = menuBar()->addMenu("File");
	edit = menuBar()->addMenu("Edit");
	help = menuBar()->addMenu("Help");

	newfile = new QAction("New", this);
	connect(newfile, SIGNAL(triggered()), this, SLOT(slotNewfile()));
	file->addAction(newfile);

	open = new QAction("Open", this);
	file->addAction(open);

	save = new QAction("Save", this);
	connect(save, SIGNAL(triggered()), this, SLOT(slotSave()));
	file->addAction(save);

	quit = new QAction("Quit", this);
	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
	file->addAction(quit);

}

void Editor::createStatusBar()
{
	statusBar()->showMessage("Ready");
}

void Editor::createTextEdit()
{
	textEdit = new QTextEdit(this);

	setCentralWidget(textEdit);
}


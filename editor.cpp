
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
	tool = menuBar()->addMenu("Tool");
	help = menuBar()->addMenu("Help");

	newfile = new QAction("New", this);
	connect(newfile, SIGNAL(triggered()), this, SLOT(slotNewfile()));
	file->addAction(newfile);

	open = new QAction("Open", this);
	connect(open, SIGNAL(triggered()), this, SLOT(slotOpen()));
	file->addAction(open);

	save = new QAction("Save", this);
	connect(save, SIGNAL(triggered()), this, SLOT(slotSave()));
	file->addAction(save);

	quit = new QAction("Quit", this);
	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
	file->addAction(quit);

	cut = new QAction("Cut", this);
	connect(cut, SIGNAL(triggered()), this, SLOT(slotCut()));
	edit->addAction(cut);

	copy = new QAction("Copy", this);
	connect(copy, SIGNAL(triggered()), this, SLOT(slotCopy()));
	edit->addAction(copy);

	paste = new QAction("Paste", this);
	connect(paste, SIGNAL(triggered()), this, SLOT(slotPaste()));
	edit->addAction(paste);

	expandtab = new QAction("Expand tab", this);
	tool->addAction(expandtab);
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


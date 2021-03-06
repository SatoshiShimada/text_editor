
#ifndef EDITOR_H
#define EIDTOR_H

#include <QtGui>
#include <QMainWindow>

#include <QMenu>
#include <QAction>
#include <QTextEdit>

class Editor : public QMainWindow
{
	Q_OBJECT

	public:
		Editor(QWidget *parent = 0);

	private slots:
		void slotNewfile();
		void slotOpen();
		void slotSave();
		void slotCut();
		void slotCopy();
		void slotPaste();

	private:
		void createMenu();
		void createStatusBar();
		void createTextEdit();

		QMenu *file;
		QMenu *edit;
		QMenu *tool;
		QMenu *help;

		QAction *newfile;
		QAction *open;
		QAction *save;
		QAction *quit;

		QAction *cut;
		QAction *copy;
		QAction *paste;

		QAction *expandtab;

		QTextEdit *textEdit;

		QString inFileName;
		QString outFileName;
};

#endif

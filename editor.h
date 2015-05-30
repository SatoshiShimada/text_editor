
#ifndef EDITOR_H
#define EIDTOR_H

#include <QtGui>

class Editor : public QMainWindow
{
	public:
		Editor(QWidget *parent = 0);

	private slots:
		void slotNewfile();
		void slotSave();

	private:
		void createMenu();
		void createStatusBar();
		void createTextEdit();

		QMenu *file;
		QMenu *edit;
		QMenu *help;

		QAction *newfile;
		QAction *open;
		QAction *save;
		QAction *quit;

		QTextEdit *textEdit;
};

#endif

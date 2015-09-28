
#include <QtGui>
#include <iostream>

#include "editor.h"

void Editor::slotNewfile()
{
	statusBar()->showMessage("new file");
	textEdit->setPlainText(QString(""));
}

void Editor::slotOpen()
{
	inFileName = QFileDialog::getOpenFileName(this, tr("Open File"));
	if(!inFileName.isEmpty()) {
		QFile file(inFileName);
		if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QMessageBox::information(this, tr("Unable to open file"),
			file.errorString());
		} else {
			textEdit->setPlainText(QString());
			QString text = QString();
			while(!file.atEnd()) {
				QByteArray line = file.readLine();
				text += QString(line);
			}
			textEdit->setPlainText(text);
		}
	}
}

void Editor::slotSave()
{
	outFileName = QFileDialog::getSaveFileName(this, tr("Save File"));
	if(!outFileName.isEmpty()) {
		QFile file(outFileName);
		if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QMessageBox::information(this, tr("Unable to open file"),
			file.errorString());
		} else {
			QTextStream out(&file);
			out << textEdit->toPlainText();
		}
	}
}

void Editor::slotCut()
{
}

void Editor::slotCopy()
{
}

void Editor::slotPaste()
{
}


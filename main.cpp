
#include <QApplication>
#include "editor.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	Editor window;

	window.resize(700, 500);
	window.show();

	return app.exec();
}

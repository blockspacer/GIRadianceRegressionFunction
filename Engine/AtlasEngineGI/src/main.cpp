#include "include/mainwindow.h"
#include <QApplication>
#include <QtGlobal>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOverrideCursor(QCursor(Qt::BlankCursor));

#if QT_VERSION >= 0x050000
    QSurfaceFormat fmt;
    fmt.setVersion(3, 3);
    fmt.setProfile(QSurfaceFormat::CoreProfile);

    QSurfaceFormat::setDefaultFormat(fmt);
#else
    QGLFormat glFormat;
    glFormat.setVersion(3, 3);
    glFormat.setProfile(QGLFormat::CoreProfile);

    QGLFormat::setDefaultFormat(glFormat);
#endif

    MainWindow w;
    w.show();

    return a.exec();
}
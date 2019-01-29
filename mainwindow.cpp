#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include "mainwindow.hh"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QMenu *fileMenu = new QMenu("File");
    menuBar()->addMenu(fileMenu);

    QAction *openMapAction = new QAction("Open map...");
    fileMenu->addAction(openMapAction);
}

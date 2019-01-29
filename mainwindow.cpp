#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QTextStream>

#include "mainwindow.hh"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QMenu *fileMenu = new QMenu("File");
    menuBar()->addMenu(fileMenu);

    QAction *openMapAction = new QAction("Open map...");
    fileMenu->addAction(openMapAction);
    connect(openMapAction, &QAction::triggered,
            this, &MainWindow::openMapDialog);
}

void MainWindow::openMapDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    QVector<QVector<bool>> map;
    while (!stream.atEnd()) {
        QVector<bool> row;
        for (const QChar &ch : stream.readLine()) {
            if (ch == "0")
                row.push_back(false);
            else if (ch == "1")
                row.push_back(true);
            else if (ch == "\n")
                break;
            else {
                QMessageBox::warning(this, "Error", QString("Invalid character: ") + ch);
                return;
            }
        }
        map.append(row);
    }
}

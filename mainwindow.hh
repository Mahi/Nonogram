#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void openMapDialog();
};

#endif // MAINWINDOW_HH

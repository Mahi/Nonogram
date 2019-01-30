#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

#include "game.hh"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void openMapDialog();

private:
    Game *m_game;
};

#endif // MAINWINDOW_HH

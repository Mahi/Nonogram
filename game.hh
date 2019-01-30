#ifndef GAME_HH
#define GAME_HH

#include <QGridLayout>
#include <QWidget>

#include "square.hh"

template<class T>
using Grid = QVector<QVector<T>>;

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    explicit Game(Grid<bool> grid, QWidget *parent = nullptr);

private:
    QGridLayout *m_layout;
    Grid<Square*> m_grid;
};

#endif // GAME_HH

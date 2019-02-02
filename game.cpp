#include <QMessageBox>

#include "game.hh"

Game::Game(QWidget *parent) :
    Game(Grid<bool>(), parent)
{
}

Game::Game(Grid<bool> grid, QWidget *parent) :
    QWidget(parent)
{
    m_layout = new QGridLayout;

    for (int y = 0; y < grid.size(); ++y) {
        QVector<Square*> row;
        for (int x = 0; x < grid[y].size(); ++x) {
            SquareState correctState = grid[y][x] ? SquareState::FILLED : SquareState::EMPTY;
            Square *square = new Square(correctState, this);
            connect(square, &Square::stateChanged,
                    this, &Game::checkWinCondition);
            row.push_back(square);
            m_layout->addWidget(square, y, x);
        }
        m_grid.push_back(row);
    }

    setLayout(m_layout);
}

void Game::checkWinCondition()
{
    for (const QVector<Square*> &row : m_grid) {
        for (Square *square : row) {
            if (!square->isCorrectState()) {
                return;
            }
        }
    }
    QMessageBox::information(this, "Victory", "You won!");
}

#include "square.hh"

Square::Square(QWidget *parent) :
    Square(SquareState::EMPTY, parent)
{
}

Square::Square(SquareState correctState, QWidget *parent) :
    QWidget(parent),
    m_state(SquareState::EMPTY),
    m_correctState(correctState)
{
}

SquareState Square::getState() const
{
    return m_state;
}

void Square::setState(SquareState state)
{
    m_state = state;
}

SquareState Square::getCorrectState() const
{
    return m_correctState;
}

void Square::setCorrectState(SquareState correctState)
{
    m_correctState = correctState;
}

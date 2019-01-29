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

void Square::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (getState() == SquareState::FILLED)
            setState(SquareState::EMPTY);
        else if (getState() == SquareState::EMPTY)
            setState(SquareState::FILLED);
        event->accept();
    }
    else if (event->button() == Qt::RightButton) {
        if (getState() == SquareState::FLAGGED)
            setState(SquareState::EMPTY);
        else if (getState() == SquareState::EMPTY)
            setState(SquareState::FLAGGED);
        event->accept();
    }
}

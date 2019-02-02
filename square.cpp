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
    setAutoFillBackground(true);
    updateColor();
}

SquareState Square::getState() const
{
    return m_state;
}

void Square::setState(SquareState state)
{
    if (state != m_state) {
        m_state = state;
        updateColor();
        emit stateChanged();
    }
}

SquareState Square::getCorrectState() const
{
    return m_correctState;
}

void Square::setCorrectState(SquareState correctState)
{
    m_correctState = correctState;
}

bool Square::isCorrectState() const
{
    if (getCorrectState() == SquareState::FILLED) {
        return getState() == SquareState::FILLED;
    }
    else {
        return getState() != SquareState::FILLED;
    }
}

void Square::updateColor()
{
    QPalette pal = palette();
    switch (getState()) {
    case SquareState::EMPTY:
        pal.setColor(QPalette::Background, Qt::white);
        break;
    case SquareState::FLAGGED:
        pal.setColor(QPalette::Background, Qt::yellow);
        break;
    case SquareState::FILLED:
        pal.setColor(QPalette::Background, Qt::black);
        break;
    }
    setPalette(pal);
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

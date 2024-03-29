#ifndef SQUARE_HH
#define SQUARE_HH

#include <QMouseEvent>
#include <QWidget>

enum SquareState {
    EMPTY,
    FLAGGED,
    FILLED
};

class Square : public QWidget
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent = nullptr);
    explicit Square(SquareState correctState, QWidget *parent = nullptr);

    SquareState getState() const;
    void setState(SquareState state);

    SquareState getCorrectState() const;
    void setCorrectState(SquareState state);

    bool isCorrectState() const;

protected:
    void updateColor();
    virtual void mousePressEvent(QMouseEvent *event);

signals:
    void stateChanged();

private:
    SquareState m_state;
    SquareState m_correctState;
};

#endif // SQUARE_HH

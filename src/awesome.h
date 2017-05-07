#ifndef AWESOME_H
#define AWESOME_H

#include <QWidget>
#include "QtAwesome.h"

class Awesome : public QWidget
{
    Q_OBJECT

private:
    static Awesome * singleton;

public:
    explicit Awesome(QWidget *parent = 0);

};

#endif // AWESOME_H

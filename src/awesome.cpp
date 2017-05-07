#include "awesome.h"

Awesome::Awesome(QWidget *parent) : QWidget(parent)
{
    QtAwesome* awesome = new QtAwesome(this);
    awesome->initFontAwesome();
    //return awesome;
}

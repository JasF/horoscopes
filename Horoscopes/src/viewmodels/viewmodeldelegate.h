//
// Created by Jasf on 28.01.2018.
//

#ifndef HORO_VIEWMODELDELEGATE_H
#define HORO_VIEWMODELDELEGATE_H

#include "base/horobase.h"

class ViewModelDelegate {
public:
    ViewModelDelegate() {}
    virtual ~ViewModelDelegate() {}
public:
    virtual void willAppear() = 0;
    virtual void didAppear() = 0;
    virtual void willDisappear() = 0;
    virtual void didDisappear() = 0;
};

#endif //HORO_VIEWMODELDELEGATE_H

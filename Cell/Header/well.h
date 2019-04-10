//File : well.h
#ifndef well_H
#define well_H

#include "facility.h"

//Well merupakan turunan dari Facility
class Well : public Facility{
public:
    Well();
    int render(); //mengembalikan char yang akan diprint
    // void fillWater(); //mengisi air pada ember
    void updateCell(UpdateType);
    void interactCell();
};

#endif

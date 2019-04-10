//File : cowmeat.h
#ifndef cowmeat_H
#define cowmeat_H

#include "farmproduct.h"

//cowmeat merupakan turunan dari farm product
class CowMeat : public FarmProduct{
public:
    CowMeat(); //ctor cow meat : untuk menambah jumlah cow meat, menetapkan harga chicken meat
};

#endif

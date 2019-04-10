//File : cowmilk.h
#ifndef cowmilk_H
#define cowmilk_H

#include "farmproduct.h"

//cowmilk merupakan turunan dari farm product
class CowMilk : public FarmProduct{
public:
    CowMilk(); //ctor cow milk : untuk menambah jumlah cow milk, menetapkan harga cow milk
};

#endif

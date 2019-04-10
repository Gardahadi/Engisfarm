//File : mixer.h
#ifndef mixer_H
#define mixer_H

#include "facility.h"
#include "../../Product/Header/beefomellete.h"
#include "../../Product/Header/chickenegg.h"
#include "../../Product/Header/platypusegg.h"
#include "../../Product/Header/chickenmeat.h"
#include "../../Product/Header/cowmeat.h"
#include "../../Product/Header/cowmilk.h"
#include "../../Product/Header/platypusmilk.h"

//mixer merupakan turunan dari facility
class Mixer : public Facility{
public:
    Mixer();
    int render(); //mengembalikan int yang akan menjadi id 
    void updateCell(UpdateType);
    void interactCell();
};

#endif

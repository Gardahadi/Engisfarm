//File : land.h
#ifndef land_H
#define land_H

#include "cell.h"
#include "../../FarmAnimal/Header/farmanimal.h"

enum LandType {barn, coop, grassLand};

class Land : public Cell {
    private:
        //true jika ada rumput
        bool rumput; 
        FarmAnimal* animal;
        LandType type;
    public:
        Land ();
        Land (bool rumput, FarmAnimal* animal, LandType type);
        //mengembalikan char yang akan diprint
        int render();  
        bool isRumput(); 
        //set isRumput menjadi true jika merupakan grassland, false ketika dimakan animal
        void setRumput(bool); 
        LandType getType();
        void setType(LandType);
        FarmAnimal* getAnimal();
        void setAnimal(FarmAnimal*);
        //menerima update untuk grow
        //menerima update untuk makan
        void updateCell(UpdateType);
        void interactCell();
};

#endif

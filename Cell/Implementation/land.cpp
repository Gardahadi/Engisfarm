#include "../Header/land.h"
Land::Land(){}
Land::Land(bool rumput, FarmAnimal* animal, LandType type){
    this->rumput = rumput;
    this->animal = animal;
    this->type = type;
}

int Land::render(){
    if(getPlayer() == NULL){
        if(getAnimal() == NULL){
            if(type == barn){
                if(isRumput()){
                    return 14;
                }else{
                    return 13;
                }
            }

            if(type == coop){
                if(isRumput()){
                    return 16;
                }else{
                    return 15;
                }
            }
            if(type == grassLand){
                if(isRumput()){
                    return 18;
                }else{
                    return 17;
                }
            }
        }else{
            return getAnimal()->getId();
        }
    }
    else{
        return 22;
    }
    return -2;
}

bool Land::isRumput(){
    return rumput;
}

void Land::setRumput(bool b){
    rumput = b;
}

LandType Land::getType(){
    return type;
}

void Land::setType(LandType type){
    this->type = type;
}

FarmAnimal* Land::getAnimal(){
    return animal;
}

void Land::setAnimal(FarmAnimal* animal){
    this->animal = animal;
}

void Land::updateCell(UpdateType type){
    if(type == grow){
        setRumput(true);
        Player* P = getPlayer();
        P -> grow();
        return;
    }
    
    if(type == makan){
        // cout << "makanpass1\n";
        FarmAnimal* F = getAnimal();
        // cout << "makanpass2\n";
        if(F != NULL){
            if(isRumput()){
                if (F->isHungry()){
                    F->makan();
                    setRumput(false);
                }
            }
            // cout << "makanpass4\n";
        }
        return;
    }

    if (type == removeAnimal){
        FarmAnimal* F = getAnimal();
        delete F;
        setAnimal(NULL);
        return;
    }
    
    if (type == checkAnimal){
        FarmAnimal* F = getAnimal();
        if(F != NULL){
            F->updateLivingTime();
            F->updateHungryTime();
            if(F->getLivingTime() <= 0){
                updateCell(removeAnimal);
            }
        }
        return;
    }

    if (type == canMove){
        FarmAnimal* F = getAnimal();
        if(F != NULL){
            F->setMoved(false);
        }
        return;
    }
    
}

void Land::interactCell(){
    FarmAnimal* F = getAnimal();
    Player* P = getPlayer();
    if(F != NULL){
        P->interact(F);
    }
}
#include "../Header/cell.h"

CellType Cell::getType(){
    return type;
}

void Cell::setType(CellType type){
    this->type = type;
}

Player* Cell::getPlayer(){
    return engi;
}

void Cell::setPlayer(Player* P){
    engi = P;
}
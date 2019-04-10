//File: player.cpp
#include "../Header/player.h"
#include "../../Product/Header/cowmeat.h"
#include "../../Product/Header/chickenegg.h"
#include <string>
#include <sstream>
Player::Player() : water(DEFWATER), money(DEFMONEY){
}

string Player::talk(FarmAnimal *F){
     return F->bersuara();
}

void Player::interactWell(){
    if(water < MAXWATER){
        water++;
    }else{
        throw "Ember penuh";
    }
}

void Player::interactMixer(){
    cout << "mix1\n";
    bool hasMix = false;

    //mixer jenis 1 (chcken egg, cow meat) = beef omellete
    bool found1 = false;
    bool found2 = false;
    int idx1 = 0;
    int idx2 = 0;
    //cari chicken egg = 1
    while (idx1<=inventory.getLastIdx() && !found1){
        Product temp = inventory.getElmt(idx1);
        if (temp.getID()==1){
            found1 = true;
        }else{
            idx1++;
        }
    }
    //cari cowmeat = 3
    while (idx2<=inventory.getLastIdx() && !found2){
        Product temp = inventory.getElmt(idx2);
        if (temp.getID()==1){
            found2 = true;
        }else{
            idx2++;
        }
    }

    if(found1 && found2){
        hasMix = true;
        inventory.removeAt(idx1);
        inventory.removeAt(idx2);
        SideProduct beefomellete = BeefOmellete();
        inventory.add(beefomellete);
    }

    //jika belom mix
    if(!hasMix){
        //mixer jenis 2 (platypus] egg, cow milk) = platypus pancake
        bool found1 = false;
        bool found2 = false;
        int idx1 = 0;
        int idx2 = 0;
        //cari platypus egg = 5
        while (idx1<=inventory.getLastIdx() && !found1){
            Product temp = inventory.getElmt(idx1);
            if (temp.getID()==5){
                found1 = true;
            }else{
                idx1++;
            }
        }
        //cari cowmilk = 4
        while (idx2<=inventory.getLastIdx() && !found2){
            Product temp = inventory.getElmt(idx2);
            if (temp.getID()==4){
                found2 = true;
            }else{
                idx2++;
            }
        }

        if(found1 && found2){
            hasMix = true;
            inventory.removeAt(idx1);
            inventory.removeAt(idx2);
            SideProduct platycowpancake = PlatycowPancake();
            inventory.add(platycowpancake);
        }
    }

    //jika belom mix
    if(!hasMix){
        //mixer jenis 3 (platypus milk, chicken meat) = plachick soup
        bool found1 = false;
        bool found2 = false;
        int idx1 = 0;
        int idx2 = 0;
        //cari platypus milk = 6
        while (idx1<=inventory.getLastIdx() && !found1){
            Product temp = inventory.getElmt(idx1);
            if (temp.getID()==6){
                found1 = true;
            }else{
                idx1++;
            }
        }
        //cari chickenmeat = 2
        while (idx2<=inventory.getLastIdx() && !found2){
            Product temp = inventory.getElmt(idx2);
            if (temp.getID()==2){
                found2 = true;
            }else{
                idx2++;
            }
        }

        if(found1 && found2){
            hasMix = true;
            inventory.removeAt(idx1);
            inventory.removeAt(idx2);
            SideProduct plachicksoup = PlachickSoup();
            inventory.add(plachicksoup);
        }
    }
}

void Player::interactTruck(){
    while(!inventory.isEmpty()){

             
        if(inventory.getElmt(inventory.getLastIdx()).getHarga() + money > MAXMONEY){
            money = MAXMONEY;
        }else{
            money +=inventory.getElmt(inventory.getLastIdx()).getHarga();
        }
        inventory.removeAt(inventory.getLastIdx());   
    }
}


void Player::interact(FarmAnimal* F){
    cout << F->getId() <<endl;
    if(F->isMeat() && !F->isEgg() &&  !F->isMilk()){
        throw "Tidak bisa berinteraksi dengan animal yang meat producing only";
    }else{
        if(inventory.getNeff() < MAXBAG){
            try{
                inventory.add(F->getProduct(false));
            }catch (string s){
                throw s;
            }
        }else{
            throw "Inventory penuh";
        }
    }
}

void Player::kill(FarmAnimal *F){
    if(inventory.getNeff() < MAXBAG){
        inventory.add(F->getProduct(true));
    }else{
        throw "Inventory penuh";
    }
}

void Player::grow(){
    if(water > 0){
        water--;    
    }else{
        throw "Air tidak cukup";
    }
}

int Player::render(){
    return 22;
}

int Player::getWater(){
    return water;
}

long Player::getMoney(){
    return money;
}

List <Product>  Player::getInventory(){
    return inventory;
}

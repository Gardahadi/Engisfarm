//File: player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "../../Product/Header/product.h"
#include "../../Product/Header/beefomellete.h"
#include "../../Product/Header/platycowpancake.h"
#include "../../Product/Header/plachicksoup.h"
#include "../../FarmAnimal/Header/farmanimal.h"
#include "../../List/list.h"
#define DEFWATER 10
#define MAXWATER 20
#define DEFMONEY 0
#define MAXMONEY 2000000
#define MAXBAG 10

class Player{
    private:
        int water; //menyimpan jumlah air yg dimiliki player
        List <Product> inventory; //tas
        long money; //menyimpang uang dari player
    public:
        //ctor
        Player();  
        
        //menerima input Farm Animal
        //mencetak di layar suara animal tersebut
        string talk(FarmAnimal* F); 
        
        
        //hasil penjualan akan ditambahkan ke money
        //jika kapasitas money sudah penuh, maka akan ditambahkan hingga MAXMONEY
        void interactTruck(); 
        void interactWell();
        void interactMixer();
        //menerima input Farm Animal
        //berinteraksi dengan milk dan egg producing animal
        //throw "Tidak bisa berinteraksi dengan meat producing animal" jika berinteraksi dengan meat producing animal
        //jika animal tidak lapar, akan mendapatkan prodcut
        //throw exception jika animal lapar
        //mendapatkan product jika inventory masih cukup
        //throw "Inventory penuh" jika inventory penuh
        void interact(FarmAnimal* F); 
        
        //menerima input Farm Animal
        //jika animal tidak lapar, akan mendapatkan prodcut
        //throw exception jika animal lapar
        //throw "Bukan meat producing animal" jika input bukan meat producing animal
        //throw "Inventory penuh" jika inventory penuh
        void kill(FarmAnimal *F); 

        //mengurangi jumlah water jika water > 0
        //throw "Air tidak cukup" jika water 
        void grow();

        //mengembalikan 22
        int render();
        // void cekPosisi(int, int&, int&); //buat cek sekitar look around, mungkin bs ditaruh di kelas lbh atas kalo dibutuhkan

        int getWater();

        long getMoney();
        List <Product> getInventory();
};

#endif

#include "Cell/Header/cell.h"
#include "Cell/Header/land.h"
#include "Cell/Header/facility.h"
#include "Cell/Header/mixer.h"
#include "Cell/Header/truck.h"
#include "Cell/Header/well.h"
#include "Player/Header/player.h"
#include "List/list.h"
#include "Cell/Header/facility.h"
#include "FarmAnimal/Header/bull.h"
#include "FarmAnimal/Header/chickenjago.h"
#include "FarmAnimal/Header/chickenkampung.h"
#include "FarmAnimal/Header/cow.h"
#include "FarmAnimal/Header/goldenplatypus.h"
#include "FarmAnimal/Header/platypus.h"
#include "Product/Header/platypusmilk.h"


#include <string>
#define WORLDSIZE 13

class GameEngine{
    private:
        Cell*** world;
        int tick;
        int XPlayer;
        int YPlayer;
        int Animals;
    public:
        GameEngine();
        List<int> lookAround(int,int); //utara , timur, selatan, barat
        int look(int,int);

        //Handler Functions
        void handleMove(int); //1 = atas, 2 = kanan, 3 = bawah, 4 = kiri
        void handleMoveAnimal(int,int);
        string handleTalk();
        void handleInteract();
        void handleKill();
        void handleGrow();
        void updateGame(); //nambahTick, ngubah posisi animal, ngubah avaibality truck
        void printWorld();

        //Method Menampilkan Ke Layar
        void renderer(int);
        void printMap();
        void printMessage(string);
        void printKeterangan(int);
        void printKeadaan(string);
        
        //Getter 
        int getXPlayer();
        int getYPlayer();
        int getAnimals();
        int getID(int,int);
        Player* getEngi();
        FarmAnimal* getAnimalAt(int x, int y);
        Cell*** getWorld();
        //Setter
        void setXPlayer();
        void setYPlayer();
};

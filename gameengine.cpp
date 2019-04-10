#include<iostream>
#include "gameengine.h"
#include <ostream>
#include <cstdlib>
using namespace std;

Cell*** GameEngine::getWorld() {
    return world;
}

int GameEngine::getXPlayer(){
    return XPlayer;
}

int GameEngine::getYPlayer() {
    return YPlayer;
}

Player* GameEngine::getEngi(){
    return world[XPlayer][YPlayer]->getPlayer();
}

GameEngine::GameEngine(){
    tick = 0;
    XPlayer = 6;
    YPlayer = 6;
    Animals = 12;
    world = new Cell**[WORLDSIZE];

    //Inisialisasi dunia dan set semua petak menjadi graassland berumput
    for(int i=0;i<WORLDSIZE;i++){
        world[i]=new Cell*[WORLDSIZE];
    }
    for(int i=0;i<WORLDSIZE;i++){
        for(int j=0; j<WORLDSIZE; j++){ 
            {
                world[i][j] = new Land(true,NULL,grassLand);
            } 
        }
    }

    //Menetapkan Player
    world[XPlayer][YPlayer]->setPlayer(new Player());
    
    //Menetapkan Coop
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            world[i][j]= new Land(true,NULL,coop);
        }
    }

    for(int i=0; i<6; i++){
        for(int j=6; j<13; j++){
            world[i][j] = new Land(true,NULL,barn);
        }
    }

    //Menetapkan Facility 
    world[8][12] = new Mixer();
    world[9][12] = new Well();
    world[10][12]=  new Truck();

    //Menetapkan Animal di coop
    world[0][0]->setAnimal(new ChickenKampung());
    world[1][1]->setAnimal(new ChickenKampung());
    world[2][2]->setAnimal(new Platypus());
    world[3][3]->setAnimal(new Platypus());

    //Menetapkan Animal di barn
    world[0][6]->setAnimal(new ChickenJago());
    world[0][7]->setAnimal(new ChickenJago());
    world[2][8]->setAnimal(new Bull());
    world[2][9]->setAnimal(new Bull());

    //Menetapkan ANimal di Grassland
    world[8][3]->setAnimal(new Cow());
    world[9][2]->setAnimal(new Cow());
    world[10][2] -> setAnimal(new GoldenPlatypus());
    world[11][1] -> setAnimal(new GoldenPlatypus());
}

int GameEngine::look(int i, int j){
    if(i>=0 && i<13 && j>=0 && j<13){
        return world[i][j]->render();    
    }
    else{
        return 0;
    }
}

List<int> GameEngine::lookAround(int x, int y){
    List<int> around;
    //lihat objek utara (x-1)(y)
    around.add(look(x-1,y));
    //lihat objek timur (x)(y+1)
    around.add(look(x,y+1));
    //lihat objek selatan (x+1)(y)
    around.add(look(x+1,y));
    //lihat objek barat (x)(y-1)
    around.add(look(x,y-1));
    return around;
}

void GameEngine::handleInteract(){
    //Mendapatkan list yang berisi objek disekitarnya
    // cout << "pass1\n";
    List<int> around = lookAround(XPlayer,YPlayer);
    bool foundAnimal= false;
    bool foundFacility = false;
    int i=0;
    // cout << "pass2\n";
    while (!foundAnimal && !foundFacility && (i<4)){
        //jika animal
        if(around.getElmt(i)>=1 && around.getElmt(i)<=10){
            foundAnimal = true;
        }else if (around.getElmt(i)>=19 && around.getElmt(i)<=21){ //facility
            foundFacility=true;
        }else{
            i++;
        }
    }

    if (foundAnimal){
        // cout << "Pass3" << endl;

        if (i==0){//interact animal utara    
            FarmAnimal* temp = world[XPlayer-1][YPlayer]->getAnimal();
            getEngi()->interact(temp);
            
        }else if (i==1){ //interact animal timur
            FarmAnimal *temp = world[XPlayer][YPlayer+1]->getAnimal();
            getEngi()->interact(temp);
        }else if (i==2){ //interact animal selatan
            FarmAnimal *temp = world[XPlayer+1][YPlayer]->getAnimal();
            getEngi()->interact(temp);

        }else if (i==3){ //interact animal barat
            FarmAnimal *temp = world[XPlayer][YPlayer-1]->getAnimal();
            getEngi()->interact(temp);
        }

        // FarmAnimal* temp = world[XPlayer-1][YPlayer]->getAnimal();
        // getEngi()->interact(temp);
        // cout << temp->getId() << endl;
        // cout << "Pass4" << endl;

    }

    if(foundFacility){
        // cout<< "pass 3" <<endl;
        int id = around.getElmt(i);
        if(around.getElmt(i)==19){//well
            getEngi()->interactWell();
        }else if (around.getElmt(i)==20){//mixer
            getEngi()->interactMixer();
        }else if (around.getElmt(i)==21){//truck
            // cout<< "pass 4" <<endl;
            getEngi()->interactTruck();
        }    
    }
}

bool moveAnimal(FarmAnimal* f, List<int> around, int i){
    bool found = false;
    //penghasil telur move bisa ke coop 15 16
    if(f->isEgg()){ 
        if(around.getElmt(i)==15 || around.getElmt(i)==16){
            found = true;
        }
    }
    //penghasil daging move bisa ke barn 13 14
    if(f->isMeat()){
        if(around.getElmt(i)==13 || around.getElmt(i)==14){
            found = true;
        }
    }
    //move bisa ke grassland 17 18
    if(f->isMilk()){
        if(around.getElmt(i)==17 || around.getElmt(i)==18){
            found = true;
        }
    }
    return found;
}

void GameEngine::handleMoveAnimal(int x, int y){
    List <int> around = lookAround(x,y);
    FarmAnimal* f = world[x][y]->getAnimal();
    if(f!=NULL){
        if(!f->getMoved()){
            bool found = false;
            int i = 0;
            while (!found && i<4){
                int n = rand()%4;
                if (n==0 && moveAnimal(f,around,0)){//utara (x-1)(y)
                    world[x][y]->setAnimal(NULL);
                    world[x-1][y]->setAnimal(f);
                    found = true;
                }else if (n==1 && moveAnimal(f,around,1)){ //timur (x)(y+1)
                    world[x][y]->setAnimal(NULL);
                    world[x][y+1]->setAnimal(f);
                    found = true;
                }else if (n==2 && moveAnimal(f,around,2)){//selatan (x+1)(y)
                    world[x][y]->setAnimal(NULL);
                    world[x+1][y]->setAnimal(f);
                    found = true;
                }else if (n==3 && moveAnimal(f,around,3)){//barat (x)(y-1)
                    world[x][y]->setAnimal(NULL);
                    world[x][y-1]->setAnimal(f);
                    found = true;
                }else{
                    i++;
                }
            }
            if (!found){
                throw "Ada animal yang stuck!";
            }else{
                f->setMoved(true);
            }
        }
    }
}

//BELOM IMPLEMENTASI
void GameEngine::handleMove(int n){
    List<int> around = lookAround(XPlayer, YPlayer);
    bool found = false;
    int i = 0;
    Player *P = getEngi();
    if (n==1){//atas
        if((around.getElmt(0))>=13 && (around.getElmt(0))<=18){
            world[XPlayer][YPlayer]->setPlayer(NULL);
            XPlayer--;
            world[XPlayer][YPlayer]->setPlayer(P);
        }
        else{
            throw "Tidak dapat melakukan move";
        }
    } else if (n==2){//kanan
        if((around.getElmt(1))>=13 && (around.getElmt(1))<=18){
            world[XPlayer][YPlayer]->setPlayer(NULL);
            YPlayer++;
            world[XPlayer][YPlayer]->setPlayer(P);
        }
        else{
            throw "Tidak dapat melakukan move";
        }
    } else if (n==3){//bawah
        if((around.getElmt(2))>=13 && (around.getElmt(2))<=18){
            world[XPlayer][YPlayer]->setPlayer(NULL);
            XPlayer++;
            world[XPlayer][YPlayer]->setPlayer(P);
        }
        else{
            throw "Tidak dapat melakukan move";
        }
    } else if (n==4){//kiri
        if((around.getElmt(3))>=13 && (around.getElmt(3))<=18){
            world[XPlayer][YPlayer]->setPlayer(NULL);
            YPlayer--;
            world[XPlayer][YPlayer]->setPlayer(P);
        }
        else{
            throw "Tidak dapat melakukan move";
        }
    }
}

void GameEngine::handleGrow(){
    try{
        world[getXPlayer()][getYPlayer()]->updateCell(grow);
    }catch(string s){
        throw "Air tidak cukup";
    }

}

string GameEngine::handleTalk(){
    List<int> around = lookAround(XPlayer, YPlayer);
    string s;
    if(around.getElmt(0)>=1 && around.getElmt(0)<=12){
        FarmAnimal* temp = world[XPlayer-1][YPlayer]->getAnimal();
        s= getEngi()->talk(temp);
        return s;
    }else if(around.getElmt(1)>=1 && around.getElmt(1)<=12){
        FarmAnimal* temp = world[XPlayer][YPlayer+1]->getAnimal();
        s=getEngi()->talk(temp);
        return s;
    }else if(around.getElmt(2)>=1 && around.getElmt(2)<=12){
        FarmAnimal* temp = world[XPlayer+1][YPlayer]->getAnimal();
        s=getEngi()->talk(temp);
        return s;
    }else if(around.getElmt(3)>=1 && around.getElmt(3)<=12){
        FarmAnimal* temp = world[XPlayer][YPlayer+1]->getAnimal();
        s=getEngi()->talk(temp);
        return s;
    }
    else{
        throw "sedang ngomong sendiri";
    }
}

void GameEngine::handleKill(){
    List<int> around = lookAround(XPlayer, YPlayer);
    bool hasKill = false;
    int i = 0;
    while (!hasKill && i<4){
        //penghasil daging id = 1 2 3 4 5 6 11 12
        if((around.getElmt(i)>=1 && around.getElmt(i)<=6) || around.getElmt(i)==11 || around.getElmt(i)==12){
            hasKill=true;
        }else{
            i++;
        }
    }
    if (i==0){//kill animal utara
        FarmAnimal *temp = world[XPlayer-1][YPlayer]->getAnimal();
        getEngi()->kill(temp);
        world[XPlayer-1][YPlayer]->updateCell(removeAnimal);
        
    }else if (i==1){ //kill animal timur
        FarmAnimal *temp = world[XPlayer][YPlayer+1]->getAnimal();
        getEngi()->kill(temp);
        world[XPlayer][YPlayer+1]->updateCell(removeAnimal);
    }else if (i==2){ //kill animal selatan
        FarmAnimal *temp = world[XPlayer+1][YPlayer]->getAnimal();
        getEngi()->kill(temp);
        world[XPlayer+1][YPlayer]->updateCell(removeAnimal);

    }else if (i==3){ //kill animal barat
        FarmAnimal *temp = world[XPlayer][YPlayer-1]->getAnimal();
        getEngi()->kill(temp);
        world[XPlayer][YPlayer-1]->updateCell(removeAnimal);
    }

}

int GameEngine::getID(int i,int j){
    return world[i][j]->render(); 
}

/* FUNGSI UPDATE */
void GameEngine::updateGame(){
    tick++;
    //Menggerakan animal
    for(int i = 0; i<WORLDSIZE; i++){
        for(int j =0 ; j<WORLDSIZE; j++){
            if(getID(i,j) < 13) { //Jika merupakan animal

                world[i][j]->updateCell(checkAnimal);
                //Bikin Animal tsb makan
                world[i][j]->updateCell(makan);
                //kurangin living time, sekaligus bunuh yang mati
                if(world[i][j]->getAnimal() != NULL){
                    //Gerakan Animal Tsb   
                    handleMoveAnimal(i,j);
                }
                Animals = world[i][j]->getAnimal()->getJumlah();
            }
            else if (getID(i,j) == 21 ){ //Jika merupakan truck
                //Ubah keadaan trucknya
                world[i][j]->updateCell(readyTruck);
            }
            //Kasus lain???
        }
    } 

    //mengeset hewan untuk bisa move
    for(int i = 0; i<WORLDSIZE; i++){
        for(int j =0 ; j<WORLDSIZE; j++){
            if(getID(i,j) < 13) { //Jika merupakan animal
                //Bikin Animal bisa move
                world[i][j]->updateCell(canMove);
            }
        }
    } 
}


void GameEngine::renderer(int n){
    switch (n)
    {   
        case 0 : //Out of Bounds

            break;
        case 1 : //Chicken Kampung
            cout << "\033[31;46m" << "CK" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 2 : 
            cout << "\033[30;46m" << "CK" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 3 : //Chicken Jago
            cout << "\033[31;46m" << "CJ" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 4 : 
            cout << "\033[30;46m" << "CJ" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 5 : //Cow
            cout << "\033[31;46m" << "CO" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 6 :
            cout << "\033[30;46m" << "CO" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 7 : // Golden Platypus
            cout << "\033[31;46m" << "GP" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 8 : 
            cout << "\033[30;46m" << "GP" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 9 : // Platypus
            cout << "\033[31;46m" << "PL" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 10 :
            cout << "\033[30;46m" << "PL" << "\033[0m"; //Print Kotak background Magenta
            break;
        case 11 : //Bull
            cout << "\033[31;46m" << "BL" << "\033[0m"; //Print Kotak background Magenta teks merah
            break;
        case 12 :
            cout << "\033[30;46m" << "BL" << "\033[0m"; //Print Kotak background Magenta teks item
            break;
        case 13 : //Barn
            cout << "\033[30;43;1m" << 'B' << " \033[0m"; //Print Kotak Background kuning
            break;
        case 14 :
            cout << "\033[30;42;1m" << 'B' << " \033[0m"; //Print Kotak background Hijau
            break;
        case 15 : //Coop
            cout << "\033[30;43;1m" << 'C' << " \033[0m"; //Print Kotak background Kuning
            break;
        case 16 :
            cout << "\033[30;42;1m" << 'C' << " \033[0m"; //Print Kotak background Hijau
            break;
        case 17: //GrassLand Ga Berumput
            cout << "\033[30;43;1m" << 'G' << " \033[0m"; //Print Kotak background Kuning
            break;
        case 18: //GrassLand Berumput
            cout << "\033[42;1m" << 'G' << " \033[0m"; //Print Kotak background Hijau
            break;
        case 19 : //Well
            cout << "\033[37;44m" << 'W' << " \033[0m"; //Print Kotak background Hijau
            break;
        case 20 : //Mixer
            cout << "\033[37;44m" << 'M' << " \033[0m"; //Print Kotak background Hijau
            break;
        case 21 : //Truck
            cout << "\033[37;44m" << 'T' << " \033[0m"; //Print Kotak background Hijau
            break;
        case 22 : //player
            cout << "\033[31;1;42m" << 'P' << " \033[0m"; //Print Kotak background Hijau
            break;
        default:
            break;
    }
}
//Fungsi untuk print Map
void GameEngine::printMap(){
    for (int i = 0; i<WORLDSIZE; i++){
        for(int j=0; j<WORLDSIZE; j++){
            renderer(getID(i,j));
        }
        cout << "  "; //Kasih Spasi
        printKeterangan(i);
        cout << endl;
    }
}
void GameEngine::printMessage(string msg) {
    cout<< msg << endl;
}

void GameEngine::printKeterangan(int n){
    switch (n)
    {
        case 0:
            cout << "Legend :";
            break;
        case 1:
            cout << "";
            break;
        case 2:
            cout << "Hewan Text Hitam: Kenyang | Hewan Text Merah: Lapar";
            break;
        case 3:
            cout << "Land Background Hijau: Ada Rumput | Land Background Kuning: Tidak ada rumput";
            break;
        case 4:
            cout << "P: Player";
            break;
        case 5:
            cout << "W: Well | M: Mixer | T: Truck";
            break;
        case 6:
            cout << "G: GrassLand | C: Coop | B: Barn";
            break;
        case 7:
            cout << "CK: Chicken Kampung";
            break;
        case 8:
            cout << "CJ: Chicken Jago";
            break;
        case 9:
            cout << "CO: Cow";
            break;
        case 10:
            cout << "GP: Golden Platypus";
            break;
        case 11:
            cout << "PL: Platypus";
            break;
        case 12:
            cout << "BL: Bull";
            break;
        default:
            break;
    }
}

void GameEngine::printKeadaan(string Name){
    cout << "Ticks : " << tick << endl;
    cout << "Nama Player :" << Name << endl;
    cout << "Water : " << getEngi()->getWater() << endl;
    cout << "Money : " << getEngi()->getMoney() << endl;
    cout << "Jumlah Animal : " << Animals << endl;
    cout << "Inventory : ";
    List <Product>  productList = getEngi()->getInventory();
    for(int i = 0; i< productList.getNeff(); i++){
        switch (productList.getElmt(i).getID())
        {
            case 1 : cout << "ChickenEgg"; break;
            case 2 : cout << "ChickenMeat"; break;
            case 3 : cout << "CowMeat"; break;
            case 4 : cout << "CowMilk"; break;
            case 5 : cout << "PlatypusEgg"; break;
            case 6 : cout << "PlatypusMilk"; break;
            case 7 : cout << "BeefOmellete"; break;
            case 8 : cout << "PlaChickSoup"; break;      
            default:
                break;
        }
        if (i != productList.getLastIdx()){
            cout << ", ";
        }
        else {
            cout << endl;
        }
    }
    cout << endl;

}

int GameEngine::getAnimals(){
    return Animals;
}
#include <iostream>
#include <string>
#include <stdlib.h>
#include "gameengine.h"
//Included Libraries
// #include "restoran.h"
// #include <ncurses.h>

using namespace std;

int main(){
    std::cout << "Rika's Farm" <<std::endl;
    std::cout << "A Game build with C++ using Object Oriented Paradigm" <<std::endl;
    std::cout << "========================================================" <<std::endl;
    std::cout << "Lukas Kurnia Jonathan / 13517006" <<std::endl;
    std::cout << "Eginata Kasan / 13517030" <<std::endl;
    std::cout << "Vivianni / 13517060" <<std::endl;
    std::cout << "Gardahadi / 13517144" <<std::endl;
    std::cout << "Rika Dewi / 13517147" <<std::endl;
    std::string command;
    cout << "Silahkan input Nama Player lalu tekan entar" << endl;
    cin >> command;
    
    /*****************************
    Inisialisasi Objek-objek Game
    *****************************/
    bool gameOver = false; 
    string Name = command;
    GameEngine G;
    string message = "Welcome To Engi's Farm!";

    /**************************
    Looping Utama Main Program
    ***************************/
    while(!gameOver){

        Clear Screen 
        system("clear");
        G.printKeadaan(Name);        
        G.printMap();
        std::cout<< "Message : ";
        G.printMessage(message);
        std::cout<< "Command : " ;
        std::cin >> command;
        
        try
        {
            /* Do Commands */
            if(command.compare("TALK")==0){
                message = G.handleTalk();
            }        
        
            else if(command.compare("GROW")==0){
                G.handleGrow();   
            }
             
            else if(command.compare("KILL")==0){
                G.handleKill();
            }
            
            else if(command.compare("INTERACT")==0){
                G.handleInteract();
            }
            
            else if(command.compare("GL")==0){
                G.handleMove(4);
                message = Name + " telah bergerak satu petak!";
            }
            
            else if(command.compare("GD")==0){
                G.handleMove(3);
                message = Name + " telah bergerak satu petak!";
            }
            else if(command.compare("GU")==0){
                    G.handleMove(1);
                    message = Name + " telah bergerak satu petak!";
            }
            
            else if(command.compare("GR")==0){
                    G.handleMove(2);
                    message = Name + " telah bergerak satu petak!";
            }
            else if (command.compare("EXIT") == 0) {
                gameOver = true;
            }
            else {
                message = "Salah command!";
            }

            G.updateGame();
            if(G.getAnimals()<=0){
                gameOver = true;
            }
        }
        
        catch(const char* errorMessage)
        {
            message = errorMessage;
        }
        
        
        
        
    }
    return 0;
}
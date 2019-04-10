//File: list.h
#ifndef __LIST_H__
#define __LIST_H__
#define MAXSIZE 256
#define IdxMin 0
#include <iostream>
using namespace std;

template <class Type>
class List {
    private:
        Type *data;
        int size;
        int Neff;
    public:
        //default Ctor
        List(){
            size = MAXSIZE;
            Neff = 0;
            data = new Type[size];
        } 

        // Ctor dengan parameter
        List(int _size){
            size = _size;
            Neff = 0;
            data = new Type[size];
        }
        // Cctor
        List(const List<Type>& L){
            size = L.size;
            Neff = L.Neff;
            data = new Type[size];
            for (int i=0; i<size; i++){
                data[i] = L.data[i];
            }
        }

        ~List(){
            delete[] data;
        }
        
        List& operator= (const List<Type>& L){
            delete[] data;
            size = L.size;
            Neff = L.Neff;
            data = new Type[size];
            for (int i=0; i<size; i++){
                data[i] = L.data[i];
            }
            return *this;
        }

        //Services

        bool isEmpty() const{
            return (Neff == 0);
        }
        bool isFull() const{
            return (Neff == size);
        }
        void add(Type X){
            try
            {    
                if(size > Neff){
                    data[Neff] = X;
                    Neff++;
                }
                else {
                    throw X;
                }
            }
            catch(Type e)
            {
                cout << "List penuh, tidak dapat menambahkan objek baru" << endl;
            }
        }

        void remove(Type elmt){
            removeAt(find(elmt));
        }        

        void removeAt(int idx){
            //MENGGESER SETIAP ELEMENT
            for(int i=idx; i<getLastIdx(); i++){
                data[i] = data[i+1];
            }
            Neff--;
        }


        //jika tidak ditermukan kembalikan -1
        int find(Type elmt){
            bool found = false;
            int i=0;
            while(!found && i<Neff){
                if(data[i] == elmt){
                    found = true;
                }
                else {
                    i++;
                }
            }
            if (found){
                return i;
            }
            else{
                return -1;
                cout << "Tidak Ditemukan Objek" << endl;
            }
        }
        
        Type getElmt(int i){
            return data[i];
        }
        int getSize(){
            return size;
        }
        int getNeff(){
            return Neff;
        }
        int getFirstIdx(){
            return IdxMin;
        }
        int getLastIdx() {
            if(Neff > 0)
                return Neff-1;
            else
                return 0;
        }
};

#endif
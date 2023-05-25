#include "include\shelf.hpp"
#include "include\pallet.hpp"

Shelf::Shelf(){
    
}

bool Shelf::isEmpty(){
    for(int i = 0; i < 4; i++){
        if(pallets[i].getItemCount() == 0){
            return false;
        }
    }
    return true;
}

bool Shelf::isFull(){
    for(int i = 0; i < 4; i++){
        if(pallets[i].getRemainingSpace() > 0){
            return false;
        }
    }
    return true;
}

bool Shelf::swapPallet(int slot, int slot2){
    pallets[slot], pallets[slot2] = pallets[slot2], pallets[slot];
}
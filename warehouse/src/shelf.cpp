#include "include\shelf.hpp"
#include "include\pallet.hpp"
#include <iostream>

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
    Pallet temporary_slot = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temporary_slot;
    return true;
}

std::ostream& operator<<(std::ostream& out, Shelf& s){
    out << "pallet 1:" << s.pallets[0] << "\n" << "pallet 2:" << s.pallets[1] << "\n" << "pallet 3:" << s.pallets[2] << "\n" <<  "pallet 4:" << s.pallets[3];
    return out;
}


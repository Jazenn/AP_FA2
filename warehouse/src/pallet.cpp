#include "include\pallet.hpp"
#include "include\IContainer.hpp"
#include <iostream>

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) : itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount){

}

Pallet::Pallet() : itemName("Unknown"), itemCapacity(1), itemCount(0){

}

std::string Pallet::getItemName() const{
    return itemName;
}

int Pallet::getItemCount() const{
    return itemCount;
}

int Pallet::getItemCapacity() const{
    return itemCapacity;
}

int Pallet::getRemainingSpace() const{
    return itemCapacity - itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    if(isEmpty() == true){
        this -> itemName = itemName;
        this -> itemCapacity = itemCapacity;
        return true;
    }
    return false;
}

bool Pallet::takeOne(){
    if(isEmpty() == true){
        return false;
    }
    itemCount -= 1;
    return true;
}

bool Pallet::putOne(){
    if(isFull() == true){
        return false;
    }
    itemCount += 1;
    return true;
}

bool Pallet::isEmpty(){
    return getItemCount() == 0;
}

bool Pallet::isFull(){
    return getRemainingSpace() == 0;
}

std::ostream& operator<<(std::ostream& out, Pallet& p){
    out << "Itemname: " << p.getItemName() << ", itemCount: " << p.getItemCount() << ", itemCapacity: " << p.getItemCapacity();
    return out;
}
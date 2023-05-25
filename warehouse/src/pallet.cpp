#include "include\pallet.hpp"
#include "include\IContainer.hpp"

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
    return true;
}

bool Pallet::putOne(){
    if(isFull() == true){
        return false;
    }
    return true;
}

bool Pallet::isEmpty(){
    if(getItemCount() == 0){
        return true;
    }
    return false;
}

bool Pallet::isFull(){
    if(getRemainingSpace() == 0){
        return true;
    }
    return false;
}
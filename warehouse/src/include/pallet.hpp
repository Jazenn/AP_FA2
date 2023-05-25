#pragma once
#include <string>
#include "IContainer.hpp"

class Pallet : public IContainer{
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;

    public:
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();

        std::string getItemName();
        int getItemCount();
        int getItemCapacity();
        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();
        bool isEmpty();
        bool isFull();
};
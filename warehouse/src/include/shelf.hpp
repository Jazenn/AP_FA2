#pragma once
#include <array>
#include "pallet.hpp"
#include "IContainer.hpp"

class Shelf : public IContainer{
    public:
        std::array<Pallet, 4> pallets;
        Shelf();
        bool swapPallet(int slot, int slot2);
        bool isEmpty();
        bool isFull();
};
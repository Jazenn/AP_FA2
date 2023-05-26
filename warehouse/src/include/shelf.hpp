#pragma once
#include <array>
#include "IContainer.hpp"
#include "pallet.hpp"

class Shelf : public IContainer{
    public:
        std::array<Pallet, 4> pallets;
        Shelf();
        bool swapPallet(int slot, int slot2);
        bool isEmpty() override;
        bool isFull() override;
        friend std::ostream& operator<<(std::ostream& out, Shelf& s);
};
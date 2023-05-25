#include "include\warehouse.hpp"

Warehouse::Warehouse(){

}

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    Shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf){
    for(const Employee& employee : Employees){
        if(employee.forkliftCertificate){
            for(int i = 0; i < 4; i ++){
                Pallet key = shelf.pallets[i];
                int j = i - 1;

                while(key.getItemCount() < shelf.pallets[j].getItemCount() and j >= 0){
                    shelf.swapPallet(j + 1, j);
                    --j;
                }
                shelf.pallets[j + 1] = key;
            }
        }
    }
}

bool Warehouse::pickItems(std::string itemName, int itemCount){
    for(Shelf& shelf : Shelves){
        for(int i = 0; i < 4; i++){
            Pallet& pallet = shelf.pallets[i];

            if(pallet.getItemName() == itemName){
                while(itemCount > 0 && pallet.takeOne()){
                    itemCount --;
                }

                if(itemCount == 0){
                    return true;
                }
            }
        }
    }
    return false;
}
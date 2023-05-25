#include "include\warehouse.hpp"
#include "include\employee.hpp"
#include "include\shelf.hpp"
#include "include\pallet.hpp"

Warehouse::Warehouse(){

}

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    Shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf){
    for(Employee& employee : Employees){
        if(employee.forkliftCertificate){
            employee.busy = true;
            for(int i = 0; i < 4; i ++){
                Pallet key = shelf.pallets[i];
                int j = i - 1;

                while(key.getItemCount() < shelf.pallets[j].getItemCount() and j >= 0){
                    shelf.swapPallet(j + 1, j);
                    --j;
                }
                shelf.pallets[j + 1] = key;
            }
            return true;
        }
    }
    return false;
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
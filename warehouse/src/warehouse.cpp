#include "include\warehouse.hpp"
#include "include\employee.hpp"
#include "include\shelf.hpp"
#include "include\pallet.hpp"
#include <iostream>

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
        if(employee.forkliftCertificate && !employee.busy){
            employee.busy = true;
            for(int i = 0; i < 4; i ++){
                Pallet key = shelf.pallets[i];
                int j = i - 1;

                while(j >= 0 && key.getItemCount() < shelf.pallets[j].getItemCount()){
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
    for(Employee& employee : Employees){
        if(!employee.busy){
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
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, Warehouse& w){
    out << "These are all the shelves and the pallets on them:\n";
    for(int i = 0; i < w.Shelves.size(); i++){
        out << w.Shelves[i] << "\n";
    }
    out << "These are all the employees:\n";
    for(int i = 0; i < w.Employees.size(); i++){
        out << w.Employees[i] << "\n";
    }
    return out;
}

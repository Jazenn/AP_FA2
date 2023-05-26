#include <iostream>
#include "src\include\warehouse.hpp"

int main(void){
    std::cout << "Welcome to the demo of this warehouse." << std::endl;

    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee("Bob", true));

    std::cout << "This is the current state of the warehouse:\n" << warehouse << "\n";
    warehouse.rearrangeShelf(warehouse.Shelves[0]);
    std::cout << "This is the warehouse after shelf 1 has been rearranged:\n" << warehouse << "\n";

    std::cout << "This is the current state of the warehouse:\n" << warehouse << "\n";
    warehouse.pickItems("Books", 20);
    std::cout << "This isthe warehouse after 20 books have been taken:\n" << warehouse << "\n";

}

#include "include/catch.hpp"

#include "../src/include/warehouse.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////
//                                                           //
//                    Warehouse unittests                    //
//                                                           //
///////////////////////////////////////////////////////////////
//                                                           //
// This file contains all testcases for the Warehouse class. //
// Currently it only contains tests for the rearranging of   //
// Shelves. All other Warehouse functions will also need to  //
// be tested. You will have to do this yourself.             //
//                                                           //
// For information on how to write testcases with catch2,    //
// see https://github.com/catchorg/Catch2.                   //
//                                                           //
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//                Functions used in testcases                //
///////////////////////////////////////////////////////////////

/// \brief 
/// Creates a mock Warehouse.
/// \return Warehouse with shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted Shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.
Warehouse createMockWarehouse(){
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

    return warehouse;
}


///////////////////////////////////////////////////////////////
//           Warehouse::rearrangeShelf test cases            //
///////////////////////////////////////////////////////////////

TEST_CASE("Rearrange empty shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = Warehouse();
    warehouse.addShelf(Shelf());
    warehouse.addEmployee(Employee("Bob", true));

    // Check if shelf is already arranged.
    // Empty shelf should already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Empty shelf should still be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 0);
}

TEST_CASE("Rearrange full shelf", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange half filled shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 20), 
        Pallet(), 
        Pallet()
    };
    
    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange shelf without qualified employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    warehouse.addEmployee(Employee("Bert", false));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Rearrange shelf with quallified, but busy, employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    Employee bert = Employee("Bert", true);
    bert.busy = true;

    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Create pallet", "Pallet::Pallet"){
    Pallet pallet1 = Pallet("Books", 100, 20);
    REQUIRE(pallet1.getItemName() == "Books");
    REQUIRE(pallet1.getItemCapacity() == 100);
    REQUIRE(pallet1.getItemCount() == 20);
}

TEST_CASE("Create pallet without passing parameters", "Pallet::Pallet"){
    Pallet pallet1 = Pallet();
    REQUIRE(pallet1.getItemName() == "Unknown");
    REQUIRE(pallet1.getItemCapacity() == 1);
    REQUIRE(pallet1.getItemCount() == 0);
}

TEST_CASE("Retrieve remaining space on pallet", "Pallet::getRemainingSpace"){
    Pallet pallet1 = Pallet("Books", 100, 20);
    REQUIRE(pallet1.getRemainingSpace() == 80);
}

TEST_CASE("Check if pallet is empty", "Pallet::isEmpty"){
    Pallet pallet1 = Pallet();
    REQUIRE(pallet1.getRemainingSpace() == pallet1.getItemCapacity());
}

TEST_CASE("Check if pallet is full", "Pallet::isFull"){
    Pallet pallet1 = Pallet("Books", 100, 100);
    REQUIRE(pallet1.getRemainingSpace() == 0);
}

TEST_CASE("Reallocate empty pallet with new items", "Pallet::reallocateEmptyPallet"){
    Pallet pallet1 = Pallet();
    REQUIRE(pallet1.reallocateEmptyPallet("Protein bars", 100) == true);
    REQUIRE(pallet1.getItemName() == "Protein bars");
    REQUIRE(pallet1.getItemCapacity() == 100);
}

TEST_CASE("Take 1 item from pallet", "Pallet::takeOne"){
    Pallet pallet1 = Pallet("Books", 100, 80);
    pallet1.takeOne();
    REQUIRE(pallet1.getItemCount() == 79);
}

TEST_CASE("Put 1 item on pallet", "Pallet::putOne"){
    Pallet pallet1 = Pallet("Books", 100, 80);
    pallet1.putOne();
    REQUIRE(pallet1.getItemCount() == 81);
}

TEST_CASE("Taking 1 item with itemName 'Books'. ", "Warehouse::pickItems"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Magazines", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Newspapers", 100, 10)
    };

    Employee employee = Employee("Elena", false);
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(employee);
    employee.busy = false;

    bool success = warehouse.pickItems("Books", 1);
    REQUIRE(success);

    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Taking 30 item with itemName 'Books'. ", "Warehouse::pickItems"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Magazines", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Newspapers", 100, 10)
    };

    Employee employee = Employee("Elena", false);
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(employee);
    employee.busy = false;

    bool success = warehouse.pickItems("Books", 30);
    REQUIRE(success);

    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Taking 1 item with itemName 'Magazines'. ", "Warehouse::pickItems"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Magazines", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Newspapers", 100, 10)
    };

    Employee employee = Employee("Elena", false);
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(employee);
    employee.busy = false;

    bool success = warehouse.pickItems("Books", 1);
    REQUIRE(success);

    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 39);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Taking 30 item with itemName 'Magazines'. ", "Warehouse::pickItems"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Magazines", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Newspapers", 100, 10)
    };

    Employee employee = Employee("Elena", false);
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(employee);
    employee.busy = false;

    bool success = warehouse.pickItems("Magazines", 1);
    REQUIRE(success);

    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 19);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Trying to take too many items from shelves", "Warehouse::pickItems"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Magazines", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Newspapers", 100, 10)
    };

    Employee employee = Employee("Elena", false);
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(employee);
    employee.busy = false;

    bool success = warehouse.pickItems("Books", 60);
    REQUIRE(!success);

    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Taking 1 item with itemName 'Protein bars', which is not present on the shelves. ", "Warehouse::pickItems"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Magazines", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Newspapers", 100, 10)
    };

    Employee employee = Employee("Elena", false);
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(employee);
    employee.busy = false;

    bool success = warehouse.pickItems("Protein bars", 1);
    REQUIRE(!success);

    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Attempting to take items when every employee is busy.", "Warehouse::pickItems"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Magazines", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Newspapers", 100, 10)
    };

    Employee employee = Employee("Elena", false);
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(employee);
    employee.busy = true;
    
    bool success = warehouse.pickItems("Books", 1);
    REQUIRE(!success);

    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}


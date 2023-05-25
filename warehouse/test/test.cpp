#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"

#include "D:\Hogeschool Utrecht\Jaar 1 - Blok 4\AP\Summatieve_Opdrachten\AP_FA2\warehouse\src\include\pallet.hpp"
#include "D:\Hogeschool Utrecht\Jaar 1 - Blok 4\AP\Summatieve_Opdrachten\AP_FA2\warehouse\src\include\shelf.hpp"
#include "D:\Hogeschool Utrecht\Jaar 1 - Blok 4\AP\Summatieve_Opdrachten\AP_FA2\warehouse\src\include\employee.hpp"
#include "D:\Hogeschool Utrecht\Jaar 1 - Blok 4\AP\Summatieve_Opdrachten\AP_FA2\warehouse\src\include\warehouse.hpp"

// Find all tests in test*.cpp in test/

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




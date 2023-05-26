#include <iostream>
#include "src\include\warehouse.hpp"

int main(void){
    std::cout << "Hello world" << std::endl;

    Pallet myPallet("Item 1", 10, 5);  // Create an instance of the Pallet class
    myPallet.takeOne();
    std::cout << myPallet.getItemCount() << '\n';                // Call the takeOne() function
    myPallet.putOne();    
    myPallet.putOne();             
    std::cout << myPallet.getItemCount() << '\n';
}

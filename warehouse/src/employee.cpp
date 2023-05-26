#include "include\employee.hpp"
#include <iostream>

Employee::Employee(std::string const name, bool forkliftCertificate) : name(name), forkliftCertificate(forkliftCertificate){

}

std::string Employee::getName(){
    return name;
}

std::ostream& operator<<(std::ostream& out, Employee& e){
    out << e.getName() << "(Forkliftcertified: " << e.forkliftCertificate << ", Working status:" << (e.busy) << ")";
    return out;
}
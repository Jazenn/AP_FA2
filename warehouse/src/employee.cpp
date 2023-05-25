#include "include\employee.hpp"

Employee::Employee(std::string const name, bool forkliftCertificate) : name(name), forkliftCertificate(forkliftCertificate){

}

std::string Employee::getName(){
    return name;
}
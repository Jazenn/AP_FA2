#pragma once
#include <string>

class Employee{
    private:
        std::string const name;
    
    public:
        bool busy;
        bool forkliftCertificate;

        Employee(std::string const name, bool forkliftCertificate);
        std::string getName();
};
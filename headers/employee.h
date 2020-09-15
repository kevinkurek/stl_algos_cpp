//
// Created by Kevin Kurek on 9/12/20.
//

#pragma once
#include <string>
#include <utility>

#ifndef STL_ALGOS_CPP_EMPLOYEE_H
#define STL_ALGOS_CPP_EMPLOYEE_H

class Employee{

private:
    std::string firstname;
    std::string lastname;
    int salary;

public:
//    Employee(){};
    Employee(std::string first="", std::string last="", int sal=0):
        firstname(std::move(first)), lastname(std::move(last)), salary(sal){};
    int getSalary(){return salary;}
    std::string getSortingName(){return lastname + " " + firstname;}
};

#endif //STL_ALGOS_CPP_EMPLOYEE_H

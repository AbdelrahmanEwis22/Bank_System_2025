#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>
#include<fstream>
#include <sstream>
#include"Employee.h"
#include"iterator"
using namespace std;
class Admin :public Employee
{
public:
    // cons
   /* Admin() : Employee() {} 
    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary)
    {
        setSalary(salary); 
    }*/
    // using Employee::Employee;
    
    // Methods
    void addEmployee(Employee& employee) {
        allEmployees.push_back(employee);
    }
    Employee* searchEmployee(int id) {
        for (auto& elIt : allEmployees) {
            if (elIt.getId() == id) {
                return &elIt; // Return a copy
            }
        }
        return nullptr;
    }
    void listEmployees() {
        for (elIt = allEmployees.begin(); elIt != allEmployees.end(); elIt++) {
            elIt->display();
            cout << "===== All Clients =====" << endl;
        }
    }
    void editClient(int id, string name, string password, double salary) {
        searchEmployee(id)->setId(id);
        searchEmployee(id)->setName(name); 
        searchEmployee(id)->setPassword(password);
        searchEmployee(id)->setSalary(salary);

    }
    void display()
    {
        cout << "ID: " << id
            << "\nName: " << name
            << "\npassword" << password
            << "\nSalary: " << salary << endl;
    }
};

static vector<Admin>allAdmins;
static vector<Admin>::iterator alIt; 




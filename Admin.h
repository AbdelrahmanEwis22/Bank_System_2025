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
using namespace std;
class Admin :public Employee
{
public:
    // cons
    Admin() {
        this->salary;
    }
    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary)
    {
        setSalary(salary);
    }
    // using Employee::Employee;
    // setter
    void setSalary(double salary)
    {
        if (!Validation::validateSalary(salary))
            throw invalid_argument("Minimum salary is 5000");
        this->salary = salary;
    }
    double getSalary()
    {
        return this->salary;
    }
    // Methods
    void addEmployee(Employee& employee) {
        allEmployees.push_back(employee);
    }
    Employee* searchEmployee(int id) {
        for (elIt = allEmployees.begin(); elIt != allEmployees.end(); elIt++) {
            if (elIt->getId() == id) {
                return elIt._Ptr; // Return a copy
            }
        }
        return NULL;
    }
    void listEmployees() {
        for (elIt = allEmployees.begin(); elIt != allEmployees.end(); elIt++) {
            elIt->display();
            cout << "===== All Clients =====" << endl;
        }
    }
    void editClient(int id, string name, string password, double salary) {
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
    

    /* void addEmployee(Employee& employee) {
         FileManager().addEmployee(employee);
     }

     Employee* searchEmployee(int targetId) {
         vector<Employee> employees = FileManager().getAllEmployees();
         for (auto& emp : employees) {
             if (emp.getId() == targetId) {
                 return new Employee(emp);
             }
         }
         return nullptr;
     }

     void editEmployee(int targetId, string newName, string newPassword, double newSalary) {
         vector<Employee> employees = FileManager().getAllEmployees();
         bool found = false;

         for (Employee& emp : employees) {
             if (emp.getId() == targetId) {
                 emp = Employee(targetId, newName, newPassword, newSalary);
                 found = true;
                 break;
             }
         }

         if (found) {
             FileManager().removeAllEmployees();
             for (Employee& emp : employees) {
                 FileManager().addEmployee(emp);
             }
         }
     }

     void listEmployees() {
         vector<Employee> employees = FileManager().getAllEmployees();
         cout << "===== All Employees =====" << endl;
         for ( Employee& e : employees) {
             cout << "ID: " << e.getId()
                 << " | Name: " << e.getName()
                 << " | Salary: " << e.getSalary() << endl;
         }
     }*/
};

static vector<Admin>allAdmins;
static vector<Admin>::iterator alIt;




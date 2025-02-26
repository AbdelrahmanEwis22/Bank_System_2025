#pragma once
#include <string>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>
#include<fstream>
#include"Client.h" 
#include"iterator"
using namespace std;
class Employee :public Person
{
protected:
    double salary;

public:
    // Constructor
    Employee() {
        this->id = 0;
        this->name = " ";
        this->password = " ";
        this->salary=0.0;
    }
    Employee(int id, string name, string password, double salary)
        : Person(id, name, password)
    {
        setSalary(salary);
    }

    // Setters
    void setSalary(double salary)
    {
        if (!Validation::validateSalary(salary))
            throw invalid_argument("Minimum salary is 5000");
        this->salary = salary;
    }

    // Getters
    double getSalary()
    {
        return this->salary;
    }

    // Methods
    void addClient(Client& client) {
        allClients.push_back(client);
    }

    Client* searchClient(int id) {
        for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
            if (clIt->getId() == id) {
                return clIt._Ptr; // Return a copy
            }
        }
        return NULL;
    }

    void listClients() {
        for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
            clIt->display();
            cout << "===== All Clients =====" << endl;
        }
    }

    void editClient(int id, string name, string password, double balanceEGP, double balanceUSD) {
        searchClient(id)->setName(name);
        searchClient(id)->setPassword(password);
        searchClient(id)->setBalanceEGP(balanceEGP);
        searchClient(id)->setBalanceUSD(balanceUSD);
    }
    void display()
    {
        cout << "ID: " << id << "\nName: " << name
            << "\nSalary: " << salary << endl;
    }
    
};
static vector<Employee>allEmployees;
static vector<Employee>::iterator elIt;


#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>
#include<fstream>
#include "Client.h"
#include"Parser.h"
#include "Admin.h"
#include "Employee.h"
#include"FileHelper.h"
#include"DataSourceInterface.h"
//#include"ClientManger.h"



using namespace std;
class FileManager :public DataSourceInterface
{
public:
    //AddFiles
    void addClient(Client client) {
        FileHelper::saveClient(client);
    }
    void addEmployee(Employee employee) {
        FileHelper::saveEmployee(employee);
    }
    void addAdmin(Admin admin) {
        FileHelper::saveAdmin(admin);
    }
    //RemoveAllFiles
    void removeAllClients() {
        FileHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }
    void removeAllEmployees() {
        FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
    }
    void removeAllAdmins() {
        FileHelper::clearFile("Admins.txt", "AdminLastId.txt");
    }
    //GetAllFiles
    vector<Client> getAllClients() { 
        FileHelper::getClients(); 
        return allClients; 
    }
    vector<Employee> getAllEmployees() {
        FileHelper::getEmployee();
        return allEmployees;
    }
    vector<Admin> getAllAdmins() {
        FileHelper::getAdmin();
        if (allAdmins.empty()) { 
            cout << " Warning: No admins found in the system!" << endl;
        }
        return allAdmins;
    }
    void getAllData() { 
        getAllClients();
        getAllAdmins();
        getAllEmployees();
    }

    void updateClients() {
        removeAllClients();
        for (clIt = allClients.begin(); clIt != allClients.end(); clIt++)
            addClient(*clIt);
    }
    void updateEmployees() {
        removeAllEmployees();
        for (elIt = allEmployees.begin(); elIt != allEmployees.end(); elIt++)
            addEmployee(*elIt);
    }
    void updateAdmins() {
        removeAllAdmins();
        for (alIt = allAdmins.begin(); alIt != allAdmins.end(); alIt++)
            addAdmin(*alIt);
    }
};


#pragma once
#include "Parser.h"
#include <iostream>
#include <sstream>
#include<fstream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"


using namespace std;
//#include"Parser.h"
class FileHelper {
//private:
//    static void saveLast(string fileName, int id) {
//        fstream file(fileName, ios::out);
//        if (file.is_open()) {
//            file << id;
//            file.close();
//        }
//        else {
//            throw runtime_error("Could not open " + fileName + " for writing.");
//        }
//    }
public:
    // ???? ???????? ??? ID ?? ?????
    static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        }
        else {
            throw runtime_error("Could not open " + fileName + " for writing.");
        }
    }
    static int getLast(string fileName) {
        ifstream file(fileName);
        int lastId = 0;
        if (file.is_open()) {
            file >> lastId;
            file.close();
        }
        else {
            throw runtime_error("Could not open " + fileName + " for reading.");
        }
        return lastId;
    }
    static void saveClient(Client c) {
        int id = getLast("ClientLastId.txt");
        ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file
                << id + 1 << ","
                << c.getName() << ","
                << c.getPassword() << ","
                << c.getBalanceEGP() << ","
                << c.getBalanceUSD() << endl;
            file.close();
            saveLast("ClientLastId.txt", id + 1);
        }
        else {
            throw runtime_error("Could not open client.txt for writing.");
        }
    }
    static void saveEmployee(Employee e) {
        int id = getLast("EmployeesLastId.txt");
        fstream file("Employees.txt", ios::app);
        if (file.is_open()) {
            file
                << id + 1 << ","
                << e.getName() << ","
                << e.getPassword() << ","
                << e.getSalary() << endl;
            file.close();
            saveLast("EmployeesLastId.txt", id + 1);
        }
        else {
            throw runtime_error("Could not open client.txt for writing.");
        }
    }
    static void saveAdmin(Admin a) {
        int id = getLast("AdminsLastId.txt");
        fstream file("Admins.txt", ios::app);
        if (file.is_open()) {
            file
                << id + 1 << ','
                << a.getName() << ','
                << a.getPassword() << ','
                << a.getSalary() << endl;
            file.close();
            saveLast("AdminsLastId.txt", id + 1);
        }
        else {
            throw runtime_error("Could not open client.txt for writing.");
        }
    }

    static void getClients() {
        //vector<Client> clients; 
        ifstream File1;
        File1.open("Clients.txt");
        if (File1.is_open())
        {
            string line;
            while (getline(File1, line))
            {
                try
                {
                    Client client = Parser::parseToClient(line);
                    allClients.push_back(client);
                }
                catch (const exception& e)
                {
                    cout << "Error parsing client: " << e.what() << endl;
                }
            }File1.close();
        }
        else throw runtime_error("Could not open file client.txt for reading. ");
    }
    static void getEmployee() {
        ifstream File2;
        File2.open("Employees.txt");
        if (File2.is_open())
        {
            string line;
            while (getline(File2, line))
                
            {
                try
                {
                    Employee employee = Parser::parseToEmployee(line);
                    allEmployees.push_back(employee);
                }
                catch (const exception& e)
                {
                    cout << "Error parsing Employee: " << e.what() << endl;
                }
            }File2.close();
        }
        else throw runtime_error("Could not open file client.txt for reading. ");
    }
    static void getAdmin() {
        ifstream File3;
        File3.open("Admins.txt");
        if (File3.is_open())
        {
            string line;
            while (getline(File3, line))
            {
                try
                {
                    Admin admin = Parser::parseToAdmin(line);
                    allAdmins.push_back(admin);
                }
                catch (const exception& e)
                {
                    cout << "Error parsing Admin: " << e.what() << endl;
                }
            }File3.close();
        }
        else throw runtime_error("Could not open file client.txt for reading. ");
    }



    static void clearFile(string fileName, string lastIdFile) {
        fstream File, File2;
        File.open(fileName, ios::out | ios::trunc);
        File.close();
        File2.open(lastIdFile, ios::out | ios::trunc);
        File2 << 0;
        File2.close();
    }
};


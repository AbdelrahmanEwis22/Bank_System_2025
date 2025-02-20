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
#include"Person.h"
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
//#include"FileHelper.h"
//#include"FileManager.h"
using namespace std;
class Parser
{
//private:
//    static vector<string> split(string line, char deli) {
//        vector<string> tokens;
//        stringstream ss(line);
//        string token;
//        while (getline(ss, token, deli)) {
//            tokens.push_back(token);
//        }
//        return tokens;
//    }
public:
    //static string trim(const string& str) {
    //    size_t first = str.find_first_not_of(" \t");
    //    if (first == string::npos) return ""; // ??? ???? ??????? ???? ??????
    //    size_t last = str.find_last_not_of(" \t");
    //    return str.substr(first, last - first + 1);
    //}
    static vector<string> split(string line, char deli) {
        vector<string> tokens; 
        stringstream ss(line);
        string token;
        while (getline(ss, token, deli)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Client parseToClient(string line) {
        vector<string> data = split(line, ',');
        if (data.size() != 5) {
            throw runtime_error("Invalid client data format.");
        }
        Client  client;
        client.setId(stoi(data[0]));
        client.setName(data[1]);
        client.setPassword(data[2]);
        client.setBalanceEGP(stod(data[3]));
        client.setBalanceUSD(stod(data[4]));
        return client;
    }

    static Employee parseToEmployee(string line) {
        vector<string> data = split(line, ',');
        if (data.size() != 4) {
            throw runtime_error("Invalid employee data format.");
        }
        Employee  employee;
        employee.setId(stoi(data[0]));
        employee.setName(data[1]);
        employee.setPassword(data[2]);
        employee.setSalary(stod(data[3]));
        return employee;
    }

    static Admin parseToAdmin(string line) {
        vector<string> data = split(line, ',');
        if (data.size() != 4) {
            throw runtime_error("Invalid admin data format.");
        }
        Admin  admin;
        admin.setId(stoi(data[0]));
        admin.setName(data[1]);
        admin.setPassword(data[2]);
        admin.setSalary(stod(data[3]));
        return admin;
    }
};


#pragma once

#include <iostream>
#include "Validayion.h"
using namespace std;
class Person
{
protected:
    int id;
    string name;
    string password;

public:
    // Constructor
    Person()
    {
        this->id = 0;
        this->name = " ";
        this->password = " ";
    }
    Person(int id, string name, string password)
    {
        setId(id);
        this->name=name;
        setPassword(password);
    }

    // Setters
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        //cout << "Checking name: " << name << endl; // طباعة الاسم قبل التحقق
       // cout << "Trying to set name: " << name << endl;
        if (!Validation::validateName(name))
            throw invalid_argument("Invalid name");
        this->name = name;
    }
    void setPassword(string password)
    {
       // cout << "Trying to set password: " << password << endl; // Debugging

        if (password.empty()) { 
            cout << " Error: Password cannot be empty!" << endl;
            throw invalid_argument("Error: Password cannot be empty!");
        }

        if (!Validation::validatePassword(password)) {
            cout << " Weak Password: " << password << endl;
            throw invalid_argument("Weak password");
        }

       // cout << " Password accepted: " << password << endl;
        this->password = password;
    }


    // Getters
    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    string getPassword()
    {
        return this->password;
    }
};


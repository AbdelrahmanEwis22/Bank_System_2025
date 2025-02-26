#pragma once
#include <cctype>
#include <iostream>
using namespace std;
class Validation
{
public:
    static bool validateName(string name)
    {
        if (name.length() < 5 || name.length() > 20)
            return false;
        for (char c : name)
        {
            if (!isalpha(c) && c != ' ')
                return false;
        }
        return true;
    }

    static bool validatePassword(string password)
    {
       // cout << "Checking password: " << password << endl; // Debugging

        if (password.length() < 8 || password.length() > 20)
            return false; 

        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        string specialChars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";

        for (char c : password) {
            if (isupper(c)) hasUpper = true;
            if (islower(c)) hasLower = true;
            if (isdigit(c)) hasDigit = true;
            if (specialChars.find(c) != string::npos) hasSpecial = true;
        }

        return hasUpper && hasLower && hasDigit && hasSpecial; // الآن الرموز مسموحة
    }


    static bool validateBalance(double balance)
    {
        return (balance >= 1500);
    }

    static bool validateSalary(double salary)
    {
        return (salary >= 5000);
    }
};


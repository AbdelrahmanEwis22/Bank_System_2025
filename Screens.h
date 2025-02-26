#pragma once
#include <iostream>
#include <thread>  
#include <chrono>  
#include <cstdlib> 
#include <map>     
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"


using namespace std;

class Screens {
public:
    static map<char, vector<string>> letters;

    static void printLine(const string& text, int lineIndex) {
        for (size_t i = 0; i < text.size(); i++) {
            char ch = text[i];
            if (ch == ' ') {
                cout << "     ";
            }
            else {
                if (letters.find(ch) != letters.end()) {
                    cout << letters[ch][lineIndex];
                }
                else {
                    cout << "     ";
                }
            }
            cout << "  ";
        }
        cout << endl;
    }
    static void printText(const string& text) {
        for (int line = 0; line < 5; line++) {
            printLine(text, line);
        }
    }

    static void showSplashScreen() {
        system("cls");
        for (int i = 0; i < 5; i++) cout << endl;
        printText(" WELCOME TO BANK ");
        this_thread::sleep_for(chrono::seconds(3));
        system("cls");
    }

    // عرض اسم البنك
    static void bankName() {
        cout << "===================================\n";
        cout << "       National Bank of Egypt      \n";
        cout << "===================================\n";
    }

    // عرض شاشة الترحيب مع التأخير
    static void welcomeWithDelay() {
        showSplashScreen(); // عرض رسالة الترحيب
        bankName();
        cout << "Welcome to the Banking System!\n";
        cout << "Loading...\n";
        this_thread::sleep_for(std::chrono::seconds(3)); // تأخير لمدة 3 ثواني 
        clearScreen(); // مسح الشاشة بعد انتهاء التأخير
    }

    // مسح الشاشة
    static void clearScreen() {
        #ifdef _WIN32
            system("cls"); // لنظام ويندوز
        #endif
    }

    // عرض خيارات تسجيل الدخول
    static void loginOptions() {
        cout << "\n=== Login Options ===\n";
        cout << "1. Login as Client\n";
        cout << "2. Login as Employee\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";
    }

    // اختيار نوع المستخدم لتسجيل الدخول
    static int loginAs() {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }

    // رسالة خطأ عند اختيار غير صحيح
    static void invalid(int c) {
        cout << "Invalid choice: " << c << ". Please try again.\n";
    }

    // رسالة تسجيل الخروج
    static void logout() {
        cout << "Logging out...\n";
    }

    // شاشة تسجيل الدخول
    static void loginScreen(int c) {
        int id;
        string password;

        cout << "Enter your ID: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> password;

        switch (c) {
        case 1: { // تسجيل دخول كعميل
            Client* client = ClientManger::login(id, password);
            if (client) {
                clearScreen(); // مسح الشاشة قبل عرض قائمة العميل
                ClientManger::clientOptions(client);
                delete client;
            }
            break;
        }
        case 2: { 

            Employee* employee = EmployeeManager::login(id, password);
            if (employee) {
                clearScreen(); 
                EmployeeManager::employeeOptions(employee); 
                delete employee;
            }
            break;
        }
        case 3: {
            Admin* admin = AdminManager::login(id,password);  
            if (admin) { 
                clearScreen(); 
                AdminManager::adminOptions(admin);
                delete admin;
            }
            break;
        }
        default:
            invalid(c);
        }
    }

    // تشغيل التطبيق
    static void runApp() {
        welcomeWithDelay();
        int choice;
        while (true) {
            loginOptions();
            choice = loginAs();
            if (choice == 4) {
                logout();
                exit(0);  // إنهاء البرنامج مباشرة
            }
            if (choice >= 1 && choice <= 3) {
                clearScreen();
                loginScreen(choice);
                clearScreen();
            }
            else {
                invalid(choice);
            }
        }
    }
};

// تعريف خريطة الحروف




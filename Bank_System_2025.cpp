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
#include "Admin.h"
#include "Employee.h"
#include"Parser.h"
#include"Screens.h"
#include"FileHelper.h"
#include"FileManager.h"
using namespace std;



int main()
{
    /*FileManager fileManager;
    vector<Client> clients = fileManager.getAllClients();

    if (clients.empty()) {
        cout << " No clients found in system!\n";
    }
    else {
        cout << " Clients loaded successfully:\n";
        for ( auto& client : clients) {
            cout << "Client ID: " << client.getId()
                << "  \nName: " << client.getName()
                << "  \nBalance: " << client.getBalanceEGP() << " EGP, "
                << client.getBalanceUSD() << " USD\n";
        }
    }*/

    FileManager f;
    Client c;
    c.display();
   // /*FileHelper c;
   // Client a(1, "Omar Ewis", "Omar_2021", 10000, 5000);
   // c.saveClient(a);*/
   //// f.removeAllAdmins();
   // f.getAllClients(); // استرجاع العملاء
   // f.getAllEmployees();
   // Employee e;
   // e.listClients();
   // f.getAllAdmins(); 
   
  //  FileManager f;
  ////  f.updateClients();
  //  FileHelper s;
  // 
  // // f.removeAllClients();
  //   Client a(1, "Mohamed Ewis", "Omar_2023", 25000,10000); 
  //  f.addClient(a);
  //  //f.removeAllEmployees();
  //  Employee c(1, "Omar Ewis", "Ewis_2025", 10000);
  // cout << "done1\n";
  // f.getAllClients();
  // f.getAllAdmins();
  // 
  //  f.getAllEmployees();
  //  cout << "done2\n";
  //  f.addEmployee(c);
  // // f.updateClients()
  //  cout << "done3\n";
  //      f.getAllEmployees();
  //      cout << "done4\n";
   //f.addAdmin(a); 
   // f.getAllAdmins();
   // FileManager f;
   // f.removeAllAdmins();
    //Client a(3, "AbdoEwis", "12345678", 10000,5000); 
  /*  Admin a(55, "EmarEwis", "1234567899", 25000);
    f.addAdmin(a); 
    cout << "done\n";
    s.getAdmin();
    cout << "done\n";
    f.getAllAdmins();
    cout << "\n";
    f.getAllClients();*/
   //Screens::runApp();
    /*ofstream file("C:\\Users\\ewisa\\OneDrive\\Desktop\\Bank_System_2025\\AdminsLastId.txt", ios::app);
    if (!file) {
        cerr << "Failed to create Clients.txt!" << endl;
    }
    else {
        cout << "Clients.txt created successfully!" << endl;
        file.close();
    }*/

  //  f.getAllAdmins();
    //// إضافة عملاء إلى النظام (اختياري)
    //try {
    //    Client c(5, "hamza", "hamza12345", 5000, 2000);
    //    Employee e1(1, "Ahmed", "Ahmed12345", 20000.0);
    //  
    //    Admin a(5, "abdo", "abdoewis2025", 10000);
    //    f.addClient(c);  
    //    cout << "1\n";
    //    f.addEmployee(e1); 
    //    cout << "2\n";
    //    f.addAdmin(a); 
    //    cout << "Admain added successfully.\n";
    //   // f.getAllAdmins();
    //    f.getAllData();

    //}
    //catch (const exception& e) {
    //    cerr << "Error adding addEmployee: " << e.what() << endl;
    //}
  //  f.addClient(c);
  //  f.addClient(c); 
    // إضافة عملاء إلى النظام (اختياري)
    //try {
    //    /* Client c(6, "hamza", "hamza12345", 5000, 2000); 
    //     Employee e1(1, "Ahmed", "Ahmed12345", 20000.0); 
    //     Employee e2(2, "Omar", "omar12345678", 22500.0); */
    //   //  Employee e(3, "abdo", "123456789", 10000);
    //  /*   Admin a(5, "abdo", "abdoewis2025", 10000); 
    //     Employee e(1, "omare", "omar123456", 10000);*/
    //   fileManager.getClients();
    //     cout << "Employee added successfully.\n";
    //}
    // catch (const exception& e) {
    //    cerr << "Error adding addEmployee: " << e.what() << endl;
    //}
    
   // Employee e(1, "omare", "omar123456", 10000);
   
   
   /* Client client1(1, "Ahmed", "Ahmed12345", 10000, 2000);
    Client client2(2, "omar", "omar12345678", 20000, 2500);
    cout << "done\n";
   
    clientMenu(client1, client2);*/
    return 0;
    //try
    //{
    //    // Client client1(1, "Ahmed", "Ahmed12345", 2000);
    //    /*client1.deposit(5000);
    //    client1.display();
    //    client1.withdraw(2000);
    //    client1.display();
    //    c2.display();*/
    //    client1.transferTo(c2, 500);
    //    client1.display();
    //    c2.display();
    //    c2.transferTo(client1, 1500);
    //    c2.checkBalance();
    //    client1.checkBalance();

    //    Employee emp1(101, "Mohamed", "MohamedPass", 6000);
    //    emp1.display();

    //    Admin admin(1001, "Admin", "AdminPass123", 10000);
    //    admin.display();
    //}
    //catch (const exception &e)
    //{
    //    cerr << "Error: " << e.what() << endl;
    //}
    
}

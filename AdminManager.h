#pragma once
#include"Admin.h"
#include "EmployeeManager.h"
#include"FileManager.h"

//#include"EmployeeManager.h"
class AdminManager 
{//private:  static  vector<Admin> allAdmins; // لم يعد static، وأصبح داخل كلاس مخصص

public:
    static int chooseUserType() {
        int choice;
        cout << "\n=== Choose User Type ===\n";
        cout << "1. Manage Clients\n";
        cout << "2. Manage Employees\n";
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }
    static void printEmployeeMenu() {
        cout << "\n=== Employee Menu ===\n";
        cout << "1. Add New Client\n";
        cout << "2. List All Clients\n";
        cout << "3. Search for Client\n";
        cout << "4. Edit Client Info\n";
        cout << "5. Balacne\n";
        cout << "6. Change Password\n";
        cout << "7. Logout\n";
    }
    static void printEmployeeMenu2() {
        cout << "\n=== Employee Menu ===\n";
        cout << "1. Add New Employee\n";
        cout << "2. List All Employee\n";
        cout << "3. Search for Employee\n";
        cout << "4. Edit Employee Info\n";
        cout << "5. Balance\n";
        cout << "6. Change Password\n";
        cout << "7. Logout\n";
    }
    //Client
    static void newClient(Admin* admin) {

        Client newClient;
        int id;
        string name, password;
        double balanceEGP, balanceUSD;
        FileManager fileManager, fileManager1;

        cout << "Enter client ID: ";
        cin >> id;

        // تحقق من ID غير مكرر
        vector<Client> allClients = fileManager.getAllClients();  // افترضنا أن هناك دالة لإرجاع كل العملاء 
        for (auto& c : allClients) {
            if (c.getId() == id) {
                throw invalid_argument("Client ID already exists!");
            }
        }

        cout << "Enter client name: ";
        cin >> name;

        cout << "Enter client password: ";
        cin >> password;
        while (password.empty()) { 
            cout << " Error: Password cannot be empty! Please enter a valid password: ";
            cin >> password;
        }
        cout << "Enter initial balance in EGP: ";
        cin >> balanceEGP;
        cout << "Enter initial balance in USD: ";
        cin >> balanceUSD;

        if (balanceEGP <= 0 || balanceUSD <= 0) {
            throw invalid_argument("Initial balance must be greater than zero.");
        }

        // تعيين البيانات للعميل
        newClient.setId(id);
        newClient.setName(name);
        newClient.setPassword(password);
        newClient.setBalanceEGP(balanceEGP);
        newClient.setBalanceUSD(balanceUSD);

        // إضافة العميل
        fileManager1.addClient(newClient);
        cout << "Client added successfully.\n";
    }
    static void listAllClients(Admin* admin) {

        FileManager fileManager;
        vector<Client> clients = fileManager.getAllClients();  // استدعاء الدالة من كائن fileManager
        cout << "\n=== Client List ===\n";

        if (clients.empty()) {
            cout << "No clients found.\n";
        }
        else {
            for (auto& client : clients) {
                client.display();
                cout << "----------------------\n";  // إضافة فاصل بين كل عميل وآخر
            }
        }
    }
    static void searchForClient(Admin* admin) {
        int clientId;
        cout << "Enter client ID to search: ";
        cin >> clientId;

        // البحث عن العميل باستخدام دالة searchClient
        Client* client = admin->searchClient(clientId);

        if (client) {
            cout << "Client found:\n";
            client->display();
        }
        else {
            cout << "Client not found.\n";
        }
    }
    static void editClientInfo(Admin* admin) {
        int clientId;
        FileManager fileManager, fileManager1;
        cout << "Enter client ID to edit: ";
        cin >> clientId;

        // الحصول على العميل بناءً على ID
        vector<Client> clients = fileManager1.getAllClients();
        Client* clientToEdit = nullptr;

        for (auto& client : clients) {
            if (client.getId() == clientId) {
                clientToEdit = &client;  // نستخدم العنوان مباشرة
                break;
            }
        }

        if (clientToEdit) {
            cout << "Client found. What would you like to edit?\n";
            cout << "1. Name\n";
            cout << "2. Password\n";
            cout << "3. Balance EGP\n";
            cout << "4. Balance USD\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string newName;
                cout << "Enter new name: ";
                cin >> newName;
                clientToEdit->setName(newName);
                cout << "Name updated successfully.\n";
                break;
            }
            case 2: {
                string newPassword;
                cout << "Enter new password: ";
                cin >> newPassword;
                clientToEdit->setPassword(newPassword);
                cout << "Password updated successfully.\n";
                break;
            }
            case 3: {
                double newBalanceEGP;
                cout << "Enter new balance in EGP: ";
                cin >> newBalanceEGP;
                clientToEdit->setBalanceEGP(newBalanceEGP);
                cout << "Balance in EGP updated successfully.\n";
                break;
            }
            case 4: {
                double newBalanceUSD;
                cout << "Enter new balance in USD: ";
                cin >> newBalanceUSD;
                clientToEdit->setBalanceUSD(newBalanceUSD);
                cout << "Balance in USD updated successfully.\n";
                break;
            }
            default:
                cout << "Invalid choice!\n";
            }

            // تحديث العملاء في الملف بعد التعديل
            fileManager.updateClients();  // تقوم هذه الدالة بتحديث العملاء في الملف
            cout << "Client information updated successfully.\n";
        }
        else {
            cout << "Client not found.\n";
        }
    }
    static void balanceClientInfo(Admin* admin) {
        int clientId;
        cout << "Enter client ID to display: ";
        cin >> clientId;

        // البحث عن العميل باستخدام `searchClient`
        Client* client = admin->searchClient(clientId);

        if (client) {
            cout << "Client details:\n";
            client->checkBalance();
        }
        else {
            cout << "Client not found.\n";
        }
    }
    static void updatePasswordClient(Admin* admin) {
        if (!admin) {
            cout <<" Error: Admin pointer is null!" << endl;
            return;
        }
         
        string newPassword; 
        cout << "Enter New Password Please:\n";
        cin >> newPassword; 

        if (newPassword.empty()) { 
            cout << " Error: Password cannot be empty!\n";
            return;
        }

        admin->setPassword(newPassword); 
        cout << " Successfully changed your password.\n";
    }
    //Employee
    static Admin* login(int id, string password) {
        for (alIt = allAdmins.begin(); alIt != allAdmins.end(); alIt++) {
            if (alIt->getId() == id) {
                return &(*alIt); // Return a copy
            }
        }
        return nullptr;
    }
    static void newEmployee(Admin* admin) { 

        Employee newemployee;
        int id;
        string name, password;
        double salary;
        FileManager fileManager, fileManager1;

        cout << "Enter client ID: ";
        cin >> id;

        // تحقق من ID غير مكرر
        vector<Employee> allEmployees = fileManager.getAllEmployees();  // افترضنا أن هناك دالة لإرجاع كل العملاء 
        for (auto& e : allEmployees) {
            if (e.getId() == id) { 
                throw invalid_argument("Client ID already exists!");
            }
        }

        cout << "Enter client name: ";
        cin >> name;

        cout << "Enter client password: ";
        cin >> password;
        while (password.empty()) { 
            cout << " Error: Password cannot be empty! Please enter a valid password: ";
            cin >> password;
        }

        cout << "Enter initial balance in EGP: ";
        cin >> salary;

        if (salary <= 0) {
            throw invalid_argument("Initial balance must be greater than zero.");
        }

        // تعيين البيانات للعميل
        newemployee.setId(id); 
        newemployee.setName(name); 
        newemployee.setPassword(password); 
        newemployee.setSalary(salary);

        // إضافة العميل
        fileManager1.addEmployee(newemployee);
        cout << "Client added successfully.\n";
    }
    static void balanceEmployeeInfo(Admin* admin) {
        int employeeId;
        cout << "Enter client ID to display: \n";
        cin >> employeeId;

        // البحث عن العميل باستخدام `searchClient`
        Employee* employee = admin->searchEmployee(employeeId);

        if (employee) { 
            cout << "Employee details:\n";
            employee->getSalary();  
        }
        else {
            cout << "Employee not found.\n";
        }
    }
    static void listAllEmployees(Admin* admin) {

        FileManager fileManager;
        vector<Employee> employees = fileManager.getAllEmployees();  // استدعاء الدالة من كائن fileManager
        cout << "\n=== Client List ===\n";

        if (employees.empty()) { 
            cout << "No clients found.\n";
        }
        else {
            for (auto& employee : employees) { 
                employee.display(); 
                cout << "----------------------\n";  // إضافة فاصل بين كل عميل وآخر
            }
        }
    }
    static void searchForEmployee(Admin* admin) {
        int employeeId;
        cout << "Enter client ID to search:\n ";
        cin >> employeeId;

        // البحث عن العميل باستخدام دالة searchClient
        Employee* employee = admin->searchEmployee(employeeId);

        if (employee) {
            cout << "Client found:\n";
            employee->display(); 
        }
        else {
            cout << "Client not found.\n";
        }
    }
    static void updatePasswordEmployee(Admin* admin) {
        string newPassword;
        cout << "Enter New Password Please:\n";
        cin >> newPassword;
        admin->setPassword(newPassword); 
        cout << "Sussfucle Change Your Password.\n";
    }
    static void editEmployeeInfo(Admin* admin) {
        int employeeId;
        FileManager fileManager, fileManager1;
        cout << "Enter client ID to edit: ";
        cin >> employeeId; 

        // الحصول على العميل بناءً على ID
        vector<Employee> employees = fileManager1.getAllEmployees(); 
        Employee* employeeToEdit = nullptr;

        for (auto& employee : employees) {
            if (employee.getId() == employeeId) {
                employeeToEdit = &employee;  // نستخدم العنوان مباشرة 
                break;
            }
        }

        if (employeeToEdit) { 
            cout << "Client found. What would you like to edit?\n";
            cout << "1. Name\n";
            cout << "2. Password\n";
            cout << "3. Salary\n";
            cout << "Enter your choice: \n";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string newName;
                cout << "Enter new name: \n";
                cin >> newName;
                employeeToEdit->setName(newName); 
                cout << "Name updated successfully.\n";
                break;
            }
            case 2: {
                string newPassword;
                cout << "Enter new password:\n ";
                cin >> newPassword;
                employeeToEdit->setPassword(newPassword); 
                cout << "Password updated successfully.\n";
                break;
            }
            case 3: {
                double newSalary;
                cout << "Enter new Salary: \n";
                cin >> newSalary;
                employeeToEdit->setSalary(newSalary);
                cout << "Salary updated successfully.\n";
                break;
            }
            default:
                cout << "Invalid choice!\n";
            }

            // تحديث العملاء في الملف بعد التعديل
            fileManager.updateEmployees();  // تقوم هذه الدالة بتحديث العملاء في الملف  
            cout << "Employee information updated successfully.\n";
        }
        else {
            cout << "Employee not found.\n";
        }
    }
    static bool adminOptions(Admin* admin) { 
        bool backToMain = false;

        while (!backToMain) {
            int userType = chooseUserType();
            bool exitSubMenu = false;

            while (!exitSubMenu) {
                if (userType == 1) {  // إدارة العملاء
                   printEmployeeMenu(); 
                    int choice;
                    cout << "\nEnter your choice: ";
                    cin >> choice;
                    
                    switch (choice) {
                    case 1: newClient(admin);
                        break;
                    case 2: listAllClients(admin); 
                        break;
                    case 3: searchForClient(admin);
                        break;
                    case 4: editClientInfo(admin); 
                        break;
                    case 5: balanceClientInfo(admin); 
                        break;
                    case 6: updatePasswordClient(admin);
                        break;
                    case 7: exitSubMenu = true;
                        break;
                    default: cout << "Invalid choice. Try again.\n";
                    }
                }
                else if (userType == 2) {  // إدارة الموظفين
                    printEmployeeMenu2();
                    int choice;
                    cout << "\nEnter your choice: ";
                    cin >> choice;

                    switch (choice) {
                    case 1: newEmployee(admin);
                        break;
                    case 2: listAllEmployees(admin); 
                        break;
                    case 3: searchForEmployee(admin); 
                        break;
                    case 4: editEmployeeInfo(admin); 
                        break;
                    case 5:balanceEmployeeInfo(admin); 
                        break;
                    case 6:updatePasswordEmployee(admin);
                        break;
                    case 7: exitSubMenu = true; 
                        break; // الرجوع إلى القائمة الرئيسية
                    default: cout << "Invalid choice. Try again.\n";
                    }
                }
                else {
                    cout << "Invalid choice! Please select again.\n";
                    break;
                }
            }
        }
        return backToMain;
    }
};


#pragma once
#include"Employee.h"
#include"FileManager.h"
#include"AdminManager.h"
class EmployeeManager
{
public:
    static void printEmployeeMenu() {
        cout << "\n=== Employee Menu ===\n";
        cout << "1. Add New Client\n";
        cout << "2. List All Clients\n";
        cout << "3. Search for Client\n";
        cout << "4. Edit Client Info\n";
        cout << "5. Desplay\n";
        cout << "6. Change Password\n";
        cout << "7. Logout\n";
    }
    static Employee* login(int id, string password) {
        for (elIt = allEmployees.begin(); elIt != allEmployees.end(); elIt++) {
            if (elIt->getId() == id) {
                return elIt._Ptr; 
            }
        }
        return NULL;
    }
    static void newClient(Employee* employee) {
        
            Client newClient;
            int id;
            string name, password;
            double balanceEGP,balanceUSD;
            FileManager fileManager, fileManager1;

            cout << "Enter client ID: ";
            cin >> id;

            vector<Client> allClients = fileManager.getAllClients();  
            for (auto& c : allClients) {
                if (c.getId() == id) {
                    throw invalid_argument("Client ID already exists!");
                }
            }

            cout << "Enter client name: ";
            cin >> name;

            cout << "Enter client password: ";
            cin >> password;

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

            fileManager.addClient(newClient);  
            cout << "Client added successfully.\n";
        }
    static void balanceClientInfo(Employee* employee) {
        int clientId;
        cout << "Enter client ID to display: ";
        cin >> clientId;

        Client* client = employee->searchClient(clientId);

        if (client) {
            cout << "Client details:\n";
            client->checkBalance();
        }
        else {
            cout << "Client not found.\n";
        }
    }
    static void listAllClients(Employee* employee) {
        
            FileManager fileManager;
            vector<Client> clients = fileManager.getAllClients();  
            cout << "\n=== Client List ===\n";

            if (clients.empty()) {
                cout << "No clients found.\n";
            }
            else {
                for (auto& client : clients) {
                    client.display();
                    cout << "----------------------\n";  
                }
            }
        } 
    static void searchForClient(Employee* employee) { 
            int clientId; 
            cout << "Enter client ID to search: ";
            cin >> clientId; 

            Client* client = employee->searchClient(clientId);  

            if (client) { 
                cout << "Client found:\n"; 
                client->display(); 
            }
            else {
                cout << "Client not found.\n";
            }
        }
    static void updatePassword(Employee* employee) {
        string newPassword;
        cout << "Enter New Password Please:\n";
        cin >> newPassword;
        employee->setPassword(newPassword);
        cout << "Sussfucle Change Your Password.";
    }
    static void editClientInfo(Employee* employee) {
            int clientId;
            FileManager fileManager, fileManager1;
            cout << "Enter client ID to edit: ";
            cin >> clientId;

            vector<Client> clients = fileManager1.getAllClients();
            Client* clientToEdit = nullptr;

            for (auto& client : clients) {
                if (client.getId() == clientId) {
                    clientToEdit = &client;  
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

                fileManager.updateClients();  
                cout << "Client information updated successfully.\n";
            }
            else {
                cout << "Client not found.\n";
            }
        }
    static bool employeeOptions(Employee* employee) {
        int choice;
        cout << "\n=== Employee Menu ===\n";
        cout << "1. Add New Client\n";
        cout << "2. List All Clients\n";
        cout << "3. Search for Client\n";
        cout << "4. Edit Client Info\n";
        cout << "5. Display Client Info\n";
        cout << "6. Change Password\n";
        cout << "7. Logout\n";
        cout << "Please choose an option: ";
        cin >> choice;
        bool logout = false;
        while (!logout)
        {
            printEmployeeMenu();
            cout << "\nEnter your choice:\n";
            cin >> choice;
            switch (choice)
            {
            case 1:newClient(employee);
                break; 
            case 2:listAllClients(employee); 
                break;
            case 3:searchForClient(employee);
                break;
            case 4:editClientInfo(employee); 
                break;
            case 5:balanceClientInfo(employee);
                break;
            case 6:updatePassword(employee); 
                break;
            case 7:logout = true;
                cout << "Logging out...\n";
                break;
            default:
                break;
            }
        }
        return logout;
    }

};


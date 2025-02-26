#pragma once
#include"Client.h"
#include"Person.h"
#include"FileManager.h"
class ClientManger
{
public:
	//chose the your opetion.
	static void printClientMenu(){
		cout << "\n Chose your opetion:\n";
		cout << "1. Deposit\n";
		cout << "2. Withdraw\n";
		cout << "3. TransferTo\n";
		cout << "4. TransferCurrency\n";
		cout << "5. CheckBalance\n";
		cout << "6. Display\n";
		cout << "7. DisplayTransactions\n";
		cout << "8. updatePassword\n";
		cout << "9. Logout\n";
	}
	//Update the new Passweord.
    static void updatePassword(Client* client){
		string newPassword;
		cout << "Enter New Password Please:\n";
		cin >> newPassword;
		client->setPassword(newPassword); 
		cout << "Sussfucle Change Your Pssword.";
	}
	//
	static Client* login(int id, string password){
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id) {
				return clIt._Ptr;
			}
		}
		return NULL;
	}
    static bool clientOptions(Client* client){
		int choice;
		bool logout = false;
		while (!logout)
		{
			printClientMenu();
			cout << "\nEnter your choice:\n";
			cin >> choice;
			switch (choice)
			{
			case 1: {
				double amount;
				string currency;
				cout << "\nEnter your deposit amount: \n";
				cin >> amount;
				cout << "Enter currency (EGP/USD): ";
				cin >> currency;
				client->deposit(amount, currency);
				break;
			}
			case 2: {
				double amount;
				string currency;  
				cout << "\nEnter your deposit amount: \n";
				cin >> amount;  
				cout << "Enter currency (EGP/USD): ";
				cin >> currency; 
				client->deposit(amount, currency); 
				break;
			}
			case 3: {
				int recipientId; 
				double amount;  
				string currency;
				cout << "Enter recipient ID: ";
				cin >> recipientId; 
				cout << "Enter transfer amount: ";
				cin >> amount;
				cout << "Enter currency (EGP/USD): ";
				cin >> currency;
				FileManager fileManager;
				vector<Client> clients = fileManager.getAllClients();
				Client* recipient = nullptr; 
				for (auto& c : clients) { 
					if (c.getId() == recipientId) {   
						recipient = new Client(c); 
						break;
					}
				}
				if (recipient) {
					client->transferTo(*recipient, amount, currency); 
					cout << "Transfer successful.\n";
					delete recipient; 
				}
				else cout << "Recipient not found.\n";
				break;
			}
			case 4: {
				int choice;
				cout << "Choose Currency Transfer Type:\n";
				cout << "1. Convert currency for yourself\n";
				cout << "2. Convert currency and transfer to another client\n";
				cout << "Enter your choice: ";
				cin >> choice;

				if (choice == 1) {
					// ????? ?????? ???? ????????
					double amount;
					string from, to;

					cout << "Enter amount to convert: ";
					cin >> amount;
					cout << "Enter from currency (EGP/USD): ";
					cin >> from;
					cout << "Enter to currency (EGP/USD): ";
					cin >> to;

					client->transferCurrency(*client, amount, from, to);
					cout << "Currency conversion successful.\n";

				}
				else if (choice == 2) {
					// ????? ?????? ??? ???? ???
					int recipientId;
					double amount;
					string from, to;

					cout << "Enter recipient ID: ";
					cin >> recipientId;
					cout << "Enter amount to transfer: ";
					cin >> amount;
					cout << "Enter from currency (EGP/USD): ";
					cin >> from;
					cout << "Enter to currency (EGP/USD): ";
					cin >> to;
					FileManager fileManager;
					vector<Client> clients = fileManager.getAllClients();
					Client* recipient = nullptr;

					for (auto& c : clients) {
						if (c.getId() == recipientId) {
							recipient = new Client(c);
							break;
						}
					}

					if (recipient) {
						client->transferCurrency(*recipient, amount, from, to);
						cout << "Currency transfer successful.\n";
						delete recipient;
					}
					else {
						cout << "Recipient not found.\n";
					}
				}
				else cout << "Invalid choice. Please try again.\n";
				break;
			}
			case 5: client->checkBalance(); 
				break;
			case 6: client->display(); 
				break;
			case 7: client->displayTransactions(); 
				break;
			case 8: updatePassword(client);
				break;
			case 9: cout << "\nLogging out...\n";
				logout = true;
				break;
			default:
				cout << "Invalid choice, try again.\n";
			}
		}
		return logout;
	}
};


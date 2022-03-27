#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getBalance(string username){
    string user, pass;
    int balance;
    ifstream accounts("accounts.txt");
    accounts >> user;
    while (!accounts.eof()){
        accounts >> pass;
        accounts >> balance;
        if(username == user){
            return balance;
        }
        accounts >> user;
    }   
    accounts.close();
}

bool transaction(string userFrom, string userTo){
    int quantity;
    string copyData[3];
    cout << "Ingrese la cantidad que desea transferir a: " + userTo << endl;
    cin >> quantity;
    if(getBalance(userFrom) < quantity){
        cout << "Saldo insuficiente!" << endl;
        return false;
    }
    ifstream accounts("accounts.txt");
    ofstream secondary("auxarch.txt", ios::app);
    if(!accounts.is_open() && !secondary.is_open()){
        cout << "Error interno!, vuelva a intentarlo." << endl;
        return false;
    }
    accounts >> copyData[0];
    while(!accounts.eof()){
        accounts >> copyData[1];
        accounts >> copyData[2];
        if(copyData[0] == userFrom){
            secondary << copyData[0] << "\t" << copyData[1] << "\t" << to_string(stoi(copyData[2]) - quantity) << endl;
        }
        if(copyData[0] == userTo){
            secondary << copyData[0] << "\t" << copyData[1] << "\t" << to_string(stoi(copyData[2]) + quantity) << endl;
        }else{
            secondary << copyData[0] << "\t" << copyData[1] << "\t" << copyData[2] << endl;
        }
        accounts >> copyData[0];
    }
    accounts.close();
    secondary.close();
    remove("accounts.txt");
    rename("auxarch.txt", "accounts.txt");
    cout << "Transacción exitosa!" << endl;
    return true;
}

bool addBalance(string username){
    int quantity;
    string copyData[3];
    cout << "Ingrese la cantidad que desea agregar a su saldo, recuerde que su saldo actual es de: " << getBalance(username) << endl;
    cin >> quantity;
    ifstream accounts("accounts.txt");
    ofstream secondary("auxarch.txt", ios::app);
    if(accounts.is_open()){
        accounts >> copyData[0];
        while(!accounts.eof()){
            accounts >> copyData[1];
            accounts >> copyData[2];
            if(copyData[0] == username){
                secondary << copyData[0] << "\t" << copyData[1] << "\t" << to_string(stoi(copyData[2]) + quantity) << endl;
            }else{
                secondary << copyData[0] << "\t" << copyData[1] << "\t" << copyData[2] << endl;    
            }
            accounts >> copyData[0];
        }
        accounts.close();
        secondary.close();
    }else{
        cout << "Error interno!, vuelva a intentarlo." << endl;
        return false;
    }
    remove("accounts.txt");
    rename("auxarch.txt", "accounts.txt");
    cout << "Transacción exitosa!" << endl;
    return true;
}
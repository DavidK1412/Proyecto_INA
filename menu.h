#include <iostream>
#include <unistd.h>
#include <windows.h>
#include "balanceActions.h"

using namespace std;

string username = "";

void menu(string user);

void menuOptions(){
    string userTo;
    int opc = 0;
    cin >> opc;
    switch(opc){
        case 1:
            cout << "Su saldo actual es de: $" << getBalance(username) << endl;
            sleep(2);
            system("cls");
            menu(username);
            break;
        case 2:
            if(!addBalance(username)){
                sleep(2);
                system("cls");
                menu(username);
            }else{
                cout << "Su nuevo saldo es de: $" << getBalance(username) << endl;
                sleep(2);
                system("cls");
                menu(username);
            }
            break;
        case 3:
            cout << "Ingrese el número al que desea transferir" << endl;
            cin >> userTo;
            if(!verifyUser(userTo)){
                cout << "Error, el usuario al que desea transferir no existe" << endl;
                sleep(2);
                system("cls");
                menu(username);
            }
            if(!transaction(username, userTo)){
                sleep(2);
                system("cls");
                menu(username);
            }else{
                cout << "Su nuevo saldo es de: $" << getBalance(username) << endl;
                sleep(2);
                system("cls");
                menu(username);
            }
            break;
        case 4:
            break;
        default:
            cout << "Error!. Opcion no es valida.";
            sleep(2);
            system("cls");
            menu(username);
            break;
    }
}

void menu(string user){
    username = user;
    cout << "\t Bienvenido al sistema de gestion bancaria!: " + username + " \t" << endl;
    cout << "Ingrese el numero de la opcion a realizar: \n1. Consultar saldo\n2. Agregar saldo\n3. Transferir saldo\n4. Salir" <<endl;
    menuOptions();
}
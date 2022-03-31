#include <iostream>
#include <unistd.h>
#include <windows.h>
#include "balanceActions.h"
#include "voucher.h"
#include "loan.h"

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
            int quantity;
            cout << "Ingrese la cantidad que desea agregar a su saldo, recuerde que su saldo actual es de: " << getBalance(username) << endl;
            cin >> quantity;
            if(!addBalance(username, quantity)){
                sleep(2);
                system("cls");
                menu(username);
                break;
            }
            cout << "Su nuevo saldo es de: $" << getBalance(username) << endl;
            record("RECARGA", username, quantity);
            sleep(2);
            system("cls");
            menu(username);
            break;
        case 3:
            cout << "Ingrese el número al que desea transferir" << endl;
            cin >> userTo;
            if(!verifyUser(userTo)){
                cout << "Error, el usuario al que desea transferir no existe" << endl;
                sleep(2);
                system("cls");
                menu(username);
                break;
            }
            if(!transaction(username, userTo)){
                sleep(2);
                system("cls");
                menu(username);
            }
            cout << "Su nuevo saldo es de: $" << getBalance(username) << endl;
            sleep(2);
            system("cls");
            menu(username);
            break;
        case 4:
            int res;
            searchTransactions(username);
            cout << "Escriba cualquier número para volver al menu" << endl;
            cin >> res;
            system("cls");
            menu(username);
            break;
        case 5:
            vouchers(username);
            sleep(2);
            system("cls");
            menu(username);
            break;
        case 6:
            loanMenu(username);
            sleep(2);
            system("cls");
            menu(username);
            break;
        case 7:
            cout << "Adiós!";
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
    cout << "Ingrese el numero de la opcion a realizar: \n1. Consultar saldo\n2. Agregar saldo\n3. Transferir saldo\n4. Ver historial transacciones\n5. Ver comprobantes\n6. Salir" <<endl;
    menuOptions();
}
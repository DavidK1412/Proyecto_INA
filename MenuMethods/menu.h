#include <iostream>

using namespace std;

string username = "";

void menu(string user);

void menuOptions(){
    int opc = 0;
    cin >> opc;
    switch(opc){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            cout << "Error!. Opcion no es valida.";
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
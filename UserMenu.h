#include <iostream>
#include <fstream>
#include "auth.h"

using namespace std;

void UserMenu();

void UserMenuOptions(){
    string user, pass; 
    int UserOpc = 0;
    cin >> UserOpc;
    switch(UserOpc){
        case 1:
            cout<<"Ingrese su numero"<<endl;
            cin>>user;
            cout<<"Ingrese su contrasena"<<endl;
            cin>>pass;
            logInUser(user, pass);
            break;
        case 2:
            cout<<"Ingrese su numero" << endl;
            cin>>user;
            cout<<"Ingrese su contrasena" << endl;
            cin>>pass;
            createUser(user, pass);
            break;
        default:
            cout << "Error!. Opcion no es valida.";
            system("cls");
            break;
    }
}
void UserMenu(){
    cout << "\t Seleccione un metodo de ingreso\t" << endl;
    cout << "Ingrese el numero de la opcion a realizar: \n1. Logearse\n2. Registrarse" <<endl;
    UserMenuOptions();
}
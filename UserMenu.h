#include <iostream>
#include <fstream>
#include "auth.h"
#include <unistd.h>
#include <windows.h>

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
            if(user.length() != 10){
                cout << "Error!. Los números de telefono sólo tienen 10 caracteres!\n";
                sleep(2);
                system("cls");
                UserMenu();
                break;
            }
            cout<<"Ingrese su contrasena"<<endl;
            cin>>pass;
            if(!logInUser(user, pass))
                UserMenu();
            break;
        case 2:
            cout<<"Ingrese su numero" << endl;
            cin>>user;
            if(user.length() != 10){
                cout << "Error!. Los números de telefono sólo tienen 10 caracteres!\n";
                system("cls");
                UserMenu();
                break;
            }
            cout<<"Ingrese su contrasena" << endl;
            cin>>pass;
            if(!createUser(user, pass))
                UserMenu();
            break;
        case 3:
            cout << "Hasta luego!";
            break;
        default:
            cout << "Error!. Opcion no es valida.";
            system("cls");
            UserMenu();
            break;
    }
}
void UserMenu(){
    cout << "\t Seleccione un metodo de ingreso\t" << endl;
    cout << "Ingrese el numero de la opcion a realizar: \n1. Logearse\n2. Registrarse\n3. Salir" <<endl;
    UserMenuOptions();
}
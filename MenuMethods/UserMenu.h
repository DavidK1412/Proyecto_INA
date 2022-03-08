#include <iostream>
#include <fstream>
//#include "../userAuth/logIn.h"
//#include "../userAuth/register.h"

using namespace std;

void UserMenu();

void UserMenuOptions(){
    int UserOpc = 0;
    cin >> UserOpc;
    switch(UserOpc){
        case 1:
            break;
        case 2:
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
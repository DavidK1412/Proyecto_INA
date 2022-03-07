#include <iostream>
#include <fstream>
#include "encrypter.h"
#include "../userActions/verifyUser.h"

using namespace std;

void createUser(string user, string pass){
    int balance = 0;
    pass = encrypt(pass);
    ofstream accArch("../utils/accounts.txt", ios::app);
    if (!accArch){
        cout << "Error en el registro del usuario! , no se pudo abrir el archivo.";
    }else{
        if (verifyUser(user)){
            cout << "Error, usuario ya existe..." << endl;
        }else{
            accArch << user << "\t" << pass << "\t" << balance << endl;
            cout << "Usuario creado satisfactoriamente!" << endl;
        }
    }
    accArch.close();
}
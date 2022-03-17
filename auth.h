#include <iostream>
#include <fstream>

#include "encrypter.h"
#include "verifyUser.h"
#include "menu.h"

using namespace std;

void logInUser(string username, string pass){
    string user, password;
    if(verifyUser(username)) {
        ifstream archLeer("accounts.txt");
        archLeer >> user;
        while (!archLeer.eof()){
            archLeer >> password;
            password = decrypt(password);
            if (user == username){
                if(pass == password){
                    cout << "Logueo exitoso como: " << user << endl ;
                    system("cls");
                    menu(user);
                }else{
                    cout << "Contrasena incorrecta!" << endl;
                }
            }
            archLeer >> user;
        }
        archLeer.close();
    }else{
        cout << "Error, usuario no existe." << endl;
    }
}

void createUser(string user, string pass){
    int balance = 0;
    pass = encrypt(pass);
    ofstream accArch("accounts.txt", ios::app);
    if (!accArch){
        cout << "Error en el registro del usuario! , no se pudo abrir el archivo.";
    }else{
        if (verifyUser(user)){
            cout << "Error, usuario ya existe..." << endl;
        }else{
            accArch << user << "\t" << pass << "\t" << balance << endl;
            cout << "Usuario creado satisfactoriamente!" << endl;
            menu(user);
        }
    }
    accArch.close();
}
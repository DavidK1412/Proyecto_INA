#include <iostream>
#include <fstream>

#include "encrypter.h"
#include "verifyUser.h"
#include "menu.h"

using namespace std;

bool logInUser(string username, string pass){
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
                    archLeer.close();
                    menu(user);
                }else{
                    cout << "Contrasena incorrecta!" << endl;
                    sleep(2);
                    system("cls");
                    return false;
                }
            }
            archLeer >> user;
        }
        archLeer.close();
    }else{
        cout << "Error, usuario no existe." << endl;
        sleep(2);
        system("cls");
        return false;
    }
}

bool createUser(string user, string pass){
    int balance = 0;
    pass = encrypt(pass);
    ofstream accArch("accounts.txt", ios::app);
    if (!accArch){
        cout << "Error en el registro del usuario! , no se pudo abrir el archivo.";
    }else{
        if (verifyUser(user)){
            cout << "Error, usuario ya existe..." << endl;
            sleep(2);
            system("cls");
            return false;
        }else{
            accArch << user << "\t" << pass << "\t" << balance << endl;
            cout << "Usuario creado satisfactoriamente!" << endl;
            accArch.close();
            menu(user);
        }
    }
    accArch.close();
}
#include <iostream>
#include <fstream>

#include "encrypter.h"
#include "../userActions/verifyUser.h"

using namespace std;

void logInUser(string username, string pass){
    string user, password;
    if(verifyUser(username)) {
        ifstream archLeer("../utils/accounts.txt");
        archLeer >> user;
        while (!archLeer.eof()){
            archLeer >> password;
            password = decrypt(password);
            if (user == username && pass == password){
                cout << "Logueo exitoso como: " << user << endl ;
            }else{
                cout << "Contraseña incorrecta!";
            }
            archLeer >> user;
        }
        archLeer.close();
    }else{
        cout << "Error, usuario no existe." << endl;
    }
}
#include <iostream>
#include <fstream>

using namespace std;

bool verifyUser(string username){
    string user;
    ifstream archLeer("accounts.txt"); // arch
    archLeer >> user;
    while (!archLeer.eof()){
        if (user == username){
            archLeer.close();
            return true;
        }
        archLeer >> user;
    }
    archLeer.close();
    return false;
}
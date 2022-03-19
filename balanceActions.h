#include <iostream>
#include <fstream>

using namespace std;

int getBalance(string username){
    string user, pass;
    int balance;
    ifstream accounts("accounts.txt");
    accounts >> user;
    while (!accounts.eof()){
        accounts >> pass;
        accounts >> balance;
        if(username == user){
            return balance;
        }
        accounts >> user;
    }   
    accounts.close();
}
#include <iostream>

using namespace std;

string encrypt(string txt){
    for (int i = 0; i < 100 && txt[i] != '\0'; i++) { //Caesar Cypher Algorithm
        txt[i] = txt[i] + 2; // ASCII + 2
    }
    return txt;
}

string decrypt(string txt){
    for (int i = 0; i < 100 && txt[i] != '\0'; i++){
        txt[i] = txt[i] - 2;
    }
    return txt;
}
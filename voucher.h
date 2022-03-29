#include <iostream>
#include <fstream>

using namespace std;

void vouchers(string username){
    string userFrom, userTo, date;
    int quantity, count = 0;
    char resp = 's';
    ifstream transactions("transactions.txt");
    if(!transactions){
        cout << "Error interno!" << endl;
    }else{
        transactions >> userFrom;
        while(!transactions.eof() && (resp == 's'|| resp == 'S')){
            transactions >> userTo;
            transactions >> quantity;
            transactions >> date;
            if (username == userFrom){
                count++;
                system("cls");
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                cout << "| ID : " << count << "                     |" << endl;
                cout << "| FECHA: " + date << " |" << endl;
                cout << "| DESTINO: " + userTo << "        |" << endl;
                cout << "| CANTIDAD: " << quantity << "            |"<< endl;
                cout << "|____________________________|"<< endl;
                cout << "Desea ver el siguiente comprobante? s/n" << endl;
                cin >> resp;
            }
            transactions >> userFrom;
        }
        if(count == 0){
            cout << "No se han encontrado transacciones!" << endl;
        }else{
            cout << "No hay más comprobantes!" << endl;
        }
        transactions.close();
    }
}
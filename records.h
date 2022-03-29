#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;

string getDate(){
   time_t t = time(NULL);
   struct tm tiempoLocal = *localtime(&t);
   char fechaHora[70];
   char *formato = "%Y-%m-%d-%H:%M:%S";
   int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
   if (bytesEscritos != 0){
      return fechaHora;
   }
   return "ERROR";
}

void record(string userFrom, string userTo, int quantity){
   ofstream arch("transactions.txt", ios::app);
   if (!arch.is_open()){
      cout << "Error en registrar la transacción" << endl;
   }
   else{
      arch << userFrom << "\t" << userTo << "\t" << quantity << "\t" << getDate() << endl;
   }
   arch.close();
}

void searchTransactions(string username){
   string userFrom, userTo, date;
   int quantity, count = 0;
   ifstream arch("transactions.txt");
   if (!arch.is_open()){
      cout << "Error interno!";
   }
   else{
      arch >> userFrom;
      while (!arch.eof()){
         arch >> userTo;
         arch >> quantity;
         arch >> date;
         if (username != userFrom){
            cout << "RECIBIDO DE: " + userFrom + " CANTIDAD: $" << quantity << " FECHA: " << date << endl;
            count++;
         }
         if (username == userFrom){
            cout << "ENVIADO A: " + userTo + " CANTIDAD: $" << quantity << " FECHA: " << date << endl;
            count++;
         }
         arch >> userFrom;
      }
      if (count == 0){
         cout << "No se han encontrado transacciones!" << endl;
      }
   }
   arch.close();
}
#include <iostream>
#include <fstream> 


using namespace std;
 
/* Recibe: string1:"Recarga" string2:"3102391200"  string3:"3000"
   Procedimiento: Abre el archivo trasnsactions.txt y escribe la transacción
*/
void record(string userFrom, string userTo, int quantity){
   ofstream arch("transactions.txt", ios::app);
   if(!arch.is_open()){
      cout << "Error en registrar la transacción" << endl;
   }else{
      arch << userFrom << "\t" << userTo << "\t" << quantity;
   }
   arch.close();
}
/* No recibe nada
   Procedimiento: Busca las transacciones donde el número se ha visto involucrado e imprime
   en pantalla la información de la transacción
*/
void searchTransactions(string username){
   ifstream arch("transactions.txt");
   string userFrom, userTo;
   int quantity, count = 0;
   if(!arch.is_open()){
      cout << "Error interno!";
   }else{
      arch >> userFrom;
      while(!arch.eof()){
         arch >> userTo;
         arch >> quantity;
         if(username != userFrom){
            cout << "RECIBIDO DE: " + userFrom + " CANTIDAD: $" << quantity << endl;
            count++;
         }
         if(username == userFrom){
            cout << "ENVIADO A: " + userTo + " CANTIDAD: $" << quantity << endl;
            count++;
         }
         arch >> userFrom;
      }
      if(count == 0){
         cout << "No se han encontrado transacciones!" <<endl;
      }
   }
   arch.close();
}
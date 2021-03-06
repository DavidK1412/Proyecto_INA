#include <iostream>
#include <fstream>
#include <string>

using namespace std;
 
string user;
string loansInfo[3][6];

void fillArray(){    
    int i = 0;
    ifstream loans("loans.txt");
    if(loans){
        loans >> loansInfo[i][0];
        while(!loans.eof()){
            if(loansInfo[i][0] == user){
                loans >> loansInfo[i][1];
                loans >> loansInfo[i][2];
                loans >> loansInfo[i][3];
                loans >> loansInfo[i][4];
                loans >> loansInfo[i][5];
                i++;
            }
            loans >> loansInfo[i][0];
        }
        loans.close();
    }   
}

void printArray(string username){
    int opc;
    user = username;
    fillArray();
    cout << "Prestamo #" << "\t" << "Usuario" << "\t" << "Valor" << "\t" << "Meses" << "\t" << "Añadido ( > mes 4)" << "\t" << "Interes" << "\t" << "Cuota" <<endl;
    for(int i = 0; i < 3; i++){
        cout << i+1 << "." << "\t";
        for(int j = 0; j < 6; j++){
            cout << loansInfo[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Ingrese cualquier numero para continuar al menu" << endl;
    cin >> opc;
}
int verifyLoans(){
    string username;
    int loanValue, months, plus, interest, fee, count = 0;
    ifstream loans("loans.txt");
    loans >> username;
    while(!loans.eof()){
        loans >> loanValue;
        loans >> months;
        loans >> plus;
        loans >> interest;
        loans >> fee;
        if (username == user){
            count++;
        }
        loans >> username;
    }
    loans.close();
    return count;
}

void createLoan(int loanValue, int months){
    int plus = 0, entry;
    if(months > 4){
        plus = 3000*(months-4);
    }
    int interest = (loanValue *0.03), fee = (loanValue/months) + interest + plus;
    cout << "Su prestamo será de: $" << loanValue << " con un valor añadido de: $" << plus << " en un plazo de: " << months << " meses. ";
    cout << "Con un interes mensual de: $" << interest << " mensual,  quedando cada cuota de $ " << fee << endl;
    ofstream loans("loans.txt", ios::app);
    if(loans){
        loans << user << "\t" << loanValue << "\t" << months << "\t" << plus << "\t" << interest << "\t" << fee <<endl;
        addBalance(user, loanValue);
        loans.close();
    }
    cout << "Para volver menu, escriba cualquier numero" << endl;    
    cin >> entry;
}

void loanMenu(string username){
    user = username;
    int maxLoan = getBalance(username)*0.30, loanValue, months;
    char resp = 'n';
    system("cls");
    cout << "Bienvenido al sistema de prestamos: " << username << endl;
    cout << "Recuerde que sólo se puede tener un máximo de 3 prestamos, cada prestamo equivalente a un 30% del saldo que tiene al momento de pedirlo, y tendrá un interes de un 3% al mes." << endl;
    cout << " - IMPORTANTE: Por cada mes después de los 4 meses, se añadirán $3.000 al total de pago" << endl;
    cout << "Si desea continuar con el proceso, escriba la letra s" << endl;
    cin >> resp;
    if(verifyLoans() <= 3){
        if(resp == 's' || resp == 'S'){
            cout << "Basados en su saldo actual, el valor máximo de su prestamo es de: $" << maxLoan << endl << "Ingrese el valor de su prestamo: ";
            cin >> loanValue;
            while(loanValue > maxLoan || loanValue <=0){
                cout << "Error!, cantidad de prestamo invalida. Ingrese el valor nuevamente. " << endl;
                cin >> loanValue;
            }
            cout << "Ingrese los meses que tomara su prestamo: ";
            cin >> months;
            while(months == 0){
                cout << "Error!, la cantidad de meses debe ser diferente a 0 " << endl;
                cin >> months;
            }
            createLoan(loanValue, months);
            record("PRESTAMO", username, loanValue);
        }
    }else{
        cout << "No puede pedir más prestamos, ya tiene 3";
    }
    
}
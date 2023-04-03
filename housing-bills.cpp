#include <iostream> 
#include <iomanip> 
#include <string> 

using namespace std; 

int main() 
 { 
    double rOrM, phoneBill, utilities, cable, total; 
    cout << "Housing bills calculator from @CodeMaster7000 Studios." << endl << endl; 
    cout << "Enter your monthly rent/mortgage payment: USD$" ;  
    cin >> rOrM; 
    cout << "Enter your monthly phone payment: USD$"; 
    cin >> phoneBill; 
    cout << "Enter your monthly utility payment: USD$"; 
    cin >> utilities; 
    cout << "Enter your monthly cable payment: USD$"; 
    cin >> cable; 
    total = (rOrM + phoneBill + utilities + cable); 
    cout << endl;
    cout << setprecision(2) << fixed; 
    cout << "The monthly cost of these expenses is: USD$" << total << endl; 
    total = total * 12; 
    cout << "The annual cost of these expenses is: USD$" << total << endl; 
    system("pause"); 
    return (0); 
 }

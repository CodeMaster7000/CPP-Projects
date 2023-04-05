#include <iostream>
using namespace std;
void f(double x)
{
    double func;
    func = ; //Enter function here
    cout << "Function output: " << func << endl;
}
int main()
{
    double number;
    string repeat;
    do
    {
        cout << "Input a number: ";
        cin >> number;
        f(number);
        cout << "Would you like to enter a new calculation? (Y/N)";
        cin >> repeat;
    } while (repeat == "Y" || repeat == "y");
    return 0;
}

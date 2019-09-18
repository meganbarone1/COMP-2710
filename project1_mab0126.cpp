/**
 * Megan Barone
 * mab0126
 * project1_mab0126.cpp
 * Compile using g++: g++ project1_mab0126.cpp -o project1_mab0126
 */

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;
long double loanAmt, interestRate, paymentAmt, monthlyInterest, interest, principal, totalInterest;

int main() {
    cout << "Loan Amount: ";
    cin >> loanAmt;
    cout << "Interest Rate (% per year): ";
    cin >> interestRate;
    cout << "Monthly Payments: ";
    cin >> paymentAmt;
    monthlyInterest = interestRate / 12.0;
    interest = (loanAmt * (monthlyInterest / 100));
    if (interest > paymentAmt) {
        cout << "Interest is greater than monthly payment." << endl;
        exit(1);
    }
    cout << "*****************************************************************" << endl;
    cout << "        Amortization Table" << endl;
    cout << "*****************************************************************" << endl;
    cout <<"Month   Balance     Payment     Rate       Interest    Principal " << endl;
    cout << left << "0       $" << setprecision(2) << fixed << setw(10) << loanAmt <<" N/A         N/A        N/A         N/A" << endl;
    int month = 0;
    while (loanAmt >= paymentAmt) {
        interest = loanAmt * (monthlyInterest / 100);
        totalInterest += interest;
        principal = paymentAmt - interest;
        loanAmt = loanAmt - principal;
        month++;
        cout << setw(7) << left << month << " $"  << setprecision(2) << fixed << setw(10) << loanAmt << " $" << setw(10) << paymentAmt << " ";
        cout << setw(10) << resetiosflags(ios::fixed) << left << monthlyInterest;
        cout << left  << fixed << " $"  << setprecision(2) << setw(10) << left << interest << " $"  << setw(10) << principal << endl;
    }
    if (loanAmt > 0) {
        interest = loanAmt * (monthlyInterest / 100);
        principal = loanAmt;
        loanAmt = loanAmt - principal;
        paymentAmt = principal + interest;
        totalInterest += interest;
        month++;
        cout << setw(7) << left << month << " $"  << setprecision(2) << fixed << setw(10) << loanAmt << " $" << setw(10) << paymentAmt << " ";
        cout << setw(10) << resetiosflags(ios::fixed) << left << monthlyInterest;
        cout << left  << fixed << " $"  << setprecision(2) << setw(10) << left << interest << " $"  << setw(10) << principal << endl;
        if ((loanAmt + interest) > paymentAmt) {
            principal = paymentAmt - interest;
            loanAmt = loanAmt - principal;
            totalInterest += interest;
            month++;
            cout << setw(7) << left << month << " $"  << setprecision(2) << fixed << setw(10) << loanAmt << " $" << setw(10) << paymentAmt << " ";
            cout << setw(10) << resetiosflags(ios::fixed) << left << monthlyInterest;
            cout << left  << fixed << " $"  << setprecision(2) << setw(10) << left << interest << " $"  << setw(10) << principal << endl;
        }

    }
    cout << "*****************************************************************\n" <<endl;
    cout << "It takes " << month << " months to pay off the loan." <<endl;
    cout << "Total interest paid is: $" << totalInterest <<endl;
    return 0;
}

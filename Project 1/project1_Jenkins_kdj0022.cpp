/* project1_Jenkins_kdj0022.cpp
 * Kelci Jenkins
 * Auburn UserID: kdj0022
 * fileName: project1_Jenkins_kdj0022
 * Brief Description
 * Help sources:
 * Spoke with Traevon Wright about the use of cin.clear(), cin.fail(), and formatting issues.
 * Used given lecture slides to better understand concepts.
 * Used Stack Overflow to understand how to properly exit while loops. https://stackoverflow.com/questions/872996/immediate-exit-of-while-loop-in-c
 * Used https://hallertau.cs.gsu.edu/exit.txt to help with the compilation errors I was getting on the AU server when using exit()
 */
#include <iostream>
#include <cstring> // taken from link to help with exit()
#include <cstdlib> // taken from link to help with exit()

using namespace std;

int main() {
    // Variable Initilization
    double loan = 0;
    double interestRate = 0;
    double monthlyPaid = 0;
    double interestRateC = 0;
    double interestTotal = 0;
    int currentMonth = 0;
    double principle = 0;
    
    // Currency Formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // USER INPUT
    // NOTE: For valid input, the loan, interest, and monthly payment must
    // be positive. The monthly payment must also be large enough to
    // terminate the loan.
    
    while (loan <= 0){
        cout << "\nLoan Amount: ";
        cin >> loan;
        cin.clear();
        
        if (loan <= 0 || cin.fail()){
            exit(0);
        }
    }
    
    while (interestRate <= 0){
        cout << "Interest Rate (% per year): ";
        cin >> interestRate;
        cin.clear();
        
        if (interestRate <= 0 || cin.fail()) {
            exit(0);
        }
    }
    
    
    // GET PROPER INTEREST RATES FOR CALCULATIONS
    interestRate /= 12;
    interestRateC = interestRate / 100;
   
    while (monthlyPaid <= 0){
        cout << "Monthly Payments: ";
        cin >> monthlyPaid;
        cin.clear();
        
        if (monthlyPaid <= 0 || cin.fail()) {
            exit(0);
        }
    }
    
    cout << endl;
    
    // AMORTIZATION TABLE
    cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
    // LOOP TO FILL TABLE
    while (loan > 0) {
        double payment = loan * interestRateC;
            if (currentMonth == 0) {
            cout << currentMonth++ << "\t    $" << loan;
            if (loan < 1000) cout << "\t"; // Formatting MAGIC
                cout << "\t" << "N/A  \tN/A    \tN/A    \t\tN/A\n";

        }
        else {
            interestTotal += payment;
            if (loan * (1 + interestRateC) < monthlyPaid) {
                monthlyPaid= loan + payment;
                principle = monthlyPaid - payment;
                loan -= principle;
              }
            else if (loan * (1 + interestRateC) >= monthlyPaid) {
              principle = monthlyPaid - payment;
              loan -= principle;
            }
            cout << currentMonth++ << "\t    $" << loan;
            if (loan < 1000) cout << "\t";
            cout << "\t$" << monthlyPaid << "\t$" << interestRate << "\t$" << payment << "\t\t$" << principle << "\n";
            }
          }
              
           cout << "****************************************************************\n";
           cout << "\nIt takes " << --currentMonth << " months to pay off "
                << "the loan.\n"
                << "Total interest paid is: $" << interestTotal;
           cout << endl << endl;
           return 0;
          }


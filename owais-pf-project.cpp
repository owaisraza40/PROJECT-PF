#include <iostream>
#include <iomanip>
using namespace std;

double calculateTax (double currentBalance , double annualRate)
{
  return (currentBalance * annualRate)/1200.0;

}

void displayFinalReport(double finalBalance, double deposits[], double withdrawals[], double taxes[], int totalMonths)
{

  double totalDeposits = 0;
  double totalWithdrawals = 0;
  double totalTax = 0;
  for (int i = 0; i < totalMonths ; i++ ){
    totalDeposits += deposits [i];
    totalWithdrawals += withdrawals [i];
    totalTax += taxes [i];
  }

  cout<<"\n\n";
    cout << "-----------------------------------------" << endl;
    cout << "          FINAL ACCOUNT SUMMARY          " << endl;
    cout << "-----------------------------------------" << endl;

    cout << "Final Balance       : " << finalBalance << endl;     
    cout << "Total Deposited     : " << totalDeposits << endl;  
    cout << "Total Withdrawn     : " << totalWithdrawals << endl;
    cout << "Total Tax Deducted  : " << totalTax << endl;       
    cout << "-----------------------------------------" << endl;

}

int main (){
    const int max_month = 120;
    
    double deposits[max_month];
    double withdrawals[max_month];
    double taxes[max_month];

    double annualTaxRate;
    double initialBalance;
    int totalMonths;

    cout << fixed << setprecision(2);



    cout << "=========================================" << endl;
    cout << "   SAVINGS ACCOUNT MANAGEMENT SYSTEM   " << endl;
    cout << "=========================================" << endl;
    
    cout << "Name       : Muhammad Owais Raza" << endl;
    cout << "Department : Data Science (BSDS)" << endl;
    cout << "ID No      : 2540218" << endl;

    cout << "Please provide the following details:\n" << endl;
    cout << "Annual Tax Rate (%)        : ";
    cin >> annualTaxRate;

    cout << "Initial Account Balance   : ";
    cin >> initialBalance;

    cout << "Number of Months to Simulate : ";
    cin >> totalMonths;


    while (totalMonths > max_month  || totalMonths <=0)
    {
      cout <<"\n Invalid number of months !"<<endl;
      cout <<"please enter a value between 1 and "<<max_month<<endl;

      cout<<"Try again ";
      cin >> totalMonths;

    }
    for (int month =0 ; month<totalMonths ; month ++){
        cout << "\n------------------ MONTH " << month + 1 << " ------------------\n";
        cout << "Deposit Amount     : ";
        cin >> deposits[month];


        

        while (deposits[month] < 0 ){
          cout <<"Invalid input! Deposit cannot be negative."<<endl;
          cout<<"Please enter again positive amount "<<endl;
          cin >> deposits[month];
        }

        initialBalance += deposits[month];



        cout << "Withdrawal Amount  : ";
        cin >> withdrawals[month];


        

        while (withdrawals[month] < 0 || withdrawals[month] > initialBalance) {
        cout << "Invalid input! Withdrawal cannot be negative or exceed balance." << endl;
        cout << "Please enter again: ";
        cin >> withdrawals[month];
}

        initialBalance -= withdrawals[month];

        taxes[month]= calculateTax(initialBalance , annualTaxRate);
        initialBalance -= taxes[month];
        cout << "Tax Deducted       : " << taxes[month] << endl;
        cout << "Remaining Balance  : " << initialBalance << endl;
        cout << "--------------------------------------------\n";


    }

    displayFinalReport (initialBalance , deposits, withdrawals, taxes , totalMonths);

    return 0;

}
#include <iostream>
#include <iomanip>
using namespace std;

int main (){
    const int max_month = 120;
    
    double deposits[max_month];
    double withdrwals[max_month];
    double taxes[max_month];

    double annualTaxRate;
    double intialBlance;
    int totalMonths;



    cout<<"-----------------------------------------"<<endl;
    cout<<"    SAVINGS ACCOUT MANAGEMENT SYSTEM     "<<endl;
    cout<<"-----------------------------------------"<<endl;

    cout <<"Enter Annual tax Rate (in %):"<<endl;
    cin>>annualTaxRate;


    cout<<"Enter the Intial (starting) balance :"<<endl;
    cin>>intialBlance;

    cout<<"Enter the Total Number of months to simulate "<<endl;
    cin>>totalMonths;

    while (totalMonths > max_month  || totalMonths <=0)
    {
      cout <<"\n Invalid number of months !"<<endl;
      cout <<"please enter a value between 1 and "<<max_month<<endl;

      cout<<"Try again ";
      cin >> totalMonths;

    }
    for (int month =0 ; month<totalMonths ; month ++){
        cout <<"Enter the amount desposite this months "<<month<<endl;
        cin >> deposits[month];

        intialBlance += deposits[month];

        cout<<"--------------------------------------"<<endl;

        cout <<"Enter the amount Withdraw this month "<<month<<endl;
        cin>>withdrwals[month];

        intialBlance -= withdrwals[month];

        





    }
    




}
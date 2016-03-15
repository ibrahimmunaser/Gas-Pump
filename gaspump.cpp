#include <iostream>
#include <unistd.h>


using namespace std;
///creating class for gaspump
class GasPump
    {
        ///declaring private variables
        private:
   int loading[100];
   double costGallon;
   double priceLoading;
   double gasLoading;
   char choice;
   double countGallons;
   double countPrice;



    ///declaring public variables
        public:
   int done;
   char decision;
   double amountDispensed;
   double amountCharged;
   double Calculate();

    };
///creating method to do calculations and prompts
double GasPump::Calculate()
{

    ///displaying prices of gas
   cout<<"\nCost Per-Gallon: \nRegular: $2.50\nPremium: $2.80\n ";
   cout<<"\nEnter (R) for Regular or (P) for Premium\n";
   cout<<"Enter choice: ";
   cin>>choice;
   ///checking what kind of gas they chose
   if (choice == 'R' || choice == 'r')
   {
      costGallon=2.50;
   }
   else if(choice == 'P' || 'p')
   {
      costGallon=2.80;
   }
   else
   {
      cout<<"Please ONLY Enter (R) for Regular or (P) for Premium\n";
   }

    ///enter amount of money

   cout<<"Enter Amount: ";
   cin>>amountCharged;
   amountDispensed=amountCharged/costGallon;
   cout<<"Amount Dispensed: \n"<<amountDispensed;
   cout<<"\nYour Gas Tank Will be Filled in 5 seconds!";
   cout<<"\nPlease wait";

    ///progress of gas and purchase going up
   priceLoading=amountCharged*.20;
   gasLoading=amountDispensed*.20;
   countGallons=0;
   countPrice=0;

    ///a console progress bar for gas and purchase
   while(countPrice <= amountCharged)
   {
      cout <<"\nPurchase: $" <<countPrice<<"\r"<<flush;
      cout<<"\nGallons: "<<countGallons<<"\r\n"<<flush;
      countPrice+=priceLoading;
      countGallons+=gasLoading;
      sleep(1);
   }
   ///asking customer if they are done with their purchase
   cout<<"\nAre you done with your purchase(Y or N)?";
   cin>>decision;
}

int main()
{
    ///creating object
   GasPump gas;

   ///do-while loop to decide weather to continue purh
   while(gas.done != -1)
   {
      gas.done=0;
      gas.Calculate();

      if (gas.decision=='Y' || gas.decision=='y')
      {
         gas.done=1;
         cout<<"\nThank You!\n";
      }
      else if (gas.decision=='N' || gas.decision=='n')
      {
         gas.done=0;
      }
   }


   return 0;

}




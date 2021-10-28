#include<iostream>
#include<string>
#include <stdlib.h> //rand
using namespace std;
// declaration of the pet class
class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      int happy;            // private data member
      int energy;
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void print();         // public member function
      void nap();
      int check_health();   // public member function
};
   bool loopbreaker; 
int main()
{
   pet pet1;
   int choice;
   int health_check;
   bool loopbreaker; 
   do{
       pet1.print();
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Nap (3)\n Exit (0) \n";
       cin >> choice;
       switch(choice){
        case 0:
        loopbreaker = true;
        break;
       case 1:
           pet1.play();
           break;
       case 2:
           pet1.feed();
           break;
        case 3:
            pet1.nap();
            break;
      }
      health_check = pet1.check_health();
   }while(choice != 0 && health_check != 1 && loopbreaker == false);
   cin.ignore();
   cout << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
} 

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     cout << "Pet's name? (One word) ";
     cin >> name;
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cin >> choice;
    switch(choice){
    case(1):
         happy += 10;
         hunger += 5;
         energy -= 10;
         break;
    case(2):
         happy += 5;
         hunger += 1;
         energy += 1;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    int a = rand() % 3 + 1; //range of 1-3
    switch(a)
    {
        case 1:
        cout << "\ntastee\n";
        hunger -= 5;
        break;

        case 2:
        cout << "\ndelicious\n";
        hunger -= 5;
        break;

        case 3:
        cout << "\nscrumptious\n";
        hunger -= 5;
        break;
    default: //just in case I messed up 
    cout << "\nMMM, Yummy!\n";
    hunger -= 5;
    }

}

/* Member function print(), prints information about a pet. */
void pet::print(){
    if(hunger <= 100 && hunger > 85)
    {
        cout << name << " is about to starve." << endl << "Hunger: "<<  hunger << endl;
    }
    else if(hunger <= 85 && hunger > 60)
    {
        cout << name << " is very hungry." << endl << "Hunger: "<<  hunger << endl;        
    }
    else if(hunger <= 60 && hunger > 40)
    {
        cout << name << " wishes for dinner." << endl << "Hunger: "<<  hunger << endl;
    }
    else if(hunger <= 30 && hunger > 20)
    {
        cout << name << " could use a snack." << endl << "Hunger: "<<  hunger << endl;
    }
    else if(hunger <= 20 && hunger > 10)
    {
        cout << name << " isn't very hungry." << endl << "Hunger: "<<  hunger << endl;       
    }
    else if(hunger <= 10 && hunger > 0)
    {
        cout<< name << " doesn't need any food right now." << endl << "Hunger: "<< hunger << endl;
    }
    else if(hunger > 100) // I added this not knowing that there was a check health function, so thats fun.
    {
        cout << name << " has starved" << endl;
        cout << "Try again? y/n)"<< endl;
        string a;
        cin >> a;
        if (a == "n")
        {
            loopbreaker = true;
            cout << "Goodbye" << endl; 
        }

    }
    cout << "Happy: " << happy << endl;
}

void pet::nap()
{
    cout << "sleepy time" << endl;
    energy += 20;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
    }
    return 0;
}
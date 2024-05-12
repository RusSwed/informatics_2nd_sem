#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

class Car{
    int Number_Wheels;
    double Mileage;
    double Tank_Capacity;
    double Speed;
    double Engine_Consumtion;
    double Engine_Power;
    double Time;
    string name;
public:
    Car(){{cout << "Vehicle created" << endl;}};
    Car(int amount_car, Car* Cars);
    ~Car(){{cout << "Vehicle deleted" << endl;}}
    double Calculation_Speed(){return sqrt(Engine_Power)*(70/Number_Wheels-2.5);}
    double Calculation_Engine_Consumption(){return pow(Engine_Power, 1/3)+sqrt(Engine_Power)-6.25;}
    double Calculation_Travel_Time(double Race_Length){return (Race_Length/Speed);}
    double Calculation_Number_GasStations(){return ((Mileage*(Engine_Consumtion)/100))/Tank_Capacity;}
    string get_name(){return name;}
    void menu();
    void output(int amount_car, Car* Cars);
    int chek_menu = 0;
};

void new_page()
{
    for(int i = 0; i < 100; i++)
    {
        cout << "\n";
    }
}

void IGNORE(int i)
{
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Enter Number!" << endl;
    }
}

Car::Car(int amount_car, Car* Cars)
{
    int chek = 0;
    cout << "Enter name vehicle:" << endl;
    cin >> Cars[amount_car].name;
    while(chek == 0)
    {
        cout << "Enter amount wheels:(minimal - 3, maximum - 24" << endl;
        cin >> Cars[amount_car].Number_Wheels;
        IGNORE(Cars[amount_car].Number_Wheels);
        if(Cars[amount_car].Number_Wheels >= 3 && Cars[amount_car].Number_Wheels <= 24)
        {
            chek = 1;
        }
        else
        {
            cout << "Enter try again" << endl;
        }
    }
    chek--;
    while(chek == 0)
    {
         cout << "Enter Tank Capacity:" << endl;
         cin >> Cars[amount_car].Tank_Capacity;
         IGNORE(Cars[amount_car].Tank_Capacity);
         if(Cars[amount_car].Tank_Capacity > 0)
         {
             chek = 1;
         }
         else
         {
             cout << "Enter try again" << endl;
         }
    }
    chek--;
    while(chek == 0)
    {
         cout << "Enter Engine Power:" << endl;
         cin >> Cars[amount_car].Engine_Power;
         IGNORE(Cars[amount_car].Engine_Power);
         if(Cars[amount_car].Engine_Power > 0)
         {
             chek = 1;
         }
         else
         {
             cout << "Enter try again" << endl;
         }
    }
}


void Car::output(int amount_car, Car* Cars)
{
    Cars[amount_car].Speed = Cars[amount_car].Calculation_Speed();
    Cars[amount_car].Engine_Consumtion = Cars[amount_car].Calculation_Engine_Consumption();

    cout << "Car: " << Cars[amount_car].name << endl;
    cout << "Count Wheels: " << Cars[amount_car].Number_Wheels << endl;
    cout << "Engine Power: " << Cars[amount_car].Engine_Power << endl;
    cout << "Speed: " << Cars[amount_car].Speed << endl;
    cout << "Engine Consumtion:" << Cars[amount_car].Engine_Consumtion << endl;
}


void menu(int amount_car, Car *Cars)
{
    int exit = 0;
    int press = 0;
    int chek = 0;
    int i = -1;
    int choise;
    double Length_Route;
     while(exit == 0)
{
    cout << "1 - Enter data about vehicles" << endl;
    cout << "2 - Database vehicles" << endl;
    cout << "3 - Enter the length of the route" << endl;
    cout << "4 - Calculation of the route passage" << endl;
    if(Cars[amount_car].chek_menu == 1)
    {
        cout << "5 - Output of the results of the passage of the route" << endl;
        cout << "0 - Exit the program" << endl;
    }
    else
    {
        cout << "0 - Exit the program" << endl;
    }
    cin >> choise;
    IGNORE(choise);
    switch(choise)
    {
        case 1:
            new_page();
            cout << "Enter number Vehicle:" << endl;
            cin >> i;
            if(i <= amount_car && i > 0)
             {
                 i--;
                 Car(i, Cars);
             }
             else
            {
                    cout << "This Vehicle no in database" << endl;
            }
        break;
        case 2:
            new_page();
            if(i >= 0)
            {
                cout << i << endl;
                cout << "Enter number Vehicle:" << endl;
                cin >> i;
                if(i <= amount_car && i > 0)
                 {
                     i--;
                     Cars[amount_car].output(i, Cars);
                 }
                 else
                 {
                        cout << "This Vehicle no in database" << endl;
                 }
            }
            else
            {
                cout << "No Vehicle in database" << endl;
            }
            break;
        case 3:
            new_page();
            while(chek == 0)
            {
                cout << "Enter the length of the route:" << endl;
                cin >> Length_Route;
                IGNORE(Length_Route);
                if(Length_Route > 0)
                {
                    chek = 1;
                }
                else
                {
                    cout << "Enter try again" << endl;
                }
            }
            chek--;
            break;
        case 4:
            break;
        case 0:
            cout << "If you want close programs press 1\n";
            cin >> press;
            IGNORE(press);
            if(press == 1)
            {
                exit = 1;
            }
            else
            {
                exit = 0;
            }
        break;

        case 5:
        cout << "Yes" << endl;
        break;
        default:
        cout<<"Error\n";
        break;
    }
}
}

int main()
{
    int size_array = -1;
    while(size_array <= 0)
    {
        cout << "How many vehicles do you want to create?" << endl;
        cin >> size_array;
        IGNORE(size_array);
        if(size_array <= 0)
        {
            cout << "Enter it again" << endl;
        }
    }
    Car *Cars = new Car[size_array];
    menu(size_array, Cars);
    delete [] Cars;
    return 0;
}



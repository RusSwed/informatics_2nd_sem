#include <iostream>
#include <math.h>
#include <string>

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
    void input();
    void output();
    int chek_menu = 0;
};

Car::Car(int amount_car, Car* Cars)
{
    cout << "Enter name vehicle:" << endl;
    cin >> Cars[amount_car].name;
    cout << "Enter amount wheels:" << endl;
    cin >> Cars[amount_car].Number_Wheels;
    cout << "Enter Tank Capacity";
    cin >> Cars[amount_car].Tank_Capacity;
    cout << "Enter Engine_Power";
    cin >> Cars[amount_car].Engine_Power;
}


void Car::output()
{
    Speed = Calculation_Speed();
    Engine_Consumtion = Calculation_Engine_Consumption();

    cout << "Car: " << name << endl;
    cout << "Count Wheels: " << Number_Wheels << endl;
    cout << "Engine Power: " << Engine_Power << endl;
    cout << "Speed: " << Speed << endl;
    cout << "Engine Consumtion" << Engine_Consumtion << endl;
}



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

void menu(int amount_car, Car *Cars)
{
    int exit = 0;
    int press = 0;
    int choise;
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
            int i;
            cin >> i;
            Car(i, Cars);
        break;
        case 2:
            int j;
            cin >> j;
            Cars[amount_car].output();
            break;
        case 3:
            break;
        case 4:

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



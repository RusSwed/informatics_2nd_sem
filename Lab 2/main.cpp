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
    Car();
    ~Car();
    double Calculation_Speed(){return sqrt(Engine_Power)*(70/Number_Wheels-2.5);}
    double Calculation_Engine_Consumption(){return pow(Engine_Power, 1/3)+sqrt(Engine_Power)-6.25;}
    double Calculation_Travel_Time(double Race_Length){return (Race_Length/Speed);}
    double Calculation_Number_GasStations(){return ((Mileage*(Engine_Consumtion)/100))/Tank_Capacity;}
    void menu();
    void input();
    void output();
    int chek_menu = 0;
};

Car::Car()
{
    cout << "C" << endl;
}


Car::~Car()
{
    cout << "D" << endl;
}

Car* add_car(Car *number, const int size_array)
{
     if (size_array == 0)
     {
        number = new Car[size_array + 1];
     }
     else
     {
        Car* tempNumber = new Car[size_array + 1];

         for (int i = 0; i < size_array; i++)
         {
            tempNumber[i] = number[i];
         }
         delete [] number;

         number = tempNumber;
     }
     return number;
}

void Car::input()
{
    cout << "Enter name car:" << endl;
    cin >> name;
    cout << "Enter Number Wheels:" << endl;
    cin >> Number_Wheels;
    cout << "Enter Tank Capacity:" << endl;
    cin >> Tank_Capacity;
    cout << "Enter Engine Power:" << endl;
    cin >> Engine_Power;
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


void Car::menu()
{
    cout << "1 - Enter data about vehicles" << endl;
    cout << "2 - Database vehicles" << endl;
    cout << "3 - Enter the length of the route" << endl;
    cout << "4 - Calculation of the route passage" << endl;
    if(chek_menu == 1)
    {
        cout << "5 - Output of the results of the passage of the route" << endl;
        cout << "0 - Exit the program" << endl;
    }
    else
    {
        cout << "0 - Exit the program" << endl;
    }
}

void IGNORE(int i);

int main()
{
    int size_array = 0;
    int exit = 0;
    int press = 0;
    int choise;
    Car *Vehiecle = nullptr;


    while(exit == 0)
{
    Vehiecle[size_array].menu();
    cin >> choise;
    IGNORE(choise);
    switch(choise)
    {
    case 1:
        add_car(Vehiecle, size_array);
        Vehiecle[size_array].input();
        size_array++;
        break;
    case 2:
        for(int i = 0; i < size_array; i++)
        {
            Vehiecle[i].output();
            cout << '\n';
        }
        break;
    case 3:
        break;
    case 4:
        Vehiecle[size_array].chek_menu = 1;
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



    return 0;
}

void IGNORE(int i)
{
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Enter Number!" << endl;
    }
}


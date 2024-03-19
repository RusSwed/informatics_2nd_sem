#include <iostream>

using namespace std;

class Car{
    int Number_Wheels;
    double Mileage;
    double Tank_Capacity;
    double Speed;
    double Engine_Power;
    double Time;
    string name;
public:
    Car();
    ~Car();
    double get_Speed();
    double Engine_Consumption();
    double Calculation_Travel_Time();
    int Calculation_Number_GasStations();
    void menu();
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


void Car::menu()
{
    cout << "1 - Enter data about vehicles" << endl;
    cout << "2 - Database vehicles" << endl;
    cout << "3 - Enter the length of the route" << endl;
    cout << "4 - Calculation of the route passage" << endl;
    if(chek_menu == 1)
    {
        cout << "5 - Output of the results of the passage of the route" << endl;
        cout << "6 - Exit the program" << endl;
    }
    else
    {
        cout << "5 - Exit the program" << endl;
    }
}

void IGNORE(int i);

int main()
{
    int  size_array = 5;
    int exit = 0;
    int press = 0;
    int choise;
    Car* Vehiecle = new Car[size_array];

    while(exit == 0)
{
    Vehiecle[size_array].menu();
    cin >> choise;
    IGNORE(choise);
    switch(choise)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        Vehiecle[size_array].chek_menu = 1;
        break;
    case 5:
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
    case 6:
        cout << "Yes" << endl;
    default:
        cout<<"Error\n";
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

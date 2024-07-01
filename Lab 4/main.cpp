#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <time.h>
#include <cstdlib>

using namespace std;


class Wheel
{
    enum Status{Unbroken, Broken};
    double mileage;
public:
    Status status;
    Wheel(){status = Unbroken; mileage = 0;}
};


class Engine
{
protected:
    double power;
    double consumption;
public:
    Engine(){power = 0; consumption = 0;}
};


class FuelSystem
{
protected:
    double tank_capacity;
    double current_fuel_balance;
public:
    FuelSystem(){tank_capacity = 0; current_fuel_balance = 0;}
};


class TransportVehicle: public Engine, public FuelSystem
{
    int amount_wheels;
    double start_speed;
    double current_speed;
    double time;
    double current_milleage;
    double number_refuel;
    int broken_wheels;
public:
    vector<Wheel> vec_wheel;
    string name;
    double pit_stop_time;


};
void menu(int i);

int main()
{
    srand(time(NULL));
    int checkMenu = 0;
    menu(checkMenu);
    return 0;
}


void menu(int i)
{
    cout << "1 - Add a new Vehicle" << endl;
    cout << "2 - Display information about Vehicles" << endl;
    cout << "3 - Enter the Length of the Route" << endl;
    cout << "4 - Calculate the Passage of the Route" << endl;
    if(i == 1)
    {
        cout << "5 - Display the Results of the Race" << endl;
    }
    cout << "0 - Exit" << endl;
}

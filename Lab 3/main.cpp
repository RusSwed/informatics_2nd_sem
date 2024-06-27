#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

class Wheel
{
    enum Status {Unbroken, Broken};
    Status status;
    double mileage;
public:
    Wheel()
    {
        status = Unbroken;
        mileage = 0;
    }

    void check_status_wheel(mileage)
    {

    }

    void updateMileage(double length_route)
    {
        mileage += length_route;
        check_status_wheel();
    }

};


class Engine
{
    double power;
    double consumption;
public:
    Engine()
    {
        power = 0;
        consumption = 0;
    }

    double calculateConsumption()
    {

    }
};


class FuelSystem
{
    double tank_capacity;
    double current_fuel_balance;
public:
    FuelSystem()
    {
        tank_capacity = 0;
        current_fuel_balance = 0;
    }

    double updateFuel(double fuel)
    {
        current_fuel_balance = fuel;
    }
};

class TransportVehicle
{
    string name;
    double current_mileage;
    int number_wheels;
    Engine engine;
    FuelSystem fuelsystem;
    Wheel* wheels;
public:
    TransportVehicle()
    double calculateSpeed();
    void travel();
};

void menu(int i)
{
    cout << "1 - New Vehicle" << endl;
    cout << "2 - Vehicle Data" << endl;
    cout << "3 - Enter the length of the route" << endl;
    cout << "4 - Calculate the route passage" << endl;
    if(i == 1)
    {
        cout << "5 - Output of the route results" << endl;
    }
    cout << "0 - Exit" << endl;
}


int main()
{
    return 0;
}

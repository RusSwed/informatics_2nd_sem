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
    double mileage_wheel;
public:
    Status status;
    Wheel(){status = Unbroken; mileage_wheel = 0;}
};


class Engine
{
protected:
    double power;
    double consumption;
public:
    Engine(){power = 0; consumption = 0;}
    double calculateConsumption(double Engine_Power)
    {
        return fabs(pow(Engine_Power, 1/3)+sqrt(Engine_Power)-6.25);
    }
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
    double mileage;
    double current_mileage;
    double number_refuel;
    int broken_wheels;
public:
    vector<Wheel> vec_wheel;
    string name;
    double pit_stop_time;
    TransportVehicle()
    {
        time = number_refuel = pit_stop_time = current_mileage = mileage = 0;
        broken_wheels = 0;
    }

    friend istream &operator >> (istream &stream, TransportVehicle& Vehicle)
    {
        cout << "Enter Vehicle Name: " << endl;
        stream >> Vehicle.name;
        cout << "Enter Number Wheels: " << endl;
        stream >> Vehicle.amount_wheels;
        for(int i = 0; i < Vehicle.amount_wheels; i++)
        {
            Wheel wheel;
            Vehicle.vec_wheel.push_back(wheel);
        }
        cout << "Enter Tank Capacity: " << endl;
        stream >> Vehicle.tank_capacity;
        cout << "Enter Engine Power: " << endl;
        stream >> Vehicle.power;
        Vehicle.current_fuel_balance = Vehicle.tank_capacity;
        Vehicle.consumption = Vehicle.calculateConsumption(Vehicle.power);
        Vehicle.CalculateSpeed();
        return stream;
    }


    friend ostream &operator << (ostream& stream, TransportVehicle& Vehicle)
    {
        stream << "Name: " << Vehicle.name << endl;
        stream << "Number Wheels: " << Vehicle.amount_wheels << endl;
        stream << "Broken Wheels: " << Vehicle.broken_wheels << endl;
        stream << "Speed: " <<  Vehicle.start_speed << endl;
        stream << "Tank Capacity: " << Vehicle.tank_capacity << endl;
        stream << "Current Fuel Balance: " << Vehicle.current_fuel_balance << endl;
        stream << "Consumption: " << Vehicle.consumption << endl;
        stream << "Mileage: " << Vehicle.mileage << endl;
        return stream;
    }

    void CalculateSpeed()
    {
        start_speed =  fabs(sqrt(power) * ((70 / double(amount_wheels)) - 2.5));
    }

};
void menu(int i);
void new_page();

int main()
{
    srand(time(NULL));
    int checkMenu = 0;
    int exitMenu = 0;
    int press = 0;
    int number_circles;
    double Length_Route = 0;
    vector<TransportVehicle> Vehicle;
    while(exitMenu == 0)
    {
        menu(checkMenu);
        int choise;
        cin >> choise;
        switch(choise)
        {
        case 0:
            {
                cout << "If you want close program press 1" << endl;
                cin >> press;
                if(press == 1)
                {
                    exitMenu = 1;
                }
                break;
            }
        case 1:
            {
                new_page();
                TransportVehicle addcar;
                cin >> addcar;
                Vehicle.push_back(addcar);
                break;
            }
        case 2:
            {
                new_page();
                for(int i = 0; i < Vehicle.size(); i++)
                {
                    cout << Vehicle[i];
                    cout << '\n' << endl;
                }
                break;
            }
        case 3:
            {
                cout << "Enter the Number of Circles: " << endl;
                cin >> number_circles;
                cout << "Enter the Length of the Route: " << endl;
                cin >> Length_Route;
                break;
            }
        default:
            {
                cout << "Error, Try Again!" << endl;
            }
        }
    }
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


void new_page()
{
    for(int i = 0; i < 100; i++)
    {
        cout << '\n' << endl;
    }
}

#include <iostream>
#include <math.h>
#include <string.h>
#include <time.h>
#include <cstdlib>

using namespace std;
int amount_car = 0;

double exponentialRand(double lambda) {
    double u = rand() / (RAND_MAX + 1.0);
    return -log(1 - u) / lambda;
}


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

    void check_status_wheel(double length_route)
    {
        if(mileage >= 1 && length_route >= 1)
        {
            int lambda = (int)length_route;
            for(int i = (int)mileage; i <= ((int)mileage + lambda); i++)
            {
                 double sample = exponentialRand(i);
                 if(sample < 0.0005)
                {
                    status = Broken;
                    mileage += i;
                    break;
                }
            }
        }

    }

    double getWheelMileage() const {return mileage}
    void output()
    {
        string status_wheel;
        if(status == Unbroken)
        {
            status_wheel = "Unbroken";
        }
        else
        {
            status_wheel = "Broken";
        }

        cout << "Wheel Status: " << status_wheel << " Mileage: " << mileage << endl;
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
        return fabs(pow(Engine_Power, 1/3)+sqrt(Engine_Power)-6.25);
    }

    void output()
    {
        cout << "Engine Power: " << power << endl;
        cout << "Engine Consumption: " << consumption << endl;
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

    void output()
    {
        cout << "Tank Capacity: " << tank_capacity << endl;
        cout << "Current Fuel Balance: " << current_fuel_balance << endl;
    }
};

class TransportVehicle: public Engine, public FuelSystem
{
    string name;
    double current_mileage;
    int number_wheels;
    double start_speed;
    double current_speed
public:
    Wheel* wheels;
    TransportVehicle(string vehicle_name)
    {
        Set_name(vehicle_name);
        cout << "Enter number of wheels for vehicle: ";
        cin >> number_wheels;
        while ( number_wheels <= 0)
        {
            cout << "Error! Please enter a positive integer for the number of wheels: ";
            IGNORE(number_wheels);
        }

        wheels = new Wheel[number_wheels];

        for (int i = 0; i < number_wheels; i++) {
            wheels[i] = Wheel();
        }

        cout << "Enter the power of the car:\t";
        double Cpower;
        getInput(&Cpower);
        speed_s=NULL;
        while ( Cpower <= 0) {
            cout << "Error! Please enter a positive number for the power: ";
            getInput(&Cpower);
        }
        power = Cpower;

        cout << "Enter the Volume of the tank:";
        double Volume_tank;
        getInput(&Volume_tank);
        while (Volume_tank <= 0) {
            cout << "Error! Please enter a positive number for the volume: ";
            getInput(&Volume_tank);
        }
        volume= Volume_tank;
        current_volume=Volume_tank;
        Fuel_consumption=calculating_fuel_consumption(power);
        calculating_speed();


    }
    double calculateCurrentSpeed();
    double calculateStartSpeed(){return fabs(sqrt(Engine_Power) * ((70 / double(Number_Wheels)) - 2.5));}
    void travel();
};

void new_page()
{
    for(int i = 0; i < 100; i++)
    {
        cout << "\n";
    }
}


int IGNORE(int i)
{
    int check = 0;
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Enter Number!" << endl;
    }
    if(i > 0)
    {
        check = 1;
    }
    else
    {
        cout << "Error, Try Again" << endl;
    }
    return check;
}

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
    srand(time(NULL));
    TransportVehicle *Vehicle = nullptr;
    int exit = 0;
    int results = 0;
    int press = 0;
    while(exit == 0)
    {
        menu(results);
        int choise;
        cin >> choise;
        IGNORE(choise);
        switch(choise)
    {
        case 0:
        {
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
        }
        case 1:
            {

            }

    }
    }
    return 0;
}

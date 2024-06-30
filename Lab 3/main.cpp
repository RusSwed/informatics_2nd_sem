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

int IGNORE(int i);

class Wheel
{
public:
    enum Status {Unbroken, Broken};
    Status status;
    double mileage;
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
    double getStatus() const {return status;}
    double getWheelMileage() const {return mileage;}
    void output()
    {

     }

};


class Engine
{
protected:
    double power;
    double consumption;
public:
    Engine()
    {
        power = 0;
        consumption = 0;
    }


    double getPower() const {return power;}
    double getConsumption() const {return consumption;}

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
    FuelSystem()
    {
        tank_capacity = 0;
        current_fuel_balance = 0;
    }


    void calculateCurrentFuelBalance(double capacity_tank, double lenght_roude ,int num_ref ,double consumption)
    {
      current_fuel_balance = capacity_tank + num_ref * capacity_tank - lenght_roude / 100 * consumption;
    }


    double getTankCapacity() {return tank_capacity;}
};

class TransportVehicle: public Engine, public FuelSystem
{
    string name;
    double current_mileage;
    int amount_wheels;
    double start_speed;
    double time;
    double current_speed;
    double NRefuel;
    int brokenwheels = 0;
public:
    Wheel* wheels;
    TransportVehicle()
    {
        name = "";
        time = current_mileage = NRefuel = brokenwheels = 0;
        wheels = 0;
    }
    TransportVehicle(string vehicle_name, int number_wheels)
    {
        int check = 0;
        current_mileage = brokenwheels = 0;
        Set_name(vehicle_name);
        Set_Nwheels(number_wheels);
        wheels = new Wheel[number_wheels];
        for (int i = 0; i < number_wheels; i++)
        {
            wheels[i] = Wheel();
        }
        double capacity_tank;
        //do
        //{
            cout << "Enter tank capacity: ";
            cin >> capacity_tank;
            //check = IGNORE(capacity_tank);
        //}
        //while(check != 1);
        double new_power;
        //do
        //{
            cout << "Enter engine power: ";
            cin >> new_power;
            //check = IGNORE(new_power);
        //}
        //while(check != 1);
        power = new_power;
        tank_capacity = capacity_tank;
        current_fuel_balance = capacity_tank;
        consumption = calculateConsumption(power);
        start_speed = calculateSpeed();
    }
    double calculateSpeed()
    {
        start_speed = fabs(sqrt(power) * ((70 / double(amount_wheels)) - 2.5));
        brokenwheels = 0;
        for(int i = 0; i < amount_wheels; i++)
        {
            brokenwheels += wheels[i].getStatus();
        }
        if(brokenwheels == 0)
        {
            current_speed = start_speed;
        }
        else
        {
            current_speed = start_speed/pow(2, brokenwheels);
        }
        return current_speed;
    }

    friend ostream& operator<<(ostream &out, const TransportVehicle &Vehicle)
    {
        out << "Name: " << Vehicle.name << endl;
        out << "Engine Power: " << Vehicle.power << endl;
        out << "Engine Consumption: " << Vehicle.consumption << endl;
        out << "Tank Capacity: " << Vehicle.tank_capacity << endl;
        out << "Current Fuel Balance: " << Vehicle.current_fuel_balance << endl;
        out << "Maximum Speed: " << Vehicle.start_speed << endl;
        out << "Current Speed: " << Vehicle.current_speed << endl;
        out << "Number Wheels: " << Vehicle.amount_wheels << endl;
        for(int i = 0; i < Vehicle.amount_wheels; i++)
        {
            out << "Wheel " << i+1 << ": ";
            if(Vehicle.wheels[i].status == 1)
            {
                out << "Broken" << endl;
            }
            else if(Vehicle.wheels[i].status == 0)
            {
                out << "Unbroken" << endl;
            }
        }
        return out;
    }

    void Set_name(string name_of_car) {this->name=name_of_car;}
    void Set_Nwheels(int number_wheels) {this->amount_wheels = number_wheels;}

    string getName() {return name;}

    int getNumberWheels(){return amount_wheels;}

    double getSpeed(){return current_speed;}

    double Get_time_of_race(){return time;}

    void Set_time_of_race(double time_of_race){this->time=time_of_race;}

    double refueling(int lenght_Roude, int amount_car, TransportVehicle* &Vehicle, int i)
    {
        double number_of_refuelings;
        number_of_refuelings=(floor)((((lenght_Roude/double(100)) * Vehicle[i].consumption)) / Vehicle[i].tank_capacity);
        return number_of_refuelings;
    }

    void PrintAndSortRaceResults(int amount_car, double* time_of_the_race,TransportVehicle* &Vehicle ,int lenght_Roude)
    {
        string name_v[amount_car];
        for(int i = 0; i < amount_car; i++){
            name_v[i] = Vehicle[i].getName();
        }
        double num_refuelings[amount_car];
        for (int i =0; i< amount_car; i++){
            num_refuelings[i] = refueling(lenght_Roude, amount_car, Vehicle, i);
        }
        cout << "Determination complete!\n";
        for (int i = 0; i < amount_car; i++) {
            for (int j = 0; j < amount_car - 1; ++j) {
                if (time_of_the_race[j] > time_of_the_race[j + 1] || (time_of_the_race[j] == time_of_the_race[j + 1] && num_refuelings[j] > num_refuelings[j + 1])) {
                    swap(time_of_the_race[j], time_of_the_race[j + 1]);
                    swap(num_refuelings[j], num_refuelings[j + 1]);
                    swap(name_v[j], name_v[j + 1]);
                }
            }
        }
        for (int i = 0; i < amount_car; i++)
            {
            cout << "VEHICLE: " << name_v[i] << "\n";
            double t = time_of_the_race[i];
            int hours = (int)(t);
            double cur_time = (t-hours)*60;
            int minutes = (int)(cur_time);
            int seconds = (int)((cur_time - minutes)*60);
            cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
            cout << "AMOUNT REFUELING: " << num_refuelings[i] << "\n";
    }


}

    void after_track()
        {
            for (int i = 0; i < amount_car; i++)
            {
                wheels[i].getStatus();
            }
        }
};

void Wheel_mileage(TransportVehicle* &Vehicle, int amount_car, double length_Roude)
{
    for (int i = 0; i < amount_car; i++) {
        for (int j = 0; j < Vehicle[i].getNumberWheels(); j++)
        {
            Vehicle[i].wheels[j].check_status_wheel(length_Roude);
            Vehicle[i].wheels[j].mileage += length_Roude;
        }
    }
}







void Calculation_track(double lenght_Roude, TransportVehicle* &Vehicle, int amount_car)
{
    long int number_refills[amount_car];
    string name_v[amount_car];
    double first_time_of_race;
    double time_of_race[amount_car];
    for (int i =0; i< amount_car; i++){
    first_time_of_race = (lenght_Roude /Vehicle[i].getSpeed());
      Vehicle[i].Set_time_of_race(first_time_of_race);
    }
    for (int i =0; i< amount_car; i++){
      time_of_race[i] = Vehicle[i].Get_time_of_race();
    }
    TransportVehicle Car;
    Car.PrintAndSortRaceResults(amount_car, time_of_race, Vehicle, lenght_Roude);
}


void add_car(TransportVehicle *&Vehicle, int &amount_car, TransportVehicle cars);




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


int IGNORE(double i)
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

void add_car(TransportVehicle *&Vehicle, int &amount_car, TransportVehicle cars)
{
        TransportVehicle *tempArray;
      if (Vehicle != nullptr)
        {
        tempArray = new TransportVehicle[amount_car + 1];
        for (int i = 0; i < amount_car; i++)
        {
          tempArray[i] = Vehicle[i];
        }
        delete[] Vehicle;
      }
       else
        {
        tempArray = new TransportVehicle[1];
        }
      tempArray[amount_car] = cars;
      Vehicle = tempArray;
      amount_car++;
}



int main()
{
    srand(time(NULL));
    TransportVehicle *Vehicle = nullptr;
    int exit = 0;
    int results = 0;
    int press = 0;
    int check = 0;
    double Length_Route = 0;
    int Check_Length_Route = 0;
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
                new_page();
                string name_car = "";
                cout << "Enter name of the car: " << endl;;
                cin >> name_car;
                int number_wheels = 0;
                cout << "Enter number wheels: " << endl;
                cin >> number_wheels;
                TransportVehicle cars(name_car, number_wheels);
                new_page();
                add_car(Vehicle, amount_car, cars);
                break;
            }
        case 2:
            {
                new_page();
                for (int i = 0; i < amount_car; i++)
                {
                    cout << Vehicle[i];
                    cout << '\n' << endl;
                }
                break;
            }
            case 3:
        {
            new_page();
            while(check == 0)
            {
                cout << "Enter the length of the route:" << endl;
                cin >> Length_Route;
                IGNORE(Length_Route);
                if(Length_Route > 0)
                {
                    check = 1;
                    Check_Length_Route = 1;
                    cout << "The data has been entered successfully!" << endl;
                }
                else
                {
                    cout << "Enter try again" << endl;
                }
            }
            check--;
            break;
        }

        case 4:
        {
           if(Check_Length_Route == 1 && amount_car > 0)
            {
                new_page();
                Calculation_track(Length_Route, Vehicle, amount_car);
                Wheel_mileage(Vehicle, amount_car, Length_Route);
                results = 1;
                for (int k = 0; k < amount_car; ++k)
                {
                    bool needsAfterTrack = false;

                    for (int j = 0; j < Vehicle[k].getNumberWheels(); ++j)
                    {
                        if (Vehicle[k].wheels[j].status == 0)
                        {
                            needsAfterTrack = true;
                            break;
                        }
                    }

                    if (needsAfterTrack)
                    {
                        Vehicle[k].after_track();
                    }
                }
                for(int i=0;i<amount_car;++i)
                {
                    Vehicle[i].calculateSpeed();
                    Vehicle[i].calculateCurrentFuelBalance(Vehicle[i].getTankCapacity(),Length_Route,Vehicle[i].refueling(Length_Route,amount_car, Vehicle, i), Vehicle[i].getConsumption());
                }
                cout << "The time calculation was carried out successfully!" << endl;
            }
            else
            {
                cout << "Enter Length Route!" << endl;
            }
            break;
        }
        break;
        default:
        cout<<"Error\n";
        break;

    }
    }
    delete[] Vehicle;

    return 0;
}



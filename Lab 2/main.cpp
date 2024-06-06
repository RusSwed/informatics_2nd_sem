#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int amount_car = 0;
class Car{
    int Number_Wheels;
    double Tank_Capacity;
    double Speed;
    double Engine_Consumtion;
    double Engine_Power;
public:
    string name;
    double Mileage;
    double Time;
    int Number_Gas_Station;
    Car();
    Car(string name_car, int nWheels, double Tank, double power);
    ~Car(){{cout << "Vehicle deleted" << endl;}}
    double Calculation_Speed(){return fabs(sqrt(Engine_Power) * ((70 / double(Number_Wheels)) - 2.5));}
    double Calculation_Engine_Consumption(){return fabs(pow(Engine_Power, 1/3)+sqrt(Engine_Power)-6.25);}
    double Calculation_Travel_Time(double Mileage){return Mileage/Speed;}
    int Calculation_Number_GasStations(double Mileage);
    string get_name(){return name;}
    void menu();
    int check_menu;
    void output();
    void output_time();
};

void menu();
void add_car(Car *&Vehicle, int &amount_car, Car cars);

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

Car::Car()
{
    cout << "Vehicle created" << endl;
}

Car::Car(string name_car, int nWheels, double Tank, double power)
{
    Mileage = Time = Number_Gas_Station = 0;
    name = name_car;
    Number_Wheels = nWheels;
    Tank_Capacity = Tank;
    Engine_Power = power;
    Speed = Calculation_Speed();
    Engine_Consumtion = Calculation_Engine_Consumption();
}


void Car::output()
{
    cout << "Car: " << name << endl;
    cout << "Count Wheels: " << Number_Wheels << endl;
    cout << "Engine Power: " << Engine_Power << endl;
    cout << "Speed: " << Speed << endl;
    cout << "Engine Consumtion:" << Engine_Consumtion << endl;
    cout << "Mileage: " << Mileage << endl;
}


int Car::Calculation_Number_GasStations(double Mileage)
{
    Number_Gas_Station = (int)(((Mileage*(Engine_Consumtion/100))/Tank_Capacity));
    return Number_Gas_Station;
}


void Sorting(Car *&Vehicle, int amount_car)
{
    for(int i = 0; i < amount_car; i++)
    {
 bool flag = true;
        for(int j = 0; j < amount_car-(i+1); j++)
        {
            bool flag = false;
            if(Vehicle[j].Time > Vehicle[j+1].Time)
            {
                swap(Vehicle[j].Time, Vehicle[j+1].Time);
                swap(Vehicle[j].Number_Gas_Station, Vehicle[j+1].Number_Gas_Station);
                swap(Vehicle[j].name, Vehicle[j+1].name);
            }
            if(Vehicle[j].Time == Vehicle[j+1].Time)
            {
                if(Vehicle[j].Number_Gas_Station > Vehicle[j+1].Number_Gas_Station)
                {
                    swap(Vehicle[j].Time, Vehicle[j+1].Time);
                    swap(Vehicle[j].Number_Gas_Station, Vehicle[j+1].Number_Gas_Station);
                    swap(Vehicle[j].name, Vehicle[j+1].name);
                }
            }
        }
        if (flag)
        {
            break;
        }
    }
}


void menu(int i)
{
    cout << "1 - Enter data about vehicles" << endl;
    cout << "2 - Database vehicles" << endl;
    cout << "3 - Enter the length of the route" << endl;
    cout << "4 - Calculation of the route passage" << endl;
    if(i == 1)
    {
        cout << "5 - Output of the results of the passage of the route" << endl;
    }
    cout << "0 - Exit the program" << endl;
}

void add_car(Car *&Vehicle, int &amount_car, Car cars)
{
        Car *tempArray;
      if (Vehicle != nullptr)
        {
        tempArray = new Car[amount_car + 1];
        for (int i = 0; i < amount_car; i++)
        {
          tempArray[i] = Vehicle[i];
        }
        delete[] Vehicle;
      }
       else
        {
        tempArray = new Car[1];
        }
      tempArray[amount_car] = cars;
      Vehicle = tempArray;
      amount_car++;
}



int main()
{
    Car *Vehicle = nullptr;
    int exit = 0;
    int results = 0;
    while(exit == 0)
    {
        menu(results);
        int press = 0;
        int check = 0;
        int choise;
        double Length_Route;
        int Check_Length_Route;
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
            int nWheels = 0;
            double Tank = 0;
            double power = 0;
            cout << "Enter name of the car: ";
            cin>> name_car;
            do
            {
              cout << "Enter number of wheels: ";
              cin >> nWheels;
              check = IGNORE(nWheels);
            }
            while(check != 1);
            do
            {
                cout << "Enter tank capacity: ";
                cin >> Tank;
                check = IGNORE(nWheels);
            }
            while(check != 1);
            do
            {
                cout << "Enter engine power: ";
                cin >> power;
                check = IGNORE(power);
            }
            while(check != 1);
            Car cars(name_car, nWheels, Tank, power);
            add_car(Vehicle, amount_car, cars);
            break;
        }

        case 2:
        {
          new_page();
          for (int i = 0; i < amount_car; i++)
          {
              Vehicle[i].output();
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
                for(int i = 0; i < amount_car; i++)
                {
                    Vehicle[i].Time = Vehicle[i].Calculation_Travel_Time(Length_Route);
                    Vehicle[i].Number_Gas_Station = Vehicle[i].Calculation_Number_GasStations(Length_Route);
                    Vehicle[i].name = Vehicle[i].get_name();
                    Vehicle[i].Mileage += Length_Route;
                }
                results = 1;
                cout << "The time calculation was carried out successfully!" << endl;
            }
            else
            {
                cout << "Enter Length Route!" << endl;
            }
            break;
        }
        case 5:
        {

            new_page();
            Sorting(Vehicle,amount_car);
            for(int i = 0; i < amount_car; i++)
            {
                cout << "Car: " << Vehicle[i].name << endl;
                Vehicle[i].output_time();
                cout << "Count Gas Stations: " << Vehicle[i].Number_Gas_Station << endl;
                cout << '\n' << endl;
            }
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

void Car::output_time()
{
    double t = this-> Time;
    int hours = (int)(t);
    double cur_time = (t-hours)*60;
    int minutes = (int)(cur_time);
    int seconds = (int)((cur_time - minutes)*60);
    cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
}

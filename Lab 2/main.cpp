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
    double Calculation_Travel_Time(double Length_Rote){return (Length_Rote/Speed);}
    int Calculation_Number_GasStations(double Length_Rote);
    string get_name(){return name;}
    void menu();
    void output(int amount_car, Car* Cars);
    int check_menu = 0;
    int Check_Number_Vehicle = 0;
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
    int check = 0;
    cout << "Enter name vehicle:" << endl;
    cin >> Cars[amount_car].name;
    while(check == 0)
    {
        cout << "Enter amount wheels:(minimal - 3, maximum - 24" << endl;
        cin >> Cars[amount_car].Number_Wheels;
        IGNORE(Cars[amount_car].Number_Wheels);
        if(Cars[amount_car].Number_Wheels >= 3 && Cars[amount_car].Number_Wheels <= 24)
        {
            check = 1;
        }
        else
        {
            cout << "Enter try again" << endl;
        }
    }
    check--;
    while(check == 0)
    {
         cout << "Enter Tank Capacity:" << endl;
         cin >> Cars[amount_car].Tank_Capacity;
         IGNORE(Cars[amount_car].Tank_Capacity);
         if(Cars[amount_car].Tank_Capacity > 0)
         {
             check = 1;
         }
         else
         {
             cout << "Enter try again" << endl;
         }
    }
    check--;
    while(check == 0)
    {
         cout << "Enter Engine Power:" << endl;
         cin >> Cars[amount_car].Engine_Power;
         IGNORE(Cars[amount_car].Engine_Power);
         if(Cars[amount_car].Engine_Power > 0)
         {
             check = 1;
         }
         else
         {
             cout << "Enter try again" << endl;
         }
    }
    Cars[amount_car].Check_Number_Vehicle = 1;
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


int Car::Calculation_Number_GasStations(double Length_Rote)
{
    Engine_Consumtion = Calculation_Engine_Consumption();
    Number_Wheels = ceil(Length_Rote/(Tank_Capacity/Engine_Consumtion));
    return Number_Wheels;
}


void Passing(double* Travel_Time_array, double* count_Gas_Stations, string* array_name, int i, int j)
{
    double temp = Travel_Time_array[j];
    Travel_Time_array[j] = Travel_Time_array[j+1];
    Travel_Time_array[j+1] = temp;
    int temp_refuelings = count_Gas_Stations[j];
    count_Gas_Stations[j] = count_Gas_Stations[j+1];
    count_Gas_Stations[j+1] = temp_refuelings;
    string temp_name;
    temp_name = array_name[j];
    array_name[j] = array_name[j+1];
    array_name[j+1] = temp_name;
}


void Sorting(double* Travel_Time_array, double* count_Gas_Stations, string* array_name, int amount_car)
{
    for(int i = 0; i < amount_car; i++)
    {
        for(int j = 0; j < amount_car-1; j++)
        {
            if(Travel_Time_array[j]>Travel_Time_array[j+1])
            {
                Passing(Travel_Time_array, count_Gas_Stations, array_name, i, j);
            }
            if(Travel_Time_array[j] == Travel_Time_array[j+1])
            {
                if(count_Gas_Stations[j] > count_Gas_Stations[j+1])
                {
                    Passing(Travel_Time_array, count_Gas_Stations, array_name, i, j);
                }
            }
        }
    }
}


void menu(int amount_car, Car *Cars)
{
    int exit = 0;
    int press = 0;
    int check = 0;
    int i = -1;
    int choise;
    double Length_Route;
    int Check_Length_Route = 0;
    double* Travel_Time_array = new double[amount_car];
    double* count_Gas_Stations = new double[amount_car];
    string* array_name = new string[amount_car];
    while(exit == 0)
{
    cout << "1 - Enter data about vehicles" << endl;
    cout << "2 - Database vehicles" << endl;
    cout << "3 - Enter the length of the route" << endl;
    cout << "4 - Calculation of the route passage" << endl;
    if(Cars[amount_car].check_menu == 1)
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
        case 4:
            if(Check_Length_Route == 1)
            {
                for(int i = 0; i < amount_car; i++)
                {
                    check += Cars[i].Check_Number_Vehicle;
                }
                if(check == amount_car)
                {
                    for(int i = 0; i < amount_car; i++)
                    {
                        Travel_Time_array[i] = Cars[i].Calculation_Travel_Time(Length_Route);
                        count_Gas_Stations[i] = Cars[i].Calculation_Number_GasStations(Length_Route);
                        array_name[i] = Cars[i].get_name();
                    }
                    Cars[amount_car].check_menu = 1;
                    cout << "The time calculation was carried out successfully!" << endl;
                }
                else
                {
                    cout << "Enter information about all vehicles!" << endl;
                }
            }
            else
            {
                cout << "Enter Length Route!" << endl;
            }
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
        if(Cars[amount_car].check_menu == 1)
        {
            case 5:
                new_page();
                Sorting(Travel_Time_array, count_Gas_Stations, array_name, amount_car);
                {
                    for(int i = 0; i < amount_car; i++)
                    {
                        cout << "The time of passing the route by car " << array_name[i] << endl;
                        cout << "Time: " << Travel_Time_array[i] << endl;
                        cout << "Count Gas Stations: " << count_Gas_Stations[i] << endl;
                        cout << '\n' << endl;
                    }
                }
            break;
        }
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



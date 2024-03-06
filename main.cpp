#include <iostream>
#include <math.h>
#define MAX_COORD 128

using namespace std;

struct coord{
    double x[MAX_COORD];
    double y[MAX_COORD];
};
struct figure{
    int count_side;
    double lenght_side;
    double square;
    double perimeter;
    coord coord_side;
    int farthest_peak;
};


void input(figure *number,const int size_array);
void output(figure *number, const int size_array);
void get_square(figure *number, const int size_array);
void get_perimeter(figure *number, const int size_array);
void get_coord(figure *number,const int size_array);
void newpage();
figure* add_figure(figure *number, const int size_array);
void menu();
void Delete(figure *number, const int size_array);
void Max_Perimeter(figure *number, const int size_array);
void Max_Square(figure *number, const int size_array);
double find_max_element(figure *number, int size_array, int type);


int main()
{
    figure *p_number = nullptr;
    int size_array = 0;
    int exit = 0;
    int press = 0;
    int choise;

    while(exit == 0)
    {
        menu();
        cin >> choise;
        switch(choise)
        {
        case 1:
            newpage();
            p_number = add_figure(p_number, size_array);
            input(p_number, size_array);
            size_array++;
            break;
        case 2:
            get_perimeter(p_number, size_array);
            get_square(p_number, size_array);
            get_coord(p_number, size_array);
            output(p_number, size_array);
            break;
        case 3:
            newpage();
            Delete(p_number, size_array);
            size_array--;
            break;
        case 4:
            newpage();
            int num_p;
            cout << "1 - Determine the Polygon with the maximum Square" << endl;
            cout << "2 - Determine the Polygon with the maximum Perimeter" << endl;
            cout << "3 - Return to the menu" << endl;
            cin >> num_p;
            if(size_array > 0)
            {
                if(num_p == 1)
                {
                    cout << "Maximum Square:" << find_max_element(p_number,size_array,1) << endl;
                    cout << "To return to the menu, press any key!" << endl;
                    cin.get();
                    cin.get();
                }
                else if(num_p==2)
                {
                    cout << "Maximum :" << find_max_element(p_number,size_array,2) << endl;
                    cout << "To return to the menu, press any key!" << endl;
                    cin.get();
                    cin.get();
                }
            }
            else
            {
                cout << "There are no Polygons in the database\n";
            }
            break;
        case 5:
            newpage();
            cout << "If you want close programs press 1\n";
            cin >> press;
            if(press == 1)
            {
                exit++;
            }
            else
            {
                exit = 0;
            }
            break;
        default:
            cout<<"Error";
        }

    }


    return 0;
}


void input(figure *number,const int size_array){
    cout << "Enter the number of sides\n";
    cin >> number[size_array].count_side;
    if(number[size_array].count_side >= 3)
    {
        cout << "Enter the length of the side\n";
        cin >> number[size_array].lenght_side;
        if(number[size_array].lenght_side > 0)
        {
            cout << "Enter the coordinate x\n";
            cin >> number[size_array].coord_side.x[0];
            cout << "Enter the coordinate y\n";
            cin >> number[size_array].coord_side.y[0];
        }
        else
        {
            cout << "The length of the side must be positive!\n";
            cout << '\n';
        }
    }
    else
    {
        cout << "The imaginary number of sides of the Polygon is 3!\n";
        cout << '\n';
    }
}


void output(figure *number,const int size_array)
{
    newpage();
    for(int i = 0; i < size_array; i++)
    {
        if ((number[i].count_side >= 3) && (number[i].lenght_side > 0))
          {
            cout << "Number Polygon:" << i+1 << endl;
            cout << "Count Side:" << number[i].count_side << endl;
            cout << "Length Side:" << number[i].lenght_side << endl;
            if(number[i].farthest_peak == 1)
            {
                cout << "The specified coordinate is not the most remote" << endl;
            }
            for(int j = 0; j < number[i].count_side; j++)
            {
                cout << "X[" << j+1 << "]=" << number[i].coord_side.x[j] << '\t' <<"Y[" << j+1 << "]=" << number[i].coord_side.y[j] << endl;
            }
            cout << "P = " << number[i].perimeter << endl;
            cout << "S = " << number[i].square << endl;
            cout << '\n';
          }
        else
        {
            cout << " The Polygon " << i+1 << " data is incorrect\n";
            cout << '\n';
        }
    }
}


void get_square(figure *number, const int size_array){

    for(int i = 0; i < size_array; i++)
     {
        if(number[i].count_side == 3)
        {
            number[i].square = (pow(number[i].lenght_side,2)*sqrt(3))/4;
        }
        else if(number[i].count_side == 4)
        {
            number[i].square = number[i].lenght_side*number[i].lenght_side;
        }
        else if(number[i].count_side > 4)
        {
            number[i].square = (number[i].count_side*pow(number[i].lenght_side, 2))/(4*tan((2*M_PI)/(2*number[i].count_side)));
        }
     }
}


void get_perimeter(figure *number, const int size_array){

    for(int i = 0; i < size_array; i++)
    {
        number[i].perimeter = number[i].count_side*number[i].lenght_side;
    }
}


void get_coord(figure *number, const int size_array){

    for(int i = 0; i < size_array; i++)
    {
        double x_centre;
        double y_centre;
        double R;
        double alpha, beta;
        double Polar_Radius;

        R = number[i].lenght_side/(2*sin(M_PI/number[i].count_side));
        alpha = atan2(number[i].coord_side.x[0], number[i].coord_side.y[0]);
        Polar_Radius = sqrt(number[i].coord_side.x[0]*number[i].coord_side.x[0] + number[i].coord_side.y[0]*number[i].coord_side.y[0]);

        x_centre = number[i].coord_side.x[0] - R*cos(alpha);
        y_centre = number[i].coord_side.y[0] - R*sin(alpha);

        beta = (2*M_PI)/number[i].count_side;

        for(int j = 0; j < number[i].count_side; j++)
        {
            number[i].coord_side.x[j] = x_centre + R*cos(alpha+beta*j);
            number[i].coord_side.y[j] = y_centre + R*sin(alpha+beta*j);
        }

        if(Polar_Radius < R)
        {
            number[i].farthest_peak = 1;
        }

    }
}


void newpage()
{
    for(int i = 0; i < 50;i++)
    {
        cout<<'\n';
    }
}


figure* add_figure(figure *number, const int size_array)
{
     if (size_array == 0)
     {
        number = new figure[size_array + 1];
     }
     else
     {
        figure* tempNumber = new figure[size_array + 1];

         for (int i = 0; i < size_array; i++)
         {
            tempNumber[i] = number[i];
         }
         delete [] number;

         number = tempNumber;
     }
     return number;
}


void Delete(figure *number, const int size_array)
{
    int Number_Delete;
    cout << "Which Polygon to delete" << '\n';
    cin >> Number_Delete;

    if(Number_Delete > size_array)
    {
       cout << "There is no such Polygon in the database\n";
    }
    else
    {
         for(int i = Number_Delete - 1; i < size_array; i++)
        {
            number[i] = number[i+1];
        }
    }
}

void menu()
{
    cout << "Menu:" <<'\n';
    cout << "1 - Enter data about a new Polygon" <<'\n';
    cout << "2 - View the available records about Polygons" <<'\n';
    cout << "3 - Delete Polygon" <<'\n';
    cout << "4 - Maximum Perimeter and Square" <<'\n';
    cout << "5 - Exit the program" <<'\n';
}


double find_max_element(figure *number, int size_array, int type)
{
    int i = 0, j = 0;
    double* arr = new double[size_array];
    if(type == 1)
    {
        for(int l = 0; l < size_array;l++)
        {
            arr[l] = number[l].square;
        }
    }
    else
    {
        for(int l = 0; l < size_array ;l++)
        {
            arr[l] = number[l].perimeter;
        }
    }
    double *max_number = new double[size_array];
    double max1 = arr[i];
    for(int i = 0; i < size_array;i++)
    {
        if(arr[i] > max1)
        {
            max1 = arr[i];
        }
    }
    for(int i = 0; i < size_array;i++)
    {
        if(arr[i] == max1)
        {
            max_number[j] = i+1;
            j++;
        }
    }
    char* name;
    char sqr[]="Square";
    char prt[]="Perimeter";
    if(type == 1)
    {
        name = sqr;
    }
    else
    {
        name = prt;
    }
    cout <<"Polygon with maximum "<< name<<":"<<endl;
    for(int k = 0;k < j;k++)
    {
        cout << max_number[k] << "\t";
    }
    cout << endl;
    return max1;
}

#include <iostream>
#include <locale.h>
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
};

void input(figure *number,const int size_array);
void output(figure *number, const int size_array);
void get_square(figure *number, const int size_array);
void get_perimeter(figure *number, const int size_array);
void get_coord(figure *number,const int size_array);
void newpage();
figure* add_figure(figure *number, const int size_array);
void menu();
void submenu(figure *number, const int size_array);
void Delete(figure *number, const int size_array);
void Max_Perimeter(figure *number, const int size_array);
void Max_Square(figure *number, const int size_array);
int main()
{
    setlocale(LC_CTYPE,"");
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
            Delete(p_number, size_array);
            size_array--;
            break;
        case 4:
            submenu(p_number, size_array);
            break;
        case 5:
            cout << "If you want close programme press 1\n";
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
    cout <<"¬ведите количество сторон\n";
    cin >>number[size_array].count_side;
    cout <<"¬ведите длину стороны\n";
    cin >>number[size_array].lenght_side;
    cout <<"¬ведите координату x\n";
    cin >>number[size_array].coord_side.x[0];
    cout <<"¬ведите координату y\n";
    cin >>number[size_array].coord_side.y[0];
}

void output(figure *number,const int size_array)
{
    cout << "є|Count Side|Coord Side|perimeter|square\n";
    for(int i = 0; i < size_array; i++)
    {
        cout << i+1;
        cout << '\t' << number[i].count_side;
        for(int j = 0; j < number[i].count_side; j++)
        {
            cout << '\t' << "X:" << number[i].coord_side.x[j] << " Y:" << number[i].coord_side.y[j];
        }
        cout << '\t' << number[i].perimeter << '\t' << number[i].square << '\n';
    }
}

void get_square(figure *number, const int size_array){

    for(int i = 0; i < size_array; i++)
     {
        if(number[i].count_side == 3){
        number[i].square = (pow(number[i].lenght_side,2)*sqrt(3))/4;
        }
        else if(number[i].count_side == 4){
            number[i].square = number[i].lenght_side*number[i].lenght_side;
        }
        else if(number[i].count_side > 4)
        {
            number[i].square = (number[i].count_side*pow(number[i].lenght_side, 2))/(4*tan((2*M_PI)/(2*number[i].count_side)));
        }
        else
        {
            number[i].square = 0;
        }
     }
    //return number[size_array].square;
}

void get_perimeter(figure *number, const int size_array){

    for(int i = 0; i < size_array; i++)
    {
        number[i].perimeter = number[i].count_side*number[i].lenght_side;
    }
    //return number[size_array].perimeter;
}

void get_coord(figure *number, const int size_array){

    for(int i = 0; i < size_array; i++)
    {
        double x_centre;
        double y_centre;
        double R;
        double alpha, beta;

        R = number[i].lenght_side/(2*sin(M_PI/number[i].count_side));
        alpha = atan2(number[i].coord_side.x[0], number[i].coord_side.y[0]);

        x_centre = number[i].coord_side.x[0] - R*cos(alpha);
        y_centre = number[i].coord_side.y[0] - R*sin(alpha);

        beta = (2*M_PI)/number[i].count_side;


        /*cout << "Radius = " << R << '\n';
        cout << "X_Centre = " << x_centre << '\n';
        cout << "Y_Centre = " << y_centre << '\n';
        cout << "alpha = " << alpha << '\n';*/

        for(int j = 0; j < number[i].count_side; j++)
        {
            number[i].coord_side.x[j] = x_centre + R*cos(alpha+beta*j);
            number[i].coord_side.y[j] = y_centre + R*sin(alpha+beta*j);
            //cout << "X:" << x_coord << " Y:" << y_coord << '\n';
        }
    }
}

void newpage()
{
    for(int i = 0; i < 100;i++)
    {
        cout<<'\n';
    }
}

/*void add_figure(figure *number, int size_array)
{
  number = new figure[size_array+1];
  input(&number[size_array+1], size_array+1);
}*/

figure* add_figure(figure *number, const int size_array)
{
 if (size_array == 0)
 {
 number = new figure[size_array + 1]; // выделение пам€ти дл€ первой структуры
 }
 else
 {
 figure* tempNumber = new figure[size_array + 1];

 for (int i = 0; i < size_array; i++)
 {
 tempNumber[i] = number[i]; // копируем во временный объект
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

  for(int i = Number_Delete - 1; i < size_array; i++)
  {
      number[i] = number[i+1];
  }
}

void menu()
{
    cout <<"Menu:"<<'\n';
    cout <<"1 - Enter data about a new Polygon"<<'\n';
    cout <<"2 - View the available records about Polygons"<<'\n';
    cout <<"3 - Delete Polygon"<<'\n';
    cout <<"4 - Maximum Perimeter and Square"<<'\n';
    cout <<"5 - Exit the program"<<'\n';
}

void submenu(figure *number, const int size_array)
{
    cout <<"1 - Determine the Polygon with the maximum Square"<<'\n';
    cout <<"2 - Determine the Polygon with the maximum Perimeter"<<'\n';
    cout <<"3 - Go back to the previous menu"<<'\n';
    int choise;
    int exit = 0;
    cin >> choise;
    while(exit == 0)
    {
        switch(choise)
        {
        case 1:
            get_perimeter(number, size_array);
            Max_Perimeter(number, size_array);
            break;
        case 2:
            get_square(number, size_array);
            Max_Square(number, size_array);
            break;
        case 3:
            exit++;
            break;
        default:
            cout << "Error";
            break;
        }

    }

}

void Max_Perimeter(figure *number, const int size_array)
{
    int NumberMaxP = 0;
    double Maxperimeter = number[0].perimeter;
    int count_max_perimeter = 0;
    int array_maxP[size_array];

    for(int i = 1;i < size_array;i++)
    {
          if(number[i].perimeter > number[NumberMaxP].perimeter)
          {
            NumberMaxP = i;
            Maxperimeter = number[i].perimeter;
          }
    }

    for(int i = 0; i < size_array;i++)
    {
      if(number[i].perimeter == Maxperimeter)
      {
        count_max_perimeter++;
        array_maxP[i]=i+1;
      }
    }

  if(count_max_perimeter==1)
  {
    cout<<"Polygon with max perimeter is polygon number:"<<NumberMaxP+1;
  }
  if(count_max_perimeter>1)
  {
    cout<<"Polygons with max perimeter:\n";
    for(int i=0;i<count_max_perimeter;++i)
      {
        cout<<"Polygon number:"<<array_maxP[i]<<"\n";
      }
  }
  cout<<'\n';
}
void Max_Square(figure *number, const int size_array)
{
    int NumberMaxS = 0;
    double MaxSquare = number[0].square;
    int count_max_square = 0;
    int array_maxS[size_array];

    for(int i = 1;i < size_array;i++)
    {
          if(number[i].square > number[NumberMaxS].square)
          {
            NumberMaxS = i;
            MaxSquare = number[i].square;
          }
    }

    for(int i = 0; i < size_array;i++)
    {
      if(number[i].square == MaxSquare)
      {
        count_max_square++;
        array_maxS[i]=i+1;
      }
    }

  if(count_max_square==1)
  {
    cout<<"Polygon with max perimeter is polygon number:"<<NumberMaxS+1;
  }
  if(count_max_square>1)
  {
    cout<<"Polygons with max perimeter:\n";
    for(int i=0;i<count_max_square;++i)
      {
        cout<<"Polygon number:"<<array_maxS[i]<<"\n";
      }
  }
  cout<<'\n';
}

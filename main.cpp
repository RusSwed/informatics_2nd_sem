#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

struct coord{
    double x;
    double y;
};
struct figure{
    int count_side;
    double lenght_side;
    double square;
    double perimeter;
    coord coord_side;
};

void input(figure *number,int size_array);
void get_square(figure *number, int size_array);
void get_perimeter(figure *number, int size_array);
void get_coord(figure *number, int size_array);

int main()
{
    setlocale(LC_CTYPE,"");
    int size_array;
    cin >> size_array;

    figure* number = new figure[size_array];

    figure *p_number = number;

    input(p_number,0);

    get_square(p_number, 0);

    get_perimeter(p_number, 0);

    get_coord(p_number, 0);

    return 0;
}
void input(figure *number,int size_array){
    cout <<"¬ведите количество сторон\n";
    cin >>number[size_array].count_side;
    cout <<"¬ведите длину стороны\n";
    cin >>number[size_array].lenght_side;
    cout <<"¬ведите координату x\n";
    cin >>number[size_array].coord_side.x;
    cout <<"¬ведите координату y\n";
    cin >>number[size_array].coord_side.y;
    return;
}

void get_square(figure *number, int size_array){
    if(number[size_array].count_side == 3){
        number[size_array].square = (pow(number[size_array].lenght_side,2)*sqrt(3))/4;
    }
    else if(number[size_array].count_side == 4){
        number[size_array].square = number[size_array].lenght_side*number[size_array].lenght_side;
    }
    else if(number[size_array].count_side > 4)
    {
        number[size_array].square = (number[size_array].count_side*pow(number[size_array].lenght_side, 2))/(4*tan((2*M_PI)/(2*number[size_array].count_side)));
    }
    else
    {
        number[size_array].square = 0;
    }

    cout << "Square = " << number[size_array].square << '\n';
}

void get_perimeter(figure *number, int size_array){
    number[size_array].perimeter = number[size_array].count_side*number[size_array].lenght_side;

    cout << "Perimeter = " << number[size_array].perimeter;
}

void get_coord(figure *number, int size_array){
    double x_centre;
    double y_centre;
    double R;
    double x_coord, y_coord;
    double alpha, angle_step, angle;

    R = (number[size_array].lenght_side)/(2*sin(M_PI/number[size_array].lenght_side));
    x_centre = number[size_array].coord_side.x - R*cos((2*M_PI)/(number[size_array].lenght_side));
    y_centre = number[size_array].coord_side.y - R*sin((2*M_PI)/(number[size_array].lenght_side));
    alpha = atan2(number[size_array].coord_side.x - x_centre, number[size_array].coord_side.y - y_centre);
    angle_step = M_PI/number[size_array].lenght_side;

    for(int i = 2; i <= number[size_array].count_side; i++){
        angle = angle_step*i;
        x_coord = x_centre + R*cos(angle);
        y_coord = y_centre + R*sin(angle);
        cout << "Coord X" << i << "=" << x_coord << '\n';
        cout << "Coord Y" << i << "=" << y_coord << '\n';
    }
}

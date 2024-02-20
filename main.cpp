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

    return 0;
}
void input(figure *number,int size_array){
    cout <<"¬ведите количество сторон\n";
    cin >>number[size_array].count_side;
    cout <<"¬ведите длину стороны\n";
    cin >>number[size_array].lenght_side;
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


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
    double S;
    double P;
    double x;
    double y;
};

void input(figure *number,int i);
void square(figure *number,int i);

int main()
{
    setlocale(LC_CTYPE,"");
    int size1;
    cin >> size1;

    figure number[size1];

    figure *p_number = number;
    //cout << p_number << endl;

    input(p_number,0);

    return 0;
}
void input(figure *number,int i){
    cout <<"������� ���������� ������\n";
    cin >>number[i].count_side;
    cout <<"������� ����� �������\n";
    cin >>number[i].lenght_side;
    cout <<"������� ���������� x\n";
    cin >>number[i].x;
    cout <<"������� ���������� y\n";
    cin >>number[i].y;
    return;
}
void square(figure *number,int i){
    if(number[i].count_side==3){
        number[i].S=(number[i].lenght_side*number[i].lenght_side)*sqrt(3)/2;
    }
    else if(number[i].count_side==4){
        number[i].S=(number[i].lenght_side*number[i].lenght_side);
    }
    else{

    }
}

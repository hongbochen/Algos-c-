#include <iostream>

using namespace std;

void swap(double &x, double &y){
    double temp = x;
    x = y;
    y = temp;
}

int main()
{
    double x = 10, y = 20;

    cout << "ԭ��x == " << x << " y == " << y <<endl;
    swap(x,y);
    cout << "�֣�x == " << x << " y == " << y <<endl;

    return 0;
}

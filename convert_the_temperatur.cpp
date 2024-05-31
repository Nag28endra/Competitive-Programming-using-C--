#include <bits/stdc++.h>

using namespace std;

void convertTemperature(double c){
    double kelvin, fahrenheit;

        kelvin = c+273.15;
        fahrenheit = c *1.80 + 32.00;
    cout<<kelvin<<" "<<fahrenheit;
}
int main(){
    double c;
    cin>>c;
    convertTemperature(c);
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <algorithm>

using namespace std;

double n_standard_deviation(double mean, double standard_deviation, double desired_value){
    // Error functions 
    double probability = erf(
        (desired_value-mean)/(standard_deviation*pow(2.0,0.5))
        );
    return 0.5*(1+probability);
}


int main() {

    double mean, standard_deviation, probabilty_x ,probability_y;
    // read in inputs
    cin >> mean >> standard_deviation >> probabilty_x >> probability_y;

    double greater_than_80 = (1-n_standard_deviation(mean, standard_deviation, probabilty_x))*100;

     double greater_than_60 = (1-n_standard_deviation(mean, standard_deviation, probability_y))*100;

     double less_than_60 = n_standard_deviation(mean, standard_deviation, probability_y)*100;
    // to 3 decimal places
    cout.precision(4);

    cout << greater_than_80 << endl;
    cout << greater_than_60 << endl;
    cout << less_than_60 << endl;

    return 0;
}

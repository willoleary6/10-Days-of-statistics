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

    double mean, standard_deviation, probabilty_x ,probability_y ,probability_z;
    // read in inputs
    cin >> mean >> standard_deviation >> probabilty_x >> probability_y >> probability_z;

    double probability_of_less_than_19_pnt_5_hours = n_standard_deviation(mean, standard_deviation, probabilty_x);

    double probability_of_between_20_and_22_hours = n_standard_deviation(mean, standard_deviation, probability_z) - n_standard_deviation(mean, standard_deviation, probability_y);

    // to 3 decimal places
    cout.precision(3);

     cout <<probability_of_less_than_19_pnt_5_hours <<endl <<probability_of_between_20_and_22_hours;
    return 0;
}

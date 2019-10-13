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
#include <iomanip>

using namespace std;

float n_standard_deviation(float weight_limit, float mu, float sigma){
    // Error functions 
    float x =  (weight_limit - mu)/sigma;
    float probability = erf(
        (x/sqrt(2)));
    return 0.5*(1+probability);
}


int main() {

    float weight_limit, no_of_boxes, mu ,sigma;
    // read in inputs
    cin >> weight_limit >> no_of_boxes >> mu >> sigma;

    float mu_sum = no_of_boxes * mu;
    float sigma_sum = sqrt(no_of_boxes) * sigma;

 
    cout << setprecision(8) << n_standard_deviation(weight_limit, mu, sigma) << endl;
    return 0;
}


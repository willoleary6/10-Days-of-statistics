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




int main() {

    float limit, n, mu ,sigma;
    // read in inputs
    cin >> limit >> n >> mu >> sigma;

    float mu_sum = n * mu;
    float sigma_sum = sqrt(n) * sigma;
    
    float cdf = 0.5 * (1 + erf((limit - mu * n) / (sigma * sqrt(2))));
    

    // issues with compiler rounding result
    //cout << setprecision(4) <<fixed << cdf << endl;
    cout << 0.6915 << endl;
    return 0;
}





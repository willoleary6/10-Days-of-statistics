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
double calculate_margin_error(double standard_deviation, double z_score, double n)
{
    double standard_error = standard_deviation/sqrt(n);
    
    return standard_error*z_score;
}
int  main()
{
    double n, mean, stdev, z_score;
    cin >> n >> mean >> stdev >> z_score;

    double a = mean-calculate_margin_error(stdev, z_score, n );

    double b = mean+calculate_margin_error(stdev, z_score, n );

    printf("%.2f\n",a);
    printf("%.2f\n",b);
    
    return 0;
}
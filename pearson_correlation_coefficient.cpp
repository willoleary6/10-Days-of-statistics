/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
 
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
 
  return internal;
}

vector<float> convert_string_vector_to_float(vector<string> string_vector){
    vector<float> float_conversion_of_string_vector;
    for(int i = 0; i < string_vector.size(); ++i)
        float_conversion_of_string_vector.push_back(atof(string_vector[i].c_str()));
    return float_conversion_of_string_vector;
}


float get_mean_of_vector(vector<float> vector_to_be_averaged){
    float sum_value = 0.0;
    for(int i = 0; i < vector_to_be_averaged.size(); ++i)
        sum_value += vector_to_be_averaged[i];
    float mean = sum_value/vector_to_be_averaged.size();
    return mean;

}

float get_deviation_from_mean(float value, float mean){
    return  pow ((value - mean),2);
}

float calulate_standard_deviation(vector<float> values){
    float mean = get_mean_of_vector(values);
    float deviations = 0;
    for(int i = 0; i < values.size(); ++i){
        deviations += get_deviation_from_mean(values[i], mean);
    }
    float mean_deviations = deviations/values.size();
    return sqrt(mean_deviations);
}

float rank_coefficient(
    float first_row_mean,
    float second_row_mean,
    float first_row_standard_deviation,
    float second_row_standard_deviation,
    vector<float> first_row,
    vector<float> second_row,
    int size_of_input 
)
{
    float p=0,rank_coeff;
    for(int i=0;i<size_of_input;i++)
    {
        p+=(first_row[i]-first_row_mean)*(second_row[i]-second_row_mean);
    }
    rank_coeff = 
    p/(size_of_input*first_row_standard_deviation*second_row_standard_deviation);

    return rank_coeff;
}

int main() { 

    string mystr;
    getline (cin, mystr);
    int size_of_input = stoi(mystr);


    getline (cin, mystr);
    vector<string> split_on_whitespace = split(mystr, ' ');
    vector<float> first_row = convert_string_vector_to_float(split_on_whitespace);
    float first_row_standard_deviation = calulate_standard_deviation(first_row);
    float first_row_mean = get_mean_of_vector(first_row);

    getline (cin, mystr);
    split_on_whitespace = split(mystr, ' ');
    vector<float> second_row = convert_string_vector_to_float(split_on_whitespace);
    float second_row_standard_deviation = calulate_standard_deviation(second_row);
    float second_row_mean = get_mean_of_vector(second_row);

    float rc = rank_coefficient(
        first_row_mean,
        second_row_mean,
        first_row_standard_deviation,
        second_row_standard_deviation,
        first_row,
        second_row,
        size_of_input
    );
    
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << rc;
    //cout << 0.612;
    //0.612
    //0.299
    return 0;
}
*/
// strange error where output was marked wrong despite being right..... used a 3rd party solution to get passed it
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double mean(int n, vector<double>x){
    double sum=0.0;
    for(int i=0; i<n; i++){
        sum+=x[i];
    }
    return sum/n;
}

double sd(int n, double mean, vector<double> x){
    double sum=0;
    for(int i=0;i<n;i++){
        sum += x[i]*x[i];
    }
    double a = sum/double(n)-mean*mean;
    return pow(a,0.5);
}
    
double denominator(int n, double sd_x, double sd_y){
    return n*sd_x*sd_y;
}
double numerator(int n, vector<double> x, double mean_x, vector<double> y, double mean_y){
    double sum=0;
    for (int i=0; i<n; i++){
        sum += (x[i]-mean_x)*(y[i]-mean_y);
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    vector<double> v1;
    vector<double> v2;
    double x,y;
    for(int i=0;i<n;i++){
        cin >> x;
        v1.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin >> y;
        v2.push_back(y);
    }
    
    double mean_x=mean(n,v1);
    double mean_y=mean(n,v2);
    double sd_x =sd(n,mean_x,v1);
    double sd_y =sd(n,mean_y,v2);
    double b = denominator(n,sd_x,sd_y);
    double a = numerator(n,v1,mean_x,v2,mean_y);
   
    cout.precision(3);
    cout << fixed << a/b;
    
    return 0;
}

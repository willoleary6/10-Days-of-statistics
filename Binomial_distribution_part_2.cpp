#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
#include <iomanip>
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

float factorial(float n){
    if(n == 0){
        return 1;
    }else{
        float factorial = 1;
        for(int i = 1; i <=n; ++i)
        {
            factorial *= i;
        }
        return factorial;
    }
}

float combination (float n, float k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}

float binomial(float n, float k, float p){
    return combination(n, k) * pow(p, k) * pow(1 - p, n - k);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string mystr;

    // values
    getline (cin, mystr);
    vector<string> values = split(mystr, ' ');

    vector<float> float_inputs = convert_string_vector_to_float(values);

    float ratio = float_inputs[0];
    float number_of_subjects = float_inputs[1];
    

    float results = 0;
    for(int i = 0; i < 3; ++i){
        results += binomial(number_of_subjects,i, ratio/100);
    }

    cout << std::setprecision(3);
    cout << results << endl;
    results = 0;
    for(int i = 2; i < number_of_subjects+1; ++i){
        results += binomial(number_of_subjects,i, ratio/100);
    }

    cout << std::setprecision(3);
    cout << results << endl;

    return 0;
}


/*

def factorial(n):
    return 1 if n == 0 else n * factorial(n - 1)


def combination(n, k):
    return factorial(n) / (factorial(k) * factorial(n - k))


def binomial(n, k, p):
    return combination(n, k) * pow(p, k) * pow(1 - p, n - k)


b, g = map(float, input().strip().split(' '))

sum([binomial(6, i, b / (b+ g)) for i in range(3, 7)]

result = round(sum([binomial(6, i, b / (b+ g)) for i in range(3, 7)]), 3)
print(result)
*/

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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string mystr;

    // values
    getline (cin, mystr);
    vector<string> string_propabilty_vector = split(mystr, ' ');
    vector<float> float_propabilty_vector = convert_string_vector_to_float(string_propabilty_vector);
    
    float propability = float_propabilty_vector[0]/float_propabilty_vector[1];

    getline (cin, mystr);
    float iteration = stof(mystr);
    printf("%.3lf\n", 1 - pow(1-propability,iteration));
    return 0;
}




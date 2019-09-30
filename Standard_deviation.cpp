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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    string mystr;
    getline (cin, mystr);
    int size_of_input = stoi(mystr);


    getline (cin, mystr);


    vector<string> split_on_whitespace = split(mystr, ' ');

    vector<float> input_floats = convert_string_vector_to_float(split_on_whitespace);

    cout << calulate_standard_deviation(input_floats);
    return 0;
}




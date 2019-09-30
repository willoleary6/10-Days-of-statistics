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

float get_median_of_vector(vector<float> vector_to_be_averaged){
    sort(vector_to_be_averaged.begin(), vector_to_be_averaged.end()); 
    float median = 0;
    if(vector_to_be_averaged.size() % 2 == 0){
        median = (
            vector_to_be_averaged[(vector_to_be_averaged.size()/2)]
            + vector_to_be_averaged[(vector_to_be_averaged.size()/2) -1]
        )/2;
    }else{
        median = vector_to_be_averaged[(vector_to_be_averaged.size()/2)];
    }
    return median;
}

vector<float> get_quartile(vector<float> values, bool upper, float median){
    sort(values.begin(), values.end()); 
    vector<float> quartile_values;

    for(int i = 0; i < values.size(); ++i){
        if(upper){
            if(median < values[i]){
                quartile_values.push_back(values[i]);
            }
        }else{
            if(median > values[i]){
                quartile_values.push_back(values[i]);
            }
        }
    }

    return quartile_values;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    string mystr;
    getline (cin, mystr);
    int size_of_input = stoi(mystr);

    //cout << size_of_input;

    getline (cin, mystr);

    //cout << mystr;

    vector<string> split_on_whitespace = split(mystr, ' ');

    vector<float> input_floats = convert_string_vector_to_float(split_on_whitespace);
    float median = get_median_of_vector(input_floats);
    vector<float> lower_quartile = get_quartile(input_floats, false, get_median_of_vector(input_floats));

    vector<float> upper_quartile = get_quartile(input_floats, true, get_median_of_vector(input_floats));

    
    cout << get_median_of_vector(lower_quartile) << endl;
    cout << get_median_of_vector(input_floats) << endl;
    cout << get_median_of_vector(upper_quartile) << endl;
    //cout << get_quartile(input_floats, true, get_median_of_vector(input_floats));
    return 0;
}




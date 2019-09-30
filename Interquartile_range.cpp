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
            + vector_to_be_averaged[(vector_to_be_averaged.size()/2)]
        )/2;
    }else{
        median = vector_to_be_averaged[(vector_to_be_averaged.size()/2 +1)]; // weird results ...
    }
    return median;
}

vector<float> get_quartile(vector<float> values, bool upper, float median){
    sort(values.begin(), values.end()); 
    vector<float> quartile_values;
    for(int i = 0; i < values.size(); ++i){
        if(upper){
            if(median <= values[i]){
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
vector<float> create_set_of_values_respective_to_frequencies(vector<float> value_floats, vector<float> frequency_floats){
    vector<float> values_on_frequency;

    for(int i =0; i < value_floats.size(); ++i){
        for(int j = 0; j < frequency_floats[i]; ++j){
            values_on_frequency.push_back(value_floats[i]);
        }
    }
    sort(values_on_frequency.begin(), values_on_frequency.end());
    return values_on_frequency;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    string mystr;
    getline (cin, mystr);
    int size_of_input = stoi(mystr);

    // values
    getline (cin, mystr);
    vector<string> values = split(mystr, ' ');

    //vector<string> values = split("10 40 30 50 20", ' ');


    vector<float> value_floats = convert_string_vector_to_float(values);

    // frequencies
    getline (cin, mystr);
    vector<string> frequencies = split(mystr, ' ');

    //vector<string> frequencies = split("1 2 3 4 5", ' ');
    
    vector<float> frequency_floats = convert_string_vector_to_float(frequencies);
    vector<float> frequency_X_values = create_set_of_values_respective_to_frequencies(value_floats, frequency_floats);
   for (auto i = frequency_X_values.begin(); i != frequency_X_values.end(); ++i)
    float median = get_median_of_vector(frequency_X_values);
    vector<float> lower_quartile = get_quartile(frequency_X_values, false, get_median_of_vector(frequency_X_values));

    vector<float> upper_quartile = get_quartile(frequency_X_values, true, get_median_of_vector(frequency_X_values));
    float interquartile_range = get_median_of_vector(upper_quartile) - get_median_of_vector(lower_quartile);
    
    

    printf("%.1f", floor(interquartile_range)); 

    return 0;
}




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

float get_mean_of_vector(vector<string> vector_to_be_averaged){
    float sum_value = 0.0;
    for(int i = 0; i < vector_to_be_averaged.size(); ++i)
        sum_value += atof(vector_to_be_averaged[i].c_str());
    float mean = sum_value/vector_to_be_averaged.size();
    return mean;

}


float get_median_of_vector(vector<string> vector_to_be_averaged){
    //float sum_value = 0.0;
    vector<float> int_conversion_of_avg_vector;
    for(int i = 0; i < vector_to_be_averaged.size(); ++i)
        int_conversion_of_avg_vector.push_back(atof(vector_to_be_averaged[i].c_str()));

    sort(int_conversion_of_avg_vector.begin(), int_conversion_of_avg_vector.end()); 

    float median = (int_conversion_of_avg_vector[(vector_to_be_averaged.size()/2)]
    + int_conversion_of_avg_vector[(vector_to_be_averaged.size()/2) -1]
    )/2;
    return median;
}

float get_mode_of_vector(vector<string> vector_to_be_averaged){
    vector<float> int_conversion_of_avg_vector;
    for(int i = 0; i < vector_to_be_averaged.size(); ++i)
        int_conversion_of_avg_vector.push_back(atof(vector_to_be_averaged[i].c_str()));

    sort(int_conversion_of_avg_vector.begin(), int_conversion_of_avg_vector.end()); 

    vector<int> no_of_occurances;
    for(int i = 0; i < int_conversion_of_avg_vector.size(); ++i){
        no_of_occurances.push_back(0);
        for(int j = 0; j < int_conversion_of_avg_vector.size(); ++j){
            if (int_conversion_of_avg_vector[i] == int_conversion_of_avg_vector[j]){
                no_of_occurances[j]++;
            }
        }
    }
    float max_occurances = (float)*max_element(no_of_occurances.begin(),         no_of_occurances.end());
    vector<float> vector_of_most_numerous_values;
    for(int i = 0; i < int_conversion_of_avg_vector.size(); ++i){
        if (no_of_occurances[i] == max_occurances){
            vector_of_most_numerous_values.push_back(int_conversion_of_avg_vector[i]);

        }
    }

    return vector_of_most_numerous_values[0];
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
    
    cout << get_mean_of_vector(split_on_whitespace) << endl;
    cout << get_median_of_vector(split_on_whitespace) << endl;
    cout << get_mode_of_vector(split_on_whitespace) << endl;

    return 0;
}

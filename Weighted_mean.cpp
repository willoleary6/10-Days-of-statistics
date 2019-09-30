#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
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

float get_sum_of_weights(vector<string> weights){
    float sum_value = 0.0;
    for(int i = 0; i < weights.size(); ++i)
        sum_value += atof(weights[i].c_str());
    return sum_value;
}

float get_weighted_mean_of_vector(vector<string> vector_to_be_averaged, vector<string> weights){
    float sum_value = 0.0;
    for(int i = 0; i < vector_to_be_averaged.size(); ++i)
        sum_value += (atof(vector_to_be_averaged[i].c_str()) * atof(weights[i].c_str()));
    float mean = sum_value/get_sum_of_weights(weights);
    return mean;

}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    string mystr;
    getline (cin, mystr);
    int size_of_input = stoi(mystr);

    //cout << size_of_input;

    getline (cin, mystr);

    //cout << mystr;

    vector<string> values = split(mystr, ' ');

    getline (cin, mystr);
    vector<string> weights = split(mystr, ' ');
    cout << fixed;
    cout << setprecision(1);
    cout << get_weighted_mean_of_vector(values, weights) << endl;
    return 0;
}




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

vector<float> convert_string_vector_to_float(vector<string> string_vector){
    vector<float> float_conversion_of_string_vector;
    for(int i = 0; i < string_vector.size(); i++){
        float_conversion_of_string_vector.push_back(stof(string_vector[i]));
    }
    return float_conversion_of_string_vector;
}

float highest_value(vector<float> arr){
    float highest = 0;
    for(int i = 0; i< arr.size(); i++){
        if(arr[i] > arr[highest])
            highest = i;
    }
    return highest;
}

vector<int> get_rank(vector<float> arr){
    vector<int> rank(arr.size());
    vector<bool> used(arr.size());
    for(int i = 0; i < arr.size(); i++){
        used[i] = false;
    }
    int lowest = highest_value(arr);
    for(int i = 1; i <= arr.size(); i++){
        for(int j = 0; j< arr.size(); j++){
            if(used[j] == false && arr[lowest] > arr[j])
                lowest = j;
        }
        rank[lowest] = i;
        used[lowest] = true;
        lowest = highest_value(arr);
    }
    return rank;
}

float deviation(vector<int> first_row_rank,vector<int> second_row_rank){
    float deviation = 0.00;
    for(int i = 0 ; i < first_row_rank.size(); i++){
        deviation += pow(first_row_rank[i]-second_row_rank[i],2);
    }
    return deviation;
}

double get_spearman_coefficient(vector<int> first_row_rank,vector<int> second_row_rank){
   
    return 1-((6*deviation(first_row_rank,second_row_rank))/(first_row_rank.size()*(pow(first_row_rank.size(), 2)-1)));
}

int main() { 

    string mystr;
    getline (cin, mystr);
    int size_of_input = stoi(mystr);


    getline (cin, mystr);
    vector<string> split_on_whitespace = split(mystr, ' ');
    vector<float> first_row = convert_string_vector_to_float(split_on_whitespace);
    vector<int> first_row_rank = get_rank(first_row);

    getline (cin, mystr);
    split_on_whitespace = split(mystr, ' ');
    vector<float> second_row = convert_string_vector_to_float(split_on_whitespace);
    vector<int> second_row_rank = get_rank(second_row);

    
    
    float spearman_coefficient =get_spearman_coefficient(first_row_rank,second_row_rank);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << spearman_coefficient;
    return 0;
}
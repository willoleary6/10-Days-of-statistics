#include <vector>
#include <iostream>
using namespace std;

vector<vector<double>> mul(vector<vector<double>> x,vector<vector<double>> y){
    vector<vector<double>> res(x.size(), vector<double>(y[0].size()));
    
    for(int i =0; i< res.size(); i++){
        for(int j =0; j< res[0].size(); j++){
            res[i][j] =0.0;
            for(int k =0; k<x[0].size(); k++)
                res[i][j] += x[i][k]*y[k][j]; 
        }
    }
    return res;
}

void swap_row(vector<double> *x, vector<double> *y){
    for(int i=0; i< x->size(); i++){
        double temp = (*x)[i];
        (*x)[i] = (*y)[i];
        (*y)[i] = temp;
    }
}

vector<vector<double>> inv(vector<vector<double>> x){
    vector<vector<double>> res(x.size(), vector<double>(x.size(),0));
    int n = x.size();
    for(int i=0; i< n; i++)
        res[i][i] = 1.0;
    // converting to row-echelon
    for(int j = 0; j < n-1; j++){
        if(x[j][j]==0)
            for(int i = j+1; i < n; i++){
                if(x[i][j]!=0){
                    swap_row(&x[j],&x[i]);
                    swap_row(&res[j],&res[i]);
                    break;
                }
            }
        if(x[j][j]==0)
            continue;
        for(int i = j+1; i< n; i++){
            double factor = -x[i][j]/x[j][j];
            for(int k=0; k< n; k++){
                x[i][k] += factor*x[j][k];
                res[i][k] += factor*res[j][k];
            }
        }
    }
    //converting to diagnoal form
    for(int i = n-1; i>0; i--){
        for(int j = i-1; j>=0; j--){
            double factor = -x[j][i]/x[i][i];
            for(int k =0; k< n; k++){
                x[j][k] += factor*x[i][k];
                res[j][k] += factor*res[i][k];
            }
        }
    }
    //converting to unit.
    for(int i=0; i< n; i++){
        for(int j=0; j <n; j++)
            res[i][j]/=x[i][i];
    }
    return res;
}

int main() {
    int col,row;
    cin>>col>>row;
    vector<vector<double>> A(row,vector<double>(col+1)),AT(col+1,vector<double>(row)),B(row, vector<double>(1));
    //reading from stdin and making AT.
    for(int i = 0 ; i < row; i++){
        A[i][0] = 1.0;
        AT[0][i] = 1.0;
        for(int j = 1 ;j <= col; j++){
            cin>>A[i][j];
            AT[j][i] = A[i][j];
        }
        cin>>B[i][0];
    }
    auto ans = mul(inv(mul(AT,A)),mul(AT,B));
    int f;
    cin>>f;
    for(int i=0; i<f; i++){
        vector<double> v(col+1);
        v[0] = 1.0;
        for(int j=1; j<= col; j++)
            cin>>v[j];
        double final_ans =0.0;
        for(int j=0;  j< ans.size(); j++)
            final_ans += ans[j][0]*v[j];
        cout<<final_ans<<endl;
    }
    return 0;
}
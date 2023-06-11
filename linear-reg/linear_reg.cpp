#include <bits/stdc++.h>
#include<cmath>
using namespace std;

double OLS(double *b,vector<int> x,int y,int n){
    double pred = 0;
    
    for (int i = 0; i < n; i++){
        cout << b[i] << "\n";
        pred += double(b[i]*x[i]);
    }
    return pow((pred-y),1);
}



double* gradient_descent(vector<vector<int>> x, vector<int>y,double alpha){
    int m = y.size();
    int n = x[0].size();
    double err_b = 1000;
    double err_n = 0;
    double* coeff = new double[n];
    int i = 0;
    for (int i = 0; i < n;i++){
        coeff[i] = 0;
    }
    double error[m];
    while(1){
        i++;
        double err_n = 0;
        // calculating error
        for (int i = 0;i < m;i++){
            error[i] = OLS(coeff,x[i],y[i],n);
            err_n += error[i];
        }
        err_n /= n+1;

        // computing coefficients
        for (int i = 0;i < n;i++){
            double delta = 0;
            for (int j = 0;j < n;j++){
                delta += double(error[i]*x[j][i]);
            }
            delta = delta/n+1;
            coeff[i] = coeff[i] - delta*alpha;
        }
        // checking break conditions
        if (abs(err_b - err_n) < 0.000001){
            break; 
        } 

        err_b = err_n;
        
    }
    return coeff;
}

void print_preds(double* b,vector<vector<int>> x){
    int n = x.size();
    for (int i = 0; i < n;i++){
        int m = x[0].size();
        double pred = 0;
        for (int j = 0; j < m; j++){
            pred += (b[j]*x[i][j]);
        }
        cout << pred << "\n";
    }
}

int main(){
    vector<vector<int>> x = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{1,8}};
    vector<int> y = {2,4,6,8,10,12,14,16};
    double *coeff = gradient_descent(x,y,0.01);
    cout << coeff[0]<< " " << coeff[1]<<"\n";
    cout << coeff[2] << "\n";
    print_preds(coeff,x);
    return 0;
}
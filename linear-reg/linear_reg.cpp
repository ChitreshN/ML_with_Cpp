#include <bits/stdc++.h>
using namespace std;

double OLS(double *b,vector<int> x,int y,int n){
    double pred = 0;
    for (int i = 0; i < n; i++){
        pred += double(b[i]*x[i]);
    }
    return (pred - double(y));
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
        for (int i = 0;i < m;i++){
            error[i] = OLS(coeff,x[i],y[i],n);
            err_n += error[i];
        }
        err_n /= n+1;
        for (int i = 0;i < n;i++){
            double delta = 0;
            for (int j = 0;j < n;j++){
                delta += double(error[i]*x[j][i]);
            }
            delta = delta/n+1;
            coeff[i] = coeff[i] - delta*alpha;
        }
        if (abs(err_n) < 1){
            cout << err_n << "\n"; 
            break; 
        }
        
        err_b = err_n;
        
    }
    cout << i << "\n";   
    return coeff;
}



int main(){
    vector<vector<int>> x = {{1,1},{1,2},{1,3},{1,4},{1,5}};
    vector<int> y = {2,4,6,8,10};
    double *coeff = gradient_descent(x,y,0.001);
    cout << coeff[0] << " " << coeff[1];
    return 0;
}
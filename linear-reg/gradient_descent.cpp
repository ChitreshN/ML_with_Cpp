#include <bits/stdc++.h>
#include<array>


double prediction(std::vector<int> x, double* b){
    double pred = b[0];
    int number_of_parameters = x.size();
        
    for (int i = 0; i < number_of_parameters;i++){
        pred += x[i]*b[i+1];
    }

    return pred;
}


double* gradient_descent(std::vector<std::vector<int>> X, std::vector<int> Y,int epochs,double alpha){

    // initialize the weights to 0
    int m = X.size();
    int n = X[0].size();
    double* b = new double[n+1];

    for (int i = 0;i <= n;i++){
        b[i] = 0;
    }

    // start gradient descent
    // calculate error in each epoch
    // use error to calculate gradient and update weights accordingly

    int current_epoch = 0;
    while(++current_epoch <= epochs){
        
        // calculate predictions
        double predictions[m];
        
        for (int i = 0;i < m;i++){
            predictions[i] = prediction(X[i],b);
        }

        // Update coefficients by calculating deltas
        
        // Delta is (2/m)*sigma(pred-y)*x for all x's other than b0
        // For b0 replace x with 1 in the above formula

        for (int i = 0;i <= n;i++){
            if(i == 0){
                double place_holder = 0;
                for (int j = 0;j < m;j++){
                   place_holder += predictions[j] - Y[j]; 
                }
                place_holder = place_holder/m;

                b[0] = b[0] - alpha*place_holder;            
            }
            else{
                double place_holder = 0;
                for(int j = 0;j < m;j++){
                    place_holder += (predictions[j] - Y[j])*X[j][i-1];
                }
                place_holder = place_holder/m;
                b[i] = b[i] - alpha*place_holder; 
            }
        }
    }
    return b;
}


int main(){
    std::vector<std::vector<int>> X;
    std::vector<int> Y;
    X = {{1,1},{2,3},{2,4},{3,2},{4,5},{5,11}};
    Y = {2,5,6,5,9,16};
    double *b = gradient_descent(X,Y,1000,0.01);
    std::cout << b[0] << " " << b[1] << "\n";
    int m = X.size();  
    for (int i = 0;i < m;i++){
        std::cout << prediction(X[i],b) << " ";
        if (i == m-1) std::cout << "\n";
    }

    
}
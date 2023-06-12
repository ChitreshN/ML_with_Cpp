// Similar to normal gradient descent but the "batch" size
// is not the whole data set, that is we update the coefficients 
// multiple times for one pass over the data set
// No.of times depend on the batch size

// [TODO] 
// 1.divide the dataset based on the batch size
// 2.Perform gradient descent on each batch


#include <bits/stdc++.h>

double prediction(std::vector<int> x, double* b){
    double pred                 = b[0];
    int number_of_parameters    = x.size();
        
    for (int i = 0; i < number_of_parameters;i++){
        pred += x[i]*b[i+1];
    }

    return pred;
}

 
double* gradient_descent(std::vector<std::vector<int>> X, std::vector<int> Y, int epochs, int batch_size, double alpha) {
    int m = X.size();
    int n = X[0].size();
    double* b = new double[n + 1];

    for (int i = 0; i <= n; i++) {
        b[i] = 0;
    }

    int current_epoch = 0;

    while (++current_epoch <= epochs) {
        int passes_for_single_epoch = ceil((double)m / batch_size);

        for (int i = 0; i < passes_for_single_epoch; i++) {
            double predictions[batch_size];
            int init = i * batch_size;
            int no_of_samples;
            int end;

            if (i != passes_for_single_epoch - 1) {
                no_of_samples = batch_size;
                end = i * batch_size + batch_size;
            } else {
                if (m % batch_size == 0) {
                    no_of_samples = batch_size;
                    end = i * batch_size + batch_size;
                } else {
                    no_of_samples = m % batch_size;
                    end = i * batch_size + (m % batch_size);
                }
            }

            for (int j = 0; j < no_of_samples; j++) {
                predictions[j] = prediction(X[init + j], b);
            }

            for (int j = 0; j <= n; j++) {
                if (j == 0) {
                    double temp = 0;
                    for (int k = init; k < end; k++) {
                        temp += predictions[k - init] - Y[k];
                    }
                    temp = temp / no_of_samples;

                    b[0] = b[0] - alpha * temp;
                } else {
                    double temp = 0;
                    for (int k = init; k < end; k++) {
                        temp += (predictions[k - init] - Y[k]) * X[k][j - 1];
                    }
                    temp = temp / no_of_samples;
                    b[j] = b[j] - alpha * temp;
                }
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
    double *b = gradient_descent(X,Y,500,4,0.01);
    int m = X.size();  
    for (int i = 0;i < m;i++){
        std::cout << prediction(X[i],b) << " ";
        if (i == m-1) std::cout << "\n";
    }  
}
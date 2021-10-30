#include <iostream>
#include <iomanip>
//Calculate in a simple way the sum of a series "1/n**2 n in 1, inf" 
//using variables of the double and float types.


//with float precision
float pow_f(float x, int n){
    return (n == 1) ? x : (x * pow_f(x, n - 1));;
}
float sum_f(float sum, int n){
    for(int i = 1; i < n; i++){
        sum += 1/pow_f(2, i);
    }
    return sum;
}

//with double precision
double pow_d(double x, int n){
    return (n == 1) ? x : (x * pow_d(x, n - 1));;
}
double sum_d(float sum, int n){
    for(int i = 1; i < n; i++){
        sum += 1/pow_d(2, i);
    }
    return sum;
}


main(){
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(20);
    std::cout << "with float precision sum = " << sum_f(0, 100000) << std::endl; //1.00000000000000000000
    std::cout << "with double precision sum = " << sum_d(0, 100000) << std::endl; //1.00000000000000000000
    std::cout << "right answer is 1" << std::endl;
    return 0;
}
    

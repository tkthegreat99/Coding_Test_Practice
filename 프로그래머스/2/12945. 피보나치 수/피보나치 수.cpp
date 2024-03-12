#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> fibona;

int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    for(int i = 2; i <= n; i++){
        fibona.push_back(fibona[i-1] % 1234567 + fibona[i-2] % 1234567);
    }
    return fibona[n];
}


int solution(int n) {
    fibona.push_back(0);
    fibona.push_back(1);
    return fibo(n) % 1234567;
    //Garden is Pretty
}
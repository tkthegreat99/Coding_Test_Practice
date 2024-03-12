#include <string>
#include <vector>
#include <iostream>

using namespace std;


int gcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}


int solution(vector<int> arr) {
    if(arr.size() == 1) return arr[0];
    int tmp = arr[0] * arr[1] / gcd(arr[0], arr[1]);
    if(arr.size() == 2) return tmp;

    for(int i = 2; i < arr.size(); i++) {
        tmp = tmp * arr[i] / gcd(tmp, arr[i]);
    }
    return tmp;
}

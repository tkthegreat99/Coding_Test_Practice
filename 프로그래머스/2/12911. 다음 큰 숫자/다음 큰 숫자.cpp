#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int namugi[30], i;
int Convert(int n){
    int cnt = 0;
    string tmp = "";
    fill(namugi, namugi + 30, 0);
    i = 0;
    while(n > 0){
        namugi[i] = n % 2;
        i++;
        n /= 2;
    }
    while(i > 0){
        i--;
        tmp += to_string(namugi[i]);
    }
    for(int i = 0 ; i < tmp.size(); i++){
        if(tmp[i] == '1') cnt++;
    }
    return cnt;
}

int solution(int n) {
    int std = Convert(n);
    while(1){
        n++;
        if(Convert(n) == std) break;
    }
    return n;
}
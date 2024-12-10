#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N, M;
vector<int> num;
long long modNum[1000 + 1];
long long pSum[1000000 + 1];

void input(){
    cin >> N >> M;
    num.resize(N);
    for(int i=0;i<N;i++){
        cin >> num[i];
    }
}

void init(){
    for(int i=1;i<=N;i++){
        pSum[i] = (pSum[i-1] + num[i-1]) % M;
        modNum[pSum[i]]++;
    }
}

long long combination(long long num){
    return ((num * (num-1)) / 2);
}

long long solution(){
	// 초기 값을 modNum[0]으로 하는 이유는 Step 2.에 나와있다.
    long long count = modNum[0];
    for(int i=0;i<M;i++){
    	// Step 3. 과정
        count += combination(modNum[i]);
    }
    return count;
}

int main(){
    fastio;
    input();
    init();
    cout << solution() << endl;

    return 0;
}
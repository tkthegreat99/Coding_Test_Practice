#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <iostream>
#include <algorithm>


using namespace std;


int isPrime(int number)
{
    if(number == 1 || number == 0) return 0;
    for(int i = 2; i <= sqrt(number); i++)
    {
        if(number % i == 0) return 0;
    }
    return 1;
}

int solution(string numbers) {
    int answer;
    
    unordered_set<int> s;
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i = 1; i <= numbers.size(); i++)
        {
            string tmp = numbers.substr(0, i);
            //cout << tmp << '\n';
            if(isPrime(stoi(tmp)))
            {
                //cout << "소수 : " << stoi(tmp) << '\n';
                s.insert(stoi(tmp));
            }
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    answer = s.size();
    
    
    
    return answer;
}

//모든 경우를 탐색하고 소수일 때 맞는지만 판별해주면 댐.

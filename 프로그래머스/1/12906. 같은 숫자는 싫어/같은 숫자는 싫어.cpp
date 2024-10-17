#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int tmp = 1000001;
    
    for(int i = 0 ; i < arr.size(); i++)
    {
        if(arr[i] != tmp) answer.push_back(arr[i]);
        tmp = arr[i];
    }
    
   return answer;
}

//queue에 계속 넣는데 전 원소와 다를 때만 집어넣음.
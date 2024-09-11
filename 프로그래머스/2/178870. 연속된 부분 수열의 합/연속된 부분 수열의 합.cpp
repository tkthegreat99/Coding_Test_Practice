#include <string>
#include <vector>
#include <iostream>

using namespace std;
int psum[1000001];
int mn = 1e11;
int st, en;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int lim = sequence.size();
    psum[0] = 0;
    psum[1] = sequence[0];
    for(int i = 1; i <= sequence.size(); i++){
        psum[i] = psum[i-1] + sequence[i-1];
        if(sequence[i-1] == k){
            answer.push_back(i-1);
            answer.push_back(i-1);
            return answer;
        }
        
    }
    
    
    
    for(int i = lim; i >= 0; i--){
        int l = 0;
        int r = i ;
        while(l <= r){
            int mid = (l + r) / 2;
            
            if(psum[i] - psum[mid] > k){
                l = mid + 1;
            }
            else if (psum[i] - psum[mid] < k){
                r = mid - 1;
            
            }
            else{
                mn = min(mn, i - mid);
                if(mn == i - mid){
                    st = mid;
                    en = i-1;
                }
                break;
            }
        }        
    }
    
    
    answer.push_back(st);
    answer.push_back(en);
    
    
    return answer;
}
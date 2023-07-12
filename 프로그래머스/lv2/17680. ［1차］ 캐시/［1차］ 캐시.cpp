#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//게시물을 가져오는 부분이 오래 걸린다 -> 캐시 크기를 얼마로 해야 최대 효율일까
// LRU
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if(cacheSize == 0){
        answer += cities.size() * 5;
        return answer;
    }
    
    vector<string> cache;
    for(int i = 0; i < cities.size(); i++){
        string std = cities[i];
        for(int j = 0; j < std.size(); j++){
            std[j] = tolower(std[j]);
        }
        
        auto it = find(cache.begin(), cache.end(), std);
        if(it != cache.end()){
            cache.erase(it);
            cache.push_back(std);
            answer++;
        }
        else{
            if(cache.size() < cacheSize) cache.push_back(std);
            
            
            else{
                cache.erase(cache.begin() + 0);
                cache.push_back(std);
            }
            answer += 5;
        }
        
    }
    
    
    
    
    return answer;
}
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> st;


int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    for(int i = 0; i < size ; i++){
        elements.push_back(elements[i]);
    }

    int cnt = 1;
    int tmp;
    for(int k = 0 ; k < size; k++){

        for(int i = 0; i < 2*size; i++){
            tmp = 0;
            for(int j = i; j < cnt + i; j++){
                tmp += elements[j % size];
            }
            st.insert(tmp);
        }
        cnt++;
    }
    answer = st.size();
    return answer;
}
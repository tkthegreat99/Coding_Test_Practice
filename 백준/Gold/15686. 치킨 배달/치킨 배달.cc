
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n, m, a[54][54], result = 987654321;
vector<vector<int>> chickenList;
vector<pair<int, int>> _home, chicken;



//무식하게 풀 수 있으면 무식하게 풀자.
//치킨 집 뽑고 모든 집과 거리를 비교해서 거리 중 가장 min값 더하면 된다.
//집 개수 최대 2N
//치킨집 개수 최대 13
// 13 C ?  * 100 
//1716 * 100 = 171600 충분


void combi(int start, vector<int> v) {
    if (v.size() == m) { // 조합들 중 사이즈가 m인애들.
        chickenList.push_back(v);
        return;
    }
    for (int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) _home.push_back({ i, j });  //집 좌표 pair로 벡터에 저장
            if (a[i][j] == 2) chicken.push_back({ i, j }); // 지킨집 좌표 pair로 벡터에 저장
        }
    }
    vector<int> v;
    
    combi(-1, v); // 조합 만들어서 chickenList에 넣어줌. chickenList에는 사이즈가 m인 벡터들이 들어있음
    for (vector<int> cList : chickenList) { //들어간 m사이즈 벡터들을 살펴보는데
        int ret = 0;
        for (pair<int, int> home : _home) { //집의 좌표값에서
            int _min = 987654321;
            for (int ch : cList) { // 치킨집들의 하나하나 좌표 ex) {{2, 3}, {3, 4}, {4, 5}} 있으면 {2, 3} 의 first와 home의 first, {2, 3}의 second와 home의 second를 비교.
                int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                _min = min(_min, _dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }
   
    cout << result << '\n';
}

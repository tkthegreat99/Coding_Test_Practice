#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    int l = 0;
    int r = people.size() - 1;

    sort(people.begin(), people.end());
    while(1) {
        if (l > r) return answer;

        if (people[r] + people[l] > limit) {
            //cout << "overlimit : " << people[r] << '\n';
            r--;
            answer++;

        } else {
            //cout << "nolimit : " << people[r] << "and" << people[l] << '\n';
            r--;
            l++;
            answer++;
        }
    }
}
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int rooms[1001];

int time(string str)
{
    return ((str[0] - '0')* 10 + str[1] -'0') * 60 + (str[3] - '0' ) *10 + str[4]- '0';
}



int solution(vector<vector<string>> book_time) {
    
    if(book_time.size() == 1) return 1;
    int answer = 0;
    sort(book_time.begin(), book_time.end());
    int mx_rooms = 1;
    
    int n = book_time.size();
    rooms[0] = time(book_time[0][1]);
    cout << book_time[0][0]  << " 1번째에 입실\n";
    for(int i = 1; i < n; i++)
    {
        int start_time = time(book_time[i][0]);
        int end_time = time(book_time[i][1]);
        int chk = 0;
        for(int j = 0; j < mx_rooms; j++)
        {
            if(rooms[j] + 10 <= start_time)
            {
                rooms[j] = end_time;
                cout << book_time[i][0] << " " << j+1 << "번째에 입실\n";
                chk = 1;
                break;
            }
        }
        if(chk == 0) 
        {
            mx_rooms++;
            rooms[mx_rooms-1] = end_time;
            cout << book_time[i][0] << " " << mx_rooms << "번째에 입실\n";
        }
    }
    
    answer = mx_rooms;
    
    for(int i = 0; i < mx_rooms; i++)
    {
        cout << rooms[i] << " ";
    }

    return answer;
}
/*
목표 : 필요한 최소 객실의 수를 return
한번 사용한 객실은 퇴실 시간 기준 10분 청소


*/
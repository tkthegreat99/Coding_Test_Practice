#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int time(string str){
   return ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + str[4] - '0';
}



string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int ps = time(pos);
    int videolen = time(video_len);
    int ops = time(op_start);
    int ope = time(op_end);
    
    
    for(auto x : commands){
        if(ps >= ops && ps <= ope) ps = ope;
        if(x == "next"){
            
            if (ps + 10 >= videolen) ps = videolen;
            else ps += 10;
        }
        else{
            if(ps - 10 <= 0) ps = 0;
            else ps -= 10;
        }
        if(ps >= ops && ps <= ope) ps = ope;
    }

    int min = ps / 60;
    int sec = ps - (60 * min);
    string strmin = "";
    string strsec = "";
    if(min < 10) strmin = "0" + to_string(min);
    else strmin = to_string(min);
    
    if(sec < 10) strsec = "0" + to_string(sec);
    else strsec = to_string(sec);
    
    answer = strmin + ":" + strsec;
    return answer;

}


#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int > m;
    
    
    int today_year, today_month, today_date;
    today_year = stoi(today.substr(0, 4));
    today_month = stoi(today.substr(5, 2));
    today_date = stoi(today.substr(8, 2));
    //오늘의 연도, 월, 일
    
    
    for(int i = 0 ; i < terms.size(); i++){
        m[terms[i][0]] = stoi(terms[i].substr(2));
    }
    //map 활용 정보 저장
    
    for(int i = 0 ; i < privacies.size(); i++){
        int std_year = stoi(privacies[i].substr(0, 4));
        int std_month = stoi(privacies[i].substr(5, 2));
        int std_date = stoi(privacies[i].substr(8, 2));
        char std = privacies[i][11];
        
        if (std_date == 1){
            std_date = 28;
            std_month += (m[std] - 1 );
            if(std_month > 12){
                int tmp = std_month / 12;
                std_year += tmp;
                std_month -= 12 * tmp;
            }    
        }
        else{
            std_month += m[std];
            std_date -= 1;
            if(std_month > 12){
                int tmp = std_month / 12;
                std_year += tmp;
                std_month -= 12 * tmp;
                if(std_month == 0){ std_month = 12; std_year -= 1;}
            }    
        }
        
        //유효기간보다 오늘 날짜가 이후이면 파기해야함.
        
        if(today_year > std_year){ // 만약 오늘의 연도가 유효기간의 연도보다 크다면
            answer.push_back(i + 1);
            continue;
        }
        else if (today_year == std_year){
            if(today_month > std_month){
                answer.push_back(i + 1);
                continue;
            } 
            else if (today_month == std_month){
                if(today_date > std_date){
                    answer.push_back(i + 1);
                    continue;
                }
            }
        }      
    }
    
    
    return answer;
}
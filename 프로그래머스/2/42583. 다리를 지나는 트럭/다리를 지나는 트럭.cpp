#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//1. 다리 길이만큼의 다리 큐를 생성한다. 
//2. 트럭이 입장할 떄 push되고, 앞에서 pop된다.
//3. 대기 트럭이 빌 때까지 반복한다.
//4. 매 시간마다, 트럭이 들어가기 전 (트럭이 들어갔을 때 위의 무게 < 다리 무게 threshold) 인지 확인한다.
//5. 트럭은 결국 다리 큐의 back 이 0 임과 동시에 트럭 무게가 맞을 때 올라갈 수 있다.
void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
}


bool Weight(int wait, int threshold, queue<int> q)
{
    int tmp = wait;
    while(!q.empty())
    {
        tmp += q.front();
        q.pop();
    }
    if(tmp <= threshold) return true;
    else return false;
}


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0;
    queue<int> BridgeQ;
    queue<int> TruckQ; // 트럭큐
    queue<int> FinishedQ; // 다 건넌 트럭큐
    for(int i = 0 ;i < bridge_length; i++) BridgeQ.push(0);
    //다리 큐 만들어주고, 0을 채움으로써 빔을 표시
    for(int i = 0 ; i < truck_weights.size(); i++) TruckQ.push(truck_weights[i]);
    //트럭들 큐를 만들어줌.
    
    while(1)
    {
        //print(BridgeQ);
        
         // 모두 다 건넌 경우 끝냄
        
        int cur = BridgeQ.front();
        time++;
        if(cur != 0) // 트럭이면
        {
            FinishedQ.push(cur);
            
            // 완료 큐에 넣어줌.
        }
        if(FinishedQ.size() == truck_weights.size()) return time;
        if(Weight(TruckQ.front() - cur, weight, BridgeQ)) // 맨 뒤가 비어있고 다리무게 고려해서 될 경우
        {
            BridgeQ.pop();
            BridgeQ.push(TruckQ.front()); // 다리에 올라감
            TruckQ.pop();
            TruckQ.push(0);
            continue;
        }
        BridgeQ.pop();
        BridgeQ.push(0); // 만약 새로운 트럭이 안들어온다면 0을 넣어줌.
    }
    
    
    
    return time;
}
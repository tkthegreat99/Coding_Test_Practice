#include <string>
#include <vector>
#include <set>



using namespace std;

set<int> numberSet;
int isPrime(int number)
{
    if (number == 1) return 0;
    if (number == 2) return 1;
    if (number % 2 == 0) return 0;
    for(int i = 3; i*i <= number; i++)
    {
        if (number % i == 0) return 0;
    }
    return 1;
}

void Combi(string comb, string others)
{
    if (comb != "")
        numberSet.insert(stoi(comb));

    for (int i = 0; i < others.size(); i++)
        Combi(comb + others[i], others.substr(0, i) + others.substr(i + 1));
}

int solution(string numbers) {
    Combi("", numbers);

    int answer = 0;
    for (int number : numberSet)
        if (isPrime(number))
            answer++;
    
    return answer;
}
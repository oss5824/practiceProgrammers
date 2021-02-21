#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; int len = progresses.size(); vector<int >res(len, 0);
    for (int i = 1; i <= 100; i++)
        for (int j = 0; j < len; j++)
        {
            if (progresses[j] >= 100)continue;
            progresses[j] += speeds[j]; if (progresses[j] >= 100) { res[j] = i; }
        }
    for (int i = 0; i < len; i++)
    {
        int s = res[i], cnt = 1;
        if (i != len - 1)
        {
            while (i != len - 1 && s >= res[i + 1]) { cnt++; i++; }
            answer.push_back(cnt);
        }
        else answer.push_back(cnt);
    }
    return answer;
}
int main()
{
    solution({ 95,95,95,95 }, { 4,3,2,1});
}
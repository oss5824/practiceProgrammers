#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, len = priorities.size();
    queue <pair<int, bool>>q;
    for (int i = 0; i < len; i++)if (i != location)q.push({ priorities[i] ,false }); else q.push({ priorities[i] ,true });
    sort(priorities.begin(), priorities.end(), greater<int>());
    while (!q.empty())
    {
        int lv = q.front().first; bool check = q.front().second;
        if (priorities[answer] == lv) { answer++; if (check == false)q.pop(); else break; }
        else { q.pop(); q.push({ lv,check }); }
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, int>m;
    for (string s : gems)m[s]++;
    int len = m.size();
    m.clear();
    int s = 0, e = 0, cnt = 0, distance = 1e9;
    while (1) {
        if (cnt == len) {
            if (distance > e - s) { distance = e - s; answer[0] = s + 1; answer[1] = e; }
            m[gems[s]]--; if (m[gems[s]] == 0) { m.erase(gems[s]); cnt--; } s++;
        }
        else if (e == gems.size())break;
        else { if (m[gems[e]] == 0)cnt++; m[gems[e]]++; e++; }
    }
    return answer;
}
int main()
{
    vector<int>v = solution({ "AA", "AB", "AC", "AA", "AC" });
    for (int i : v)cout << i << " ";
}
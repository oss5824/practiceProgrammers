#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[100001];
bool cmp(vector<int>a, vector<int>b) { return a.size() < b.size(); }
vector<int> solution(string s) {
    vector<int> answer;
    s.erase(0, 1); s.pop_back();
    cout << s << "\n";
    int len = s.length();
    vector<vector<int>>v;
    vector<int>v2; string tmp;
    for (int i = 0; i < len; i++) {
        if (s[i] == '{') { v2.clear(); continue; }
        if (s[i] == '}') { v2.push_back(stoi(tmp)); tmp = ""; v.push_back(v2); i++; continue; }
        if (s[i] == ',') { v2.push_back(stoi(tmp)); tmp = ""; continue; }
        tmp += s[i];
    }
    sort(v.begin(), v.end(), cmp);

    for (vector<int>vec : v) {
        for (int i : vec) {
            if (!visit[i]) { answer.push_back(i); visit[i] = true; }
        }
    }
    return answer;
}
int main()
{
    vector<int>v = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    for (int i : v)cout << i << " ";
}
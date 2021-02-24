#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string, pair<int, vector<pair<int, int>>>>m;
bool cmp(pair<int, int>a, pair<int, int>b)
{
    if (a.first == b.first) { if (a.second > b.second)return false; else return true; }
    else return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer; int len = genres.size();
    for (int i = 0; i < len; i++)
    {
        string s = genres[i]; int n = plays[i];
        m[s].first += n; m[s].second.push_back({ n,i });
    }
    vector<pair<int, vector<pair<int, int>>>>p;
    for (auto s : m)p.push_back({ s.second.first,s.second.second });
    sort(p.begin(), p.end(), greater<pair<int, vector<pair<int, int>>>>());
    for (auto s : p)
    {
        sort(s.second.begin(), s.second.end(), cmp);
        if (s.second.size() == 1)answer.push_back(s.second[0].second);
        else { answer.push_back(s.second[0].second); answer.push_back(s.second[1].second); };
    }
    for (auto s : answer)cout << s << " ";
    return answer;
}
int main()
{
    solution({ "classic", "pop", "classic", "classic", "pop" }, { 500,600,150,800,2500 });
}
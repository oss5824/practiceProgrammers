#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string s, sub;
int len;
map<string, int>cntMenu;
vector<bool>visit;
void solve(int num)
{
    if (num == len)return;
    if (sub.size() >= 2) {
        cntMenu[sub]++;
    }
    for (int i = num; i < len; i++) {
        if (!visit[i]) {
            sub.push_back(s[i]);
            visit[i] = true;
            solve(i);
            sub.pop_back();
            visit[i] = false;
        }
    }
}
bool cmp(pair<string, int>a, pair<string, int>b)
{
    if (a.first.length() < b.first.length())return true;
    else if (a.first.length() > b.first.length())return false;
    else return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (string str : orders) {
        len = str.length(); s = str; sub = ""; visit.assign(len, false); sort(s.begin(), s.end());
        solve(0);
    }

    vector<pair<string, int>>v(cntMenu.begin(), cntMenu.end());
    sort(v.begin(), v.end(), cmp);
    int start = 0, len = course.size(), sz = v.size();
    for (int i = 0; i < len; i++) {
        int val = course[i], maxVal = 0;
        for (int j = 0; j < sz; j++) {
            if (val == v[j].first.length() && maxVal <= v[j].second) {
                maxVal = v[j].second; 
                if (maxVal == 1)break;
                answer.push_back(v[j].first);
            }
            else if (val == v[j].first.length() && maxVal > v[j].second)break;
            else if (val < v[j].first.length())break;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

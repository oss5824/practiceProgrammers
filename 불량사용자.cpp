#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include <set>
using namespace std;
bool visit[8];
int banLen, userLen;
vector<int>v;
vector<string>userId, banId;
set<string>exist;
int answer = 0;
void solve(int num)
{
    if (v.size() == banLen) {
        int cnt = 0;
        bool visitTmp[8]; fill(visitTmp, visitTmp + 8, false);
        for (int i = 0; i < banLen; i++) {
            string ban = banId[i]; 
            for (int j : v) {
                if (visitTmp[j] || userId[j].length() != ban.length())continue;
                string user = userId[j]; bool check = true;
                int len = user.length();
                for (int k = 0; k < len; k++) {
                    if (ban[k] == '*' || user[k] == ban[k])continue;
                    else { check = false; break; }
                }
                if (check) { cnt++; visitTmp[j] = true; break; }
            }
        }
        if (cnt == banLen) {
            vector<int>vec = v;
            sort(vec.begin(), vec.end());
            string s;
            for (int i : vec)s += to_string(i);
            if (exist.count(s) == 0) { exist.insert(s); answer++; }
        }
        return;
    }
    for (int i = num; i < userLen; i++) {
        if (!visit[i]) {
            visit[i] = true;
            v.push_back(i);
            solve(num);
            visit[i] = false;
            v.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    banLen = banned_id.size(); userLen = user_id.size();
    userId = user_id; banId = banned_id; fill(visit, visit + 8, false);
    solve(0);
    return answer;
}
int main()
{
    cout<<solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" });
}

/*
        for (int i = 0; i < v.size(); i++) {
            if (banId[i].length() != userId[v[i]].length())continue;
            int len = userId[v[i]].length(); bool check = true;
            for (int j = 0; j < len; j++) {
                if (banId[i][j] == '*' || banId[i][j] == userId[v[i]][j])continue;
                else { check = false; break; }
            }
            if (check)cnt++; else break;
*/
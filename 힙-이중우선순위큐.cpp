#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int, greater<int>>ms;
    for (string s : operations)
    {
        if (s[0] == 'I')
        {
            int len = s.length(); string rs = ""; for (int i = 2; i < len; i++)rs += s[i];
            ms.insert(atoi(rs.c_str()));
        }
        else
        {
            if (ms.empty())continue;
            if (s == "D 1") ms.erase(ms.begin());
            else if (s == "D -1")ms.erase(--ms.end());
        }
    }
    if (ms.empty())return { 0,0 };
    else return { *ms.begin(),*(--ms.end()) };
}
int main()
{
    vector<int>v = solution({ "I 7","I 5","I -5","D -1" });
    for (int i : v)cout << i << " ";
}
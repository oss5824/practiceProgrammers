#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer; int len = answers.size(), res1 = 0, res2 = 0, res3 = 0, res = 0;
    int a[5] = { 1,2,3,4,5 }, b[8] = { 2,1,2,3,2,4,2,5 }, c[10] = { 3,3,1,1,2,2,4,4,5,5 };
    for (int i = 0; i < len; i++) { int idx = i % 5; if (a[idx] == answers[i])res1++; }
    for (int i = 0; i < len; i++) { int idx = i % 8; if (b[idx] == answers[i])res2++; }
    for (int i = 0; i < len; i++) { int idx = i % 10; if (c[idx] == answers[i])res3++; }
    res = max(max(res1, res2), res3);
    if (res == res1)answer.push_back(1); if (res == res2)answer.push_back(2); if (res == res3)answer.push_back(3);
    return answer;
}
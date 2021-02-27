#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    sort(lost.begin(), lost.end()); sort(reserve.begin(), reserve.end());
    vector<bool>l(n + 2, false); for (int i : lost)l[i] = true;
    vector<bool>v(n + 2, false); for (int i : reserve) { if (!l[i]) { v[i] = true; } else { l[i] = false; answer++; } }
    for (int i : lost)
    {
        if (!l[i])continue;
        if (i == 1 && v[2] == true) { v[2] = false; answer++; }
        else if (i == n && v[n - 1] == true) { v[n - 1] = true; answer++; }
        else if (v[i - 1] == true) { v[i - 1] = false; answer++; }
        else if (v[i + 1] == true) { v[i + 1] = false; answer++; }
    }
    return answer;
}
int main()
{
    cout << solution(3, { 1,2 }, { 2,3 });
}
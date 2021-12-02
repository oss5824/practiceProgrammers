#include <string>
#include <vector>

using namespace std;

vector<int>v;
int targ;
int answer = 0;
void solve(int num,int sum)
{
    if (num == v.size()) { if (sum == targ)answer++; return; }
    solve(num + 1, sum + v[num]);
    solve(num + 1, sum - v[num]);
}
int solution(vector<int> numbers, int target) {
    v = numbers; targ = target;
    solve(0, 0);
    return answer;
}
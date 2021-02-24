#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int>m;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (string s : completion)m[s]++;
    for (string s : participant) { if (m[s] == 0) { answer = s; break; } else m[s]--; }
        return answer;
}
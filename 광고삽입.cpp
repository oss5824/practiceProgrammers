#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
typedef long long ll;
using namespace std;
int arr[360001];
int strToTime(string str)
{
    int h = stoi(str.substr(0, 2)) * 3600;
    int m = stoi(str.substr(3, 2)) * 60;
    int s = stoi(str.substr(6, 2));
    return h+m+s;
}
string timeToStr(int num)
{
    int h = num / 3600, m = (num % 3600) / 60, s = (num % 3600) % 60;
    string h1 = to_string(h), m1 = to_string(m), s1 = to_string(s);
    if (h1.length() == 1)h1 = '0' + h1;
    if (m1.length() == 1)m1 = '0' + m1;
    if (s1.length() == 1)s1 = '0' + s1;
    return h1 + ':' + m1 + ':' + s1;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = ""; fill(arr, arr + 360001, 0);
    for (string s : logs) {
        int start = strToTime(s.substr(0, 8));
        int end = strToTime(s.substr(9, 8));
        for (int i = start; i < end; i++)arr[i]++;
    }
    int startTime = 0;
    int endTime = strToTime(play_time);
    int advTime = strToTime(adv_time);
    ll people = 0;
    ll maxPeople = 0;
    for (int i = 0; i < advTime; i++)maxPeople += (ll)arr[i];
    people = maxPeople;
    for (int i = advTime, start = 0; i < endTime; i++, start++) {
        people = people - (ll)arr[start] + (ll)arr[i];
        if (people > maxPeople) { maxPeople = people; startTime = start + 1; }
    }
    answer = timeToStr(startTime);
    return answer;
}
int main() {
    cout<<solution("99:59:59", "25:00:00", { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" });

}
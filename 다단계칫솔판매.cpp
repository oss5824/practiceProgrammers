#include <string>
#include <vector>
#include<map>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
map<string, int>mapping;
int par[10003];
int level[10003];
int result[10003];
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    memset(par, 0, sizeof(par)); memset(result, 0, sizeof(result));
    int num = 0; mapping["-"] = ++num;
    for (string s : enroll)mapping[s] = ++num;
    int len = enroll.size();
    for (int i = 0; i < len; i++) {
        int bottom = mapping[enroll[i]], top = mapping[referral[i]];
        par[bottom] = top; 
    }
    len = seller.size();
    for (int i = 0; i < len; i++) {
        int start = mapping[seller[i]];
        int before_value = 100 * amount[i];
        while (1) {
            int add_value = before_value / 10;
            if (add_value != 0)result[start] += (before_value - add_value);
            else { result[start] += before_value; break; }
            before_value /= 10;
            if (par[start] == 1)break;
            start = par[start];
        }
    }

    for (int i = 2; i <= num; i++) { cout << result[i] << " "; answer.push_back(result[i]); }

    return answer;
}
int main() {
    solution({ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" },
        { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" },
        { "sam", "emily", "jaimie", "edward" }
    , { 2, 3, 5, 4 });
    /*
    solution({ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" }, 
        { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" }, 
        { "young", "john", "tod", "emily", "mary" },
        { 12, 4, 2, 5, 10 });*/
}
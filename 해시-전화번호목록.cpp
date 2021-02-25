#include <string>
#include <vector>
#include <cstring>
using namespace std;
struct Node
{
    Node* node[10];
    bool finish = false;
    Node() { fill(node, node + 10, nullptr); }
    void insert(char* str)
    {
        if (*str == '\0') { finish = true; return; }
        int idx = *str - (int)'0';
        if (node[idx] == nullptr) node[idx] = new Node;
        node[idx]->insert(str + 1);
    }
    bool find(char* str)
    {
        int idx = *str - (int)'0'; bool check = false;
        for (Node* n : node) { if (n != nullptr)check = true; }
        if (finish == true && check == true)return false;
        else if (finish == true && check == false)return true;
        return node[idx]->find(str + 1);
    }
};
bool solution(vector<string> phone_book) {
    bool answer = true;
    Node* node = new Node();
    for (string s : phone_book) { char str[21]; strcpy(str, s.c_str()); node->insert(str); }
    for (string s : phone_book) { char str[21]; strcpy(str, s.c_str()); if (!node->find(str)) { answer = false; break; } }
    return answer;
}
int main()
{
    solution({ "12","123","1235","567","88" });
}
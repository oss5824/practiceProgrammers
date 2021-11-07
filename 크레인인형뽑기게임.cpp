#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int len = board.size();
    stack<int>s;
    for (int j : moves) {
        for (int i = 0; i < len; i++) {
            if (board[i][j - 1] != 0) {
                if (!s.empty()&&s.top() == board[i][j - 1]) { s.pop(); answer += 2; }
                else s.push(board[i][j - 1]);
                board[i][j - 1] = 0; break;
            }
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>>Map(rows);
    int start = 0;
    for (int i = 0; i < rows; i++)for (int j = 0; j < columns; j++)Map[i].push_back(++start);


    for (vector<int>v : queries) {
        int y1 = v[0] - 1, x1 = v[1] - 1;
        int y2 = v[2] - 1, x2 = v[3] - 1;

        vector<vector<int>>tmp = Map;
        int min_value = 10001;
        while (x1 < x2 && y1 < y2) {
            for (int start = x1; start < x2; start++) { Map[y1][start + 1] = tmp[y1][start]; min_value = min(min_value, tmp[y1][start]); }
            for (int start = y1; start < y2; start++) { Map[start + 1][x2] = tmp[start][x2]; min_value = min(min_value, tmp[start][x2]); }
            for (int start = x2; start > x1; start--) { Map[y2][start - 1] = tmp[y2][start]; min_value = min(min_value, tmp[y2][start]); }
            for (int start = y2; start > y1; start--) { Map[start - 1][x1] = tmp[start][x1]; min_value = min(min_value, tmp[start][x1]); }
            break;
        }
        answer.push_back(min_value);
    }
    return answer;
}


int main() {
   solution(6, 6, { {2,2,5,4},{3,3,6,6},{5,1,6,3} });
}
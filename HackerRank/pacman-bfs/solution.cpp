#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <queue>
using namespace std;

void nextMove( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
    vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<bool>> visited(r, vector<bool>(c));
    vector<vector<pair<int, int>>> parents(r, vector<pair<int, int>>(c)); 
    
    int iterations = 1;
    vector<pair<int, int>> expanded;
    queue<pair<int, int>> q;
    pair<int, int> end = {-1, -1};
    bool found = false;
    
    visited[pacman_r][pacman_c] = true;
    parents[pacman_r][pacman_c] = {-1, -1};
    expanded.push_back({pacman_r, pacman_c});
    q.push({pacman_r, pacman_c});
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        for (pair<int, int> move : moves) {
            int new_r = curr.first + move.first;
            int new_c = curr.second + move.second;
            if (
                (0 <= new_r && new_r < r && 0 <= new_c && new_c < c)
                && !visited[new_r][new_c]
                && grid[new_r][new_c] != '%'
            ) {
                iterations++;
                pair<int, int> examined = {new_r, new_c};
                visited[new_r][new_c] = true;
                parents[new_r][new_c] = {curr.first, curr.second};
                expanded.push_back({new_r, new_c});
                if (grid[new_r][new_c] == '.') {
                    found = true;
                    end = examined;
                    break;
                }
                q.push(examined);
             }
        }
        if (found) break;
    }
    vector<pair<int, int>> path;
    while (parents[end.first][end.second].first != -1) {
        path.push_back({end.first, end.second});
        end = parents[end.first][end.second];
    }
    path.push_back({pacman_r, pacman_c});
    
    cout << iterations << endl;
    
    for (pair<int, int> p : expanded) {
        cout << p.first << " " << p.second << endl;
    }
    
    cout << path.size() - 1 << endl;
    
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i].first << " " << path[i].second << endl;
    }
    
}

int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;
    
    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;
    vector<string> grid;

    for(int i=0; i<r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}

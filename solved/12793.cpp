#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int WAYS = 4;
const int WAY[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
    int width, height;
    double _start;
    cin >> width >> height >> _start;

    vector<string> board(2 * height + 1);
    for (int i = 0; i < 2 * height + 1; i++) {
        cin >> board[i];
    }

    int x = 2 * height, y = 2 * _start;
    int dx = -1, dy = -1;
    int answer = 0;
    while (true) {
        x += dx; y += dy;
        if (x == 2 * height) break;
        if (x == 0) dx *= -1;
        if (y == 0 || y == width * 2) dy *= -1;
        if (board[x][y] == '+') continue;
        if (board[x][y] == 'O') continue;

        int sx, sy;
        if (board[x][y] == '|' && board[x][y + dy] == 'B') {
            sx = x; sy = y + dy;
        }
        else if (board[x][y] == '-' && board[x + dx][y] == 'B') {
            sx = x + dx; sy = y;
        }
        else if (board[x][y] == 'B' || board[x][y] == '.') {
            sx = x; sy = y;
        }
        else {
            continue;
        }

        ++answer;

        queue< pair<int, int> > q;
        board[sx][sy] = 'O';
        q.push(make_pair(sx, sy));
        while (!q.empty()) {
            int cx = q.front().first, cy = q.front().second; q.pop();
            for (int w = 0; w < WAYS; w++) {
                int nx = cx + WAY[w][0], ny = cy + WAY[w][1];
                if (nx < 0 || nx >= 2 * height || ny < 0 || ny >= 2 * width) continue;
                if (board[nx][ny] == '.' || board[nx][ny] == 'B') {
                    board[nx][ny] = 'O';
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
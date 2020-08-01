// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int);

// Driver code to test above methods
int main() {
    // size of square board
    int t;
    cin >> t;
    while (t--) {
        int N;
        int a, b, c, d;
        cin >> N;
        cin >> a >> b;
        cin >> c >> d;
        int knightPos[] = {a, b};
        int targetPos[] = {c, d};
        cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size
int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    if (knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1]) return 0;

    int visited[N + 1][N + 1] = {0};
    visited[knightPos[0]][knightPos[1]] = 1;

    queue<pair<int, int> > q;
    q.push(pair<int, int>(knightPos[0], knightPos[1]));

    int rr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int cc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nextr = r + rr[i];
            int nextc = c + cc[i];

            if (nextr < 1 || nextc < 1 || nextr > N || nextc > N) continue;
            if (visited[nextr][nextc] != 0) continue;

            if (nextr == targetPos[0] && nextc == targetPos[1])
                return visited[r][c];

            visited[nextr][nextc] = visited[r][c] + 1;
            q.push(pair<int, int>(nextr, nextc));
        }
    }
    return 0;
}

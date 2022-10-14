#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int N;
int home[22][22]; // 집
int dp[22][22][3]; // 메모이제이션
 
void input();
void solve();
int dfs(int y, int x, int w);
 
int main() {
    fastio();
    input(); // 입력
    solve(); // 풀기
    return 0;
}
 
void input() { // 입력
    cin >> N;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> home[i][j];
}
 
void solve() { // 풀기
    cout << dfs(1, 2, 0); // 파이프 최초 위치
}
int dfs(int y, int x, int w) {
    if (y > N or x > N) return 0; // 범위
    if (home[y][x] == 1) return 0; // 가로 세로일때 체크해야 하는 부분
    if (w == 2 and (home[y][x] == 1 or home[y - 1][x] == 1 or home[y][x-1] == 1)) return 0; // 대각선일때 체크해야 하는 부분
    if (y == N and x == N) return 1; // 도착
    if (dp[y][x][w]) return dp[y][x][w];
    if (w == 0) return dp[y][x][w] = dfs(y, x + 1, 0) + dfs(y + 1, x + 1, 2);
    else if (w == 1) return dp[y][x][w] = dfs(y + 1, x, 1) + dfs(y + 1, x + 1, 2);
    else return dp[y][x][w] = dfs(y, x + 1, 0) + dfs(y + 1, x, 1) + dfs(y + 1, x + 1, 2);
}
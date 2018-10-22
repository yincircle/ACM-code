#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2000, MAXN = N * 2 + 10;
const int fx[4][2] = {{0, -1}, {0, 0}, {1, 0}, {1, -1}};

int n, s1[MAXN][MAXN], s2[MAXN][MAXN], vis[MAXN][MAXN], a[4];
char s[5];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int x, y, d;
		scanf("%s", s + 1);
		scanf("%d%d%d", &x, &y, &d);
		x += N, y += N;
		if (s[1] == 'A') {
			x -= d / 2, y -= d / 2;
			s1[x][y] ++;
			s1[x + d][y] --;
			s1[x][y + d] --;
			s1[x + d][y + d] ++;
		} else {
			s2[x][y - d / 2] --;
			s2[x][y + d / 2] --;
			s2[x - d / 2][y] ++;
			s2[x + d / 2][y] ++;
		}
	}
	for (int i = 0; i < 4; i ++) a[i] = (1 << i);
	for (int i = 1; i < MAXN; i ++)
		for (int j = 1; j < MAXN; j ++) {
			s1[i][j] += s1[i - 1][j] + s1[i][j - 1] - s1[i - 1][j - 1];
			s2[i][j] += s2[i - 1][j - 1] + s2[i - 1][j + 1];
			if (i >= 2) s2[i][j] -= s2[i - 2][j];
			if (!s2[i][j]) continue;
			for (int k = 0; k < 4; k ++){
				vis[i + fx[k][0]][j + fx[k][1]] |= (a[k] + a[(k + 1) % 4]);		
            }
		}
	double ans = 0;
	for (int i = 1; i < MAXN; i ++)
		for (int j = 1; j < MAXN; j ++) {
			if (s1[i][j]) ans += 1; else {
				for (int k = 0; k < 4; k ++) 
					if (vis[i][j] & a[k]) ans += 0.25;
			}
		}
	printf("%.2lf\n", ans);
}

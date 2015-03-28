#include <stdio.h>
#include <iostream>
using namespace std;
char map[9][9];
int flag;
int starti, startj,m,n,finishi,finishj;
int step[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
void DFS(int ii, int jj, int t)
{
	if (t == 0)
		return;
	if (flag) return;
	if (ii < 0 || ii >= n || jj < 0 || jj >= m)
		return;
	if (map[ii][jj] == 'X')
		return;
	if (ii==finishi&&jj==finishj&&t == 1){
		flag = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		map[ii][jj] = 'X';
		DFS(ii + step[i][0], jj + step[i][1], t - 1);
		map[ii][jj] = '.';
	}
}
int main(void){
	int  t;
	
	while (cin >> n >> m >> t)
	{
		if (m + n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
					starti = i, startj = j;
				if (map[i][j] == 'D')
					finishi = i, finishj = j;
			}
		}
		if ((starti + startj + finishi + finishj + t) % 2 == 1)
		{
			cout << "NO" << endl;
			continue;
		}
		flag = 0;
		DFS(starti, startj, t+1);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}
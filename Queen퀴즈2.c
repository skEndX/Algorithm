#include<stdio.h>
#include<string.h>
#include<math.h>
#define sz 8
int board[sz][sz];
int row;
int col;
int cnt = 0;

void initBoard() {
	memset(board, -1, sizeof(int)*sz*sz);
}

int OK(int _r, int _c) {
	for (int i = 0; i < sz; i++)
	{
		if (board[i][_c]!=-1&&i!=_r)
		{
			cnt++;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (board[_r][i]!=-1&&i!=_c)
		{
			cnt++;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j]!=-1&&abs(i-_r)==abs(j-_c)&&i!=_r&&j!=_c)
			{
				cnt++;
			}
		}
	}
	return cnt;
}

void find(int n) {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j]==n)
			{
				row = i;
				col = j;
			}
		}
	}
}

int main() {
	initBoard();
	int n, v1, v2;
	while (1)
	{
		scanf("%d %d %d", &n, &v1, &v2);
		if (n==-1&&v1==-1&&v2==-1)
		{
			break;
		}
		board[v1][v2] = n;
	}
	scanf("%d", &n);
	find(n);
	printf("%d", OK(row, col));
}
#include<stdio.h>
#include<string.h>
#include<math.h>
int sz;
int **board;
int cnt = 0;

void clearRow(int _r) {
	memset(&board[_r][0], 0, sizeof(int)*sz);
}
int OK(int _r, int _c) {
	for (int i = 0; i < _r; i++)
	{
		if (board[i][_c]!=0)
		{
			return 0;
		}
	}
	for (int i = 0; i < _c; i++)
	{
		if (board[_r][i]!=0)
		{
			return 0;
		}
	}
	for (int i = 0; i < _r; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j]!=0&&abs(i-_r)==abs(j-_c))
			{
				return 0;
			}
		}
	}
	return 1;
}
void show() {
	cnt++;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			printf("%d ", board[i][j]);
		}printf("\n");
	}printf("\n");
}
void checknext(int _r) {
	for (int i = 0; i < sz; i++)
	{
		clearRow(_r);
		if (OK(_r,i)==1)
		{
			board[_r][i] = 1;
			if (_r==sz-1)
			{
				show();
				return;
			}
			checknext(_r + 1);
		}
	}
}
int main() {
	scanf("%d", &sz);
	board = (int**)malloc(sizeof(int*)*sz);
	for (int i = 0; i < sz; i++)
	{
		board[i] = (int*)malloc(sizeof(int)*sz);
		memset(board[i], 0, sizeof(int*)*sz);
	}

	for (int c = 0; c < sz; c++)
	{
		clearRow(0);
		if (OK(0,c)==1)
		{
			board[0][c] = 1;
			checknext(1);
		}
	}
	printf("솔루션 개수 : %d", cnt);
}
#include<stdio.h>
#include<string.h>
#include<math.h>
#define sz 8
int board[sz][sz];

int OK(int _r, int _c) {
	for (int i = 0; i < sz; i++)
	{
		if (board[i][_c]==1&&i!=_r)
		{
			return 1;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (board[_r][i]==1&&i!=_c)
		{
			return 1;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j]==1&&abs(i-_r)==abs(j-_c)&&i!=_r&&j!=_c)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	board[a][b] = 1;
	int a1, b1;
	scanf("%d %d", &a1, &b1);
	board[a1][b1] = 1;

	printf("%d", OK(a, b));
}
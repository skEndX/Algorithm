#include<stdio.h>
#include<string.h>
#define sz 9
int sdk[sz][sz] = {
	4,0,7,5,0,0,0,0,8,
	0,5,0,7,0,0,4,0,9,
	0,0,6,0,0,4,0,7,0,
	9,0,0,6,0,0,2,4,3,
	0,4,0,9,0,3,0,8,0,
	7,3,1,0,0,2,0,0,5,
	0,2,0,8,0,0,7,0,0,
	3,0,9,0,0,6,0,5,0,
	5,0,0,0,0,7,3,0,4
};
int readsdk[sz][sz];
void solve(int _r, int _c);

void read() {
	memcpy(readsdk, sdk, sizeof(int)*sz*sz);
}
void show() {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			printf("%d ", sdk[i][j]);
		}
		printf("\n");
	}
}
void checknext(int _r, int _c) {
	if (_r==sz-1&&_c==sz-1)
	{
		show();
		return;
	}
	_c++;
	if (_c==sz)
	{
		_c = 0;
		_r++;
	}
	solve(_r, _c);
}
int OK(int _r, int _c, int value) {
	for (int i = 0; i < sz; i++)
	{
		if (sdk[i][_c]==value&&i!=_r)
		{
			return 0;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (sdk[_r][i]==value&&i!=_c)
		{
			return 0;
		}
	}
	int row = _r / 3;
	int col = _c / 3;
	for (int i = row*3; i < row*3+2; i++)
	{
		for (int j = col*3; j < col*3+2; j++)
		{
			if (sdk[i][j]==value&&i!=_r&&j!=_c)
			{
				return 0;
			}
		}
	}
	return 1;
}
void solve(int _r, int _c) {
	if (sdk[_r][_c]>0)
	{
		checknext(_r, _c);
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		memcpy(&sdk[_r][_c], &readsdk[_r][_c], sizeof(int)*sz*sz - sizeof(int)*(_r*sz + _c));
		if (OK(_r,_c,i)==1)
		{
			sdk[_r][_c] = i;
			checknext(_r, _c);
		}
	}
}

int main() {
	read();
	solve(0, 0);
	return 0;
}
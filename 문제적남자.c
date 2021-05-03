#include <stdio.h>
int sz;
int *arr;
int *read;
int cnt = 0;

int OK(int _c, int v)
{
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] == v)
		{
			return 0;
		}
	}
	return 1;
}

void show()
{
	cnt++;
	printf("---------- arr # %d ----------\n", cnt);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int nsquare(int n)
{
	int ret = 1;
	for (int i = 0; i < n; i++)
	{
		ret = sz * ret;
	}
	return ret;
}

int mod(int _c)
{
	unsigned int answer = 0;
	for (int i = 0; i <= _c; i++)
	{
		answer = answer + arr[i] * nsquare(_c - i);
	}

	if (answer % (_c + 1) == 0)
	{
		return 1;
	}
	return 0;
}

void checknext(int _c)
{
	if (_c == sz)
	{
		show();
		return;
	}
	for (int i = 0; i < sz; i++)
	{
		memcpy(&arr[_c], &read[_c], sizeof(int) * (sz - _c));
		if (OK(_c, i) == 1)
		{
			arr[_c] = i;
			if (mod(_c) == 1)
			{
				checknext(_c + 1);
			}
		}
	}
}

void solve(int  _c)
{
	for (int i = 1; i < sz; i++)
	{
		memcpy(read, arr, sizeof(int) * sz);
		if (OK(_c, i) == 1)
		{
			arr[0] = i;
			if (mod(_c) == 1)
			{
				checknext(1);
			}
		}
	}
}

int main()
{
	scanf("%d", &sz);
	arr = (int*)malloc(sizeof(int)*sz);
	memset(arr, -1, sizeof(int)*sz);
	read = (int*)malloc(sizeof(int)*sz);
	solve(0);
}
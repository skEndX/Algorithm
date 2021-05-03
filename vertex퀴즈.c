#include<stdio.h>
#define sz 5
int graph[sz][sz];

void addToGraph(int v1, int v2) {
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
}

int getDegree(int v) {
	int cnt = 0;
	for (int i = 0; i < sz; i++)
	{
		if (graph[v][i]==1)
		{
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		addToGraph(v1, v2);
	}

	scanf("%d", &num);
	printf("%d", getDegree(num));
	return 0;
}
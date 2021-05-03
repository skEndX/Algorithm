#include <stdio.h>
int vertex;

 struct node {
	int v;
	int w;
	struct node* next;
 };
struct node ** graph;
 struct dijkstra {
	int found;
	int d;
	int prev_v;
};
struct dijkstra *table;

void _putEdge(int v1, int v2, int w)
{
	struct node * new_one = (struct node *)malloc(sizeof(struct node));
	new_one->v = v2;
	new_one->w = w;
	new_one->next = 0;

	struct node * cur = graph[v1];

	if (cur == 0)
	{
		graph[v1] = new_one;
		return;
	}
	else
	{
		while (cur->next != 0)
		{
			cur = cur->next;
		}
		cur->next = new_one;
		return;
	}
}

void addEdge(int v1, int v2, int w)
{
	_putEdge(v1, v2, w);
	_putEdge(v2, v1, w);
}

void inittable()
{
	int i;
	for (i = 0; i < vertex; i++)
	{
		table[i].found = 0;
		table[i].d = 99999;
		table[i].prev_v = -1;
	}
}

void show()
{
	int i;
	for (i = 0; i < vertex; i++)
	{
		printf("%d : %d %d %d\n", i, table[i].found, table[i].d, table[i].prev_v);
	}
}

void update(int v)
{
	struct node *cur = graph[v];
	while (cur != 0)
	{
		if (table[cur->v].found == 0 && table[cur->v].d > table[v].d + cur->w)
		{
			table[cur->v].d = table[v].d + cur->w;
			table[cur->v].prev_v = v;
		}
		cur = cur->next;
	}
}

int find()
{
	int small_v = -1;
	int small_d = 99999;

	int i;
	for (i = 0; i < vertex; i++)
	{
		if (table[i].found == 0 && table[i].d < small_d)
		{
			small_d = table[i].d;
			small_v = i;
		}
	}
	return small_v;
}

void Dijkstra(int v)
{
	int next_v = -1;
	table[v].d = 0;
	while ((next_v = find()) != -1)
	{
		table[next_v].found = 1;
		update(next_v);
	}
	show();
}

int main()
{
	int v1, v2, w;
	scanf("%d", &vertex);
	graph = (struct node **)malloc(sizeof(struct node*)*vertex);
	memset(graph, 0, sizeof(struct node*)*vertex);

	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		if (v1 == -1 && v2 == -1 && w == -1)
		{
			break;
		}
		addEdge(v1, v2, w);
	}

	table = (struct dijkstra *)malloc(sizeof(struct dijkstra)*vertex);
	memset(table, 0, sizeof(struct dijkstra)*vertex);

	inittable();
	Dijkstra(0);
}
/*
	0 1 1
	0 2 3   
	0 4 5
	1 2 2
	1 4 4
	2 4 6
	2 3 7
	3 4 8
*/
#include<stdio.h>
#include<stdlib.h>
int vertex;
#define edge_n 8
int cycle[5] = { 0,1,2,3,4 };
int s_cnt = 0;

struct node {
	int v;
	int w;
	struct node*next;
};
struct node**graph;

struct edge {
	int from;
	int to;
	int w;
};
struct edge edge[edge_n];

void addEdge(int v1, int v2, int w) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	struct node*cur = graph[v1];
	new->v = v2;
	new->w = w;
	new->next = 0;

	if (cur==0)
	{
		graph[v1] = new;
		return;
	}
	while (cur->next!=0)
	{
		cur = cur->next;
	}
	cur->next = new;
}

void sort() {
	int cnt = 0;
	for (int i = 0; i < vertex; i++)
	{
		struct node*cur = graph[i];
		while (cur!=0)
		{
			edge[cnt].from = i;
			edge[cnt].to = cur->v;
			edge[cnt].w = cur->w;
			cur = cur->next;
			cnt++;
		}
	}
	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < vertex-1-i; j++)
		{
			if (edge[j].w>edge[j+1].w)
			{
				struct edge temp;
				temp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = temp;
			}
		}
	}
}

void group(int v1,int v2) {
	int b = v1, s = v2;
	if (b<s)
	{
		s = v1;
		b = v2;
	}
	for (int i = 0; i < vertex; i++)
	{
		if (cycle[i]==b)
		{
			cycle[i] = s;
		}
	}
}

void MST() {
	int edgecnt = 0;
	for (int i = 0; i < edge_n; i++)
	{
		if (cycle[edge[i].from]!=cycle[edge[i].to])
		{
			group(cycle[edge[i].from], cycle[edge[i].to]);
			edgecnt++;
			s_cnt = s_cnt + edge[i].w;
			if (edgecnt==vertex-1)
			{
				return;
			}
		}
	}
}

int main() {
	scanf("%d", &vertex);
	graph = (struct node**)malloc(sizeof(struct node*)*vertex);
	memset(graph, 0, sizeof(struct node*)*vertex);

	while (1)
	{
		int v1, v2, w;
		scanf("%d %d %d", &v1, &v2, &w);
		if (v1==-1&&v2==-1&&w==-1)
		{
			break;
		}
		addEdge(v1, v2, w);
	}
	sort();
	MST();
	printf("%d", s_cnt);
}

/*
	addEdge(0, 1, 1);
	addEdge(0, 3, 50);
	addEdge(0, 2, 1);
	addEdge(2, 1, 90);
	addEdge(3, 2, 1);
	addEdge(3, 1, 1);
*/
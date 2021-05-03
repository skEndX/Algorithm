#include<stdio.h>
#include<stdlib.h>
#define num 5
struct node {
	int v;
	struct node*next;
};
struct node*graph[num];
int stack[num];
int top = -1;
int visited[num];

void push(int v) {
	if (top==num-1)
	{
		return;
	}
	top++;
	stack[top] = v;
}
int empty() {
	return ((top == -1) ? 1 : 0);
}
int pop() {
	if (top==-1)
	{
		return -1;
	}
	int temp = stack[top];
	top--;
	return temp;
}

int putEdge(int v1, int v2) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	struct node*cur = graph[v1];
	new->v = v2;
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
void addEdge(int a, int b) {
	putEdge(a, b);
	putEdge(b, a);
}

void show(int v) {
	struct node*cur = graph[v];
	while (cur!=0)
	{
		printf("%d is the adjacent vertex\n", cur->v);
		cur = cur->next;
	}
}

int find(int v) {
	struct node*cur = graph[v];
	while (cur!=0)
	{
		if (visited[cur->v]==0)
		{
			return cur->v;
		}
		cur = cur->next;
	}
	return -1;
}
void DFS(int v) {
	printf("visited %d\n", v);
	visited[v] = 1;
	push(v);
	while (empty()==0)
	{
		int next_vertex = -1;
		next_vertex = find(stack[top]);
		if (next_vertex==-1)
		{
			pop();
			return;
		}
		DFS(next_vertex);
	}
}

int main() {
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 4);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(3, 4);

	int v;
	scanf("%d", &v);
	show(v);
	DFS(v);
}

#include<stdio.h>
#include<stdlib.h>
int NUM = 7;
int *graph = 0;
int *stack = 0;
int top = -1;
int *visited = 0;

void push(int v) {
	if (top==NUM-1)
	{
		return;	//full
	}
	top = top + 1;
	stack[top] = v;
}
int pop() {
	if (top==-1)
	{
		return -999;	//empty
	}
	int temp = stack[top];
	top--;
	return temp;

}
int empty(int v)
{
	for (int i = 0; i < top; i++)
	{
		if (stack[i] == v)
		{
			return -999;
		}
	}
	return 1;
}
void addEdge(int v1, int v2) {
	graph[v1*NUM+v2] = 1;
	graph[v2*NUM+v1] = 1;
}

void DFS(int v) {
	int cur;
	int f;
	push(v);	//stack에 넣음.

	while (1)	
	{
		cur = pop();	
		if (cur==-999)	//stack이 비어있으면
		{
			return;
		}

		//visited[cur] = 1;	//stack에서 꺼내서 visited
		if (visited[cur]!=1)
		{
			visited[cur] = 1;
			printf("%d\n", cur);
		}

		for (f=cur*NUM; f<cur*NUM+NUM; f++)	//친구들을 찾아서 stack에 push
		{
			if (graph[f]==1)	//친구
			{
				int real_f = f - cur * NUM;
				if (visited[real_f]==0 && empty(real_f)==1)
				{
					push(real_f);
				}
			}
		}
	}
}

int main() {
	graph = (int *)malloc(sizeof(int)*NUM*NUM);	//그래프 구성
	for (int i = 0; i < NUM; i++)	//초기화
	{
		graph[i] = 0;
	}

	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 4);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(3, 4);

	stack = (int *)malloc(sizeof(int)*NUM);	
	for (int i = 0; i < NUM; i++)
	{
		stack[i] = 0;
	}

	visited = (int *)malloc(sizeof(int)*NUM);
	for (int i = 0; i < NUM; i++)
	{
		visited[i] = 0;
	}

	DFS(2);	

	return 0;
}
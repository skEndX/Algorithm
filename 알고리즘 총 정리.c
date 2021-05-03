--------------------------------------------------------------------------------------------------------------
코드


입력

출력(출력이 없는경우는 그대로 실행했을 때 맞는 코드)
--------------------------------------------------------------------------------------------------------------

9월 첫 퀴즈


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define GRAPH_SZ 5

int graph[GRAPH_SZ][GRAPH_SZ];

void addToGraph(int v1, int v2)
{
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
}

int getDegree(int v)
{
	int count = 0;
	for (int index = 0; index < GRAPH_SZ; index++)
	{
		if (graph[v][index] == 1)
		{
			count++;
		}
	}
	return count;
}

int main(void)
{
	int i = 0;
	int cnt = 0;
	int degree = 0;
	int v = 0;


	scanf("%d", &cnt);

	for (i = 0; i < cnt; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		addToGraph(v1, v2);
	}

	scanf("%d", &v);
	degree = getDegree(v);
	printf("%d", degree);
	return 0;
}


9월 첫 퀴즈

5
0 1
1 2
2 3
3 0
0 4
4


--------------------------------------------------------------------------------------------------------------
9월 bfs 1번째 문제

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int VERTEX_NUM;

int* graph = 0;
int* queue = 0;
int front = 0;
int rear = 0;
int* visited = 0;
int mystery = 0;

/*
Queue full 이면 단순히 return
*/
void enqueue(int v)
{
	if ((rear + 1) % VERTEX_NUM == (front) % VERTEX_NUM)
	{
		return;
	}
	queue[rear] = v;
	rear = rear + 1;
	rear = rear % VERTEX_NUM;
}

/*
Empty queue이면 -999를 return
*/
int dequeue()
{
	if (front%VERTEX_NUM == rear % VERTEX_NUM)
	{
		return -999;
	}
	int temp = queue[front];
	front = front + 1;
	front = front % VERTEX_NUM;
	return temp;
}

void addEdge(int v1, int v2)
{
	graph[v1 * VERTEX_NUM + v2] = 1;
	graph[v2 * VERTEX_NUM + v1] = 1;
}

/*
queue에 vertex v가 있으면, 1
없으면 0을 반환
*/
int isInQueue(int v)
{
	int cnt = 0;
	int temp = front;
	while (1)
	{
		if (temp == rear)
		{
			return 1;
		}
		if (cnt == VERTEX_NUM)
		{
			return 0;
		}
		temp = temp + 1;
		temp = temp % VERTEX_NUM;
	}
}

/*
v부터 시작해서,,, DFS
*/
void doBFS(int v)
{
	int cur_vertex;
	int f;
	// 1. v를 stack에 넣는다.
	enqueue(v);

	// queue가 비어있지 않는 한...
	while (1)
	{
		cur_vertex = dequeue();

		if (cur_vertex == -999)
		{
			return;
		}

		// 1. queue에서 꺼내서 visited
		visited[cur_vertex] = 1;

		// 아래 코드는 절대 수정하지 마세요.
		if ((cur_vertex % 2) == 0)
		{
			mystery += cur_vertex;
		}
		//------------------------------
		// 여기부터는 수정해도 됩니다.


		// 2. 친구들을 찾아서 queue에 enqueue
		//

		for (f = cur_vertex * VERTEX_NUM; f < cur_vertex * VERTEX_NUM + VERTEX_NUM; f++)
		{
			if (graph[f] == 1)
			{
				int real_f = f - VERTEX_NUM * cur_vertex;
				if (visited[real_f] == 0 && isInQueue(real_f))
				{
					enqueue(real_f);
				}
			}
		}
		//
	}
}

int main(void)
{
	int v1, v2;
	int i;
	scanf("%d", &VERTEX_NUM);

	// 그래프 구성
	graph = (int*)malloc(sizeof(int) * VERTEX_NUM * VERTEX_NUM);
	// 초기화
	for (i = 0; i < VERTEX_NUM * VERTEX_NUM; i++)
	{
		graph[i] = 0;
	}

	while (1)
	{
		scanf("%d %d", &v1, &v2);
		if ((v1 == -1) && (v2 == -1))
		{
			break;
		}
		addEdge(v1, v2);
	}

	// Queue 구성
	queue = (int*)malloc(sizeof(int) * VERTEX_NUM);
	for (i = 0; i < VERTEX_NUM; i++)
	{
		queue[i] = 0;
	}
	visited = (int*)malloc(sizeof(int) * VERTEX_NUM);
	for (i = 0; i < VERTEX_NUM; i++)
	{
		visited[i] = 0;
	}

	// BFS 시작
	doBFS(0);

	printf("%d", mystery);

	return 0;
}


3
0 1
0 2
-1 -1
--------------------------------------------------------------------------------------------------------------
9월 2번문제 (교수님 실수로 통과 안된문제)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int VERTEX_NUM;

int* graph = 0;
int* queue = 0;
int front = 0;
int rear = 0;
int* visited = 0;
int mystery = 0;

/*
Queue full 이면 단순히 return
*/
void enqueue(int v)
{
	if ((rear + 1) % VERTEX_NUM == (front) % VERTEX_NUM)
	{
		return;
	}
	queue[rear] = v;
	rear = rear + 1;
	rear = rear % VERTEX_NUM;
}

/*
Empty queue이면 -999를 return
*/
int dequeue()
{
	if (front%VERTEX_NUM == rear % VERTEX_NUM)
	{
		return -999;
	}
	int temp = queue[front];
	front = front + 1;
	front = front % VERTEX_NUM;
	return temp;
}

void addEdge(int v1, int v2)
{
	graph[v1 * VERTEX_NUM + v2] = 1;
	graph[v2 * VERTEX_NUM + v1] = 1;
}

/*
queue에 vertex v가 있으면, 1
없으면 0을 반환
*/
int isInQueue(int v)
{
	int cnt = 0;
	int temp = front;
	while (1)
	{
		if (temp == rear)
		{
			return 1;
		}
		if (cnt == VERTEX_NUM)
		{
			return 0;
		}
		temp = temp + 1;
		temp = temp % VERTEX_NUM;
	}
}

/*
v부터 시작해서,,, DFS
*/
void doBFS(int v)
{
	int cur_vertex;
	int f;
	// 1. v를 stack에 넣는다.
	enqueue(v);

	// queue가 비어있지 않는 한...
	while (1)
	{
		cur_vertex = dequeue();

		if (cur_vertex == -999)
		{
			return;
		}

		// 1. queue에서 꺼내서 visited
		visited[cur_vertex] = 1;

		// 아래 코드는 절대 수정하지 마세요.
		if ((cur_vertex % 2) == 0)
		{
			mystery += cur_vertex;
		}
		//------------------------------
		// 여기부터는 수정해도 됩니다.


		// 2. 친구들을 찾아서 queue에 enqueue
		//

		for (f = cur_vertex * VERTEX_NUM; f < cur_vertex * VERTEX_NUM + VERTEX_NUM; f++)
		{
			if (graph[f] == 1)
			{
				int real_f = f - VERTEX_NUM * cur_vertex;
				if (visited[real_f] == 0 && isInQueue(real_f))
				{
					enqueue(real_f);
				}
			}
		}
		//
	}
}
int whoisfirst(int v1, int v2)
{
	int cur_vertex;
	int f;
	int check;
	// 1. v를 stack에 넣는다.
	enqueue(0);

	// queue가 비어있지 않는 한...
	while (1)
	{
		cur_vertex = dequeue();

		if (cur_vertex == -999)
		{
			return -999;
		}

		// 1. queue에서 꺼내서 visited
		visited[cur_vertex] = 1;
		if (visited[v1] == 1)
		{
			return 1;
		}
		if (visited[v2] == 1)
		{
			return 0;
		}
		for (f = cur_vertex * VERTEX_NUM; f < cur_vertex * VERTEX_NUM + VERTEX_NUM; f++)
		{
			if (graph[f] == 1)
			{
				int real_f = f - VERTEX_NUM * cur_vertex;
				if (visited[real_f] == 0 && isInQueue(real_f))
				{
					enqueue(real_f);
				}
			}
		}
		//
	}

}
int main(void)
{
	int v1, v2;
	int i;
	scanf("%d", &VERTEX_NUM);

	// 그래프 구성
	graph = (int*)malloc(sizeof(int) * VERTEX_NUM * VERTEX_NUM);
	// 초기화
	for (i = 0; i < VERTEX_NUM * VERTEX_NUM; i++)
	{
		graph[i] = 0;
	}

	while (1)
	{
		scanf("%d %d", &v1, &v2);
		//if (v1 >= VERTEX_NUM || v2 >= VERTEX_NUM)
		//{
		//	break;
		//}
		if ((v1 == -1) && (v2 == -1))
		{
			break;
		}
		addEdge(v1, v2);
	}

	// Queue 구성
	queue = (int*)malloc(sizeof(int) * VERTEX_NUM);
	for (i = 0; i < VERTEX_NUM; i++)
	{
		queue[i] = 0;
	}
	visited = (int*)malloc(sizeof(int) * VERTEX_NUM);
	for (i = 0; i < VERTEX_NUM; i++)
	{
		visited[i] = 0;
	}

	// BFS 시작
	//doBFS(0);

	//printf("%d", mystery);
	scanf("%d %d", &v1, &v2);
	printf("%d",whoisfirst(v1, v2));
	return 0;
}



3
0 1
0 2
-1 -1
1 0
--------------------------------------------------------------------------------------------------------------
10월 2일 bfs 코드

#include <stdio.h>

int *graph;
int *visited;
int *queue;
int rear = 0, front = 0;
int VERTEX_NUM;
void enqueue(int v)
{
	if ((rear + 1) % VERTEX_NUM == front)
	{
		return;
	}
	queue[rear] = v;
	rear = (rear + 1)%VERTEX_NUM;
	return;
}

int dequeue()
{
	if (rear == front)
	{
		return -999;
	}
	int temp = queue[front];
	front = (front + 1) % VERTEX_NUM;
	return temp;
}

void addEdge(int v1, int v2)
{
	graph[v1*VERTEX_NUM + v2]= 1;
	graph[v2*VERTEX_NUM + v1]=1 ;
	return;
}
int NotInQueue(int v)
{
	int	temp = front;
	while ((temp%VERTEX_NUM) == rear)
	{
		if (queue[temp] == v)
		{
			return 0;
		}
		temp= (temp+1)%VERTEX_NUM;
	}
	return 1;
}
int doBFS(int v1, int v2)
{
	int f;
	int temp;
	enqueue(v1);
	while (front != rear)
	{
		temp = dequeue();
		visited[temp] = 1;

		for (f = temp * VERTEX_NUM; f < temp*VERTEX_NUM + VERTEX_NUM; f++)
		{
			if (graph[f] == 1)
			{
				int real_f = f - temp * VERTEX_NUM;
				if (visited[real_f] == 0 && NotInQueue(real_f))
				{
					enqueue(real_f);
				}
			}
		}
	}
	if (temp == v2)
	{
		return 1;
	}
	return 0;
}
int main(void)
{
	scanf("%d", &VERTEX_NUM);

	graph = (int *)malloc(sizeof(int)*VERTEX_NUM*VERTEX_NUM);
	for (int i = 0; i < VERTEX_NUM*VERTEX_NUM; i++)
	{
		graph[i] = 0;
	}
	visited = (int *)malloc(sizeof(int)*VERTEX_NUM);
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		visited[i] = 0;
	}	
	queue = (int *)malloc(sizeof(int)*VERTEX_NUM);
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		queue[i] = 0;
	}
	int v1, v2;
	while (1)
	{
		scanf("%d %d", &v1, &v2);
		if (v1 == -1 && v2 == -1)
		{
			break;
		}
		addEdge(v1, v2);
	}

	scanf("%d %d", &v1, &v2);
	printf("%d",doBFS(v1, v2));
}


4
0 1
0 2
2 3
-1 -1
0 3
--------------------------------------------------------------------------------------------------------------
10월 8 일 퀴즈



#include <stdio.h>

typedef struct edge {
	int from;
	int to;
	int w;
}EDGES;

typedef struct vertex {
	int v;
	int w;
	struct vertex * next;
}VERTEX;

int VERTEX_NUM = 0;
int EDGE_NUM = 0;
int *Cycle_Detection;
VERTEX *graph;
EDGES *edges;

void addVer(int v1, int v2, int _w)
{
	VERTEX * new_one = (VERTEX*)malloc(sizeof(VERTEX));
	new_one->v = v2;
	new_one->w = _w;
	new_one->next = 0;
	VERTEX* temp = &graph[v1];

	while (temp != 0)
	{
		if (temp->v == v2)
		{
			return;
		}
		temp = temp->next;
	}

	temp = &graph[v1];

	if (temp == 0)
	{
		graph[v1].next = new_one->next;
		graph[v1].w = new_one->w;
		graph[v1].v = new_one->v;
		return;
	}
	else
	{
		while (temp->next != 0)
		{
			if (temp->next->v > v2)
			{
				new_one->next = temp->next;
				temp->next = new_one;
				return;
			}
			temp = temp->next;
		}
		temp->next = new_one;
		return;
	}
}

void putEdge()
{
	int i = 0;
	VERTEX * temp;
	int cur_edges = 0;
	for(i=0; i< VERTEX_NUM; i++)
	{
		temp = &graph[i];
		temp = temp->next;
		while (temp != 0)
		{
			edges[cur_edges].from = i;
			edges[cur_edges].to = temp->v;
			edges[cur_edges].w = temp->w;
			cur_edges++;
			temp = temp->next;
		}
	}
	int x, y;
	for (x = 0; x < EDGE_NUM; x++)
	{
		for (y = 0; y < EDGE_NUM - 1 - x; y++)
		{
			if (edges[y].w > edges[y + 1].w)
			{
				EDGES tem = edges[y];
				edges[y] = edges[y + 1];
				edges[y + 1] = tem;
			}
		}
	}
	return;
}

void putSameGroup(int v1, int v2)
{
	int small, big;
	if (Cycle_Detection[v1] > Cycle_Detection[v2])
	{
		small = Cycle_Detection[v2];
		big = Cycle_Detection[v1];
	}
	else
	{
		small = Cycle_Detection[v1];
		big = Cycle_Detection[v2];
	}
	
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		if (Cycle_Detection[i] == big)
		{
			Cycle_Detection[i] = small;
		}
	}
}

void doMST()
{
	int mst = 0;
	int i = 0;
	EDGES * temp;
	for (i = 0; i < EDGE_NUM; i++)
	{
		temp = &edges[i];
		if (Cycle_Detection[temp->from] != Cycle_Detection[temp->to])
		{
			putSameGroup(temp->from, temp->to);
			mst++;
			if (mst == VERTEX_NUM - 1)
			{
				break;
			}
		}
	}
	return;
}

int main(void)
{
	int v1, v2, w;
	scanf("%d", &VERTEX_NUM);

	graph = (VERTEX*)malloc(sizeof(VERTEX)*VERTEX_NUM);
	memset(graph, 0, sizeof(VERTEX)*VERTEX_NUM);
	Cycle_Detection = (int*)malloc(sizeof(int)*VERTEX_NUM);
	for (int i = 0; i < VERTEX_NUM; i++)
	{
		Cycle_Detection[i] = i;
	}

	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		if(v1 == -1 && v2 == -1 && w == -1)
		{
			break;
		}
		addVer(v1, v2, w);
		EDGE_NUM++;
	}
	edges = (EDGES*)malloc(sizeof(EDGES)*EDGE_NUM);
	memset(edges, 0, sizeof(EDGES)*EDGE_NUM);

	putEdge();
	doMST();
	int result = 0;
	for (int i = 0; i < VERTEX_NUM - 1; i++)
	{
		result = edges[i].w + result;
	}
	printf("%d", result);
	return 0;
}



4
0 1 1
0 3 50
0 2 1
2 1 90
3 2 1
3 1 1
-1 -1 -1
--------------------------------------------------------------------------------------------------------------
10월 15일  1번문제

#include <stdio.h>
#include <string.h>
#include <math.h>
#define SZ 8

int chessboard[SZ][SZ];
int x[SZ] = { 0, };
int y[SZ] = { 0, };
int isOK(int _r, int _c)
{
	for (int i = 0; i < SZ; i++)
	{
		if (chessboard[i][_c] == 1 && i != _r)
		{
			return 1;
		}
	}
	for (int i = 0; i < SZ; i++)
	{
		if (chessboard[_r][i] == 1 && i != _c)
		{
			return 1;
		}
	}
	for (int i = 0; i < SZ; i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			if (abs(_r - i) == abs(_c - j) && chessboard[i][j] == 1 && i !=_r && j != _c)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	scanf("%d %d", &x[0], &y[0]);
	scanf("%d %d", &x[1], &y[1]);
	chessboard[x[0]][y[0]] = 1;
	chessboard[x[1]][y[1]] = 1;
	printf("%d", isOK(x[0],y[0]));
}


0 0
1 1
--------------------------------------------------------------------------------------------------------------
10월 15일 2번째 문제

#include <stdio.h>
#include <string.h>
#include <math.h>
#define SZ 8

int chessboard[SZ][SZ];
int x[SZ] = { 0, };
int y[SZ] = { 0, };
int go = 0;
void isOK(int _r, int _c)
{
	for (int i = 0; i < SZ; i++)
	{
		if (chessboard[i][_c] == 1 && i != _r)
		{
			go++;
		}
	}
	for (int i = 0; i < SZ; i++)
	{
		if (chessboard[_r][i] == 1 && i != _c)
		{
			go++;
		}
	}
	for (int i = 0; i < SZ; i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			if (abs(_r - i) == abs(_c - j) && chessboard[i][j] == 1 && i !=_r && j != _c)
			{
				go++;
			}
		}
	}
	return;
}

int main(void)
{
	int num,xloc,yloc;
	for (int i = 0; i < SZ; i++)
	{
		scanf("%d %d %d", &num, &xloc, &yloc);
		if (num == -1 && xloc == -1, yloc == -1)
		{
			break;
		}
		x[num] = xloc;
		y[num] = yloc;
		chessboard[x[num]][y[num]] = 1;
	}
	scanf("%d", &num);
	isOK(x[num], y[num]);
	printf("%d", go);
}


0 0 0
1 1 1
-1 -1 -1
1
--------------------------------------------------------------------------------------------------------------
중간고사 1

#include <stdio.h>
int m, n;
unsigned int ** map;
int main(void)
{
	scanf("%d %d", &m, &n);

	map = (unsigned int **)malloc(sizeof(unsigned int*)*m);
	for (int i = 0; i < m; i++)
	{
		map[i] = (int*)malloc(sizeof(unsigned int)*n);
		memset(map[i], 0, sizeof(unsigned int)*n);
	}

	int v1, v2, v3;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		if (v1 == -1 && v2 == -1 && v3 == -1)
		{
			break;
		}
		map[v1][v2] = v3;
	}
	scanf("%d %d", &v1, &v2);
	if (map[v1][v2] != 0)
	{
		printf("-1");
	}
	else
	{
		printf("0");
	}
}


5 5
0 1 1
1 1 1
2 1 1
3 2 1
3 3 1
-1 -1 -1
0 0
--------------------------------------------------------------------------------------------------------------
중간고사 2


#include <stdio.h>
int m, n;
typedef struct node {
	int r;
	int c;
	int d;
	struct node * next;
}NODE;
NODE * head = 0;
void addnode(int _r, int _c, int _d)
{
	NODE* new_one = (NODE*)malloc(sizeof(NODE));
	new_one->r = _r;
	new_one->c = _c;
	new_one->d = _d;
	new_one->next = 0;
	if (head == 0)
	{
		head = new_one;
		return;
	}
	else
	{
		NODE* temp = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new_one;
		return;
	}
}

int findd(int v1, int v2)
{
	NODE* temp = head; 
	while (temp != 0)
	{
		if (temp->r == v1 && temp->c == v2)
		{
			return -1;
		}
		temp = temp->next;
	}
	return 0;
}
int main(void)
{
	scanf("%d %d", &m, &n);


	int v1, v2, v3;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		if (v1 == -1 && v2 == -1 && v3 == -1)
		{
			break;
		}
		addnode(v1, v2, v3);
	}
	scanf("%d %d", &v1, &v2);
	if (v1 > m || v2 > n)
	{
		printf("0");
	}
	else
	{
		printf("%d", findd(v1, v2));
	}
	return 0;
}


2000000000 2000000000
0 0 1
1999999999 1999999999 1
-1 -1 -1
1999999999 1999999999
--------------------------------------------------------------------------------------------------------------
중간고사 3


#include <stdio.h>
int m, n;
unsigned int ** map;
int cnt = 0;

void ccheck(int v1, int v2)
{
	if (v1 >= m || v2 >= n || v1 < 0 || v2 < 0)
	{
		return;
	}
	if (map[v1][v2] == 0)
	{
		cnt++;
	}
	return;
}

void check(int v1, int v2)
{
	ccheck(v1 + 1, v2);
	ccheck(v1 - 1, v2);
	ccheck(v1, v2 + 1);
	ccheck(v1, v2 - 1);
}

int main(void)
{
	scanf("%d %d", &m, &n);

	map = (unsigned int **)malloc(sizeof(unsigned int*)*m);
	for (int i = 0; i < m; i++)
	{
		map[i] = (int*)malloc(sizeof(unsigned int)*n);
		memset(map[i], 0, sizeof(unsigned int)*n);
	}

	int v1, v2, v3;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		if (v1 == -1 && v2 == -1 && v3 == -1)
		{
			break;
		}
		map[v1][v2] = v3;
	}

	scanf("%d %d", &v1, &v2);
	check(v1, v2);
	printf("%d", cnt);
}


5 5
4 4 1
-1 -1 -1
1 1
--------------------------------------------------------------------------------------------------------------
중간고사 4


#include <stdio.h>
int m, n;
int cnt = 0;
typedef struct node {
	int r;
	int c;
	int d;
	struct node * next;
}NODE;
NODE * head = 0;
void addnode(int _r, int _c, int _d)
{
	NODE* new_one = (NODE*)malloc(sizeof(NODE));
	new_one->r = _r;
	new_one->c = _c;
	new_one->d = _d;
	new_one->next = 0;
	if (head == 0)
	{
		head = new_one;
		return;
	}
	else
	{
		NODE* temp = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new_one;
		return;
	}
}
void finddd(int v1, int v2)
{
	if (v1 < 0 || v1 >= m || v2 < 0 || v2 >= n)
	{
		return;
	}
	else
	{
		NODE *temp = head;
		int flag = 0;
		while (temp != 0)
		{
			if (temp->r == v1 && temp->c == v2)
			{
				flag = 1;
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cnt++;
			return;
		}
		else
		{
			flag = 0;
			return;
		}
	}
}
int findd(int v1, int v2)
{
	finddd(v1 + 1, v2);
	finddd(v1 - 1, v2);

	finddd(v1, v2+1);

	finddd(v1, v2-1);

	return cnt;
}
int main(void)
{
	scanf("%d %d", &m, &n);


	int v1, v2, v3;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		if (v1 == -1 && v2 == -1 && v3 == -1)
		{
			break;
		}
		addnode(v1, v2, v3);
	}
	scanf("%d %d", &v1, &v2);
	if (v1 > m || v2 > n)
	{
		printf("0");
	}
	else
	{
		printf("%d", findd(v1, v2));
	}
	return 0;
}


2000000000 2000000000
0 0 1
0 1 1
-1 -1 -1
1999999999 1999999999
--------------------------------------------------------------------------------------------------------------
중간고사 5


#include <stdio.h>
int m, n;
int start_r, start_c;
int end_r, end_c;
unsigned int ** map;
typedef struct node {
	int r;
	int c;
}NODE;
typedef struct dtable{
	int found;
	int dist;
	int prev_r;
	int prev_c;
}Dtable;
Dtable ** table;
void inittable()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j].dist = 2100000000;
			table[i][j].found = 0;
		}
	}
}
void check(int _br, int _bc, int _nr, int _nc)
{
	if (_nr >= m || _nc >= n || _nr < 0 || _nc < 0)
	{
		return;
	}
	if (map[_nr][_nc] != 0)
	{
		return;
	}
	if (table[_nr][_nc].found == 0 && table[_nr][_nc].dist > table[_br][_bc].dist + 1)
	{
		table[_nr][_nc].dist = table[_br][_bc].dist + 1;
		table[_nr][_nc].prev_r = _br;
		table[_nr][_nc].prev_c = _bc;

	}
}
void update(int _r , int _c)
{
	check(_r, _c, _r + 1, _c);
	check(_r, _c, _r - 1, _c);
	check(_r, _c, _r, _c + 1);
	check(_r, _c, _r, _c - 1);
}
NODE findv()
{
	NODE temp;
	temp.r = -1;
	temp.c = -1;
	int small = 2100000000;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (table[i][j].found == 0 && table[i][j].dist < small)
			{
				small = table[i][j].dist;
				temp.r = i;
				temp.c = j;
			}
		}
	}
	return temp;
}
int main(void)
{
	scanf("%d %d", &m, &n);

	map = (unsigned int **)malloc(sizeof(unsigned int*)*m);
	for (int i = 0; i < m; i++)
	{
		map[i] = (int*)malloc(sizeof(unsigned int)*n);
		memset(map[i], 0, sizeof(unsigned int)*n);
	}
	table = (Dtable**)malloc(sizeof(Dtable*)*m);
	for (int i = 0 ;i < m; i++)
	{
		table[i] = (Dtable*)malloc(sizeof(Dtable)*n);
		memset(table[i], 0, sizeof(Dtable)*n);
	}

	int v1, v2, v3;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		if (v1 == -1 && v2 == -1 && v3 == -1)
		{
			break;
		}
		map[v1][v2] = v3;
	}
	scanf("%d %d", &start_r, &start_c);

	scanf("%d %d", &end_r, &end_c);
	inittable();
	table[start_r][start_c].dist = 0;
	table[start_r][start_c].found = 1;
	table[start_r][start_c].prev_c = -1;
	table[start_r][start_c].prev_r = -1;

	update(start_r, start_c);
	
	NODE checkkk;
	checkkk.c = -1;
	checkkk.r = -1;

	while (1)
	{
		checkkk = findv();
		if (checkkk.r == -1 && checkkk.c == -1)
		{
			break;
		}
		table[checkkk.r][checkkk.c].found = 1;
		update(checkkk.r, checkkk.c);
	}
	int temp_r, temp_c;
	printf("%d", table[end_r][end_c].dist);
	/*temp_r = end_r;
	temp_c = end_c;
*/

	/*while (1)
	{
		table[temp_r][temp_c].prev_r
	}*/

}


5 5
0 1 1
1 1 1
2 1 1
3 2 1
3 3 1
-1 -1 -1
0 0
4 4
--------------------------------------------------------------------------------------------------------------
중간고사 6

#include <stdio.h>
int m, n;
int start_r, start_c;
int end_r, end_c;
unsigned int ** map;
typedef struct node {
	int r;
	int c;
}NODE;
typedef struct dtable{
	int found;
	int dist;
	int prev_r;
	int prev_c;
}Dtable;
Dtable ** table;
void inittable()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j].dist = 2100000000;
			table[i][j].found = 0;
		}
	}
}
void check(int _br, int _bc, int _nr, int _nc)
{
	if (_nr >= m || _nc >= n || _nr < 0 || _nc < 0)
	{
		return;
	}
	if (map[_nr][_nc] != 0)
	{
		return;
	}
	if (table[_nr][_nc].found == 0 && table[_nr][_nc].dist > table[_br][_bc].dist + 1)
	{
		table[_nr][_nc].dist = table[_br][_bc].dist + 1;
		table[_nr][_nc].prev_r = _br;
		table[_nr][_nc].prev_c = _bc;

	}
}
void update(int _r , int _c)
{
	check(_r, _c, _r + 1, _c);
	check(_r, _c, _r - 1, _c);
	check(_r, _c, _r, _c + 1);
	check(_r, _c, _r, _c - 1);
}
NODE findv()
{
	NODE temp;
	temp.r = -1;
	temp.c = -1;
	int small = 2100000000;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (table[i][j].found == 0 && table[i][j].dist < small)
			{
				small = table[i][j].dist;
				temp.r = i;
				temp.c = j;
			}
		}
	}
	return temp;
}
int main(void)
{
	scanf("%d %d", &m, &n);

	map = (unsigned int **)malloc(sizeof(unsigned int*)*m);
	for (int i = 0; i < m; i++)
	{
		map[i] = (int*)malloc(sizeof(unsigned int)*n);
		memset(map[i], 0, sizeof(unsigned int)*n);
	}
	table = (Dtable**)malloc(sizeof(Dtable*)*m);
	for (int i = 0 ;i < m; i++)
	{
		table[i] = (Dtable*)malloc(sizeof(Dtable)*n);
		memset(table[i], 0, sizeof(Dtable)*n);
	}

	int v1, v2, v3;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		if (v1 == -1 && v2 == -1 && v3 == -1)
		{
			break;
		}
		map[v1][v2] = v3;
	}
	scanf("%d %d", &start_r, &start_c);

	scanf("%d %d", &end_r, &end_c);
	inittable();
	table[start_r][start_c].dist = 0;
	table[start_r][start_c].found = 1;
	table[start_r][start_c].prev_c = -1;
	table[start_r][start_c].prev_r = -1;

	update(start_r, start_c);
	
	NODE checkkk;
	checkkk.c = -1;
	checkkk.r = -1;

	while (1)
	{
		checkkk = findv();
		if (checkkk.r == -1 && checkkk.c == -1)
		{
			break;
		}
		table[checkkk.r][checkkk.c].found = 1;
		update(checkkk.r, checkkk.c);
	}
	int temp_r, temp_c;
	int c_r, c_c;
	scanf("%d %d", &c_r, &c_c);
	temp_r = end_r;
	temp_c = end_c;
	int temp_rr = 0;
	int temp_cc = 0;
	int flag = 0;
	while (1)
	{
		if (temp_rr == -1 && temp_cc == -1)
		{
			break;
		}
		if (table[temp_r][temp_c].prev_r == c_r && table[temp_r][temp_c].prev_c == c_c)
		{
			printf("1");
			flag = 1;
		}
		temp_rr = table[temp_r][temp_c].prev_r;
		temp_cc = table[temp_r][temp_c].prev_c;
		temp_r = temp_rr;
		temp_c = temp_cc;
	}
	if (flag == 0)
	{
		printf("0");
	}
}


5 5
0 1 1
1 1 1
2 1 1
3 2 1
3 3 1
-1 -1 -1
0 0
4 4
1 0	
--------------------------------------------------------------------------------------------------------------
중간고사 7


#include <stdio.h>
int m, n;
int start_r, start_c;
int end_r, end_c;
int cnt = 0;
unsigned int ** map;
typedef struct node {
	int r;
	int c;
}NODE;
typedef struct dtable{
	int found;
	int dist;
	int prev_r;
	int prev_c;
}Dtable;
Dtable ** table;
void inittable()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j].dist = 2100000000;
			table[i][j].found = 0;
		}
	}
}
void check(int _br, int _bc, int _nr, int _nc)
{
	if (_nr >= m || _nc >= n || _nr < 0 || _nc < 0)
	{
		return;
	}
	if (map[_nr][_nc] != 0)
	{
		if (map[_nr][_nc] != 2)
		{
			return;
		}
	}
	if (table[_nr][_nc].found == 0 && table[_nr][_nc].dist > table[_br][_bc].dist + 1)
	{
		table[_nr][_nc].dist = table[_br][_bc].dist + 1;
		table[_nr][_nc].prev_r = _br;
		table[_nr][_nc].prev_c = _bc;

	}
}
void update(int _r , int _c)
{
	check(_r, _c, _r + 1, _c);
	check(_r, _c, _r - 1, _c);
	check(_r, _c, _r, _c + 1);
	check(_r, _c, _r, _c - 1);
}
NODE findv()
{
	NODE temp;
	temp.r = -1;
	temp.c = -1;
	int small = 2100000000;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (table[i][j].found == 0 && table[i][j].dist < small)
			{
				small = table[i][j].dist;
				temp.r = i;
				temp.c = j;
			}
		}
	}
	return temp;
}
int main(void)
{
	scanf("%d %d", &m, &n);

	map = (unsigned int **)malloc(sizeof(unsigned int*)*m);
	for (int i = 0; i < m; i++)
	{
		map[i] = (int*)malloc(sizeof(unsigned int)*n);
		memset(map[i], 0, sizeof(unsigned int)*n);
	}
	table = (Dtable**)malloc(sizeof(Dtable*)*m);
	for (int i = 0 ;i < m; i++)
	{
		table[i] = (Dtable*)malloc(sizeof(Dtable)*n);
		memset(table[i], 0, sizeof(Dtable)*n);
	}

	int v1, v2, v3;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		if (v1 == -1 && v2 == -1 && v3 == -1)
		{
			break;
		}
		map[v1][v2] = v3;
	}
	scanf("%d %d", &start_r, &start_c);

	scanf("%d %d", &end_r, &end_c);
	inittable();
	table[start_r][start_c].dist = 0;
	table[start_r][start_c].found = 1;
	table[start_r][start_c].prev_c = -1;
	table[start_r][start_c].prev_r = -1;

	update(start_r, start_c);
	
	NODE checkkk;
	checkkk.c = -1;
	checkkk.r = -1;

	while (1)
	{
		checkkk = findv();
		if (checkkk.r == -1 && checkkk.c == -1)
		{
			break;
		}
		table[checkkk.r][checkkk.c].found = 1;
		update(checkkk.r, checkkk.c);
	}
	int temp_r, temp_c;
	int c_r, c_c;
	//scanf("%d %d", &c_r, &c_c);
	temp_r = end_r;
	temp_c = end_c;
	int temp_rr = 0;
	int temp_cc = 0;
	int flag = 0;
	while (1)
	{
		if (temp_rr == -1 && temp_cc == -1)
		{
			break;
		}
		if (map[temp_r][temp_c] == 2)
		{
			cnt++;
		}
		temp_rr = table[temp_r][temp_c].prev_r;
		temp_cc = table[temp_r][temp_c].prev_c;
		temp_r = temp_rr;
		temp_c = temp_cc;
	}
	printf("%d",cnt);
}


5 5
0 1 1
1 1 1
2 1 1
3 2 1
3 3 1
1 0 2
2 0 2
-1 -1 -1
0 0
4 4
--------------------------------------------------------------------------------------------------------------

중간고사 8

#include<stdio.h>
char map[21][21];
char visit[92]; //65~90 대문자 A ~Z
int arr_y[] = { 0,0,1,-1 };
int arr_x[] = { 1,-1,0,0 };
int R, C;
int max;

void DFS(int y, int x, int cnt) {
   int next_y, next_x;

   for (int i = 0; i < 4; i++) {
      next_y = y + arr_y[i];
      next_x = x + arr_x[i];

      if (next_y >= 0 && next_y < R && next_x >= 0 && next_x < C) {
         if (visit[(int)map[next_y][next_x]] == 1) {
            if (max < cnt) max = cnt;
            continue;
         }

         visit[(int)map[next_y][next_x]] = 1;
         DFS(next_y, next_x, cnt + 1);
         visit[(int)map[next_y][next_x]] = 0;
      }
   }

}


int main() {
   int i, j;
   scanf("%d%d", &R, &C);

   for (i = 0; i < R; i++) scanf("%s", map[i]);

   visit[(int)map[0][0]] = 1;
   max = 1;
   DFS(0, 0, 1);


   printf("%d", max);
   return 0;
}

--------------------------------------------------------------------------------------------------------------
11월 12일 퀴즈 1 빈도수

#include <stdio.h>
#include <string.h>

int main(void)
{
	int size;
	scanf("%d", &size);

	int i;
	unsigned char max;

	int small= 0;

	int chr[256] = { 0, };
	
	char* n;
	char c;
	n = (char*)malloc(sizeof(char)*size+5);

	scanf("%s", n);
	char* temp = n;
	while (1)
	{
		c = *temp;
		//printf("%c", c);
		if (c == 0)
		{
			break;
		}
		chr[c] = chr[c] + 1;
//		printf("%d\n",chr[c]);
		temp++;
	}
	chr[0]++;

	for (i = 0; i < 256; i++)
	{
		if (small < chr[i])
		{
			small = chr[i];
			max = i;
			//loc = i;
		}
	}
	printf("%c", max);

}

5
abcda

a
--------------------------------------------------------------------------------------------------------------
11월 12일 2번문제

#include <stdio.h>
#include <string.h>
int charFreq[256];
int cnt[256];
void findBiggest() { //배열에서 가장 큰 원소를 찾아내는 함수
   int biggest = 0;
   int biggest_name = 0;
   for (int i = 0; i < 256; i++)
   {
      if (biggest < cnt[i]) {
         biggest = cnt[i];
         biggest_name = i;
      }
   }
   printf("%d", biggest_name);
}
int main() {
   int n; 
   scanf("%d\n", &n);
   char name[1000];
   scanf("%s", &name);
   int len = strlen(name);
   memset(charFreq, 0, sizeof(int) * 256);
   memset(cnt, 0, sizeof(int) * 256);
   for (int i = 0; i < len; i++) { //문자열의 길이 저장
      charFreq[(int)name[i]]++;
   }
   for (int i = 0; i < 256; i++) { //문자열의 빈도수 저장
      if (charFreq[i] > 0){
         cnt[charFreq[i]]++;
      }
   }
   findBiggest();
}



/*#include <stdio.h>
#include <string.h>
int charFreq[256];

int main() {
   int n; 
   scanf("%d\n", &n);
   char name[1000];
   /*for (int i = 0; i < n; i++)
   {
      scanf("%s", &name);
   }
scanf("%s", &name);
int len = strlen(name);
memset(charFreq, 0, sizeof(int) * 256);
for (int i = 0; i < len; i++)
{
   charFreq[(int)name[i]]++;
}
int biggest = 0;
int biggest_name = 0;
for (int i = 0; i < 256; i++)
{
   if (biggest < charFreq[i]) {
      biggest = charFreq[i];
      biggest_name = i;
   }
}
printf("%c", (char)biggest_name);
}

5
aabbc

출력 : 2
--------------------------------------------------------------------------------------------------------------
11월 19일  문제 1


#include <stdio.h>

typedef struct node {
	char c;
	int frequency;
	struct node *next;
	struct node *left;
	struct node *right;
}NODE;

NODE* head = 0;
int idx = -1;
char buf[200] = { 0, };
NODE* createNode(char _c, int _freq)
{
	NODE* new_one = (NODE*)malloc(sizeof(NODE));
	new_one->c = _c;
	new_one->frequency = _freq;
	new_one->left = new_one->right = new_one->next = 0;
	return new_one;
}

void addToSLL(NODE* temp)
{
	if (head == 0)
	{
		head = temp;
		return;
	}
	NODE* tmp = head;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
	}
	tmp->next = temp;
	return;
}
NODE* findleast()
{
	NODE* temp = head;
	NODE* leastnode = 0;
	int least = 1000000;
	while (temp != 0)
	{
		if (temp->frequency < least)
		{
			least = temp->frequency;
			leastnode = temp;
		}
		temp = temp->next;
	}
	
	temp = head;
	if (leastnode == head)
	{
		head = head->next;
		return leastnode;
	}
	while (temp->next != leastnode)
	{
		temp = temp->next;
	}
	temp->next = leastnode->next;
	return leastnode;
}
int flag = 0;
void travesal(NODE* n, char _code, char find)
{
	if (n==0 && flag==0 )
	{
		printf("1");
		flag = 2;
		return;
	}
	if (flag == 2 && n == 0)
	{
		return;
	}
	idx++;
	buf[idx] = _code;
	if (n->left == 0 && n->right == 0)
	{
		if(n->c == find)
		printf("%d", strlen(buf));
	}
	else
	{
		travesal(n->left, '0' ,find);
		travesal(n->right, '1',find);
	}

	buf[idx] = 0;
	idx--;
	
}

int main(void)
{
	int freq;
	char c;
	while (1)
	{
		scanf("%c %d\n", &c, &freq);
		if (freq < 0)
		{
			break;
		}
		addToSLL(createNode(c, freq));
	}
	scanf("%c", &c);

	while (1)
	{
		if (head->next == 0)
		{
			break;
		}
		NODE* a = findleast();
		NODE* b = findleast();
		NODE* c = createNode(' ', a->frequency + b->frequency);
		c->left = a;
		c->right = b;

		addToSLL(c);
	}

	travesal(head->left, '0', c);
	travesal(head->right, '1',c);
	char str[100];

	return 0;
}

a 5
b 6
c 7
a -1
a
--------------------------------------------------------------------------------------------------------------
11월 19일 문제 2


#include <stdio.h>

typedef struct node {
	char c;
	int frequency;
	struct node *next;
	struct node *left;
	struct node *right;
}NODE;

NODE* head = 0;
int idx = -1;
char buf[200] = { 0, };
int total = 0;
NODE* createNode(char _c, int _freq)
{
	NODE* new_one = (NODE*)malloc(sizeof(NODE));
	new_one->c = _c;
	new_one->frequency = _freq;
	new_one->left = new_one->right = new_one->next = 0;
	return new_one;
}

void addToSLL(NODE* temp)
{
	if (head == 0)
	{
		head = temp;
		return;
	}
	NODE* tmp = head;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
	}
	tmp->next = temp;
	return;
}
NODE* findleast()
{
	NODE* temp = head;
	NODE* leastnode = 0;
	int least = 1000000;
	while (temp != 0)
	{
		if (temp->frequency < least)
		{
			least = temp->frequency;
			leastnode = temp;
		}
		temp = temp->next;
	}
	
	temp = head;
	if (leastnode == head)
	{
		head = head->next;
		return leastnode;
	}
	while (temp->next != leastnode)
	{
		temp = temp->next;
	}
	temp->next = leastnode->next;
	return leastnode;
}
int flag = 0;
void travesal(NODE* n, char _code, char find)
{
	if (n==0 && flag==0 )
	{
		printf("1");
		flag = 2;
		return;
	}
	if (flag == 2 && n == 0)
	{
		return;
	}
	idx++;
	buf[idx] = _code;
	if (n->left == 0 && n->right == 0)
	{
		total = + total + strlen(buf);
	}
	else
	{
		travesal(n->left, '0' ,find);
		travesal(n->right, '1',find);
	}

	buf[idx] = 0;
	idx--;
	
}

int main(void)
{
	int freq;
	char c;
	while (1)
	{
		scanf("%c %d\n", &c, &freq);
		if (freq == 0)
		{
			continue;
		}
		if (freq == -1)
		{
			break;
		}
		addToSLL(createNode(c, freq));
	}
	scanf("%c", &c);

	while (1)
	{
		if (head->next == 0)
		{
			break;
		}
		NODE* a = findleast();
		NODE* b = findleast();
		NODE* c = createNode(' ', a->frequency + b->frequency);
		c->left = a;
		c->right = b;

		addToSLL(c);
	}

	travesal(head->left, '0', c);
	travesal(head->right, '1',c);
	char str[100];

	printf("%d ", total);
	return 0;
}



a 5
b 6
c 7
b -1
--------------------------------------------------------------------------------------------------------------
11월 19일 문제 3

#include <stdio.h>

typedef struct node {
	char c;
	int frequency;
	struct node *next;
	struct node *left;
	struct node *right;
}NODE;

NODE* head = 0;
int idx = -1;
char buf[200] = { 0, };
int total = 0;
NODE* createNode(char _c, int _freq)
{
	NODE* new_one = (NODE*)malloc(sizeof(NODE));
	new_one->c = _c;
	new_one->frequency = _freq;
	new_one->left = new_one->right = new_one->next = 0;
	return new_one;
}

void addToSLL(NODE* temp)
{
	if (head == 0)
	{
		head = temp;
		return;
	}
	NODE* tmp = head;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
	}
	tmp->next = temp;
	return;
}
NODE* findleast()
{
	NODE* temp = head;
	NODE* leastnode = 0;
	int least = 1000000;
	while (temp != 0)
	{
		if (temp->frequency < least)
		{
			least = temp->frequency;
			leastnode = temp;
		}
		temp = temp->next;
	}
	
	temp = head;
	if (leastnode == head)
	{
		head = head->next;
		return leastnode;
	}
	while (temp->next != leastnode)
	{
		temp = temp->next;
	}
	temp->next = leastnode->next;
	return leastnode;
}

void travesal(NODE* n, char _code, char find)
{
	idx++;
	buf[idx] = _code;
	if (n->left == 0 && n->right == 0)
	{
		if (n->c == find)
		{
			total = +total + strlen(buf);
		}
	}
	else
	{
		travesal(n->left, '0' ,find);
		travesal(n->right, '1',find);
	}

	buf[idx] = 0;
	idx--;
	
}

int main(void)
{
	int freq;
	char c;
	while (1)
	{
		scanf("%c %d\n", &c, &freq);
		if (freq == 0)
		{
			continue;
		}
		if (freq == -1)
		{
			break;
		}
		addToSLL(createNode(c, freq));
	}

	while (1)
	{
		if (head->next == 0)
		{
			break;
		}
		NODE* a = findleast();
		NODE* b = findleast();
		NODE* c = createNode(' ', a->frequency + b->frequency);
		c->left = a;
		c->right = b;

		addToSLL(c);
	}

	char str[100];
	int i = 0;
	scanf("%s", str);
	while (1)
	{
		if (str[i] == 0)
		{
			break;
		}
		c = str[i];

		travesal(head->left, '0', c);
		travesal(head->right, '1', c);
		i++;
	}
	printf("%d ", total);
	return 0;
}


a 5
b 6
c 7
a -1
aaa
--------------------------------------------------------------------------------------------------------------
11월 26일 문제 1번

#include <stdio.h>
#include <string.h>


int main(void)
{
	char str[1001] = { 0, };
	char* chr_code[256] = { 0, };
	char ch[256] = { 0, };
	int idx = 0;
	int loc = 0;
	scanf("%s", str);

	char* temp = str;
	int data = 0;
	data = (int)*temp;
	temp++;
	int i = 0;
	while (*temp != '$')
	{
		idx = *temp;
		temp++;
		loc = (int)(*temp)-'0';
		temp++;
		char *go = malloc(sizeof(char)*loc + 1);
		for (i = 0; i < loc; i++)
		{
			go[i] = *temp;
			temp++;
		}
		go[i] = 0;
		chr_code[idx] = go;
	}
	int iddx = 0;
	for (i = 0; i < 256; i++)
	{
		if (chr_code[i] != 0)
		{
			ch[iddx] = (char)i;
			iddx++;
		}
	}
	ch[iddx] = 0;
	char * find = malloc(sizeof(char) * 10);
	temp++;
	i = 0;
	int l = 0;
	int flag = 0;
	while (*temp != '#')
	{
		find[i] = *temp;
		find[i + 1] = 0;
		while (ch[l] != 0)
		{
			if (strcmp(find, chr_code[ch[l]]) == 0)
			{
				printf("%c", ch[l]);
				i = 0;
				flag = 1;
				break;
			}
			l++;
		}
		l = 0;
		if (flag == 0)
		{
			i++;
		}
		else
		{
			flag = 0;
		}
		temp++;
	}

}


3a200b11c201$00001101#
--------------------------------------------------------------------------------------------------------------

11월 26 일  문제 2번


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
   char c;
   int freq;
   struct node *next;
   struct node *right;
   struct node *left;
};
struct node *head = 0;
char string[51];
char ASC[256];
char enco[100];
int iidx=-1;
char ccode[100];
int cnt = 0;
char arr[51];
char deco[100];
int deidx = 0;
struct node* node(char c, int freq)
{
   struct node *new = (struct node *)malloc(sizeof(struct node));
   new->c = c;
   new->freq = freq;
   new->left = new->right = new->next = 0;
   return new;
}
void addSLL(struct node *new)
{
   struct node *cur = head;
   if (head == 0)
   {
      head = new;
      return;
   }
   else
   {
      while (cur->next != 0)
      {
         cur = cur->next;
      }
      cur->next = new;
   }
}
struct node *smallnode()
{
   struct node *fnode = head;
   struct node *cur = head;
   int small = 999999999;
   while (cur != 0)
   {
      if (cur->freq < small)
      {
         small = cur->freq;
         fnode = cur;
      }
      cur = cur->next;
   }
   if (head == fnode)
   {
      head = head->next;
   }
   else
   {
      cur = head;
      while (cur->next != fnode)
      {
         cur = cur->next;
      }
      cur->next = fnode->next;
   }
   fnode->next = 0;
   return fnode;
}
void traverse(struct node *cur, char c, char find,int idx,int f)
{
   iidx++;
   ccode[iidx] = c;
   ccode[iidx + 1] = 0;
   if (cur->left == 0 && cur->right == 0)
   {
      if (find == cur->c)
      {
         if (f == 0)
         {
            enco[idx] = (iidx + 1) + 48;
            for (int i = 0; i <= iidx; i++)
            {
               enco[idx + i + 1] = ccode[i];
               cnt++;
            }
         }
         else
         {
            for (int i = 0; i <= iidx; i++)
            {
               deco[deidx] = ccode[i];
               deidx++;
            }
         }
      }
      ccode[iidx] = 0;
      iidx--;
      return;
   }
   else
   {
      traverse(cur->left, '0', find, idx,f);
      traverse(cur->right, '1', find, idx,f);
   }
   ccode[iidx] = 0;
   iidx--;
   return;
}

int main(void)
{
   int k = 1;
   int total = 0;
   memset(string, 0, sizeof(51));
   scanf("%s", string);
   int flag = 0;
   int h = 0;
   deco[0] = '$';
   deidx++;
   for (int i = 0; i < strlen(string); i++)
   {
      for (int j = 0; j <= h; j++)
      {
         if (string[i] == arr[j])
         {
            flag = 1;
         }
      }
      if (flag == 0)
      {
         arr[h] = string[i];
         h++;
      }
      flag = 0;
   }
   total = h;
   for (int i = 0; i < strlen(string); i++)
   {
      ASC[(int)string[i]]++;
   }
   for (int i = 0; i < 256; i++)
   {
      if (ASC[i] > 0)
      {
         addSLL(node(i, ASC[i]));
      }
   }
   while (head->next != 0)
   {
      struct node *first = smallnode();
      struct node *secound = smallnode();
      struct node *new = node(first->c, first->freq + secound->freq);
      if (first->c > secound->c)
      {
         new->left = secound;
         new->right = first;
      }
      else
      {
         new->left = first;
         new->right = secound;
      }
      addSLL(new);
   }
   memset(enco, 0, sizeof(100));
   enco[0] = total + 48;
   for (int i = 0; i < h; i++)
   {
      enco[k] = arr[i];
      k++;
      traverse(head->left, '0', arr[i], k,0);
      traverse(head->right, '1', arr[i], k,0);
      k = k + cnt + 1;
      cnt = 0;
   }
   for (int i = 0; i < strlen(string); i++)
   {
      traverse(head->left, '0', string[i], k, 1);
      traverse(head->right, '1', string[i], k, 1);
   }
   deco[deidx] = '#';
   for (int i = 0; i < strlen(enco); i++)
   {
      printf("%c", enco[i]);
   }
   printf("%s", deco);
}

aaabbc


출력 : 3a10b210c211$000101011#






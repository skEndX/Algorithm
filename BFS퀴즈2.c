#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int *test = 0;
int cnt = 0;

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
	/* 이 곳을 채워 넣으시오 */
	if ((rear + 1) % VERTEX_NUM == front)
	{
		return;
	}
	queue[rear] = v;
	rear = (rear + 1) % VERTEX_NUM;
}

/*
 Empty queue이면 -999를 return
*/
int dequeue()
{
	/* 이 곳을 채워 넣으시오 */
	if (front == rear)
	{
		return -999;
	}
	int re = queue[front];
	front = (front + 1) % VERTEX_NUM;
	return re;
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
	/* 이 곳을 채워 넣으시오 */
	int i;
	for (i = front; i != rear; i = (i + 1) % VERTEX_NUM)
	{
		if (v == queue[i])
		{
			return 1;
		}
	}
	return 0;

}

void find(int v)
{
	int i;
	for (i = v * VERTEX_NUM; i < v*VERTEX_NUM + VERTEX_NUM; i++)
	{
		int v_id = i - v * VERTEX_NUM;
		if (visited[v_id] == 0 && graph[v_id] == 1 && isInQueue(v_id) == 0)
		{
			enqueue(v_id);

		}
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
		test[cnt] = cur_vertex;
		cnt++;

		// 아래 코드는 절대 수정하지 마세요.
		if ((cur_vertex % 2) == 0)
		{
			mystery += cur_vertex;
		}
		//------------------------------
		// 여기부터는 수정해도 됩니다.


		// 2. 친구들을 찾아서 queue에 enqueue
		//
		// 위 설명을 구현하시오.
		//
		find(cur_vertex);

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
	test = (int*)malloc(sizeof(int) * VERTEX_NUM);
	
	for (i = 0; i < VERTEX_NUM; i++)
	{
		visited[i] = 0;
		test[i] = 0;
	}

	// BFS 시작
	doBFS(0);
	int a, b;

	scanf("%d",&a);
	scanf("%d", &b);
	for (i = 0; i < VERTEX_NUM; i++)
	{
		if (test[i] == a)
		{
			printf("1");
			return 0;
		}
		else if (test[i] == b)
		{
			printf("0");
			return 0;
		}
	}
}
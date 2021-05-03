#include<stdio.h>
#define sz 5

struct stra_info {
	int found;
	int d;
	int pre_r;
	int pre_c;
};
struct stra_info table[sz][sz];

struct coord {
	int row;
	int col;
};

char map[5][5] = {
	{'.','.','.','.','.'},
	{'.','#','#','#','.'},
	{'.','.','#','.','.'},
	{'.','#','#','.','#'},
	{'.','.','#','.','.'}
};

void show() {
	for (int i = 0; i < sz; i++)
	{
		for (int  j = 0; j < sz; j++)
		{
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

void initTable() {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			table[i][j].found = 0;
			table[i][j].d = 9999;
			table[i][j].pre_r = -1;
			table[i][j].pre_c = -1;
		}
	}
}

struct coord find() {
	struct coord s_coord;
	int s_d = 9999;

	s_coord.row = -1;
	s_coord.col = -1;

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (table[i][j].found==0 && table[i][j].d<s_d)
			{
				s_d = table[i][j].d;
				s_coord.row = i;
				s_coord.col = j;
			}
		}
	}
	return s_coord;
}

void check(int r, int c, int nr, int nc) {
	if (nr<0||nr>=sz||nc<0||nc>=sz)
	{
		return;
	}
	if (map[nr][nc]=='#')
	{
		return;
	}
	if (table[nr][nc].d>table[r][c].d+1)
	{
		table[nr][nc].d = table[r][c].d + 1;
		table[nr][nc].pre_r = r;
		table[nr][nc].pre_c = c;
	}
}

void update(int r,int c) {
	check(r, c, r + 1, c);
	check(r, c, r - 1, c);
	check(r, c, r , c+1);
	check(r, c, r , c-1);
}

int main() {
	int start_r, start_c;
	scanf("%d %d", &start_r, &start_c);

	int end_r, end_c;
	scanf("%d %d", &end_r, &end_c);

	initTable();
	table[start_r][start_c].found = 1;
	table[start_r][start_c].d = 0;
	update(start_r, start_c);

	while (1)
	{
		struct coord small = find();
		if (small.row==-1&&small.col==-1)
		{
			break;
		}
		table[small.row][small.col].found = 1;
		update(small.row, small.col);
	}

	int tr = end_r;
	int tc = end_c;
	while (1)
	{
		map[tr][tc] = '$';

		int temp_r = table[tr][tc].pre_r;
		int temp_c = table[tr][tc].pre_c;

		tr = temp_r;
		tc = temp_c;
		if (tr==-1&&tc==-1)
		{
			break;
		}
	}
	show();
}
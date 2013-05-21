#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_ROW 5
#define MAX_COL 5
#define QUEUE_SIZE 5

struct point {
	int row;
	int col;
} queue[QUEUE_SIZE];
int head = 0, tail = 0;

void enqueue(struct point p) {
	queue[tail++] = p;
	tail = tail % QUEUE_SIZE;
}

struct point dequeue(void) {
	head = head % QUEUE_SIZE;
	return queue[head++];
}

int is_empty(void)
{
	return head % QUEUE_SIZE == tail;
}

int is_full(void)
{
	return (tail + 1) % QUEUE_SIZE == head % QUEUE_SIZE;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++) {
			printf("%d ", maze[i][j]);
		}
		putchar('\n');
	}
	printf("*********\n");
}

void visit(int row, int col)
{
	if (is_full()) {
		printf("The queue is full!\n");
		exit(1);
	}

	struct point visit_point = { row, col };
	maze[row][col] = 2;
	enqueue(visit_point);
}

int main(void)
{
	struct point p = { 0, 0 };

	maze[p.row][p.col] = 2;
	enqueue(p);

	while (!is_empty()) {
		p = dequeue();
		if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
			break;
		}
		if (p.col + 1 < MAX_COL && maze[p.row][p.col+1] == 0) {
			visit(p.row, p.col+1);
		}
		if (p.row + 1 < MAX_ROW && maze[p.row+1][p.col] == 0) {
			visit(p.row+1, p.col);
		}
		if (p.row - 1 >= 0 && maze[p.row-1][p.col] == 0) {
			visit(p.row-1, p.col);
		}
		if (p.col - 1 >= 0 && maze[p.row][p.col-1] == 0) {
 			visit(p.row, p.col-1);
		}
		print_maze();
	}

	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		printf("Path found!\n");
	} else {
		printf("No path!\n");
	}

	return 0;
}

		

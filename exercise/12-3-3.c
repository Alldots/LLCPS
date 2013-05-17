#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

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
		for (j = 0; j < MAX_COL ; j++) {
			printf("%d ", maze[i][j]);
		}
		putchar('\n');
	}

	printf("*********\n");
}

int DFS(int row ,int col)
{
	int found = 0;

	print_maze();
	if (row == MAX_ROW - 1 && col == MAX_COL - 1) {
		found = 1;
	}
	if (found == 0 && row + 1 < MAX_ROW && maze[row + 1][col] == 0) {
		maze[row + 1][col] = 2;
		found = DFS(row + 1, col);
	}
	if (found == 0 && col +  1 < MAX_COL && maze[row][col + 1] == 0) {
		maze[row][col + 1] = 2;
		found = DFS(row, col + 1);
	}
	if (found == 0 && row - 1 >= 0 && maze[row - 1][col] == 0) {
		maze[row- 1][col] = 2;
		found = DFS(row - 1, col);
	}
	if (found == 0 && col - 1 >= 0 && maze[row][col - 1] == 0) {
		maze[row][col - 1] = 2;
		found = DFS(row, col - 1);
	}
	
	if (found == 1) {
		printf("(%d, %d)\n", row, col);
	} else if (row == 0 && col == 0) { // Assuming found == 0
		printf("No path\n");
	}

	return found;
}

int main(void) {
	DFS(0, 0);

	return 0;
}

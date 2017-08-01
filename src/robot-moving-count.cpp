#include <stdio.h>
#include <stack>
using namespace std;

class Solution {
public:
	int Count(int row, int col) {
		int count = 0;
		while (row || col) {
			count += row % 10 + col % 10;
			row /= 10;
			col /= 10;
		}
		return count;
	}
	int movingCount(int threshold, int rows, int cols) {
		if ((rows < 1 && cols < 1) || threshold < 0)
			return 0;
		int R = 1;
		bool* visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);
		visited[0] = true;
		stack<int> S;
		S.push(0);
		int p[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
		while (!S.empty()) {
			int i = S.top() / cols, j = S.top() % cols;
			S.pop();
			for (int k = 0; k < 4; k++) {
				int row = i + p[k][0], col = j + p[k][1];
				if (row >= 0 && row < rows&&col >= 0 && col < cols && !visited[row*cols + col] && Count(row, col) <= threshold) {
					S.push(row*cols + col);
					visited[row*cols + col] = true;
					R++;
				}
			}
		}
		return R;
	}
};
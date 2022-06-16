#include <bits/stdc++.h>
using namespace std;
#define ROW 10
#define COL 10

struct Point
{
	int x;
	int y;
};

struct queueNode
{
	Point pt; // tọa độ điểm đầu && cuối
	int dist; // đếm khoảng cách
};

// kiểm tra điểm có tồn tại ko
bool isValid(int row, int col)
{
	// return true if row number and column number
	// is in range
	return (row >= 0) && (row < ROW) &&
		   (col >= 0) && (col < COL);
}

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int BFS(int mat[][COL], Point src, Point dest)
{

	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);

	// đi qua rồi thì gán true
	visited[src.x][src.y] = true;

	// tạo BFS
	queue<queueNode> q;

	// tạo điểm đầu + dist = 0
	queueNode s = {src, 0};
	q.push(s); // push vào q

	while (!q.empty())
	{
		queueNode curr = q.front();
		Point pt = curr.pt;

		// nếu đến đích thì return dist
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

		// chưa đến đích thì q bay vào pop() đợi
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];

			// nếu isvalid hợp lệ + có đường đi + chưa được truy cập ( false ) thì..
			if (isValid(row, col) && mat[row][col] &&
				!visited[row][col])
			{
				// đánh dấu ô đã đi qua và push vào q
				visited[row][col] = true;
				queueNode Adjcell = {{row, col},
									 curr.dist + 1};
				q.push(Adjcell);
			}
		}
	}
	return -1;
}

int main()
{
	int mat[ROW][COL] =
		{
			{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
			{1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
			{1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
			{1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
			{1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
			{1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
			{1, 1, 0, 0, 0, 0, 1, 0, 0, 1}};

	Point source = {0, 0};
	Point dest = {4, 4};

	int dist = BFS(mat, source, dest);

	if (dist != -1)
		cout << "Shortest Path is " << dist;
	else
		cout << "Đéo có nhá";

	return 0;
}

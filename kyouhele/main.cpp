#include <iostream>
#include <queue>
using namespace std;

// void bfs(int start, int goal, int *is_visit);
void bfs(int start, int n);

int start , goal, total_move = 10002, cnt=0;
int is_visit[100001];
bool first = true;

int main ()
{
	cin >> start >> goal;
	is_visit[start] = 1;
	bfs(start, 0);
	return 0;
}

void bfs(int start, int n)
{
	queue<pair<int, int>> que;

	que.push(make_pair(start, 0));
	while (!que.empty())
	{
		int x = que.front().first;
		int move = que.front().second;

		que.pop();
		is_visit[x] = 1;
		// cout << x << "----" << start << "====="<<move <<endl;
		if (!first && total_move == move && x == goal)
			cnt++;
		if(first && x == goal)
		{
			total_move = move;
			first = false;
			cnt++;
		}
		if (x + 1 >= 0 && x + 1 < 100001 && !is_visit[x + 1])
		{
			// is_visit[x + 1] = 1;
			que.push(make_pair(x + 1, move + 1));
		}
		if (x - 1 >= 0 && x - 1 < 100001 && !is_visit[x - 1])
		{
			// is_visit[x - 1] = 1;
			que.push(make_pair(x - 1, move + 1));
		}
		if (x * 2 >= 0 && x * 2 < 100001 && !is_visit[x * 2])
		{
			// is_visit[x * 2] = 1;
			que.push(make_pair(x * 2, move + 1));
		}
	}
	cout << total_move <<endl;;
	cout << cnt <<endl;;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;										// N, M �Է�

	vector<int> indegree(N + 1);						// ���⿡ �������� ���
	vector<int> v[1001];								// ���⿡ �ش� �������� ������ ���� ���
	vector<int> list(N);								// ���⿡ ������ �⿬ ���� ���ʷ� ���
	int cur = 0;										// vector list�� �� ������ �� ���
	queue<int> tmp_queue;								// �������� ������ ���� ť

	// ������ �Է�
	for (int i = 0; i < M; i++)							// M���� ���̽� �Է�
	{
		int num;
		cin >> num;										// �� ���̽��� ���� �� �Է�

		int prev, next;
		for (int j = 0; j < num; j++)					// ���� ����ŭ �Է�
		{
			if (j == 0)									// �ش� ���̽����� ���� ó�� �Է��ϴ� ���
			{
				cin >> next;							// �ϴ� �Է°��� next�� �Է�
				continue;
			}
			else										// �ش� ���̽����� �� ��° ���� �Է��ϴ� ���
			{
				prev = next;							// ���� next ���� prev�� �ְ�
				cin >> next;							// next�� ���� ���� �Է�

				v[prev].push_back(next);				// �� �� ���� prev���� ������ ���� next�� ���
				indegree[next]++;						// next ������ ���� ����
			}
		}
	}

	// ������ 0�� ���� ť�� push
	for (int i = 1; i <= N; i++)						// ���� N���� ������ �˻�
	{
		if (indegree[i] == 0)							// �ش� ������ ������ 0�̸�
		{
			tmp_queue.push(i);							// ť�� push
		}
	}

	// �⿬ ������ list�� �ִ� ���� 
	while (!tmp_queue.empty())							// ť�� �� ������ �ݺ�
	{
		int cur_artist = tmp_queue.front();				// ť�� �� �� ������ cur_artist�� ����
		list[cur++] = cur_artist;						// cur_artist�� list�� �ְ� cur 1 ����
		tmp_queue.pop();								// �� �� ť�� �ִ� �� pop

		for (int i = 0; i < v[cur_artist].size(); i++)	// pop�� ������ ���� �������� Ž��
		{
			int next_artist = v[cur_artist][i];			// �ش� ������ next_artist�� ����
			indegree[next_artist]--;					// ���� next_artist�� �ռ� pop�� cur_artist �������� ���� ����, ���� 1 ����

			if (indegree[next_artist] == 0)				// ���� next_artist ������ ������ 0�̸�
			{
				tmp_queue.push(next_artist);			// ť�� next_artist push
			}
		}
	}

	// list ���
	if (cur == N)										// ���� ��� ������ ��� Ž���Ǿ�
	{													// list�� ���ٸ� cur == N
		for (int i = 0; i < N; i++)
		{
			cout << list[i] << endl;
		}
	}
	else
	{
		cout << 0 << endl;								// �׷�ġ ���� ��� 0 ���
	}

	return 0;
}
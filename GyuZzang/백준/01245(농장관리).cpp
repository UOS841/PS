#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

pair<bool, bool> check_side(vector<vector<int>> farm, int r, int c) {
	int row_start = r > 0 ? r - 1 : r;
	int row_end = r < farm.size() - 1 ? r + 1 : r;
	int col_start = c > 0 ? c - 1 : c;
	int col_end = c < farm[0].size() - 1 ? c + 1 : c;

	bool is_smaller = false, is_bigger = false;

	for (int i = row_start; i <= row_end; i++) {
		for (int j = col_start; j <= col_end; j++) {
			if (farm[i][j] < farm[r][c]) is_smaller = true;
			else if (farm[i][j] > farm[r][c]) is_bigger = true;
		}
		if (is_smaller && is_bigger) break;
	}

	return { is_smaller , is_bigger };
}

int main() {
	int N, M, res = 0;
	vector<vector<int>> farm;
	vector<vector<int>> visited;
	stack<pair<int, int>> st;
	
	cin >> N >> M;
	farm.resize(N, vector<int> (M));
	visited.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> farm[i][j];
		}
	}
	//�ֺ��� ��� ������ ������ �ϴ� Ž�� ����. --> �ڱ�� ���� �ֵ� Ž��,
	//Ȥ�� Ž�� �� �ڱ⺸�� ū ���� �����ϸ�, Ž�� ������ �ٽ� ū �ֺ��� ����.
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
			pair<bool, bool> small_big = check_side(farm, i, j);
			if (!small_big.second) {
				cout << i << j << endl;
				st.push({ i, j });
				visited[i][j] = 1;
				bool is_peak = true;
				while (!st.empty()) {
					pair<int,int> now = st.top();
					int height = farm[now.first][now.second];
					bool is_break = false;
					st.pop();
					//�����¿� �밢�� Ž���ϸ鼭 �ڱ�� �����ֵ� Ǫ��, 
					for (int r = max(0, now.first-1); r <= min(N - 1, now.first+1); r++) {
						for (int c = max(0, now.second - 1); c <= min(M - 1, now.second + 1); c++) {
							if (height == farm[r][c] && !visited[r][c]) {
								st.push({ r,c });
								visited[r][c] = 1;
							}
							else if (height < farm[r][c]) {		//�� ū �� ������ st���� �ٽ� �� Ǫ��.
								while (!st.empty()) st.pop();
								if (visited[r][c]) {
									is_break = true;
									is_peak = false;
									break;
								}
								st.push({ r,c });
								visited[r][c] = 1;
								is_break = true;
								break;
							}
						}
						if (is_break) break;
					}

				}
				if(is_peak) res++;
				//���� ������, 4 üũ�ϰ� ���߿� 3������ ī��Ʈ�� �ǳ�... ��ũ���� Ȯ���� ���� ������
			}
		}
	}

	cout << res;
	
}
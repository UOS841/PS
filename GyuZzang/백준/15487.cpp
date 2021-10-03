#include<iostream>
#include<vector>

using namespace std;

struct Max {
	int diff;
	int idx;
};

int main() {
	// �߸� Ǯ����. �׳� �� ���� ���� n^2�� Ǯ��
	//idx end�� 1~n-3���� ����(for)
		// 0~end end+1~n-1 ���� �ִ� ���̰� ���ϱ� (end++�Ǹ� �ѹ����� �� ���ϸ� �ǰڴ�!)

	int N, end = 1;
	vector<int> arr;
	vector<int> max_list;
	Max max1, max2;

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> N;
	arr.resize(N);
	max_list.resize(N-2,0);

	max_list[0] = -1000000;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	max1 = { -1000000, 0};
	max2 = { -1000000, N - 1 };
	for (; end < N - 2; end++) {
		if (end == 1 || arr[end] > arr[max1.idx]) {
			for (int i = 0; i < end; i++) {
				int cur_diff = arr[end] - arr[i];
				if (cur_diff > max1.diff) max1 = { cur_diff, end }; //���� ���� �� ū �κ� �ε��� ����
			}
			cout << max1.diff;
			max_list[end] += max1.diff;
		}
	
		int end_rvs = N - 1 - end;
		if (end == 1 || arr[end_rvs] < arr[max2.idx]) {
			for (int i = end_rvs + 1; i < N; i++) {
				int cur_diff = arr[i] - arr[end_rvs];
				if (cur_diff > max2.diff) max2 = { cur_diff, end_rvs }; //���� ���� �� ���� �κ� �ε��� ����
			}
			cout << max2.diff;
			max_list[end_rvs - 1] += max2.diff;
		}
	}

	int res = max_list[0];
	for (int i = 1; i < max_list.size(); i++) {
		if (res < max_list[i]) res = max_list[i];
	}

	cout << res;

}
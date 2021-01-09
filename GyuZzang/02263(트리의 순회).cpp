#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> in;
vector<int> post;

string find_pre(int in_start, int in_end, int post_start, int post_end) {
	int center = post[post_end];
	int num_left = find(in.begin(), in.end(), center) - in.begin() - in_start;
	int num_right = in_end - in_start - num_left;
	string left, right;
	int left_in_start, left_in_end, left_post_start, left_post_end,
		right_in_start, right_in_end, right_post_start, right_post_end;

	//cout << center << num_left << num_right << endl;

	if (num_left == 0) left = "";
	else if (num_left == 1) left = " " + to_string(in[in_start]); //cout << left; 
	else {
		left_in_start = in_start;
		left_in_end = in_start + num_left - 1;
		left_post_start = post_start;
		left_post_end = post_start + num_left - 1; 

		//cout << left_in_start<< left_in_end<<left_post_start<<left_post_end<< endl;
	}

	if (num_right == 0) right = "";
	else if (num_right == 1) right = " " + to_string(in[in_start + num_left + 1]); //cout << right;
	else {
		right_in_start = in_start + num_left + 1;
		right_in_end = in_end;
		right_post_start = post_start + num_left;
		right_post_end = post_end - 1;
		//cout << right_in_start<< right_in_end<<right_post_start<<right_post_end<<endl;
	}

	return to_string(center) + ((num_left > 1) ? " " + find_pre(left_in_start, left_in_end, left_post_start, left_post_end) : left) + ((num_right > 1) ? " " + find_pre(right_in_start, right_in_end, right_post_start, right_post_end) : right);
}

int main() {
	//pre	: c-l-r
	//in	: l-c-r
	//post	: l-r-c
	int n;

	
	cin >> n;
	in.resize(n);
	post.resize(n);

	for (int i = 0; i < n; i++) cin >> in[i];
	for (int i = 0; i < n; i++) cin >> post[i];

	cout << find_pre(0, n - 1, 0, n - 1);

}
	//post�� �������� center ã�� �뵵
	//ã�� center�������� in�� ����, ������ �� ����Ʈ�� ��� ���� Ȯ��.
	//post���� �ش� ������° �ε��� -> �� ����Ʈ���� center
	//����Ʈ�� ��尳���� 1���̸� ����. ����� ȣ��

	//������ vector ����� Ǯ���ϴ� �޸��ʰ� --> index�� �Ѱܺ���.


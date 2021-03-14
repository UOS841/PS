#include<iostream>
#include<bitset>
#include<cmath>

using namespace std;

//�켱 k���� ���� �� ���� �� ������ ���� �� �� ���� ���� �� ��ġ��, 
//ó���� ��� 00001, �ѹ� ��ġ�� 00010, �ι� ��ġ�� 00100, ������ġ�� 01000...
int count_left_bottle(string str) {
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if(str[i] == '1') cnt++;
	}
	//cout << cnt;
	return cnt;
}

int count_additional_bottle(string str, int left) {
	int sum = 0;
	for (int i = str.size()-1; i > 0; i--) {
		int sti = str[i] == '1' ? 1 : 0;
		sum += sti * pow(2, str.size() - i - 1);
		if (str[i] == '0') left--;
		if (!left) return sum;
	}
	return -2;
}

int main() {
	int num_of_bottle, bottle_limit;
	cin >> num_of_bottle >> bottle_limit;

	bitset<24> bs(num_of_bottle);
	string bs_string = bs.to_string();

	//cout << bs;
	int reducing = count_left_bottle(bs_string) - bottle_limit; //# of bottle that have to reduce
	
	//cout << reducing;

	if (reducing <= 0) {
		cout << 0;
		return 0;
	}

	int res = count_additional_bottle(bs.flip().to_string(), reducing + 1);

	if (res >= 999) {
		cout << 0;
		return 0;
	}

	cout << res + 1;
	
	return 0;
	
	//9->2
	//0	1	2	3
	//9
	//1	4
	//1	0	2	
	//1	0	0	1

	//101010101 -> reducing 2
	//	   1011

	//���� 2�� �ٿ��� �Ѵٸ� ����° 1 �������� filp +1 ��ŭ �� �ʿ��ϴ� 
	//�� flip�� �ؼ� �ڿ��� ����° 0���� ���� �� +1

}
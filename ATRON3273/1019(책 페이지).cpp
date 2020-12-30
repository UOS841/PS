#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int N, position = 1, amount_sub_zero = 0;
	cin >> N;

	while (N / position > 0)
	{
		for (int i = 0; i < 10; i++)
		{
			int tmp = 0;
			// ���� Ž������ ���� i�� �ڸ������� �� Ŭ ���
			if (N / position % 10 < i)
			{
				tmp += ((N / (position * 10)) * position);
			}
			// ���� Ž������ ���� i�� �ڸ����� ���� ���
			else if (N / position % 10 == i)
			{
				tmp += ((N / (position * 10)) * position);
				tmp += N % position + 1;
			}
			// ���� Ž������ ���� i�� �ڸ������� �� ���� ���
			else
			{
				tmp += ((N / (position * 10) + 1) * position);
			}
			count[i] += tmp;
		}
		amount_sub_zero += position;
		position *= 10;
	}
	// ���� ��꿡�� ������ ���ڿ� 0�� ��� ���� ��츦 ���
	// ������� 0�� ������ N�� �ڸ�����ŭ 1�� ���� ����
	// (ex. 2563 -> 4�ڸ� ���� ������� 0�� ������ 1111��)
	count[0] -= amount_sub_zero;

	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << " ";
	}

	return 0;
}
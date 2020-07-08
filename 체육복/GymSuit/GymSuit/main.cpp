#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(int, vector<int>, vector<int>);

int main()
{
	// �л��� ��
	int n = 5;

	// ü������ �Ҿ���� �л��� ��ȣ
	vector<int> lost = { 2, 4 };

	// ������ ü������ ������ �л��� ��ȣ
	vector<int> reserve = { 1, 3, 5 };

	// �����
	cout << "ü������ ���� �ο� : " << solution(n, lost, reserve) << endl;

	return 0;
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
	// �����ο�
	int answer = 0;

	// üũ��
	bool isFind = false;

	// �л����� ������ �ִ� ü���� ������ ��´�.
	short** haveGymSuit = new short* [n];

	// �迭 �ʱ�ȭ (�⺻���� ��� �л��� ü������ ������ �ִٰ� �����Ѵ�)
	for (int i = 0; i < n; ++i)
	{
		haveGymSuit[i] = new short[1];
		haveGymSuit[i][0] = 1;

	}

	// ü������ ���� �л��� ã�� ���ְ�, ������ �ִ� �л��� �����ش�.
	for (int i = 0; i < lost.size(); ++i)
		haveGymSuit[lost[i] - 1][0]--;

	for (int i = 0; i < reserve.size(); ++i)
		haveGymSuit[reserve[i] - 1][0]++;

	// ������ �ִٸ� ü������ ���� �л����� �����ش�.
	for (int i = 0; i < n; i++)
	{
		isFind = false;

		// ü������ ���ٸ� ���̳� �� �л��� �ִ��� üũ�Ѵ�.
		if (!haveGymSuit[i][0])
		{
			// ���� �л� üũ
			if (i - 1 >= 0 && !isFind)
			{
				// ���࿡ ������ �ִٸ�
				if (haveGymSuit[i - 1][0] > 1)
				{
					haveGymSuit[i - 1][0]--;	// �����ָ鼭 ����
					haveGymSuit[i][0]++;		// �������� ����
					isFind = true;				// ���ȴٴ� üũ

				}

			}

			// ���� �л� üũ
			if (i + 1 < n && !isFind)
			{
				// ���࿡ ������ �ִٸ�
				if (haveGymSuit[i + 1][0] > 1)	
				{
					haveGymSuit[i + 1][0]--;	// �����ָ鼭 ����
					haveGymSuit[i][0]++;		// �������� ����
					isFind = true;				// ���ȴٴ� üũ

				}

			}

		}

	} // end for

	// ü���� �ִ� �л� üũ
	for (int i = 0; i < n; ++i)
	{
		if (haveGymSuit[i][0]) answer++;

	}

	// �޸� ����
	for (int i = 0; i < n; ++i)
		delete[] haveGymSuit[i];
	delete[] haveGymSuit;

	return answer;
}
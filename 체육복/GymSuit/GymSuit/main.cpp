#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(int, vector<int>, vector<int>);

int main()
{
	// 학생의 수
	int n = 5;

	// 체육복을 잃어버린 학생의 번호
	vector<int> lost = { 2, 4 };

	// 여벌의 체육복을 가져온 학생의 번호
	vector<int> reserve = { 1, 3, 5 };

	// 결과값
	cout << "체육수업 참여 인원 : " << solution(n, lost, reserve) << endl;

	return 0;
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
	// 참여인원
	int answer = 0;

	// 체크용
	bool isFind = false;

	// 학생들이 가지고 있는 체육복 수량을 담는다.
	short** haveGymSuit = new short* [n];

	// 배열 초기화 (기본으로 모든 학생은 체육복을 가지고 있다고 가정한다)
	for (int i = 0; i < n; ++i)
	{
		haveGymSuit[i] = new short[1];
		haveGymSuit[i][0] = 1;

	}

	// 체육복이 없는 학생을 찾아 빼주고, 여분이 있는 학생은 더해준다.
	for (int i = 0; i < lost.size(); ++i)
		haveGymSuit[lost[i] - 1][0]--;

	for (int i = 0; i < reserve.size(); ++i)
		haveGymSuit[reserve[i] - 1][0]++;

	// 여분이 있다면 체육복이 없는 학생에게 빌려준다.
	for (int i = 0; i < n; i++)
	{
		isFind = false;

		// 체육복이 없다면 앞이나 뒤 학생이 있는지 체크한다.
		if (!haveGymSuit[i][0])
		{
			// 뒤쪽 학생 체크
			if (i - 1 >= 0 && !isFind)
			{
				// 만약에 여분이 있다면
				if (haveGymSuit[i - 1][0] > 1)
				{
					haveGymSuit[i - 1][0]--;	// 빌려주면서 감소
					haveGymSuit[i][0]++;		// 빌렸으니 증가
					isFind = true;				// 빌렸다는 체크

				}

			}

			// 앞쪽 학생 체크
			if (i + 1 < n && !isFind)
			{
				// 만약에 여분이 있다면
				if (haveGymSuit[i + 1][0] > 1)	
				{
					haveGymSuit[i + 1][0]--;	// 빌려주면서 감소
					haveGymSuit[i][0]++;		// 빌렸으니 증가
					isFind = true;				// 빌렸다는 체크

				}

			}

		}

	} // end for

	// 체육복 있는 학생 체크
	for (int i = 0; i < n; ++i)
	{
		if (haveGymSuit[i][0]) answer++;

	}

	// 메모리 해제
	for (int i = 0; i < n; ++i)
		delete[] haveGymSuit[i];
	delete[] haveGymSuit;

	return answer;
}
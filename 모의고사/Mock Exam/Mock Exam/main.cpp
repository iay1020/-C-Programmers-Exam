#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int>);

int main()
{
	// 정답 배열
	vector<int> answers = { 1, 3, 2, 4, 2 };
	answers = solution(answers);

	// 가장 많은 문제를 맞힌 사람
	for (int i = 0; i < answers.size(); ++i)
	{
		cout << answers[i];
		if (i + 1 < answers.size()) cout << ", ";

	}
	cout << endl;

}

vector<int> solution(vector<int> answers)
{
	vector<int> answer;

	// 수포자가 정답을 찍는 방법
	short p1_Answer_Range[5] = { 1, 2, 3, 4, 5 };
	short p2_Answer_Range[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	short p3_Answer_Range[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	// 수포자가 정답을 찍는 범위
	short p1_Size, p2_Size, p3_Size;
	p1_Size = 5; p2_Size = 8; p3_Size = 10;

	// 각 수포자가 맞춘 정답 개수
	short p1_AnswerCnt, p2_AnswerCnt, p3_AnswerCnt;
	p1_AnswerCnt = p2_AnswerCnt = p3_AnswerCnt = 0;

	// 수포자들의 인덱스
	short p1_Idx, p2_Idx, p3_Idx;
	p1_Idx = p2_Idx = p3_Idx = 0;

	// 수포자가 정답을 맞췄는지 체크
	for (int i = 0; i < answers.size(); ++i)
	{
		// 맞췄다면 카운트 증가, 인덱스 증가
		if (answers[i] == p1_Answer_Range[p1_Idx]) p1_AnswerCnt++; p1_Idx++;
		if (answers[i] == p2_Answer_Range[p2_Idx]) p2_AnswerCnt++; p2_Idx++;
		if (answers[i] == p3_Answer_Range[p3_Idx]) p3_AnswerCnt++; p3_Idx++;

		// 인덱스 범위를 초과했을때 다시 초기화
		if (p1_Idx == p1_Size) p1_Idx = 0;
		if (p2_Idx == p2_Size) p2_Idx = 0;
		if (p3_Idx == p3_Size) p3_Idx = 0;

	}

	// 제일 많은 정답 개수를 구한다.
	short manyAnswer = 0;

	if (p1_AnswerCnt > manyAnswer) manyAnswer = p1_AnswerCnt;
	if (p2_AnswerCnt > manyAnswer) manyAnswer = p2_AnswerCnt;
	if (p3_AnswerCnt > manyAnswer) manyAnswer = p3_AnswerCnt;

	// 가장 많은 정답을 맞춘 사람이 중복되었을 경우 오름차순 정렬
	if (p1_AnswerCnt == manyAnswer) answer.push_back(1);
	if (p2_AnswerCnt == manyAnswer) answer.push_back(2);
	if (p3_AnswerCnt == manyAnswer) answer.push_back(3);

	return answer;
}
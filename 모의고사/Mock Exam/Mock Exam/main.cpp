#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int>);

int main()
{
	// ���� �迭
	vector<int> answers = { 1, 3, 2, 4, 2 };
	answers = solution(answers);

	// ���� ���� ������ ���� ���
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

	// �����ڰ� ������ ��� ���
	short p1_Answer_Range[5] = { 1, 2, 3, 4, 5 };
	short p2_Answer_Range[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	short p3_Answer_Range[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	// �����ڰ� ������ ��� ����
	short p1_Size, p2_Size, p3_Size;
	p1_Size = 5; p2_Size = 8; p3_Size = 10;

	// �� �����ڰ� ���� ���� ����
	short p1_AnswerCnt, p2_AnswerCnt, p3_AnswerCnt;
	p1_AnswerCnt = p2_AnswerCnt = p3_AnswerCnt = 0;

	// �����ڵ��� �ε���
	short p1_Idx, p2_Idx, p3_Idx;
	p1_Idx = p2_Idx = p3_Idx = 0;

	// �����ڰ� ������ ������� üũ
	for (int i = 0; i < answers.size(); ++i)
	{
		// ����ٸ� ī��Ʈ ����, �ε��� ����
		if (answers[i] == p1_Answer_Range[p1_Idx]) p1_AnswerCnt++; p1_Idx++;
		if (answers[i] == p2_Answer_Range[p2_Idx]) p2_AnswerCnt++; p2_Idx++;
		if (answers[i] == p3_Answer_Range[p3_Idx]) p3_AnswerCnt++; p3_Idx++;

		// �ε��� ������ �ʰ������� �ٽ� �ʱ�ȭ
		if (p1_Idx == p1_Size) p1_Idx = 0;
		if (p2_Idx == p2_Size) p2_Idx = 0;
		if (p3_Idx == p3_Size) p3_Idx = 0;

	}

	// ���� ���� ���� ������ ���Ѵ�.
	short manyAnswer = 0;

	if (p1_AnswerCnt > manyAnswer) manyAnswer = p1_AnswerCnt;
	if (p2_AnswerCnt > manyAnswer) manyAnswer = p2_AnswerCnt;
	if (p3_AnswerCnt > manyAnswer) manyAnswer = p3_AnswerCnt;

	// ���� ���� ������ ���� ����� �ߺ��Ǿ��� ��� �������� ����
	if (p1_AnswerCnt == manyAnswer) answer.push_back(1);
	if (p2_AnswerCnt == manyAnswer) answer.push_back(2);
	if (p3_AnswerCnt == manyAnswer) answer.push_back(3);

	return answer;
}
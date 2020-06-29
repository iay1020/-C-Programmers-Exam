#include<iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>>, vector<int>);

int main()
{
	vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves) << endl;

	return 0;
}

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	vector<int> saveDoll;	// ���� ������ �����Ѵ�.

	// moves �����ŭ �ݺ��Ѵ�.
	for (int playCnt = 0; playCnt < moves.size(); playCnt++)
	{
		// ������ ���� ũ�⸸ŭ �ݺ�
		for (int yCurr = 0; yCurr < board.size(); yCurr++)
		{
			// ���忡�� ������ ã�´�. (moves���� -1�� �� ������ �ε����� 0���� �����ϱ� ������)
			if (board[yCurr][moves[playCnt] - 1] != 0)
			{
				if (saveDoll.size() >= 2)
				{
					// �߰� �� ������ ���� ���� ������ ���� ��� 
					if (saveDoll.back() == board[yCurr][moves[playCnt] - 1])
					{
						saveDoll.pop_back();
						board[yCurr][moves[playCnt] - 1] = 0;
						answer += 2;
						break;

					}
				}

				saveDoll.push_back(board[yCurr][moves[playCnt] - 1]);	// ���� ������ �߰��Ѵ�.
				board[yCurr][moves[playCnt] - 1] = 0;					// ������ �ִ� �ڸ��� �ʱ�ȭ ���ش�.
				break;

			}

		}

	}


	return answer;
}

// ũ������ ��ġ currPos ��, �� �̵� �� ���� ��ġ
// ������ �Ʒ����� �������� ���δ�. (+�ٱ���)
// ����
// ���� ������ ���̸� �������.
// ���� ȭ�� ���� 2���� �迭   board
// ũ���� ��ġ �迭            moves
// ����� ������ ���� ����

// ���� �迭�� ������� 5 ~ 30 ���� 
// ĭ���� 0 ~ 100 ����
// 0�� ��ĭ
// ���� �迭 ������� 1 ~ 1000 ����
// ���� �迭�� ���Ҵ� ������ ���� ũ�� ���� �ڿ���
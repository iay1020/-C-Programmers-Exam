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

	vector<int> saveDoll;	// 뽑은 인형을 보관한다.

	// moves 사이즈만큼 반복한다.
	for (int playCnt = 0; playCnt < moves.size(); playCnt++)
	{
		// 보드의 세로 크기만큼 반복
		for (int yCurr = 0; yCurr < board.size(); yCurr++)
		{
			// 보드에서 인형을 찾는다. (moves에서 -1을 한 이유는 인덱스는 0부터 시작하기 때문에)
			if (board[yCurr][moves[playCnt] - 1] != 0)
			{
				if (saveDoll.size() >= 2)
				{
					// 추가 할 인형과 이전 뽑은 인형이 같을 경우 
					if (saveDoll.back() == board[yCurr][moves[playCnt] - 1])
					{
						saveDoll.pop_back();
						board[yCurr][moves[playCnt] - 1] = 0;
						answer += 2;
						break;

					}
				}

				saveDoll.push_back(board[yCurr][moves[playCnt] - 1]);	// 뽑은 인형을 추가한다.
				board[yCurr][moves[playCnt] - 1] = 0;					// 인형이 있던 자리를 초기화 해준다.
				break;

			}

		}

	}


	return answer;
}

// 크레인의 위치 currPos 좌, 우 이동 후 멈춘 위치
// 인형은 아래부터 차곡차곡 쌓인다. (+바구니)
// 스택
// 같은 인형이 쌓이면 사라진다.
// 게임 화면 격차 2차원 배열   board
// 크레인 위치 배열            moves
// 사라진 인형의 개수 리턴

// 보드 배열의 사이즈는 5 ~ 30 이하 
// 칸에는 0 ~ 100 정수
// 0은 빈칸
// 무브 배열 사이즈는 1 ~ 1000 이하
// 무브 배열의 원소는 보드의 가로 크기 이하 자연수
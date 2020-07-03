#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

string solution(vector<string>, vector <string>);

int main()
{
	vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> completion = { "josipa", "filipa", "marina", "nikola" };

	cout << solution(participant, completion);
	
	return 0;
}

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	unordered_map<string, int> temp;

	for (int i = 0; i < completion.size(); ++i)		++temp[completion[i]];
	
	for (int i = 0; i < participant.size(); i++)
	{
		if (temp[participant[i]] > 0) temp[participant[i]]--;
		else
		{
			answer = participant[i];
			break;
	
		}
	
	}

	return answer;

}

// 왜 레벨 1에 있는거야
// 그래도 덕분에 해시맵 사용해봄
// 해시맵이 unordered_map으로 바뀜
// insert를 하지 않고 그대로 했을때도 자동 등록이 되는 느낌? 
// 그래서 처음 for문에서 바로 ++을 해버렸음 어차피 자동 등록이면 저 키값 호출 하는 즉시 ++
// 동일이름이 한명뿐이라고 착각을 하고 있어서 계속 실패했던 문제
// 키값을 호출할때마다 숫자를 증가시켜서 몇사람이든 상관없게 만듬
// 결국에 나중에 체크할때도 감소감소하다가 0일 경우에만 리턴함
// 은근히 오래걸렸음 어제 하루종일 못했다가 오늘 품
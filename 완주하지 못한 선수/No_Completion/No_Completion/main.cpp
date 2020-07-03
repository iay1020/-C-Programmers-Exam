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

// �� ���� 1�� �ִ°ž�
// �׷��� ���п� �ؽø� ����غ�
// �ؽø��� unordered_map���� �ٲ�
// insert�� ���� �ʰ� �״�� �������� �ڵ� ����� �Ǵ� ����? 
// �׷��� ó�� for������ �ٷ� ++�� �ع����� ������ �ڵ� ����̸� �� Ű�� ȣ�� �ϴ� ��� ++
// �����̸��� �Ѹ���̶�� ������ �ϰ� �־ ��� �����ߴ� ����
// Ű���� ȣ���Ҷ����� ���ڸ� �������Ѽ� �����̵� ������� ����
// �ᱹ�� ���߿� üũ�Ҷ��� ���Ұ����ϴٰ� 0�� ��쿡�� ������
// ������ �����ɷ��� ���� �Ϸ����� ���ߴٰ� ���� ǰ
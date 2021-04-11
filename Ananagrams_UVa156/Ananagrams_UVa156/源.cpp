#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

vector<string>words;
map<string, int> match;

string toStd(const string& s)
{//将字符串标准化
	string ans = s;
	for (int i = 0; i < ans.length(); i++)
	{
		ans[i] = tolower(ans[i]);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string str;
	for (int i = 0;; i++)
	{//标准化，并打表
		cin >> str;
		if (str== "#") break;
		words.push_back(str);
		string s = toStd(words.back());
		if (match.count(s))
			match[s] = 0;
		else match[s] = 1;//如果出现过就设为0，否则设为1
	}

	vector<string> ans;//存放答案

	int cnt = 0;
	for (int i = 0; i < words.size(); i++)
	{
		if (match[toStd(words[i])])
			ans.push_back(words[i]);//找到所有不能重排的单词
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
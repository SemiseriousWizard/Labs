#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string s = "";
	string word = "";
	int ind, i = 0;
	//gets(s);
//	cin>>s;
	getline(cin, s);
	while (ind < s.length()) {
		for(i = ind; s[i] != ' '; i++) {
			word += s[i];
		}
		while (s[ind] == ' ') ind++;
		cout<<word<<endl;
		word = "";
	}
	getchar();
	return 0;
}

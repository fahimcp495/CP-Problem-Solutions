#include<bits/stdc++.h>
using namespace std;

void clr_stack(stack <string>& s){
	while(!s.empty())
		s.pop();
}

int main(){
	int T, tc = 0;	cin >> T;
	while(T--){
		stack <string> fs, bs;
		string cur = "http://www.lightoj.com/";
		cout << "Case " << ++tc << ":" << endl;
		while(true){
			string type;	cin >> type;
			if(type[0] == 'B'){
				if(bs.empty())
					cout << "Ignored" << endl;
				else{
					fs.push(cur);
					string s = bs.top();
					bs.pop();
					cur = s;
					cout << cur << endl;
				}
			}

			else if(type[0] == 'F'){
				if(fs.empty())
					cout << "Ignored" << endl;
				else{
					bs.push(cur);
					string s = fs.top();
					fs.pop();
					cur = s;
					cout << cur << endl;
				}
			}

			else if(type[0] == 'V'){
				bs.push(cur);
				string url;	cin >> url;
				cur = url;
				cout << cur << endl;
				clr_stack(fs);
			}

			else	break;
		}
	}

	return 0;
}
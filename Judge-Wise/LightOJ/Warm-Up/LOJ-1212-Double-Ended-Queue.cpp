#include<bits/stdc++.h>
using namespace std;

void clr_stack(stack <string>& s){
	while(!s.empty())
		s.pop();
}

int main(){
	int T, tc = 0;	cin >> T;
	while(T--){
		deque <int> dq;
		cout << "Case " << ++tc << ":" << endl;
		int n, m;	cin >> n >> m;
		while(m--){
			char s[20];	cin >> s;
			if(s[1] == 'u'){
				int x;	cin >> x;
				if(dq.size() == n){
					cout << "The queue is full" << endl;
				}
				else{
					if(s[4] == 'L'){
						dq.push_front(x);
						cout << "Pushed in left: " <<  x << endl;
					}

					else{
						dq.push_back(x);
						cout << "Pushed in right: " <<  x << endl;
					}
				}
			}

			else{
				if(dq.empty())
					cout << "The queue is empty" << endl;
				else{
					if(s[3] == 'L'){
						int x = dq.front();
						dq.pop_front();
						cout << "Popped from left: " << x << endl;
					}

					if(s[3] == 'R'){
						int x = dq.back();
						dq.pop_back();
						cout << "Popped from right: " << x << endl;
					}
				}
			}
		}
	}
	return 0;
}
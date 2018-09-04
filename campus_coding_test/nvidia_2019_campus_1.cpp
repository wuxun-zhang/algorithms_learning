#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int main(void){
	int n;
	while(cin>>n){
		char pm_or_am;
		string pre_line;
		string line;
		int pre_h=0, pre_m=0, days=1;
		// ignore the remaining '\n' during the cin-stream
		// make sure that getline can work well
		cin.ignore();
		for(int i=0; i<n; i++){
			getline(cin, line);
			stringstream input(line);
			int h, m;
			char a;
			input >> a;
			input >> h; 
			input>>a;
			input >> m;
			input >> a;

			if (i != 0) {
				if (pm_or_am == a && pre_h == h && pre_m == m) {
					if (!strcmp(pre_line.c_str(), line.c_str()))
						days++;
				}
				else if (pre_h > h || (pre_h == h && pre_m > m)) {
					days++;
				}
				else if (pm_or_am == 'p' && pm_or_am == 'a')
					days++;
				else if (h == 12 && m == 0 && pm_or_am == 'a')
					days++;
			}

			pm_or_am = a;
			pre_m = m;
			pre_h = h;
			pre_line = line;
		}
		cout << days << endl;
	}
	return 0;
}
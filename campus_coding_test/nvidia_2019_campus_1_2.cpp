#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void){
	int n;
	while(cin>>n){
		char pm_or_am;
		string pre_line, line;
		string pre_h, pre_m;
		int days_count;
		// *** Important ***
		cin.ignore();
		for(int i=0;i<n;i++){
			getline(cin, line);
			string h(line.substr(1,2));
			string m(line.substr(4,2));
			char p_or_a = line[7];

			if(i==0)
				days_count=1;
			else{
				if((pre_h>h) || (pre_h==h && pre_m>m))
					days_count++;
				else if(pm_or_am==p_or_a && pre_h==h && pre_m==m){
					if(!strcmp(line.c_str(), pre_line.c_str()))
						days_count++;
				}
				else if(pm_or_am=='p' && p_or_a=='a')
					days_count++;
				else if(h=="12" && p_or_a=='a')
					days_count++;
			}

			pre_line = line;
			pre_h = h;
			pre_m = m;
			pm_or_am = p_or_a;
		}

		cout<<days_count<<endl;
	}
	return 0;
}
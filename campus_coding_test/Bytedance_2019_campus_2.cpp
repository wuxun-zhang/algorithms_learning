#include<iostream>
#include<string>
#include<vector>
using namespace std;

void combinations_gen(vector<int>& a, int n, int m, vector<int>& )
{
     int i,j;
     if(cs==m)
     {
         for(i=1;i<=m;i++)
         {
             cout<<a[i];
         }
         cout<<endl;
         cs--;
     }
     else
     {
         for(i=1;i<=n;i++)
         {
             for(j=1;j<=cs;j++)
             {
                 if(a[j]==i)break;
             }
             if(j>cs)
             {
                 cs++;
                 a[cs]=i;
                 f(i);
             }
         }
         cs--;
     }
}

int main(void)
{
	string ip_str;
	while(cin>>ip_str){
		int outnum;
		int len = ip_str.size();
		if(len == 4 || len == 12){
			outnum = 1;
			cout<<outnum<<endl;
			continue;
		}
		if(len>=5 && len<=11){
			outnum=0;
			vector<vector<int>> all_options;

		}
	}
	return 0;
}
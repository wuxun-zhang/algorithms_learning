#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty())
        	return {};
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int rows = m, cols = n;
		int start = 0;
        while(rows>0 && cols>0){
            // end index of search starting point
			int row_end = start + rows - 1;
			int col_end = start + cols - 1;

			for (int i = start; i <= col_end; i++) {
        		res.push_back(matrix[start][i]);
        	}
			if (start<row_end) {
				for (int i=start+1; i <= row_end; i++) {
					res.push_back(matrix[i][col_end]);
				}
			}

			if(start<row_end && start<col_end){
				for (int i=col_end-1; i >= start; i--) {
					res.push_back(matrix[row_end][i]);
				}
        	}

			if (start < col_end && start < row_end - 1) {
				for (int i = row_end-1; i >= start+1; i--) {
					res.push_back(matrix[i][start]);
				}
			}
        	// resize
			start++;
        	rows-=2;
        	cols-=2;
        }
        return res;
    }
};

//int main(){
//	int m = 5, n = 3;
//    vector<vector<int> > mat(m, vector<int>(n));
//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            mat[i][j] = i+2*j;
//            cout<<mat[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//
//	Solution sol;
//    vector<int> res = sol.printMatrix(mat);
//    for(auto item:res){
//        cout<<item<<" ";
//    }
//    cout<<endl;
//
//    return 0;
//}
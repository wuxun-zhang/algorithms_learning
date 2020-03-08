
/*
Descropttion: 任意两个皇后不能处于同一行、同一列或同一条斜线上，求在n×n的棋盘上一共有多少种摆法？
*/

#define N (8)

class Solution{
public:
    Solution(){}

    bool check_pos_valid(int loop, int value){
        int index, data;
        for(index=0; index<loop; index++){
            data = eightQueen[index];
            if(value == data)
                return false;
            if((index+data) == (loop+value))
                return false;
            if((index-data) == (loop-value))
                return false;        
        }
        return true;
    }

    void eightQueen_solu(int index){
        int loop;
        for(loop=0; loop<N; loop++){
            if(check_pos_valid(index, loop)){
                eightQueen[index] = loop;
                if(7 == index){
                    count++;
                }
                eightQueen[index] = 0;
                return;
            }
            eightQueen_solu(index+1);
            eightQueen[index] = 0;
        }
    }
    // 设置初值
    void setInitCount(int val){
        count = val;
    }
private:
    static int eightQueen[8];
    static int count;
};

int Solution::count = 0;
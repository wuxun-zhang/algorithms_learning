#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<random>

int main(){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> data_rng(0,255);
    std::vector<int> num(32768, 0);
    for(auto& item : num){
        item = data_rng(engine);
    }

    // the probability of cache hiting is being improved 
    std::sort(num.begin(),num.end());

    long long sum = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<100000;i++){
        for(auto& item: num){
            if(item > 128){
                sum += item;
            }
        }
    }
    double time = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()-start).count();
    fprintf(stderr, "sum = %lld, elapsed time is %f s\n", sum, time/1000.0);

    return 0;
}
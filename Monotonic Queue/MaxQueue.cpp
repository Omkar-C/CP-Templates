#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MaxQueue{
    deque<T> q;
    public:
    T getMax(){
        return q.front();
    }

    void enque(T x){
        while(!q.empty() && q.back() < x)
            q.pop_back();
        q.push_back(x);
    }

    void deq(T x){
        if(!q.empty() && q.front() == x)
            q.pop_front();
    }
};

int main(){
    return 0;
}
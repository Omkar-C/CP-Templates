#include <bits/stdc++.h>
using namespace std;

template <typename T>
class union_find{
    private:
        int capacity;
        vector<int> size;
        vector<int> parent;
    public:
    union_find(T capacity)
    {
        this->capacity = capacity;
        parent = vector<int> (capacity);
        size = vector<int> (capacity);
        for(int i = 0; i < capacity; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int x)
    {
        if(x == parent[x])
            return x;
        return parent[x] = find_set(parent[x]);
    }

    void union_set(int x, int y)
    {
        x = find_set(x);
        y = find_set(y);
        if(x != y)
        {
            if(size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

int main(){
    return 0;
}
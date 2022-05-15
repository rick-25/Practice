#include <iostream>
#include <vector>

using namespace std;

#define lsb(n) (n & (-n))

class Fenwick {
    vector<int>  tree;
public:

    Fenwick(vector<int>& arr) {
        make(arr);
    }

    void make(vector<int>& arr) {

        tree.assign(arr.size() + 1, 0);
        
        for(int i=0; i<arr.size(); i++) {
            add(i, arr[i]);
        }
    }

    int sum(int index) {
        index++;
        int acc = 0;
        while (index) {
            acc += tree[index];
            index -= lsb(index);
        }
        return acc;
    }

    void add(int index, int val) {
        index++;
        while(index < tree.size()) {
            tree.at(index) += val;
            index += lsb(index);
        }
    }
    
    void update(int index, int new_val) {
        int diff = new_val - tree[index];
        add(index, diff);
    }

    void print() {
        for(auto i : tree) cout << i << " ";
        cout << endl; 
    }
};



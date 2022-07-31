#include <bits/stdc++.h>

using namespace std;


class SegmentTree {
private:
    vector<int>* tree;
    int DATA_SIZE;

    int makeTree(vector<int>& arr, int l, int r, int treeIndex) {
        if(l == r) {
            tree->at(treeIndex) = arr[l]; 
        } else {
            int mid = l + (r-l) / 2;
            tree->at(treeIndex) = makeTree(arr, l, mid, (2*treeIndex) + 1) + makeTree(arr, mid+1, r, (2*treeIndex) + 2);
        }
        return tree->at(treeIndex);
    }

    int getSum(int treeIndex, int tl, int tr, int l, int r) {
        if(l <= tl && r >= tr) return tree->at(treeIndex);
        if(l > tr || r < tl) return 0;

        int mid = tl + (tr-tl) / 2;

        return getSum(2 * treeIndex + 1, tl, mid, l, r) + getSum(2 * treeIndex + 2, mid+1, tr, l, r);
    }

    int update(int treeIndex, int tl, int tr, int dataIndex, int value) {
        if(dataIndex < tl || dataIndex > tr) return 0;

        int diff;

        if(tl == dataIndex && tr == dataIndex) {
            diff = value - tree->at(treeIndex);
            tree->at(treeIndex) = value;
            return diff;
        }

        int mid = tl + (tr-tl) / 2;

        if(dataIndex <= mid) diff = update(2 * treeIndex + 1, tl, mid, dataIndex, value);
        else diff = update(2 * treeIndex + 2, mid+1, tr, dataIndex, value);

        tree->at(treeIndex) += diff; 
        return diff;
    }

public:

    SegmentTree (vector<int>& arr) {
        const int arrSize = arr.size();
        const int treeHeight = ceil(log2(arrSize)) + 1;
        const int treeSize = pow(2, treeHeight) - 1;
        
        DATA_SIZE = arrSize;
        tree = new vector<int>(treeSize);

        makeTree(arr, 0, arrSize-1, 0);
    }

    int getSum(int l, int r) {
        return getSum(0, 0, DATA_SIZE-1, l, r);
    }


    void update(int dataIndex, int value) {
        if(dataIndex < 0 || dataIndex >= DATA_SIZE) return;
        update(0, 0, DATA_SIZE-1, dataIndex, value);
    }
};
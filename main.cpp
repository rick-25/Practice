#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <bitset>
using namespace std;

#define ln '\n'
#define sp ' '
#define ll long long
#define MOD 1000000007


class DisjointSet {
    int* parent;
    int* size;
    public:
    DisjointSet(int len) {
        parent = new int[len];
        size = new int[len];
    }
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve() {
    //if we can track path from unsorted-el position to sorted-el postion 
    //for every el then we can say that input can be sorted 
    //as per given condition
    ll n; cin >> n;
    vector<ll> v(n);
    vector<ll> sorted(n);

    DisjointSet ds(33);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        sorted[i] = v[i];
        int last = -1;
        for(int j=0; j<32; j++) {
            if(v[i] & (1 << j)) {
                if(last != -1) 
                    ds.union_sets(j, last);
                else 
                    ds.make_set(j);
                last = j;
            }
        }
    }
    sort(sorted.begin(), sorted.end());


    bool swapable = false;

    for(int i=0; i<n; i++) {

        const int a = v[i];
        const int b = sorted[i];
        //If we can't swap a and b then we can't sort the array
        
        swapable = false;

        for(int i=0; i<32 && !swapable; i++) { //for a 
            if(!(a & (1 << i)))
                continue;
            for(int j=0; j<32; j++) { //for b
                if(!(b & (1 << j)))
                    continue;
                if(ds.find_set(i) == ds.find_set(j)) {
                    swapable = true;
                    break;
                }
            }
        }

        if(!swapable)
            break;
    }


    if(swapable)
        cout << "YES\n";
    else
        cout << "NO\n";
}



int main() {
#ifndef ONLINE_JUDGE
    cout << ln;
    freopen("inputf.in","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    ll t = 1;

    cin >> t;
    while (t--)
        solve();

    return 0;
}


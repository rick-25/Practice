#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ln '\n';
typedef long long ll;

 
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return furthestBuilding(heights, bricks, ladders, 0);
    }
private:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders, int i) {
        if(i+1 == heights.size()) return i;

        int diff = heights[i+1] - heights[i];

        if(diff > 0)
        {
            int ans = -1;
            if(bricks >= diff)
                ans = max(ans, furthestBuilding(heights, bricks-diff, ladders, i+1));
            if(ladders > 0)
                ans = max(ans, furthestBuilding(heights, bricks, ladders-1, i+1));

            return max(ans, i);
        }
        return furthestBuilding(heights, bricks, ladders, i+1);
    }
};


int main() {    
   	//TODO : test here
    string temp = 1 + "ahelo" + 53;
    cout << temp << ln;
    return 0;
}


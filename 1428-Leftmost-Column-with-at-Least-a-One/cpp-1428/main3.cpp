#include <iostream>
#include <vector>

using namespace std;


/// This is the BinaryMatrix's API interface.
/// You should not implement it, or speculate about its implementation
class BinaryMatrix {
public:
    int get(int row, int col);
    vector<int> dimensions();
};


/// Search from Top Right to Bottom Left + Binary Search
/// Time Complexity: O(R + C)
/// Space Complexity: O(1)
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {

        vector<int> dim = binaryMatrix.dimensions();
        int R = dim[0], C = dim[1];

        int res = C, j = C - 1;
        for(int i = 0; i < R; i ++){

            int l = 0, r = j + 1;
            while(l < r){
                int mid = (l + r) / 2;
                if(binaryMatrix.get(i, mid)) r = mid;
                else l = mid + 1;
            }

            res = min(res, l);
            j = l - 1;
        }
        return res == C ? -1 : res;
    }
};


int main() {

    return 0;
}

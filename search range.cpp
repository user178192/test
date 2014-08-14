#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void binSearch(int A[], int target, bool flag) {
		while (start + 1 < end) {
		    mid = start + (end - start) / 2;
		    if (A[mid] == target && flag == 0) {
		           end = mid;   // lower bound
		    } else if (A[mid] == target && flag == 1) {
		           start = mid; // upper bound
		    } else if (A[mid] < target) {
		            start = mid;
		    } else {
		                end = mid;
		    }
		}
	}
	
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> res(2, -1);
        if (A == nullptr) {
            return res;
        }
        
        // find the lower bound
        start = 0; end = n - 1;
        binSearch(A, target, 0);
        if (A[start] == target) {
            res[0] = start;
        } else if (A[end] == target) {
            res[0] = end;
        } else {
            return res;
        }

        // find the upper bound
        start = 0; end = n - 1;
		binSearch(A, target, 1);
        if (A[end] == target) {
            res[1] = end;
        } else if (A[start] == target) {
            res[1] = start;
        } else {
            return res;
        }

        return res;
    }
private:
	int start, end, mid;
};
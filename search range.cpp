#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void binSearch(int A[], int target, bool flag) {
		while (start + 1 < end) {
		    mid = start + (end - start) / 2;
		    if (A[mid] == target && flag == 0) {
		           end = mid;
		    } else if (A[mid] == target && flag == 1) {
		           start = mid;
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
        
        start = 0; end = n - 1;
        // find the lower bound

        binSearch(A, target, 0);
        if (A[start] == target) {
            res[0] = start;
        } else if (A[end] == target) {
            res[0] = end;
        } else {
            return res;
        }

        start = 0; end = n - 1;
        cout << start << "|" << end << endl;		
        // find the upper bound
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

int main(int argc, char *argv[]) {
	Solution test;
	int A[3] = {2, 2, 2};
	auto res = test.searchRange(A, 3, 2); 
	//cout << res[0]<< "|" << res[1] << endl; 
}
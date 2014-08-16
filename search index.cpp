#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target) {
        int start = 0, end = n - 1;
        while (start + 1 < end) {
            const int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            }
            
            if (A[mid] < target) {
                start = mid;
            }
            
            if (A[mid] > target) {
                end = mid;
            }
        }

		if (A[end] < target) {
			return end + 1;
		}
				
        else if (A[start] < target && target <= A[end]) {
            return end;
        }
		
		return start;
    }

int main(int argc, char *argv[]) {
	int A[] = {1, 3};
	cout << searchInsert(A, 2, 4) << endl;
}
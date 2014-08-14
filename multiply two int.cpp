#include <iostream>

using namespace std;

int mutil_helper(int x, int y) {
	long long mutil1 = x;
	long long mutil2 = y;
	long long res = 0;
	
	for (int i = 0 ; mutil2 > 0 ; mutil2 = mutil2 >> 1 , i++) {
		unsigned int temp = 1;
		if (y & 1) {
			temp = temp << i;
			for ( int j = 0 ; j < temp ; j++) {
				res += mutil1;
			}
		}
	}

	return res;
}

int mutil(int x, int y ) {
	return (x > y) ? mutil_helper(x, y) : mutil_helper(y, x);
}



int main(int argc, char *argv[]) {
	cout << mutil(3, 14000000);
}
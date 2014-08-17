//
//  main.cpp
//  4 sum
//
//  Created by star on 5/29/14.
//  Copyright (c) 2014 star. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    const int size = (int)num.size();
    vector<vector<int>>result;
    if (size < 4) {return result;}
    
    set<vector<int> >res_set;
    
    for (int iter1 = 0; iter1 < size - 3; iter1++) {
        for (int iter2 = iter1 + 1; iter2 < size - 2; iter2++) {
            int iter3 = iter2 + 1;
            int iter4 = size - 1;
            while (iter3 < iter4) {
                int sum = num[iter1] + num[iter2] + num[iter3] + num[iter4];
                if (sum == target) {
                    res_set.insert({num[iter1], num[iter2], num[iter3], num[iter4]});
                    iter3++; iter4--;
                    
                } else if (sum < target) {
                    iter3++;
                } else {
                    iter4--;
                }
            }
        }
    }
    
    copy(res_set.begin(), res_set.end(), result.begin());
    return result;
}

int main(int argc, char *argv[]) {
	vector<int> num = {0, 0, 0, 0};
	auto vec2 = fourSum(num, 0);
	
	for (auto i = 0; i < vec2.size() ; i++) {
		for (auto j = 0; j < vec2[i].size() ; j++) {
			cout << vec2[i][j];
		}
		cout << endl;
	}
}


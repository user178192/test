//
//  main.cpp
//  3 sum
//
//  Created by star on 5/28/14.
//  Copyright (c) 2014 star. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &num){
    vector<vector<int>> res;
    if (num.size() < 3) { return res; }
    sort(num.begin(), num.end());
    const int target = 0;
    
    for (auto iter1 = num.begin(); iter1 < prev(num.end(), 2) ; iter1++) {
        auto iter2 = iter1 + 1; auto iter3 = num.end() - 1;
        
        if (iter1 > num.begin() && *iter1 == *(iter1 - 1) ) {continue;}
        
        while (iter2 < iter3) {
            if (*iter1 + *iter2 + *iter3 < target) {
                ++iter2;
            }
            else if (*iter1 + *iter2 + *iter3 > target) {
                --iter3;
            }
            else {
                res.push_back({*iter1 , *iter2 , *iter3});
                
                while (iter2 < iter3 && *iter2 == *(iter2 - 1) ) {iter2++;}
                while (iter2 < iter3 && *iter3 == *(iter3 + 1) ) {iter3--;}
            }
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
	vector<int> num{7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,
        -14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,
        10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,
        14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	
	auto vec2 = threeSum(num);
	for (auto i = 0 ; i < vec2.size() ; i++) {
		for (auto j = 0 ; j < vec2[i].size() ; j++) {
			cout << vec2[i][j] << ",";
		}
		cout << endl;
	}
	
	return 0;
}


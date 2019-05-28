// twoSum.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "gtest/gtest.h"
#include <vector>
#include <unordered_map>

using namespace std;

class CSolution
{
public:
	// noraml solution
	static vector< int > twoSum1( vector< int >& nums, int target ) {
		for ( int i = 0; i < nums.size(); i++ ) {
			for (int j = i + 1; j < nums.size(); j++) {
				int sum = nums[ i ] + nums[ j ];
				if (sum == target) {
					return{ i, j };
				}
			}
		}
		return{};
	}

	static vector< int > twoSum2(vector< int >& nums, int target) {
		int i;
		unordered_map<int, int> hashMapIndex;
		for (i = 0; i < nums.size(); i++) {
			hashMapIndex[nums[i]] = i;
		}

		for (i = 0; i < nums.size(); i++) {
			int key = target - nums[i];
			if (hashMapIndex.count(key) == true && hashMapIndex[key] != i) {
				return{ i,hashMapIndex[key] };
			}
		}
		
		return{};
	}
};

TEST( TestTwoSum, Test001 )
{
	vector<int> vec = { 10, 7, 11, 15, 1, 8 };
	int target = 9;
	bool res = false;

	vector<int> ans = { 4, 5 };
	for (int i = 0; i < 1000; i++) {
		res = ans == CSolution::twoSum1(vec, target);
	}
	EXPECT_TRUE(res);
}

TEST(TestTwoSum, Test002)
{
	vector<int> vec = { 10, 7, 11, 15, 1, 8 };
	int target = 9;
	bool res = false;

	vector<int> ans = { 4, 5 };
	for (int i = 0; i < 1000; i++) {
		res = ans == CSolution::twoSum2(vec, target);
	}
	EXPECT_TRUE(res);
}

int main( int argc, _TCHAR* argv[] )
{
	testing::InitGoogleTest( &argc, argv );
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}


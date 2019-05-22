// twoSum.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

class CSolution
{
public:
	static vector< int > twoSum( vector< int >& nums, int target ) {
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
};

TEST( TestTwoSum, Test001 )
{
	vector<int> vec = { 2, 7, 11, 15 };
	int target = 9;

	vector<int> ans = { 0, 1 };
	bool res = ans == CSolution::twoSum(vec, target);
	EXPECT_TRUE(res);
}

int main( int argc, _TCHAR* argv[] )
{
	testing::InitGoogleTest( &argc, argv );
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}


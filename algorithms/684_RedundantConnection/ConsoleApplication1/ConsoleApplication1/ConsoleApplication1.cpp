// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class unionFind {
public:
	vector<int> m_nID;
	// id number for each node

	vector<int> m_nSz;
	// size of the top node

public:
	// constuctor
	unionFind(int nSize) {
		m_nID = vector<int>(nSize + 1, 0);
		m_nSz = vector<int>(nSize + 1, 1);

		for (int i = 0; i < m_nID.size(); ++i) {
			m_nID[i] = i;
		}
	}

	// destructor
	~unionFind() {
		// nothing
	}

	// get root of node p with path compress
	int root(int i) {
		while(i != m_nID[i]) {
			m_nID[i] = m_nID[m_nID[i]];
			i = m_nID[i];
		}
		return i;
	}

	// check if node p is connected q
	bool isConnected(int p, int q) {
		return root(p) == root(q);
	}

	// union
	bool weightedUnion(int p, int q) {
		cout << "before" << endl;
		showUnionFindData();
		int i = root(p);
		int j = root(q);

		if (i == j) {
			showUnionFindData();
			return false;
		}
		else if (m_nSz[i] < m_nSz[j]) {
			m_nID[i] = j;
			m_nSz[j] += m_nSz[i];
		}
		else {
			m_nID[j] = i;
			m_nSz[i] += m_nSz[j];
		}
		showUnionFindData();
		cout << endl;
		return true;
	}

	void showUnionFindData(void) {
		cout << "ID:";
		for (int i = 0; i < m_nID.size(); i++) {
			cout << m_nID.at(i) << " ";
		}
		cout << endl;
		cout << "Sz:";
		for (int i = 0; i < m_nID.size(); i++) {
			cout << m_nSz.at(i) <<" ";
		}
		cout << endl;
	}
};

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		unionFind uf( edges.size() );

		for (int i = 0; i < edges.size(); i++) {
			if (!uf.weightedUnion(edges[i][0], edges[i][1])) {
				return edges[i];
			}
		}

		return{};
	}
};

// 684. Redundant Connection
// Runtime: 4 ms
// Memory Usage : 9.8 MB
int main()
{
	vector<vector<int> > edges( 3, vector<int>(2,0) );

	edges[0][0] = 1; edges[0][1] = 2;
	edges[1][0] = 1; edges[1][1] = 3;
	edges[2][0] = 2; edges[2][1] = 3;

	Solution sol;

	vector<int> ans = sol.findRedundantConnection(edges);

	system("pasue");

    return 0;
}


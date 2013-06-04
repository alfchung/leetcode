
#include <iostream>
#include <algorithm>
#include <vector>
//#include <unordered_map>

using namespace std;



typedef struct Node{
	int idx;
	int val;
	Node() {}
	Node(int i, int v): idx(i), val(v) {}
} Node;

bool comp(Node n1, Node n2) {
	return (n1.val < n2.val);
}

class Solution {

	public:


	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		//build table
		vector<int> ret;
		vector<Node> table;
		int i = 1;
		for(vector<int>::iterator itr = numbers.begin(); itr != numbers.end(); ++itr) {
			Node n(i++,*itr);	
			table.push_back(n);
		}


		// step 1, sort
		sort(table.begin(), table.end(), comp);



		// step 2, two pointers
		int v1 = 0, v2 = numbers.size()-1;


		Node first;  
		Node second;

		while (true) {
			first  = *(table.begin()+v1); 
			second = table[v2];
			int sum    =  first.val + second.val;
			//cout<< first.val<<" + "<<second.val<<" = "<<sum<<endl;;
			if ( sum == target ) {
				int i1 = min(first.idx, second.idx);  
				int i2 = max(first.idx, second.idx);  
				ret.push_back(i1);
				ret.push_back(i2);
				return ret; 
			} else if ( sum > target ) {
				--v2;
			} else {
				++v1;
			}
		}

	}
};


void print_vet(vector<int> v) {
	for (vector<int>::iterator itr=v.begin(); itr != v.end(); itr++)  {
		cout<<*itr<<" ";
	}
	cout<<endl;
}


int main() {

	vector<int> v;
	int a[] = {10, 34, 23, 24, 27, 6, 3};
	vector<int> ret;

	int size = sizeof(a)/sizeof(int);

	for (int i=0; i<size; ++i) {
		v.push_back(a[i]);
	}
	print_vet(v);

	Solution s;
	ret = s.twoSum(v, 30);


	return 0;
}


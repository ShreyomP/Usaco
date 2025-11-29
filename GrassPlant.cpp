#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream in("planting.in");
	ofstream out("planting.out");
	int n;
	in >> n;
	vector<int> outconnections(n+1,0);
	for (int x = 0; x < n-1; x++) {
		int a, b;
		in >> a >> b;
		outconnections[a]++;
		outconnections[b]++;
	}
	int big = -1;
	for (int x = 0; x <=n; x++) {
		//out<< outconnections[x] << endl;
		big = max(big, outconnections[x]);
	}
	out << big+1;
}
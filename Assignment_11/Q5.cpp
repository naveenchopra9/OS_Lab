#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n , l , p ,b;
	cout<<"CPU generates Virtual Address Bits:  ";
	cin>>m;
	cout<<"Page Size in KB: ";
	cin>>p;
	cout<<"No of Page tables TLB can hold: ";
	cin>>l;
	cout<<"N-way set associative value: ";
	cin>>n;

	int a = log2(p)+10;
	b = m -a;

	int c = log2(l/n);

	cout<<"Minimum size of TLB Tag = "<<b-c<<endl;
	return 0;
}

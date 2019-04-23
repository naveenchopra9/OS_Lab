#include <bits/stdc++.h>
using namespace std;

int main()
{
	long int pas ,las , page ,p, q,r;
    cout<<"Enter Physical Address Space (in GB)= ";
    cin>>pas;
    cout<<"Enter Logical Address Space (in GB)= ";
    cin>>las;
    cout<<"Enter  Page Size (in KB)= ";
    cin>>page;
    cout<<endl;
    p = log2(pas)+30;
    q = log2(las)+30;
    r = log2(page)+10;

    //cout<<p<<" "<<q<<" "<<r<<endl; 
    int aa = pow(2,q-r) ,bb = pow(2,p-r);
    
    cout<<"No of Pages in the system = "<<2<<"^"<<q-r<<"="<<aa<<endl;
    cout<<"No of Frames in the system = "<<2<<"^"<<p-r<<"="<<bb<<endl;

    cout<<"Number of bits required to represent the Physical address = "<<p<<endl;
    cout<<"Number of bits required to represent the Virtual address = "<<q<<endl;
    cout<<"Number of bits required to represent page offset = "<<r<<endl;

    long int ans  = pow(2,q-r-3-10)*(p-r);
    cout<<"Page table size = "<<"2^"<<q-r<<"*"<<p-r<<"="<<ans<<" KBytes"<<endl;

	return 0;
}

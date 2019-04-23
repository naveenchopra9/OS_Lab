#include <bits/stdc++.h>
using namespace std;

int main()
{
	float tlb,mem,hit;
	cout<<"TLB Search time:in (ms) ";
	cin>>tlb;
	cout<<"Memory Access time:in (ms) ";
	cin>>mem;
	cout<<"TLB Hit Ratio: ";
	cin>>hit;
    
    float ans = hit*(tlb+mem) + (1-hit)*(tlb+2*mem);
    cout<<"Total  effective memory access time: in (ms) ";
    cout<<ans<<endl;

  return 0;
}
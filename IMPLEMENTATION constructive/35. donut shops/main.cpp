#include<iostream>
#include<map>
using namespace std;
#define ll long long
#define pb push_back
 
void sol(){
	 ll a,b,c;
	 scanf("%lld %lld %lld",&a,&b,&c);
	 a>=c?cout<<"-1 ":cout<<"1 ";
	 
	 a*b<=c?cout<<"-1":cout<<b;
	 cout<<"\n";
}
 
 
int main() 
{ 
 
   int t; scanf("%d",&t);
    while(t--)
	sol();
	
return 0;
}
    
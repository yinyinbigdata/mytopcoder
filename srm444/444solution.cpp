#include <algorithm> 
#include <cmath> 
#include <iostream> 
#include <limits> 
#include <list> 
#include <map> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 
using namespace std; 

#define debug(c) cout << "> " << #c << " = " << c << endl; 
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end() 
#define mp make_pair 
#define pb push_back 
#define tr(c,i) for(typeof((c).begin() i=(c).begin(); i!=(c).end();i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(all(c),x)!=(c).end())
typedef vector<int> vi; 
typedef pair<int,int> ii;
typedef long long ll; 

bool b[2][51];
class FourBlocksEasy{
public:
	int maxScore(vector<string> grid)
	{
		int n=sz(grid[0]);
		memset(b,false,sizeof(b));
		
		int b4=0;
		int b1=0;
		for(int i=0;i<2;i++)
		  for(int j=0;j<n;j++)
			if(grid[i][j]=='1')
			{
			  b[i][j]=true;
			  b1++;
			}
	

		for(int k=0;k<n-1;k++)
		  if(b[0][k]==false && b[0][k+1]==false && b[1][k]==false && b[1][k+1]==false)
		  {
		  	 
			  b4++;
			  b[0][k]=b[0][k+1]=b[1][k]=b[1][k+1]=true;
		  }

		for(int i=0;i<2;i++)
		  for(int j=0;j<n;j++)
			if(b[i][j]==false)
			{
			  b1++;

			}
		int res=0;
		debug(b1)
		res=16*b4+b1;
		return res;
	}
};

class NumericalPerfectionLevel{
public:
	int getLevel(long long N)
	{
		int res=0;
		for(ll i=2;i*i<=N;i++)
		  while(N%i==0) N/=i,res++;
		if(N!=1) res++;
		int r=0;
		while(res>4) r++,res/=4;
		return r;
	}
}

class NumericalPerfectionLevel{
public:
	int isprime(ll n)
	{
		if(n<2) return 0;
		if(n==2) return 1;
		for(ll i=2;i*i<=n;i++)
		  if(n%i==0) return 0;
		return 1;
	}
		

	int getLevel(long long N)
	{
		int cnt=0;
		if(isprime(N)) return 0;
		for(ll i=2;i*i<=N;i++)
		{
			while(N%i==0){
				N/=i;
				cnt++;
			}
		}
		if(N!=1) cnt++;
		int ans=0;
		while(cnt/4>0)
		{
			cnt/=4;
			ans++;
		}
		return ans;
	}
	
	
};


map<ll,int> mem;
class NumericalPerfectionLevel{
public:
	int level(ll n)
	{
		if(n<16) return 0;
		if(present(mem,n)) return mem[n];
		mem[n]=0;
	
		int i,j,k,l;
		for(i=2;i<n;i++)
		  for(j=i;j<n/i+1;j++)
			for(k=j;k<n/i*j+1;k++)
			  for(l=k;l<n/i*j*k+1;l++)
				if(i*j*k*l==n)
				{
					int _i,_j,_k,_l;
					_i=level(i);
					_j=level(j);
					_k=level(k);
					_l=level(l);
					if(_i==_j==_k==_l)
					{
						mem[n]=_i+1;
						return mem[n];
					}
					int res=max(max(_i,_j),max(_k,_l));
					mem[n]=max(res,mem[n]);
					return mem[n];

				}
		return 0;
				  
	}

	int getLevel(long long N)
	{
		return level(N);
	}
};
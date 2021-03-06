#include <algorithm> 
#include <cmath> 
#include <iostream> 
#include <limits> 
#include <list> 
#include <map> 
#include <string>
#include <vector>

using namespace std;

class RabbitVoting{
public:
	string getWinner(vector<string> names,vector<string> votes)
	{
		int count[50];
		memset(count,0,sizeof(count));
		string ret="";
		for(int i=0;i<votes.size();i++)
		{
			if(names[i]==votes[i])
			  continue;
			for(int j=0;j<names.size();j++)
			{
				if(names[j]==votes[i])
				{
					count[j]++;
				}
			}
		}
		int max=-1;
		int index=-1;
		for(int i=0;i<votes.size();i++)
		{
			if(count[i]>max)
			{
				max=count[i];
				index=i;
			}
			else if(count[i]==max)
			{
				ret="";
				return ret;
			}
		}
		return names[index];
	}
};


struct node{
	int start;
	int end;
	int flag;
	int cost;
};
class RabbitJumping{
public:
	int getMinimum(vector<int> holes,int largeJump)
	{
		int n=holes.size()/2;
		vector<node> que;
		struct node curnode;
		if(largeJump%2=1)
		{
			curnode.flag=1;
			curnode.cost=1;
			curnode.start=0;
			curnode.end=holes[0];
			que.pb(curnode);
		}
		else 
		{
			curnode.flag=0;
			curnode.start=0;
			if(holes[0]%2==0)
			  curnode.end=holes[0];
			else
			  curnode.end=holes[0]-1;
			curnode.cost=0;
			que.pb(curnode);
		}
		struct node lastnode=curnode;
		for(int i=0;i<n;i++)
		{
			int nstart=holes[2*i+1];
			int nend=holes[2*i+2];
			int nsize=nend-nstart;
			int hstart=holes[2*i];
			int hend=holes[2*i+1];
			int hsize=hend-hstart;
			if(hsize==largeJump)
			{
				node.start=nstart;
				node.end=nend;
				if(nsize>largeJump && largeJump%2=1)
				{
					node.flag=1;
					node.cost=1;
				}
				else
				{
					node.flag=0;
					node.cost=0;
				}
				que.pb(node);
			}
			else if(lastnode.flag && largeJump>hsize+1)
			{
				node.start=nstart;
				node.end=nend;
				node.flag=1;
				node.cost=0;
				que.pb(node);
			}
			


			if(lastnode.flag && nsize)
			{
				node.start=nstart;
				node.end=nend;
				node.flag=1;
				node.cost=0;
				que.pb(node);
			}
			else if(!lastnode.flag && 
						
	
		int cur=0;
		for(int i=0;i<n;i++)
		{
			int start=holes[2*i];
			int end=holes[2*i+1];
			int dis=end-start;
			


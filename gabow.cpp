#include "gabow.h"
#include <algorithm>


using namespace std;
int Order[max_number];
int OrderNum=0;
int Part[max_number];
int PartNum=0;
int sccID[max_number],sccNum;
Graph* creat_graph(int V)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->arry = new adjancy_list[V];
	graph->visited = new bool[V];
	graph->times = new int[V];
	for(int i = 0; i < V; ++i)
	{
		graph->visited[i] = false;
		graph->times[i] = 0;
	}
	return graph;
}

void add_edge(Graph* graph, int src, int dest)
{
	graph->arry[src].adj_list.push_back(dest);
}


void print_graph(Graph* graph)
{
	for(int i = 0; i < graph->V; ++i)
	{
		cout << "graph using adjacenncy list:" << endl<<i;	
		for(auto j = graph->arry[i].adj_list.cbegin(); j != graph->arry[i].adj_list.cend(); ++j)
		{
			cout<<"-->"<<*j;
		}
		cout << endl;
	}
}

void dfs(Graph* graph, int v)
{
	Order[v]=++OrderNum;
	S.push(v);	
	Root.push(v);
	for(auto i = graph->arry[v].adj_list.begin(); i != graph->arry[v].adj_list.end(); ++i)
	{
		if(Order[*i]==-1)
		{
			dfs(graph,*i);
		}	
		else if(Part[*i] == -1)
		{
			while(Order[Root.top()] > Order[*i])
			{
				Root.pop();
			}
			cout << endl;
		}
	}
	if(v == Root.top())
	{
		Root.pop();
		PartNum++;
		int Top;
		do
		{
			Top=S.top();
			Part[Top]=PartNum;
			S.pop();
		}
		while(Top != v);
	}
}


int main(void)
{
	int N;
	cout<<"please input a number:(2<N<100):"<<endl;
	cin>>N;
	Graph* graph = creat_graph(N);

	cout<<"please input the edge like this:2 3(0 0 meaning end):"<<endl;
	int a,b;
	while(cin>>a>>b && (a|b))
	{
		add_edge(graph,a,b);
	}
//	print_graph(graph);
	sccNum = 0;
	for(int i = 0; i < N; ++i)
	{
		Part[i]=-1;
		Order[i]=-1;
	}
	for(int i = 0; i < N; ++i)
	{
		if(Order[i]==-1)
		{
			dfs(graph,i);
		}
	}
	for(int i = 0; i < N; ++i)
	{
		cout << Part[i]<<" ";
	}
	cout << endl;
	return 0;
}

#include "tarjan.h"
#include <algorithm>


using namespace std;
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
	low[v] = dfn[v] = ++t;
	S.push(v);
	graph->visited[v] = true;	
	for(auto  i = graph->arry[v].adj_list.begin(); i != graph->arry[v].adj_list.end(); ++i)
	{
		if(!dfn[*i])
		{
			dfs(graph,*i);
			if(low[v] > low[*i])
			{
				low[v] = low[*i];
			}
		}
		else if(graph->visited[*i] && dfn[*i] < low[v])
		{
			low[v] = dfn[*i];
		}
	}
	if(low[v] != dfn[v])
	{
		return;
	}
	int top1;
	do
	{
		top1 = S.top();
		graph->visited[top1] = false;
		sccID[top1] = sccNum;
		S.pop();
	}while(top1 != v);
	sccNum++;
}


int main(void)
{
	int N;
	cout<<"please input a number:(2<N<100):"<<endl;
	cin>>N;
	Graph* graph = creat_graph(N);

	cout<<"please input the edge like this:2 3(0 0 meaning end):"<<endl;
	int a,b;
	for(int i = 0; i < max_number; ++i)
	{
		dfn[i] = 0;
	}
	while(cin>>a>>b && (a|b))
	{
		add_edge(graph,a,b);
	}
	print_graph(graph);
	sccNum = 0;
	for(int i = 0; i < N; ++i)
	{
		if(!dfn[i])
		{
			dfs(graph,i);
		}
	}
	
	for(int i = 0; i < N; ++i)
	{
		cout << sccID[i] << " ";
	}	
	cout << endl;
	return 0;
}

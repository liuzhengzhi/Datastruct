#include <iostream>
#include "graph.h"
#include <algorithm>
using namespace std;

vertex_node* new_node(int dest)
{
	vertex_node* newnode = new vertex_node;
	newnode->dest = dest;
	newnode->next = NULL;
	return newnode;
}

Graph* creat_graph(int V)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->arry = new vertex_list[V];
	graph->visited = new bool[V];
	graph->times = new int[V];
	for(int i = 0; i < V; ++i)
	{
		graph->arry[i].head = NULL;
		graph->visited[i] = false;
		graph->times[i] = 0;
	}
	return graph;
}

void add_edge(Graph* graph, int src, int dest)
{
	vertex_node* newnode = new_node(dest);
	newnode->next = graph->arry[src].head;
	graph->arry[src].head = newnode;
}


void print_graph(Graph* graph)
{
	for(int i = 0; i < graph->V; ++i)
	{
		vertex_node* newnode = graph->arry[i].head;
		cout << "graph using adjacenncy list:" << endl << i;	
		while(newnode)
		{
			cout << "->" << newnode->dest ;
			newnode = newnode->next;
		}
		cout << endl;
		delete newnode;
	}
}

vertex_node* dfs(Graph* graph, int v)
{
	belong[v]=snt2;
	vertex_node* temp = new vertex_node;
	vertex_node* temp2 = temp;
	graph->visited[v] = true;	
	int start_time,end_time;
	start_time = times;
	vertex_node* newnode = graph->arry[v].head;
	while(newnode)
	{
		if(!graph->visited[newnode->dest])
		{
			temp->next = new_node(newnode->dest);
			temp = temp->next;
			temp->next = NULL;
			dfs(graph,newnode->dest);
		}
		newnode = newnode->next;
	}
	temp2->dest = v;
	end_time = times;
	graph->times[v] = end_time - start_time;
	return temp2;
}


void decend_time(int* oldtime,int* newtime,int v)
{
	int* time_temp = new int[v];	
	for(int i = 0; i < v; ++i)
	{
		time_temp[i] = oldtime[i];
	}
	int max, max_idx;
	for(int i = 0; i < v; ++i)
	{
		max_idx = 0;
		max = time_temp[max_idx];
		for(int j = 0; j < v; ++j)
		{
			if(time_temp[j] == -1)
			{
				continue;
			}
			if(time_temp[j] > max)
			{
				max = time_temp[j];
				max_idx = j;
			}
		}
		newtime[i] = max_idx;
		time_temp[max_idx] = -1;
	}
}
int main(void)
{
	int N;
	cout<<"please input a number:(2<N<100):"<<endl;
	cin>>N;
	vertex_node* temp[N];
	Graph* graph = creat_graph(N);
	Graph* t_graph = creat_graph(N);

	cout<<"please input the edge like this:2 3(0 0 meaning end):"<<endl;
	int a,b;
	int count=0;
	while(cin>>a>>b && (a|b))
	{
		add_edge(graph,a,b);
		add_edge(t_graph,a,b);
		e[count].l=a;
		e[count].r=b;
		count++;
	}
	print_graph(graph);
	print_graph(t_graph);
	for(int i = 0; i < N; ++i)
	{
		dfs(graph,i);
	}

	decend_time(graph->times,t_graph->times,N);

	for(int i = 0; i < N; ++i)
	{
		if(t_graph->visited[t_graph->times[i]] == false)
		{
		temp[i] = dfs(t_graph,t_graph->times[i]);
		while(temp[i]->next)
		{
			cout << temp[i]->dest << "-> ";
			temp[i] = temp[i]->next;
		}
		cout << temp[i]->dest <<endl;
		}
		snt2++;
	}
	int ind[100]={0,};
	int outd[100]={0,};	
	for(int i = 0; i < N; ++i)
	{
		outd[e[i].l]++;
		ind[e[i].r]++;
	}
	int rst1=0;
	int rst2=0;
	for(int i = 0; i < snt2; ++i)
	{
		if(!outd[i])
		{
			rst1++;
		}
		if(!ind[i])
		{
			rst2++;
		}
	}
	cout<< rst2 << endl;
	cout<< (rst1>rst2?rst1:rst2) << endl;
	return 0;
}

#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <list>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

const int max_number = 100;
int low[max_number];
int dfn[max_number]={0,};
int t=0;
stack<int> S;

struct adjancy_list
{
	list<int> adj_list;
};
//A structure to reresent an adjacency list

struct Edge
{
	int l,r;
};

//A structure to resprensent a graph."V" reprensent the number
//of vertex in this graph.
struct Graph
{
	int V;
	bool* visited;
	int* times;
	adjancy_list* arry;
};

Graph* creat_graph(int V);
void add_edge(Graph* graph, int src, int dest);
void print_graph(Graph* graph);
void dfs(Graph* graph, int v);
#endif /* __GRAPH_H__ */

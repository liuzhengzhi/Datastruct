#ifndef __GRAPH_H__
#define __GRAPH_H__

int times = 0;
int snt2=1;
int belong[100]={0};
//A structure to reprensent an adjacency list node
struct vertex_node
{
	int dest;
	struct vertex_node* next;
};

//A structure to reresent an adjacency list
struct vertex_list
{
	vertex_node* head;	//pointer to head node of list
};

struct Edge
{
	int l,r;
}e[100];

//A structure to resprensent a graph."V" reprensent the number
//of vertex in this graph.
struct Graph
{
	int V;
	bool* visited;
	int* times;
	vertex_list* arry;
};

vertex_node* new_node(int dest);
Graph* creat_graph(int V);
void add_edge(Graph* graph, int src, int dest);
void print_graph(Graph* graph);
vertex_node* dfs(Graph* graph, int v);
Graph* transpose(const Graph* graph);
void decend_time(int* oldtime,int* newtime,int v);
#endif /* __GRAPH_H__ */

#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode{
	int dest;
	ListNode* next;
}; 
struct AdjList{
	ListNode* head;
};
struct Graph{
	int V;
	AdjList* array;
};
Graph* createGraph(int v){
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = v;
	graph->array = (AdjList*)malloc(v*sizeof(AdjList));
	for(int i=0;i<v;i++){
		graph->array[i].head = NULL;
	}
	return graph;
}
ListNode* newAdjListNode(int dest){
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->dest = dest;
	newnode->next = NULL;

	return newnode;
}
void addEdge(Graph* graph, int src, int dest){
	ListNode* newnode = newAdjListNode(dest);
	newnode->next = graph->array[src].head;
	graph->array[src].head = newnode;

//Since graph is undirected, add an edge from dest to src also
	newnode = newAdjListNode(src);
	newnode->next = graph->array[dest].head;
	graph->array[dest].head = newnode;
}
void printGraph(Graph* graph){
	for(int i=0;i<graph->V;i++){
		cout<<"\nFor vertex "<<i<<" -> ";
		ListNode* node = graph->array[i].head;
		while(node!=NULL){
			cout<<node->dest<<" ";
			node = node->next;
		}
	}
}
int main(){
	Graph* graph = createGraph(5);
	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    printGraph(graph);
}
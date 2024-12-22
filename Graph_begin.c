#include <stdio.h>
#include <stdlib.h>
#define Max_Vertices 100
struct node{
    int data;
    struct node *next;
};
struct node *createNode(int value){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
void addEdge(struct node *adj[],int u,int v){
    struct node *new_node=createNode(v);
    new_node->next=adj[u];
    adj[u]=new_node;
}
void bfs(struct node *adj[],int vertices,int source,int visited[]){
    int queue[Max_Vertices];
    int front=0,rear=0;
    visited[source]=1;
    queue[rear++]=source;
    while(front!=rear){
        int curr=queue[front++];
        printf("%d ",curr);
        struct node *temp=adj[curr];
        while(temp!=NULL){
            int neighbor=temp->data;
            if(visited[neighbor]==0){
                visited[neighbor]=1;
                queue[rear++]=neighbor;
            }
            temp=temp->next;
        }
    }
}
int main(){
    int vertices=5;
    struct node *adj[vertices];
    for(int i=0;i<vertices;i++){
        adj[i]=NULL;

        addEdge(adj,0,1);
        addEdge(adj,0,2);
        addEdge(adj,1,3);
        addEdge(adj,1,4);
        addEdge(adj,2,4);

        int visited(vertices);
        for(int i=0;i<vertices;i++){
            visited[i]=0;
        }
        printf("Breadth first traversal starting from vertex 0: ",);
               bfs(adj,vertices,0,visited);
    }
    return 0;

}

#include<iostream>
#include<queue>
using namespace std;
void print_dfs(int ** edges, int n, int sv, bool* visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(int i=0;i<n;i++){
        for(int i=0;i<n;i++){
            if(i == sv){
                continue;
            }
            if(edges[sv][i] == 1){
                if(visited[i]){
                    continue;
                }
                print_dfs(edges,n,i,visited);
            }
        }
    }
    // delete [] visited;
}

void print_bfs(int ** edges, int n, int sv, bool* visited){
    queue<int> pendingVertices;
    // bool * visited = new bool[n];
    // for(int i=0;i<n;i++){
    //     visited[i] = false;
    // }
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()){
        int cv = pendingVertices.front();
        pendingVertices.pop();
        cout<<cv<<" ";
        for(int i=0;i<n;i++){
            if(i == cv){
                continue;
            }
            if(edges[cv][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void dfs(int ** edges, int n){
    bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            print_dfs(edges,n,i,visited);
        }
    }
    delete [] visited;
}
void bfs(int ** edges, int n){
     bool * visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            print_bfs(edges,n,i,visited);
        }
    }
    delete [] visited;

}
int main(){
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    } 
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    cout<<"DFS"<<endl;
    // print(edges,n,0,visited);
    dfs(edges, n);
    cout<<endl<<"BFS"<<endl;
    bfs(edges, n);
    // print_bfs(edges,n,0); // --> add visited when calling it again
    // delete [] visited;
    // for(int i=0;i<n;i++){
    //     delete [] edges[i];
    // }
    // delete [] edges;

    return 0;
}


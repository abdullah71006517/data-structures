#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#define v 5
using namespace std;
void prim(int graph [v][v] ) {
vector<int>key(v,INT_MAX);
vector<int> parent(v,-1);
vector<bool>inmst(v,false);
priority_queue<pair<int ,int>>pq;
key[0]=0;
pq.push({0,0});
while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();
    if(inmst[u]) continue ;
    inmst[u]=true;

    for(int i=0;i<v;i++){
        if(!inmst[i]&&graph[u][i]!=0&&graph[u][i]<key[i]){
              key[i]=graph[u][i];

              parent[i ] = u;
               pq.push( { -key[i], i}) ;
    }

}
}

for(int i =1;i<v;i++) {
    cout<<parent[i] <<"_"<<i<<"="<<key[i]<<endl;
}

}
int main(){
int graph [v] [v];
for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        cin>>graph[i][j];
    }

}

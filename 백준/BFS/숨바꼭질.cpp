#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K;
int dist[200001];
bool visit[200001];
queue<int> q;
  
void bfs(int x){
  q.push(x);
  dist[x] = 0;
  visit[x] = true;

  while(!q.empty()){
    int now = q.front();
    q.pop();
    if(now - 1 >= 0){
      int next = now - 1;
      if(visit[next] == false){
        q.push(next);
        visit[next] = true;
        dist[next] = dist[now] + 1;
      }
    }
    if(now + 1 < 200000){
      int next = now + 1;
      if(visit[next] == false){
        visit[next] = true;
        q.push(next);
        dist[next] = dist[now] + 1;
      }
    }
    if(now * 2 < 200000){
      int next = now * 2;
      if(visit[next] == false){
        visit[next] = true;
        q.push(next);
        dist[next] = dist[now] + 1;
      }
    }
  }
}
int main(){
  cin >> N >> K;
  bfs(N);
  
  cout << dist[K] << '\n';
}
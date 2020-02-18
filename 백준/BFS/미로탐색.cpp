```
#include<iostream>
#include<queue>
#include<utility>
#include<cstdio>
#include<algorithm>
using namespace std;

int N, M;
int arr[101][101];
bool chk[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dist[101][101];

void bfs(int x, int y){
  queue<pair<int, int> > q;
  dist[x][y] = 1;
  q.push(make_pair(x, y));
  int siz = q.size();
  while(1){
    int a = q.front().first;
    int b = q.front().second;
    q.pop();
    for(int i=0;i<siz;i++){

      if(a == N-1 && b == M-1){
        return;
      }
      for(int k=0;k<4;k++){
        int nr = a + dx[k];
        int nc = b + dy[k];
        if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
        if(chk[nr][nc] == true) continue;
        if(arr[nr][nc] != 1) continue;

        chk[nr][nc] = true;
        q.push(make_pair(nr, nc));
        dist[nr][nc] = dist[a][b] + 1;
      }
    }
  }
}
int main(){
  cin >> N >> M;
  //미로 인풋
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int in;
      scanf("%1d", &in);
      arr[i][j] = in;
    }
  }
  bfs(0, 0);
  cout << dist[N-1][M-1] << '\n';
}
```

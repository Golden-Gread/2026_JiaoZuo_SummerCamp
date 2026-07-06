#define DIJKSTRA_BFS_H
#ifdef DIJKSTRA_BFS_H


#include <vector>
#include <queue>






std::vector<int> dij(std::vector<std::vector<std::pair<int, int>>> &graph, int str_node){
    typedef std::pair<int, int> pii;
    const int MAXN = 1e9;
    using namespace std;
    int n = graph.size();
    vector<int> dist(n, MAXN);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[str_node] = 0;
    pq.push(make_pair(0, str_node));

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        if(dist[it.second] < it.first){
            continue;
        }

        for(auto v : graph[it.second]){
            int dis = v.first;
            int to = v.second;

            if(dist[to] > dist[it.second] + dis){
                dist[to] = dist[it.second] + dis;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
    return dist;
}


std::pair< std::vector< int > , std::vector< int > > dijkstra_path(std::vector<std::vector<std::pair<int, int>>> &graph, int str_node){
    typedef std::pair<int, int> pii;
    const int MAXN = 1e9;
    using namespace std;
    int n = graph.size();
    vector<int> dist(n, MAXN);
    vector<int> fa(n+1,0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[str_node] = 0;
    pq.push(make_pair(0, str_node));
    

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(dist[it.second] < it.first){
            continue;
        }

        for(auto v : graph[it.second]){
            int dis = v.first;
            int to = v.second;

            if(dist[to] > dist[it.second] + dis){
                dist[to] = dist[it.second] + dis;
                pq.push(make_pair(dist[to], to));
                fa[to]=it.second;
            }
        }
    }

    std::vector<int> path;
    int ind=n-1;
    while(ind!=0){
        path.push_back(ind);
        ind=fa[ind];
    }



    return {dist, path};


}



#endif

#include <bits/stdc++.h>
using namespace std;

// write your matric number here: A0174217H
// write your name here: Teo Chuan Kai
// write list of collaborators here:
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

//"infinite" value
const int inf = 2147483647;
//destination vertice and weight
typedef pair<int, int> ii;
//Number of vertices (junctions)
int V;
//Number of queries
int Q;
//Weighted graph representation (sg map)
vector< vector<ii> > AdjList;
//map of source to all other vertices (vector containing weights)
unordered_map<int, vector<int> > um;


void dijkstra(int source) {
    //---declaration of data structures---//
    //pq to work with
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    
    //---initialisation of source values---/
    //push weight of 0 and source vertice into pq;
    pq.push(make_pair(0, source));
    //set distances to all vertices to be "infinite"
    um[source].assign(V, inf);
    //set distance from source to source to be 0
    um[source][source] = 0;

    while(!pq.empty()) {
        //get vertice "nearest" to source node
        int currV = pq.top().second;
        //remove from pq
        pq.pop();

        //find all vertices connected to current one
        for(auto it = AdjList[currV].begin(); it != AdjList[currV].end(); it++) {
            int nextV = it->first;
            int weight = it->second;

            //if there is a shorter path to the next vertice
            if(um[source][nextV] > um[source][currV] + weight) {
                //calculate new weight
                um[source][nextV] = um[source][currV] + weight;
                //push into pq
                pq.push(make_pair(um[source][nextV], nextV));
            }
        }
    }
}

int Query(int source, int dest, int k) {
    int ans = -1;
    if(um[source][dest] != inf) {
        ans = um[source][dest];
    }
    return ans;
}

int main() {
    //freopen("in5.txt", "r", stdin);
    
    int TC;
    scanf("%d", &TC);  //number of test cases

    while(TC--) {
        //build graph
        scanf("%d", &V); //number of vertices
        AdjList.assign(V, vector<ii>()); //assign V number to AdjList

        int count, vertice, weight;
        //iterate through list of edges at each vertice
        for(int i = 0; i<V; i++) {
            scanf("%d", &count);
            while(count--) {
                scanf("%d %d", &vertice, &weight);
                AdjList[i].emplace_back(vertice, weight);
            }
        }

        //read & process queries
        int source, destination, required_k;
        vector<bool> calculated;
        calculated.assign(V, false);

        scanf("%d", &Q);
        while(Q--) {
            scanf("%d %d %d", &source, &destination, &required_k);
            if(calculated[source] == false) {
                calculated[source] = true;
                dijkstra(source);
            }
            printf("%d\n", Query(source, destination, required_k));
        }
        if(TC) {
            printf("\n");
        }
    }
    return 0;
}
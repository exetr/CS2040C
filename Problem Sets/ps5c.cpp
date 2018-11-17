#include <bits/stdc++.h>
using namespace std;

// write your matric number here: A0174217H
// write your name here: Teo Chuan Kai
// write list of collaborators here:
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

//"infinite" value
const int inf = 99;
//destination vertice and weight
typedef pair<int, int> ii;
//Number of vertices (junctions)
int V;
//Number of queries
int Q;
//Weighted graph representation (sg map)
vector< vector<ii> > AdjList;

void printDistances(vector<vector<int> > distances) {
    for(int i=0; i<V; i++) {
        printf("%d ", i);
        for(int j=0; j<V; j++) {
            printf("<%d, %d> ", j, distances[i][j]);
        }
        printf("\n");
    }
    printf("\n\n")
;}

int query(int source, int dest, int k) {
    int ans = -1;
    //vector to store weights to all other vertices
    vector<vector<int> > distances;

    //set distance to all vertices as "infinite"
    distances.assign(V, vector<int>(V, inf));
    distances[0][source] = 0;

    //iterate through vertices until k limit is hit
    for(int i = 1; i < k; i++) {
        //iterate through all vertices
        for(int j = 0; j < V; j++) {
            //iterate through neighbours of current vertice
            for(auto it = AdjList[j].begin(); it != AdjList[j].end(); it++) {
                int nextV = it->first;
                int weight = it->second;
                //relax
                if(distances[i][nextV] > distances[i-1][j] + weight) {
                    distances[i][nextV] = distances[i-1][j] + weight;
                }
                
            }
            printDistances(distances);
        }
        //check again
        for(int j = 0; j < V; j++) {
            if(distances[i][j] > distances[i-1][j]) {
                distances[i][j] = distances[i-1][j];
            }
        }
    }

    if(distances[k-1][dest] != inf) {
        ans = distances[k-1][dest];
    }
    return ans;
}

int main() {
    freopen("in5c.txt", "r", stdin);

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
        scanf("%d", &Q);
        while(Q--) {
            scanf("%d %d %d", &source, &destination, &required_k);
            printf("%d\n", query(source, destination, required_k));
        }
        if(TC) {
            printf("\n");
        }
    }
    return 0;
}
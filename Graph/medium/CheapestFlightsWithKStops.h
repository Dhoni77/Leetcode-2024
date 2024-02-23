//
// Created by Aldrin on 23-02-2024.
//

#ifndef DOOCS_CHEAPESTFLIGHTSWITHKSTOPS_H
#define DOOCS_CHEAPESTFLIGHTSWITHKSTOPS_H
#include "bits/stdc++.h"
using namespace std;

class CheapestFlightsWithKStops {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
        for(auto flight: flights) {
            int from = flight[0], to = flight[1], price = flight[2];
            adj[from].emplace_back(to, price);
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int step = 0;
        while(!q.empty() and step <= k) {
            int sz = q.size();
            while(sz-- > 0) {
                auto [node, distance] = q.front();
                q.pop();

                for(auto [neighbour, price]: adj[node]) {
                    if(price + distance >= dist[neighbour])
                        continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            step++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int>distance(n+1,INT_MAX);
        //this is for setting the distance array with INT_MAX means infinity
        unordered_map<int,vector<pair<int,int>>>adj;//this is for adjacency list
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});//this is for pushing in the adjacency list
        }
        queue<pair<int,int>>q;
        q.push({src,0});//this is for pushing in the queue
        distance[src]=0;
        while(!q.empty()&&k>=0)
        {
            int n=q.size();
            while(n--)
            {
                auto it=q.front();//getting the front of the queue
                int node=it.first;//this is for node
                int dista=it.second;//this is for distance
                q.pop();
                for(auto itr:adj[node])//exploring all its neighbour
                {
                    int nod=itr.first;
                    int di=itr.second;
                    if(di+dista<distance[nod])
                    {
                        distance[nod]=di+dista;
                        q.push({nod,distance[nod]});
                    }
                }
            }
            k--;
        }
        if(distance[dst]>=INT_MAX)
        {
            return -1;
        }
        return distance[dst];
    }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Djikstra Algorithm
     *
     * Dijkstra’s Algorithm allows you to calculate the shortest path between
    one node of your choosing and every other node in a graph.

    Given a graph and a source vertex in the graph, find shortest paths from source
    to all vertices in the given graph.

    We generate a SPT (shortest path tree) with given source as root. We maintain
    two sets, one set contains vertices included in shortest path tree, other set
    includes vertices not yet included in shortest path tree. At every step of the
    algorithm, we find a vertex which is in the other set (set of not yet included)
    and has a minimum distance from the source.

    Time Complexity:  If we take a closer look, we can observe that the statements
    in inner loop are executed O(V+E) times (similar to BFS).
    So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV)

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // create adjacency list
        unordered_map<int,vector<pair<int, int>>> adjList;
        for( auto f : flights )
            adjList[f[0]].push_back( { f[1], f[2] } );

        // minHeap based on cost of distance from source
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        minHeap.push( { 0, src, K+1 } ); // cost, vertex, hops

        while( !minHeap.empty() ) {
            auto t = minHeap.top(); minHeap.pop();
            int cost = t[0];
            int curr = t[1];
            int stop = t[2];
            if( curr == dst )
                return cost;

            if( stop > 0 )
                for( auto next : adjList[curr] )
                    minHeap.push( { cost+next.second, next.first, stop-1 } );
        }
        return -1;
    }
     */
};


#endif //DOOCS_CHEAPESTFLIGHTSWITHKSTOPS_H

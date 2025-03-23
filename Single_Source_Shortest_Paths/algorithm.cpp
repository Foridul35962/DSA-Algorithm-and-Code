Algorithm ShortestPath(v,cost,dist,n)
//dist[j], 1<=j<=n, is set to the length of the shortest path from vertex
//v to vertex j in a digraph G with n vertices. dist[v] is set to zero. G is
//represented by its cost adjacency matrix cost [1:n,1:n]
{
    for i:=1 to n do
    {
            //initialize s.
        s[i]:=false;
        dist[i]:=cost[v,i];
    }
    s[v]:=true;
    dist[v]:=0.0;   //put v in s
    for num:=2 to n-1 do
    {
            //Determine n-1 paths from v. Choose u from amoung those vertices
            //not in s such that dist[u] is minimum;
        for(each w adjacent to u with s[w]=false)
        {
                //update distances
            if(dist[w]>dist[u]+cost[u,m])then
            {
                dist[w]:=dist[u]+cost[u,m];
            }
        }
    }
}
Algorithm BellmanFord(v,cost,dist,n)
//Single-source/ all-destinations shortest paths with negetive edge costs
{
    for i:=1 to n do    //Initialize dist
        dist[i]:=cost[v,i];
    for k:=2 to n-1 do
    {
        for each u such that u!=v and u has at least one incoming edge do
        {
            for each <i,u> in the graph do
            {
                if dist[u]>dist[i]+cost[i,u] then
                    dist[u]:=dist[i]+cost[i,u];
            }
        }
    }
}
Algorithm DFS(v)
// Given an undirected (directed) graph G=(V,E) with n vertices and an
//array visited[] initially set to zero, this algorithm visits all vertices
//reachable from v. G and visited[] are global.
{
    visited[v]:=1;
    for each vertex w adjacent from v do
    {
        if(visited[w]=0) then
            DFS(w);
    }
}
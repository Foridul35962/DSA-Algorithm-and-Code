Algorithm BFT(G,n)
//Breadth first traversal of G
{
    for i:=1 to n do    //Mark all vertices unvisited
        visited[i]:=0;
    for i:=1 to n do
        if(visited[i]=0) then
            BFS(i);
}
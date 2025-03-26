Algorithm AllPaths(cost,A,n)
//cost[1:n,1:n] is the cost adjancy matrix of a graph with n vertices; A[i,j]
//is the cost of a shortest path from vertex i to vertex j. cost[i,j]=0.0;
//for 1<=i<=n.
{
    for i=1 to n do
    {
        for j:=1 to n do
        {
            A[i,j]=cost[i,j];   //copy
        }
    }
    for k:=1 to n do
    {
        for i:=1 to n do
        {
            for j:=1 to n do
            {
                A[i,j]:= min(A[i,j],A[i,j]+A[k,j]);
            }
        }
    }
}
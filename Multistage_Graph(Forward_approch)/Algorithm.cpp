Algorithm FGraph(G,k,n,p)
//The input is a k-stage graph G = (V,E) with n vertices indexed in order of stages.
//E is a set of edges and c[i,j] is the cost of <i,j>. p[1:k] is a minimum- cost path.
{
    cost[n]:=0.0;
    for j:=n-1 to 1 step -1 do
    {
            //Compute cost[j].
            Let r be a vertex such that <j,r> is an edge of G and
            c[j,r] + cost[r] is minimum;
        cost[j]:=c[j,r]+cost[r];
        d[j]:=r;
    }
        //Find a minimum cost path
    p[1]:=1;
    p[k]:=n;
    for j:=2 to k-1 do
        p[j]:=d[p[j-1]];
}
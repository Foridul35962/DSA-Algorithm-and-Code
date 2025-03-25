Algorithm BGraph(G,k,n,p)
// Same function as FGraph
{
    bcost[1]:=0.0;
    for j:=2 to n do
    {
            //Compute bcost[j]. Let r be such that <r,j> is an edge of G
            //and bcost[r]+c[r,j] is minimum;
        bcost[j]:=bcost[r]+c[r,j];
        d[j]:=r;
    }
        //Find a minimum-cost path
    p[1]:=1;
    p[k]:=n;
    for j:=k-1 to 2 do
        p[j]:=d[p[j+1]];
}
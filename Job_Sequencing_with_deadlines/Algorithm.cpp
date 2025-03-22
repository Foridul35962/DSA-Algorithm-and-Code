Algorithm JS(d,j,n)
//d[i]>=1, 1<=i<=n are the deadlines, n>=1. The jobs are ordered such that
//p[1]>=p[2]>=...p[n]. j[i] is the ith job in the optimal solution, 1<=i<=k.
//Also, at termination d[j[i]]<=d[j[i+1]], 1<=i<k.
{
    d[0]:=j[0]:=0; //Initialize.
    j[1]:=1;    //Include job 1.
    k:=1;
    for i:=2 to n do
    {
            //consider jobs in noincreasing order of p[i]. Find position for
            // i and check feasibility of insertion.
        r:=k;
        while((d[j[r]]>d[i])and (d[j[r]]!=r)) do
        r:=r-1;
        if((d[j[r]]<=d[i])and (d[i]>r)) then
        {
                //Insert i into j[]
            for q:=k to (r+1) step-1 do j[q+1]:=j[q];
            j[r+1]:=i;
            k:=k+1;
        }
    }
    return k;
}
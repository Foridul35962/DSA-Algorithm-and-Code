Algorithm Partition(a,m,p)
// Within a[m], a[m+1],..., a[p-1] the elements are rearreanged in such a
//manner that if initially t=a[m], then after completion a[q]=t for some q between
// m and p-1, a[k]<=t for m<=k<q, and a[k]>=t for q<k<p. q is returned. Set a[p]=infinity
{
    v:=a[m];
    i:=m;
    j:=p;
    repeat
    {
        repeat i:=i+1; until (a[i]>=v);
        repeat j:=j-1; until (a[j]<=v);
        if(i<j) then Interchange(a,i,j);
    } until(i>=j);
    a[m]:=a[j];
    a[j]:=v;
    return j;
}

Algorithm Interchange(a,i,j)
//Exchange a[i] with a[j]
{
    p:=a[i];
    a[i]:=a[j];
    a[j]:=p;
}

Algorithm QuickSort(p,q)
//Sort the elements a[p],...a[q] which reside in the global array a[1:n] into ascending
//order a[n+1] is considered to be defined and must be >= all elements in a [1:n]
{
    if(p<q)then     //if there are more than one element
    {
            //divided P into two subproblems.
        j:=Partition(a,p,q+1);
            // j is the position of the partitioning element
            //solve the subproblems
        QuickSort(p,j-1);
        QuickSort(j+1,q);
            //There is no need for combining solutions
    }
}
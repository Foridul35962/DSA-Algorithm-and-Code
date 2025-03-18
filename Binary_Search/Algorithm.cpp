Algorithm BinSrch(a,i,l,x)
//Given an array a[i:l] of elements in nondecresing order, 1<=i<=l, determine wheter x is present
{
    if(i=l)then
    {
        if(x=a[i])then return i;
        else return 0;
    }
    else
    {
        mid=floar((i+l)/2);
        if(x=a[mid])then return mid;
        else if(x<a[mid]) then
            return BinSrch(a,i,mid-1,x);
        else
            return BinSrch(a,mid+1,l,x);
    }
}
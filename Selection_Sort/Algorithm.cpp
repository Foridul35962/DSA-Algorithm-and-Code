Alorithm SelectionSort(a,n)
//Sort the array a[1:n] into nondecresing order.
{
    for i:=1 to n do
    {
        j:=i;
        for k:=i+1 to n do
            if(a[k]<a[j]) then
                j:=k;
        swap(a[i],a[j]);                
    }
}
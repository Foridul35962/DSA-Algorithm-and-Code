Algorithm MaxMin(i,j,max,min)
//a[1:n] is a global array. Parameters i and j are integers,
//1<=i<=j<=n. The effect is to set max and min to the largest and
// smallest value in a[i:j], respectively.
{
    if(i==j) then
        max:=min:=a[i]; //Small(P)
    else if(i=j-1) then //Another case of Small(P)
    {
        if(a[i]<a[j])then
        {
            max:=a[j];
            min:=a[i];
        }
        else
        {
            max:=a[i];
            min:=a[j];
        }
    }
    else
    {
            //If P is not small, divide P into subproblems.
            //Find where to split the set.
        mid:= floor((i+j)/2);
            //Solve the subproblems
        MaxMin(i,min,max,min);
        MaxMin(mid+1,j,max1,min1);
            //Combine the solutions.
        if(max<max1) then
            max:=max1;
        if(min>min1) then
            min:=min1;
    }
}
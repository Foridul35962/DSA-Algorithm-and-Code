Algorithm Place(k,i)
//Returns true if a queen can be placed in kth row and ith column Otherwise
//it returns false. x[] is a global array whose first (k-1) values have been set.
//Abs(r) returns the absolute value of r.
{
    for j:=1 to k-1 do
    {
        if((x[j]=i)     //Two in the same column
        or (Abs(x[j]-i)=Abs(j-k)))  //or in the diagonal
            then return false;
    }
    return true;
}


Algorithm NQueens(k,n)
//Using backtracking, this procdure prints all posible placement of n queens on
//an n*n chessboard so that they are nonattacking.
{
    for i:=1 to n do
    {
        if Place(k,i)then
        {
            x[k]:=i;
            if(k=n) then
                write (x[1:n]);
            else
                NQueens(k+1,n);
        }
    }
}
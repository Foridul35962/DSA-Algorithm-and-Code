Algorithm TowerOfHanoi(n,x,y,z)
//Move the top n disks from tower x to tower y.
{
    if(n>=1)then
    {
        TowerOfHanoi(n-1,x,z,y);
        print("move top disk from tower", x, "to top of tower", y);
        TowerOfHanoi(n-1,z,y,x);
    }
}
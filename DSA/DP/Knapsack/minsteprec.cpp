int minsteps(int n){
    if(n == 1){
        return 0;
    }
    int x = minsteps(n-1);
    int y = INT_MAX;
    int z = INT_MAX;

    if(n%2==0){
        y = minsteps(n/2);
    }
    if(n%3==0){
        z = minsteps(n/3);
    }
    return min(x,min(y,x)) + 1;
}
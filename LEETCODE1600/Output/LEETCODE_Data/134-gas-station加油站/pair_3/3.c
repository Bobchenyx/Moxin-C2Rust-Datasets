int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
 
    //int index[gasSize];
    int i,sum,j;
    //for(i=0;i<gasSize;i++)
    //index[i]=gas[i]-cost[i];
    for(i=0;i<gasSize;i++)
    {
        //if(index[i]>=0)
        if((gas[i]-cost[i])>=0)
        {
            j=i;
            sum=(gas[j]-cost[j]);
            j++;
            j=j%gasSize;//确保不能越界
            while(j!=i&&sum>=0)
            {
                sum+=gas[j]-cost[j];
                j++;
                j=j%gasSize;
            }
            if(i==j&&sum>=0)
            return i;
        }
    }
    return -1;
}
int reachNumber(int target){
    int sum , n ;
    sum=n=0;
    target=abs(target);

   while(sum-target<0||(sum-target)%2!=0)
   {
       n++;
       sum=sum+n ;
   }



    return n ;

}
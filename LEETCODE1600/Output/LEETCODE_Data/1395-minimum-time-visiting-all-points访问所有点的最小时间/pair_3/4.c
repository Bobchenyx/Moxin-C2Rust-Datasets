int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
   int sum=0;//总和
   int a,b;//两点x、y距离
   for(int i=0;i<pointsSize-1;i++){
       a=abs(points[i][0]-points[i+1][0]);
       b=abs(points[i][1]-points[i+1][1]);
       sum+=abs(a-b);
       if(a>b) sum+=b;
       else sum+=a;
   }
   *pointsColSize=sum;
   return sum;
}
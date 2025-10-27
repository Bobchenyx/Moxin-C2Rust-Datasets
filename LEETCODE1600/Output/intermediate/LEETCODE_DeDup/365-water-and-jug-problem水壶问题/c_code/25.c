bool canMeasureWater(int x, int y, int z){
int temp;
if(z==0||x+y==z) return true;
if(x==0||y==0) return false;
if(x<y)
{temp=x;
x=y;
y=temp;}
int vis[x+1];
memset(vis,0,sizeof(vis));
temp=0;
while(1)
{temp=x-(y-temp);
if(temp==z||temp+y==z) return true;
if(!vis[temp])vis[temp]=1;
else return false;
while(temp>y)
{temp-=y;
if(temp==z) return true;
if(!vis[temp])vis[temp]=1;
else return false;}
if(temp+x==z) return true;
}
}
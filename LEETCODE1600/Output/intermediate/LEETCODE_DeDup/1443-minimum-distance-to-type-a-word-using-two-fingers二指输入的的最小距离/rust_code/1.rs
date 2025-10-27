let a = g[i+1][j] + distance(i+1,i);
let b = g[i+1][i] + distance(i+1,j);
g[i][j] = min(a,b);
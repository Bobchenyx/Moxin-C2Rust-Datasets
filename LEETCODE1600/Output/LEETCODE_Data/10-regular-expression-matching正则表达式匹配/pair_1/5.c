bool isMatch(char* s, char* p){
    int lens = strlen(s);
    int lenp = strlen(p);

    if(lenp == 0)
        return lens == 0;

    bool first  = lens > 0 && (s[0] == p[0] || p[0] == '.');
    
//解释下这里为啥fisrt　真或假都执行　(isMatch(s,p+2))，　
//大多isMatch(s,p+2)可以改写成这样 (!first&&isMatch(s,p+2)) 即first不对时，ｐ跳过重新开始
    // 比如这种case: "aab"  "a*b" 　就可以第三个ｂ的fisrt不匹配，ｐ需要跳过重新开始。
 //  但是这种case: "aaa"  "a*a"  就会判断有误，因为 第三个ａ依然是匹配的，p不＋２结束不了
   // 所以即使first为true,也要每个ｓ都执行下isMatch(s,p+2)，　才能“aaa“正常退出。　　
   // 比如:"aaa"   "ab*a*c*a"  也是true
    if(lenp > 1 && p[1] == '*')
        return isMatch(s,p+2) || (first&&isMatch(s+1,p));
    else
        return first && isMatch(s+1,p+1);
}
bool backspaceCompare(char * S, char * T){
    int arrS[100] = {0}, arrT[100] = {0};
    int posS = 0, posT = 0;
    int i;
    for(i = 0; S[i] != '\0'; i++){
        if(S[i] == '#'){
            if(posS == 0) posS = 0;
            else 
                posS--;
        }
        else{
            arrS[posS++] = S[i];
        }
    }
    for(i = 0; T[i] != '\0'; i++){
        if(T[i] == '#'){
            if(posT == 0) posT = 0;
            else 
                posT--;
        }
        else{
            arrT[posT++] = T[i];
        }
    }
    if(posT != posS)
        return false;
    else{
        for(i = 0; i < posS; i++){
            if(arrT[i] != arrS[i])
                return false;
        }
        return true;
    }
}
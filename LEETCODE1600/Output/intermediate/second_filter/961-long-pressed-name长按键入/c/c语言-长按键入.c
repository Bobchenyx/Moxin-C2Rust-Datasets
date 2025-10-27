bool isLongPressedName(char * name, char * typed){
    int i=0,j=0;
    while(i<strlen(name)&&j<strlen(typed)){
        if(name[i]==typed[j]){
            i++;
            j++;
        }
        else {
            if(j>0&&typed[j]==typed[j-1])j++;
            else return false;
        }//else
    }//while
  if(i!=strlen(name))  return false;
  else if(j!=strlen(typed)){
      j++;
      while(j<strlen(typed)){
          if(typed[j]!=typed[j-1])return false;
      }//while
  }//else if
  return true;
}
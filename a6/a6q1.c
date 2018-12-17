#include<stdio.h>
int NextVertex(int,int,int,int,int,int);


int main (void){
  int arrayLen;
  int x,y;
  int i=0;
  printf("Please enter an array Length\n");
  scanf("%d",&arrayLen);
  if(arrayLen<3){
    printf("");
  }

  int xcord[arrayLen];
  int ycord[arrayLen];
  
  while(scanf("%d %d",&x,&y) == 2){
    xcord[i]=x;
    ycord[i]=y;
    i++;
  }


  int highY=ycord[0];
  int indexHighY=0;
  for(int k=1;k<arrayLen;k++){
    if(ycord[k]>highY){
      highY=ycord[k];
      indexHighY=k;
    }
  }
  

  int C[arrayLen];
  C[0]=indexHighY;

  int l=0;
  int countClockWise=0;
  
  for(int k=0;k<arrayLen;k++){
    for(int j=0;j<arrayLen;j++){
      if(j!=C[i]&&j!=k){
	countClockWise=NextVertex(xcord[C[l]],xcord[k],xcord[j]
				  ,ycord[C[l]],ycord[k],ycord[j]);
	if(countClockWise>0)
	  break;
      }
    } 
    if(countClockWise<0){
      l=l+1;
      C[l]=k;
    }
    k=0;
    if(C[l]==indexHighY)
      break;
  }
  
  for(int i=0;i<arrayLen;i++){
    printf("%d\t",C[i]);
  }
  printf("\n");
  

  return 0;
}
int NextVertex(int x0,int x1,int x2,int y0,int y1,int y2){
  return (x1-x0)*(y2-y1)-(x2-x0)*(y1-y0);
}

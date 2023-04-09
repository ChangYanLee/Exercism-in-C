#include <stdio.h>

//т程 
int max(int a,int b){
    if(a>b) return a;
    return b;
}
//т程 
int min(int a,int b){
    if(a<b) return a;
    return b;
}

void main(){
   //﹚竡ㄧΑ夹跑计 pfun 
   int (*pfun)(int,int);
   
   //结ㄧΑ夹т程 
   pfun=max;//┪&max
   int c=pfun(10,20);
   printf("%d\r\n",c);
   
   //结ㄧΑ夹т程 
   pfun=min; //┪&min
   c=pfun(10,20);
   printf("%d\r\n",c);
}
//挤ㄧΑ 
//#include <stdio.h>
////т程 
//int max(int a,int b){
//    if(a>b) return a;
//    return b;
//}
////т程 
//int min(int a,int b){
//    if(a<b) return a;
//    return b;
//}
////ㄧΑ 
//int all(int a,int b,int (*pfun)(int,int)){
//    return pfun(a,b);
//}
//void main(){
//   int c=0;
//   //т程㊣ 
//   c=all(10,20,max);
//   printf("%d\r\n",c);
//   //т程㊣ 
//   c=all(10,20,min);
//   printf("%d\r\n",c);
//}

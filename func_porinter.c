#include <stdio.h>

//��̤j�� 
int max(int a,int b){
    if(a>b) return a;
    return b;
}
//��̤p�� 
int min(int a,int b){
    if(a<b) return a;
    return b;
}

void main(){
   //�w�q�禡�����ܼ� pfun 
   int (*pfun)(int,int);
   
   //��Ȩ禡���СA��̤j�� 
   pfun=max;//�Ϊ̬�&max
   int c=pfun(10,20);
   printf("%d\r\n",c);
   
   //��Ȩ禡���СA��̤p�� 
   pfun=min; //�Ϊ̬�&min
   c=pfun(10,20);
   printf("%d\r\n",c);
}
//�^���禡 
//#include <stdio.h>
////��̤j�� 
//int max(int a,int b){
//    if(a>b) return a;
//    return b;
//}
////��̤p�� 
//int min(int a,int b){
//    if(a<b) return a;
//    return b;
//}
////�禡�J�f 
//int all(int a,int b,int (*pfun)(int,int)){
//    return pfun(a,b);
//}
//void main(){
//   int c=0;
//   //��̤j�ȩI�s 
//   c=all(10,20,max);
//   printf("%d\r\n",c);
//   //��̤p�ȩI�s 
//   c=all(10,20,min);
//   printf("%d\r\n",c);
//}

#include <stdio.h> 
#include <unistd.h>

int main() { 
   pid_t pid1, pid2;

   // 第一個 fork 創建一個子進程
   if ((pid1 = fork()) == 0) {
       // 子進程再創建一個子進程
       if ((pid2 = fork()) == 0) {
           while (1) {    
               printf("George\n");    
               sleep(1);    
           }    
       } else {
           while (1) {    
               printf("Mary\n");    
               sleep(2);    
           }    
       }
   } else {
       while (1) {     
           printf("----------------\n");    
           sleep(1);     
       }
   }

   return 0;
}

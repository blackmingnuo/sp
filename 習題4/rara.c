#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
#define LOOPS 100000000
int money = 1000;

void *in(){
for (int i=0; i<LOOPS; i++) {
    pthread_mutex_lock( &mutex1 );
    int inmoney=1000;
    printf("in: %d\n", inmoney);
    money=money+inmoney;
    printf("have: %d\n", money);
    pthread_mutex_unlock( &mutex1 );
  }
  pthread_exit(NULL);
}

void *out(){
for (int i=0; i<LOOPS; i++) {
    pthread_mutex_lock( &mutex1 );
    int outmoney=1000;

    if(money<outmoney){
        printf("cant\n");
        printf("have: %d\n", money);
        
    }
    else {
        printf("out: %d\n", outmoney);
        money=money-outmoney;
        printf("have: %d\n", money);
        
    }
    pthread_mutex_unlock( &mutex1 );
  }
  pthread_exit(NULL);
}

int main() 
{
  pthread_t input, output;

  pthread_create(&input, NULL, in, NULL);
  pthread_create(&output, NULL, out, NULL);

  pthread_join( input, NULL);
  pthread_join( output, NULL);
  printf("counter=%d\n", money);
}
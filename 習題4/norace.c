#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
#define LOOPS 100000
int money = 1000;

void *in() {
    for (int i = 0; i < LOOPS; i++) {
        pthread_mutex_lock(&mutex1);
        int inmoney = 1000;
        money = money + inmoney;
        printf("存款: %d, 當前金額: %d\n", inmoney, money);
        pthread_mutex_unlock(&mutex1);
    }
    pthread_exit(NULL);
}

void *out() {
    for (int i = 0; i < LOOPS; i++) {
        pthread_mutex_lock(&mutex1);
        int outmoney = 1000;
        if (money < outmoney) {
            printf("無法提款\n");
        } else {
            money = money - outmoney;
            printf("提款: %d, 當前金額: %d\n", outmoney, money);
        }
        pthread_mutex_unlock(&mutex1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t input, output;

    pthread_create(&input, NULL, in, NULL);
    pthread_create(&output, NULL, out, NULL);

    pthread_join(input, NULL);
    pthread_join(output, NULL);
    printf("最終金額=%d\n", money);

    return 0;
}

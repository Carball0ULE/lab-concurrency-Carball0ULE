/**
 * NON-COMPLIANT APPROACH para la regla ---CON40-C. Do not refer to an atomic variable twice in an expression---
 * Ref.: https://wiki.sei.cmu.edu/confluence/display/c/CON40-C.+Do+not+refer+to+an+atomic+variable+twice+in+an+expression
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdatomic.h>
#include <stdbool.h>
   
static atomic_bool flag = ATOMIC_VAR_INIT(false);
   
void init_flag(void) {
  atomic_init(&flag, false);
}

bool get_flag(void) {
  return atomic_load(&flag);
}
   
void toggle_flag(int id) {
  bool temp_flag = atomic_load(&flag);
  temp_flag = !temp_flag;
  printf("Hilo %d, va a guardar la flag con valor %d\n", id, temp_flag);
  atomic_store(&flag, temp_flag);
  printf("Hilo %d, consultamos flag y tiene valor %d\n", id, get_flag());
}

void *thread_code(void *arg) {
    int id = *(int *)arg;
    //sleep(id);            //Para ajustar espera y que se ejecute correctamente
    printf("Hola desde el hilo %d, con valor del flag %d\n", id, get_flag());
    toggle_flag(id);

    return NULL;
}

int main() {
    pthread_t threads[2];           // 2 threads en total
    int ids[2] = {1, 2};

    init_flag();

    for (int i = 0; i < 2; i++) {   // Crea 2 threads, ejecutan thread_code
        if (pthread_create(&threads[i], NULL, thread_code, &ids[i]) != 0) {
            perror("Error");
            return 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Hilos han finzalizado.\n");
    return 0;
}
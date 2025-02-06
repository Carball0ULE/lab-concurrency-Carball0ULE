/**
 * COMPLIANT APPROACH para la regla ---CON40-C. Do not refer to an atomic variable twice in an expression---
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
  bool old_flag = atomic_load(&flag);
  bool new_flag;
  int i = 0;
  do {
    i++;
    printf("Hilo %d: %d\n", id, i);   //Para ver cuantas iteraciones hace el do-while
    new_flag = !old_flag;
  } while (!atomic_compare_exchange_weak(&flag, &old_flag, new_flag));
  printf("Hilo %d, consultamos flag y tiene valor %d\n", id, get_flag());
}

void *thread_code(void *arg) {
    int id = *(int *)arg;
    //sleep(id);
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
            perror("Error al crear el hilo");
            return 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Todos los hilos han terminado.\n");
    return 0;
}
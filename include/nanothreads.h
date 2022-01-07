#ifndef NANOTHREADS_H_
#define NANOTHREADS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

enum {
  thrd_success  = 0,
  thrd_busy     = 1,
  thrd_error    = 2,
  thrd_nomem    = 3,
  thrd_timedout = 4,
};

enum {
  mtx_plain     = 0,
  mtx_recursive = 1,
  mtx_timed     = 2,
};


// in `src/`
#include "libs_thread.h"

//
// thread
//

typedef thread_ptr_t thrd_t;
typedef int (*thrd_start_t)(void *);

int thrd_create( thrd_t *thr, thrd_start_t func, void *arg );
_Noreturn void thrd_exit(int);

int thrd_detach(thrd_t);
int thrd_join(thrd_t, int *);

//int thrd_sleep(const struct timespec *, struct timespec *);
void thrd_yield(void);

thrd_t thrd_current(void);
int thrd_equal(thrd_t, thrd_t);

//
// mutex
//

typedef thread_mutex_t mtx_t;

int mtx_init(mtx_t *, int);
void mtx_destroy(mtx_t *);

int mtx_lock(mtx_t *);
//int mtx_timedlock(mtx_t *__restrict, const struct timespec *__restrict);
int mtx_trylock(mtx_t *);
int mtx_unlock(mtx_t *);

//
// condition variables
//

typedef thread_signal_t cnd_t;

int cnd_init(cnd_t *);
void cnd_destroy(cnd_t *);

int cnd_broadcast(cnd_t *);
int cnd_signal(cnd_t *);

//int cnd_timedwait(cnd_t *__restrict, mtx_t *__restrict, const struct timespec *__restrict);
int cnd_wait(cnd_t *, mtx_t *);


//
// thread-local storage
//
typedef thread_tls_t tss_t;
typedef void (*tss_dtor_t)(void *);

int tss_create(tss_t *, tss_dtor_t);
void tss_delete(tss_t);

int tss_set(tss_t, void *);
void *tss_get(tss_t);


#ifdef __cplusplus
}
#endif

#endif // NANOTHREADS_H_

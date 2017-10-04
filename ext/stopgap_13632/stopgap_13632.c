#ifdef BROKEN_RUBY
#include "ruby.h"
#include "ruby/config.h"

struct common_field {
	const size_t len;
	const char *name;
  int raw;
	VALUE value;
};

enum enum4 {
    status1,
    status2,
    status3,
    status4
};

#if defined(_WIN32)
#include <windows.h>
typedef HANDLE rb_nativethread_id_t;
#else
#include <pthread.h>
typedef pthread_t rb_nativethread_id_t;
#endif

typedef struct half_thread {
    void *vmlt_node1;
    void *vmlt_node2;
    void *self;
    void *vm;
    void *stack;
    size_t stack_size;
    void *cfp;
    int safe_level;
    int raised_flag;
    void *last_status;
    int state;
    int waiting_fd;
    void *passed_block;
    void *passed_bmethod_me;
    void *passed_ci_or_calling;
    void *top_self;
    void *top_wrapper;
    #ifndef VERSION_2_4_1
        void *base_block;
    #endif
    void *root_lep;
    void *root_svar;
    rb_nativethread_id_t thread_id;
#ifdef NON_SCALAR_THREAD_ID
    char thread_id_string[sizeof(rb_nativethread_id_t) * 2 + 3];
#endif
    enum enum4 status;
    int to_kill;
    int priority;
#if defined(_WIN32)
    void *interrupt_event;
#elif defined(HAVE_PTHREAD_H)
    void *ubf_list1_or_signal_thread_list;
#ifdef VERSION_2_3_4
    void *ubf_list2;
#endif
#ifdef VERSION_2_4_1
    void *ubf_list2;
#endif
    pthread_cond_t cond;
#ifdef HAVE_CLOCKID_T
    clockid_t clockid;
#endif
#endif
    void *blocking_region_buffer;
    void *thgroup;
    void *value;
    void *errinfo;
    VALUE pending_interrupt_queue;
    void *pending_interrupt_mask_stack;
    int pending_interrupt_queue_checked;
} rb_half_thread_t;

VALUE
rb_thread_purge_queue(VALUE thread)
{
    rb_half_thread_t *th = (rb_half_thread_t*)DATA_PTR(thread);
    th->pending_interrupt_queue_checked = 1;
    rb_ary_clear(th->pending_interrupt_queue);
    return Qnil;
}

void Init_stopgap_13632()
{
  rb_define_method(rb_cThread, "purge_interrupt_queue", rb_thread_purge_queue, 0);
}
#endif

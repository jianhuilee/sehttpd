#include <stdatomic.h>

struct atomic_t {
    volatile int value;
};

#define ATOMIC_INIT(v) \
    {                  \
        .value = (v)   \
    }

/* Returns the previously set value */
static inline int atomic_add(struct atomic_t *a, int i)
{
    return atomic_fetch_add(&a->value, i);
}

/* Returns the previously set value */
static inline int atomic_sub(struct atomic_t *a, int i)
{
    return atomic_fetch_sub(&a->value, i);
}

/* Returns the previously set value */
static inline int atomic_inc(struct atomic_t *a)
{
    return atomic_add(a, 1);
}

/* Returns the previously set value */
static inline int atomic_dec(struct atomic_t *a)
{
    return atomic_sub(a, 1);
}

/* Returns true when the operation was successful. */
static inline bool atomic_cmpxchg(struct atomic_t *a, int old_i, int new_i)
{
    /* TODO: is there any better way to do? */
    struct atomic_t expected, desired;
    expected.value = old_i;
    desired.value = new_i;
    return atomic_compare_exchange_strong(a, &expected, desired);
}

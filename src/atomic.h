
struct atomic_t {
    volatile int value;
};

/* Returns the previously set value */
static inline int atomic_add(struct atomic_t *a, int i)
{
    return __sync_fetch_and_add(&a->value, i);
}

/* Returns the previously set value */
static inline int atomic_sub(struct atomic_t *a, int i)
{
    return __sync_fetch_and_sub(&a->value, i);
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
    return __sync_bool_compare_and_swap(&a->value, old_i, new_i);
}


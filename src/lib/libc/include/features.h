#ifndef _FEATURES_H
#define _FEATURES_H

#if defined(_ALL_SOURCE) && !defined(_GNU_SOURCE)
#define _GNU_SOURCE 1
#endif

#if defined(_DEFAULT_SOURCE) && !defined(_BSD_SOURCE)
#define _BSD_SOURCE 1
#endif

#if !defined(_POSIX_SOURCE) && !defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE) && !defined(_GNU_SOURCE) && !defined(_BSD_SOURCE) && \
    !defined(__STRICT_ANSI__)
#define _BSD_SOURCE   1
#define _XOPEN_SOURCE 700
#endif

#if __STDC_VERSION__ >= 199901L
#define __restrict restrict
#elif !defined(__GNUC__)
#define __restrict
#endif

#if __STDC_VERSION__ >= 199901L || defined(__cplusplus)
#define __inline inline
#elif !defined(__GNUC__)
#define __inline
#endif

#if __STDC_VERSION__ >= 201112L
#elif defined(__GNUC__)
#define _Noreturn __attribute__((__noreturn__))
#else
#define _Noreturn
#endif

#define __REDIR(x, y) __typeof__(x) x __asm__(#y)

/* Macro to test version of GCC.  Returns 0 for non-GCC or too old GCC. */
#ifndef __GNUC_PREREQ
#if defined __GNUC__ && defined __GNUC_MINOR__
#define __GNUC_PREREQ(maj, min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
#define __GNUC_PREREQ(maj, min) 0
#endif
#endif /* __GNUC_PREREQ */
/* Version with trailing underscores for BSD compatibility. */
#define __GNUC_PREREQ__(ma, mi) __GNUC_PREREQ(ma, mi)

/*
 * Testing against Clang-specific extensions.
 */
#ifndef __has_attribute
#define __has_attribute(x) 0
#endif
#ifndef __has_extension
#define __has_extension __has_feature
#endif
#ifndef __has_feature
#define __has_feature(x) 0
#endif
#ifndef __has_include
#define __has_include(x) 0
#endif
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

/*
 * Compiler-dependent macros to help declare dead (non-returning) and
 * pure (no side effects) functions, and unused variables.  They are
 * null except for versions of gcc that are known to support the features
 * properly (old versions of gcc-2 supported the dead and pure features
 * in a different (wrong) way).  If we do not provide an implementation
 * for a given compiler, let the compile fail if it is told to use
 * a feature that we cannot live without.
 */
#define __weak_symbol __attribute__((__weak__))
#if !__GNUC_PREREQ__(2, 5)
#define __dead2
#define __pure2
#define __unused
#endif
#if __GNUC__ == 2 && __GNUC_MINOR__ >= 5 && __GNUC_MINOR__ < 7
#define __dead2 __attribute__((__noreturn__))
#define __pure2 __attribute__((__const__))
#define __unused
/* XXX Find out what to do for __packed, __aligned and __section */
#endif
#if __GNUC_PREREQ__(2, 7)
#define __dead2      __attribute__((__noreturn__))
#define __pure2      __attribute__((__const__))
#define __unused     __attribute__((__unused__))
#define __used       __attribute__((__used__))
#define __packed     __attribute__((__packed__))
#define __aligned(x) __attribute__((__aligned__(x)))
#define __section(x) __attribute__((__section__(x)))
#endif

/*
 * GNU C version 2.96 adds explicit branch prediction so that
 * the CPU back-end can hint the processor and also so that
 * code blocks can be reordered such that the predicted path
 * sees a more linear flow, thus improving cache behavior, etc.
 *
 * The following two macros provide us with a way to utilize this
 * compiler feature.  Use __predict_true() if you expect the expression
 * to evaluate to true, and __predict_false() if you expect the
 * expression to evaluate to false.
 *
 * A few notes about usage:
 *
 * Generally, __predict_false() error condition checks (unless
 * you have some _strong_ reason to do otherwise, in which case
 * document it), and/or __predict_true() `no-error' condition
 * checks, assuming you want to optimize for the no-error case.
 *
 * Other than that, if you don't know the likelihood of a test
 * succeeding from empirical or other `hard' evidence, don't
 * make predictions.
 *
 * These are meant to be used in places that are run 'a lot'.
 * It is wasteful to make predictions in code that is run
 * seldomly (e.g. at subsystem initialization time) as the
 * basic block reordering that this affects can often generate
 * larger code.
 */
#if __GNUC_PREREQ__(2, 96)
#define __predict_true(exp)  __builtin_expect(!!(exp), 1)
#define __predict_false(exp) __builtin_expect(!!(exp), 0)
#else
#define __predict_true(exp)  (exp)
#define __predict_false(exp) (exp)
#endif

#if __GNUC_PREREQ__(3, 1)
#define __always_inline __inline__ __attribute__((__always_inline__))
#else
#define __always_inline
#endif
#if __GNUC_PREREQ__(4, 3) || __has_attribute(__alloc_size__)
#define __alloc_size(x)     __attribute__((__alloc_size__(x)))
#define __alloc_size2(n, x) __attribute__((__alloc_size__(n, x)))
#else
#define __alloc_size(x)
#define __alloc_size2(n, x)
#endif
#if __GNUC_PREREQ__(4, 9) || __has_attribute(__alloc_align__)
#define __alloc_align(x) __attribute__((__alloc_align__(x)))
#else
#define __alloc_align(x)
#endif

#if !__GNUC_PREREQ__(2, 95)
#define __alignof(x)  \
    __offsetof(       \
        struct {      \
            char __a; \
            x    __b; \
        },            \
        __b)
#endif

/*
 * Keywords added in C11.
 */
#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L

#if !__has_extension(c_alignas)
#if (defined(__cplusplus) && __cplusplus >= 201103L) || __has_extension(cxx_alignas)
#define _Alignas(x) alignas(x)
#else
/* XXX: Only emulates _Alignas(constant-expression); not _Alignas(type-name). */
#define _Alignas(x) __aligned(x)
#endif
#endif

#if defined(__cplusplus) && __cplusplus >= 201103L
#define _Alignof(x) alignof(x)
#else
#define _Alignof(x) __alignof(x)
#endif

#if !defined(__cplusplus) && !__has_extension(c_atomic) && !__has_extension(cxx_atomic) && !__GNUC_PREREQ__(4, 7)
/*
 * No native support for _Atomic(). Place object in structure to prevent
 * most forms of direct non-atomic access.
 */
#define _Atomic(T)        \
    struct                \
    {                     \
        T volatile __val; \
    }
#endif

#if !__has_extension(c_static_assert)
#if (defined(__cplusplus) && __cplusplus >= 201103L) || __has_extension(cxx_static_assert)
#define _Static_assert(x, y) static_assert(x, y)
#elif __GNUC_PREREQ__(4, 6) && !defined(__cplusplus)
/* Nothing, gcc 4.6 and higher has _Static_assert built-in */
#elif defined(__COUNTER__)
#define _Static_assert(x, y)   __Static_assert(x, __COUNTER__)
#define __Static_assert(x, y)  ___Static_assert(x, y)
#define ___Static_assert(x, y) typedef char __assert_##y[(x) ? 1 : -1] __unused
#else
#define _Static_assert(x, y) struct __hack
#endif
#endif

#if !__has_extension(c_thread_local)
/*
 * XXX: Some compilers (Clang 3.3, GCC 4.7) falsely announce C++11 mode
 * without actually supporting the thread_local keyword. Don't check for
 * the presence of C++11 when defining _Thread_local.
 */
#if /* (defined(__cplusplus) && __cplusplus >= 201103L) || */ \
    __has_extension(cxx_thread_local)
#define _Thread_local thread_local
#else
#define _Thread_local __thread
#endif
#endif

#endif /* __STDC_VERSION__ || __STDC_VERSION__ < 201112L */

#endif

/* Multiplication: common case */
#define CMUL(NAME,TR,T1,T2)			\
  TR NAME (T1 a, T2 b) {			\
    return a * b;				\
  }

/* Multiplication by conjugate special case */
#define CMULC(NAME,TR,T1)			\
  TR NAME (T1 a) {				\
    return a * ~a;				\
  }

/* Multiplication: squaring special case */
#define CMULS(NAME,TR,T1)			\
  TR NAME (T1 a) {				\
    return a * a;				\
  }

/* Division: common case */
#define CDIV(NAME,TR,T1,T2)			\
  TR NAME (T1 a, T2 b) {			\
    return a / b;				\
  }

/* Division: inversion special case */
#define CDIVI(NAME,TR,T1)			\
  TR NAME (T1 a) {				\
    return 1. / a;				\
  }

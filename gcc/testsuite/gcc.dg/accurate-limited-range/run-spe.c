/* { dg-do run } */
/* { dg-options "-fcx-limited-range -fcx-accurate-limited-range=on -ffp-contract=off -fno-signed-zeros" } */

#include <complex.h>
#include "operations.h"

extern void abort(void);

typedef struct {
  _Complex double x;
  _Complex double z;
} s_cplx ;

static s_cplx const refconj [] = {
  { .x=-0x1.b3c0321088ef7p-48 + 0x1.eb166dc6033cbp-23 * I, .z=0x1.d70785864ec32p-45 + 0x0p+0 * I },
  { .x=0x1.3e1fa74f43797p-395 + 0x1.36a5e78de3542p-379 * I, .z=0x1.78f638517c3adp-758 + 0x0p+0 * I },
  { .x=-0x1.3d84d63d27ae9p+8 + -0x1.3b873e45c453ap+32 * I, .z=0x1.84e61ab26de24p+64 + 0x0p+0 * I },
  { .x=0x1.bc73d91fa0fbep-161 + -0x1.613269d83cb5dp-136 * I, .z=0x1.e74c11d3dba9p-272 + 0x0p+0 * I },
  { .x=-0x1.0e3ec1185efbp-329 + 0x1.0968eeca5f932p-319 * I, .z=0x1.132a7b3663f44p-638 + 0x0p+0 * I },
  { .x=-0x1.4c2a9d30cf13fp-312 + 0x1.80c6562d89a22p-300 * I, .z=0x1.2129cef083746p-599 + 0x0p+0 * I },
  { .x=-0x1.7a6bb3cced88cp-14 + -0x1.a231574180a32p+11 * I, .z=0x1.5592953a36731p+23 + 0x0p+0 * I },
  { .x=0x1.1e0387f0bf886p-504 + -0x1.40374ea8d228cp-500 * I, .z=0x1.91c9dc7cbc7f4p-1000 + 0x0p+0 * I },
  { .x=-0x1.80e2aaabd7003p+76 + 0x1.9c2a317769ee2p+97 * I, .z=0x1.4bcbeb1651227p+195 + 0x0p+0 * I },
  { .x=0x1.08b90b799c2e8p-128 + -0x1.18275cacd39dbp-117 * I, .z=0x1.3296250e65d3dp-234 + 0x0p+0 * I }
} ;

static s_cplx const refinv [] = {
  { .x=-0x1.aebec90993421p-65 + 0x1.cec05d8882827p-65 * I, .z=-0x1.1a84db6327ad9p+63 + -0x1.2f82e5623fbe8p+63 * I },
  { .x=-0x1.1c9d13c00ed3cp-175 + -0x1.e86aed192a697p-176 * I, .z=-0x1.093ed3d1516e6p+174 + 0x1.c72e352e5ac1p+173 * I },
  { .x=0x1.b4da1620356ddp-221 + -0x1.8490d47dbfadep-194 * I, .z=0x1.7b3da9dfa06f2p+166 + 0x1.515294d1f34fcp+193 * I },
  { .x=-0x1.448c4b516e2c4p-234 + -0x1.30f2ebfcb061cp-213 * I, .z=-0x1.c970cbb54bccep+191 + 0x1.add0f61b2d76dp+212 * I },
  { .x=-0x1.63d0f447c2d44p-109 + 0x1.37978c2f810e3p-86 * I, .z=-0x1.e05b1c1dc825fp+62 + -0x1.a4a7157b6359cp+85 * I },
  { .x=-0x1.9032249e7385cp+107 + -0x1.3780110a75dp+99 * I, .z=-0x1.47843f708e53fp-108 + 0x1.fddb9c44025dep-117 * I },
  { .x=0x1.0691dc7cef394p-219 + -0x1.cc2ac606dcc13p-230 * I, .z=0x1.f330590405ab3p+218 + 0x1.b56d58434a373p+208 * I },
  { .x=0x1.40b024c114adfp-349 + -0x1.467c48c8c5bccp-327 * I, .z=0x1.8a55acd1f4f61p+304 + 0x1.9176a6c83c9dbp+326 * I },
  { .x=0x1.81cc9e7b26a57p+5 + -0x1.01abd68fc2ce2p+16 * I, .z=0x1.7ccf8e9b63e05p-27 + 0x1.fcadcdd3999fcp-17 * I },
  { .x=-0x1.97cc1e354681dp-225 + 0x1.a97a54b19c844p-206 * I, .z=-0x1.2741d30978b21p+186 + -0x1.340eef1d25b9ep+205 * I }
} ;

CMULC(cconj, _Complex double, _Complex double);
CDIVI(cinv, _Complex double, _Complex double);

int main(void)
{
  int i;
  int items;

  items = sizeof(refconj)/sizeof(0[refconj]);
  for(i=0; i<items; ++i) {
    if (cconj (refconj[i].x) != refconj[i].z) {
      abort();
    }
  }

  //CINV
  items = sizeof(refinv)/sizeof(0[refinv]);
  for(i=0; i<items; ++i) {
    if (cinv (refinv[i].x) != refinv[i].z) {
      abort();
    }
  }

  return 0;
}

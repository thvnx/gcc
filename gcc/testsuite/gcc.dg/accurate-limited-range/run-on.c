/* { dg-do run } */
/* { dg-options "-fcx-limited-range -fcx-accurate-limited-range=on -ffp-contract=off" } */

#include <complex.h>
#include "operations.h"

extern void abort(void);

typedef struct {
  _Complex double x;
  _Complex double y;
  _Complex double z;
} s_cplx ;

static s_cplx const refmul [] = {
  { .x=0x1.28d6c44ab476ep-107 + -0x1.9530189d6386dp-448 * I, .y=-0x1.34fbe7b328a02p-162 + -0x1.eb4545bba97b2p-503 * I, .z=-0x1.66467b65dec3ep-269 + -0x1.425eaae8dd76fp-612 * I },
  { .x=-0x1.2263c4be4bf14p-447 + -0x1.dec992e10da6cp-560 * I, .y=0x1.4b5b6e0572559p-266 + 0x1.1d46e5ad2b6c7p-153 * I, .z=0x1.3b589715bb153p-714 +  -0x1.43997dd754405p-600 * I },
  { .x=0x1.eddcf8d3d974p+124 + -0x1.f3791bd7d2241p+44 * I, .y=-0x1.d2213fc92eeafp+31 + -0x1.4c55a371cdc42p-48 * I, .z=-0x1.c19e30bd99b15p+156 + -0x1.74cc3d026dba8p+75 * I },
  { .x=0x1.0839eeedadd69p-100 + 0x1.8fad9e6227da7p+25 * I, .y=0x1.71e81eb57a674p-200 + -0x1.5900ed142c108p-74 * I, .z=0x1.0d51364ac0d92p-48 + -0x1.0d54d199aa46ap-176 * I },
  { .x=0x1.f8e31dda2563p-56 + -0x1.fefb0a075a71dp-184 * I, .y=-0x1.526893b79061dp-236 + -0x1.44320f4637dd3p-364 * I, .z=-0x1.4db50e814b9d9p-291 + 0x1.20b01e74eed24p-423 * I },
  { .x=-0x1.49efaf2e384e8p-705 + -0x1.0b03590b9a486p-606 * I, .y=0x1.3ff96cc4ffe9cp-74 + -0x1.ecd980b7fafa7p+22 * I, .z=-0x1.0106a59d2c84ep-583 + -0x1.fcae69a4973acp-681 * I },
  { .x=0x1.02c965ee465dp-515 + -0x1.b069a5e764a8fp-729 * I, .y=0x1.c308ba47a5ee4p-217 + 0x1.3e66928703787p-430 * I, .z=0x1.c7f1a12cb70f1p-732 + -0x1.d8748d06f5373p-948 * I },
  { .x=-0x1.6a77d7ba8e96ap-672 + 0x1.0146f0f833316p+56 * I, .y=0x1.50563646cd3e6p-671 + 0x1.910c589416884p+59 * I, .z=-0x1.930c87cd4a506p+115 + -0x1.e35643ca802c8p-613 * I },
  { .x=0x1.ef89bd0ef879bp-687 + -0x1.dd94ed7b4eeb9p-1021 * I, .y=0x1.5ee4038c6bc4ap-261 + -0x1.30c2d7dd46bdfp+76 * I, .z=-0x1.e3a561d29d6p-945 + -0x1.26f65c5e0683fp-610 * I },
  { .x=-0x1.1e0f62ceba167p-186 + 0x1.cf9f4c1074f21p-734 * I, .y=-0x1.ecead5be6b8b5p-174 + -0x1.e1429775b6778p-720 * I, .z=0x1.1365fd6699b35p-359 + 0x1.3a9975a39ddfbp-906 * I }
} ;

static s_cplx const refsqr [] = {
  { .x=-0x1.aebec90993421p-65 + 0x1.cec05d8882827p-65 * I, .z=-0x1.bed5a267ccd9fp-132 + -0x1.854ffda38775ap-128 * I },
  { .x=-0x1.1c9d13c00ed3cp-175 + -0x1.e86aed192a697p-176 * I, .z=0x1.4ddbbc3449d7ap-352 + 0x1.0f812724d7c84p-349 * I },
  { .x=0x1.b4da1620356ddp-221 + -0x1.8490d47dbfadep-194 * I, .z=-0x1.26e3ab06756f9p-387 + -0x1.4b88d768397fbp-413 * I },
  { .x=-0x1.448c4b516e2c4p-234 + -0x1.30f2ebfcb061cp-213 * I, .z=-0x1.6b41d6fb25c8bp-426 + 0x1.829a913d08a8fp-446 * I },
  { .x=-0x1.63d0f447c2d44p-109 + 0x1.37978c2f810e3p-86 * I, .z=-0x1.7b4190521857p-172 + -0x1.b1157bdb9057ep-194 * I },
  { .x=-0x1.9032249e7385cp+107 + -0x1.3780110a75dp+99 * I, .z=0x1.38cda09c8955dp+215 + 0x1.e6f51e327c214p+207 * I },
  { .x=0x1.0691dc7cef394p-219 + -0x1.cc2ac606dcc13p-230 * I, .z=0x1.0d4ed57e961bfp-438 + -0x1.d7f9f73a84b97p-448 * I },
  { .x=0x1.40b024c114adfp-349 + -0x1.467c48c8c5bccp-327 * I, .z=-0x1.a060c5b5eeb4cp-654 + -0x1.98fbff4cb9828p-675 * I },
  { .x=0x1.81cc9e7b26a57p+5 + -0x1.01abd68fc2ce2p+16 * I, .z=-0x1.035a6f0f58a3ep+32 + -0x1.84516221316a1p+22 * I },
  { .x=-0x1.97cc1e354681dp-225 + 0x1.a97a54b19c844p-206 * I, .z=-0x1.6193b3d5426b7p-411 + -0x1.52e25e2b5f674p-429 * I }
} ;

static s_cplx const refdiv [] = {
  { .x=0x1.e25cb26dac813p-520 + -0x1.329e7c5e8a283p-425 * I, .y=0x1.001784bd5365ap-371 + -0x1.825d10e4559cp-466 * I, .z=0x1.d84eed2298986p-148 + -0x1.328253bb2319dp-54 * I },
  { .x=0x1.e80998ae45754p-282 + 0x1.1e065b03df815p-131 * I, .y=-0x1.e377192c2d862p-234 + -0x1.5a462bd02bfb4p-384 * I, .z=-0x1.db5f727fbf00fp-48 + -0x1.2ee809be6d9abp+102 * I },
  { .x=0x1.7083baf230901p-965 + 0x1.dd323b57b7ef9p-67 * I, .y=0x1.dbb020308ad5dp-55 + 0x1.fefdc4f989582p-1004 * I, .z=0x1.8ca539e56f988p-911 + 0x1.00cfca35e904fp-12 * I },
  { .x=-0x1.8f327ab40d276p-570 + -0x1.c3698d79c6935p-651 * I, .y=-0x1.eed17072cd64cp-452 + 0x1.e7e8df94993c3p-934 * I, .z=0x1.9d0f0ab8c332fp-119 + 0x0p+0 * I },
  { .x=0x1.17945389e046bp-17 + 0x1.b024b85afcb18p-419 * I, .y=-0x1.627a7f5cf0521p+59 + 0x1.eed65b2e85a94p-339 * I, .z=-0x1.93d14cf70f6c9p-77 + -0x1.2d5ca2c8cf534p-474 * I },
  { .x=0x1.d83d6a07bcfa2p-883 + -0x1.7496d4fa18d97p-213 * I, .y=0x1.35ca423707d7fp-138 + -0x1.2385523dec321p-940 * I, .z=0x1.863e36ae87bd3p-745 + -0x1.33e52269c85d6p-75 * I },
  { .x=0x1.5dbc6ef0c88cdp-760 + -0x1.2fa699bb68e15p-857 * I, .y=0x1.fc77af630fd23p-262 + 0x1.9a7e40036bf15p-337 * I, .z=0x1.602a715373bc1p-499 + -0x0p+0 * I },
  { .x=-0x1.cbf1ee6565d62p-957 + -0x1.1d2ad9a956ac2p-986 * I, .y=-0x1.336ec5639ee27p-65 + -0x1.7784b4749492fp-549 * I, .z=0x1.7eff5707e5558p-892 + 0x1.daeb53857e7e5p-922 * I },
  { .x=-0x1.ef1f8da19b925p-462 + 0x1.ec619efd3422dp-863 * I, .y=-0x1.f1f950d727fbap-326 + 0x1.7a2bfa209a355p+75 * I, .z=0x1.8354aee69ac33p-937 + 0x1.4f2b53e495a0fp-537 * I },
  { .x=0x1.4bde0938cb9a7p-663 + 0x1.d89998c6015eap-355 * I, .y=-0x1.e153ba6a73387p-525 + 0x1.832d3be88e666p-216 * I, .z=0x1.387b4abb97e4ap-139 + -0x1.9da9eb8108b41p-447 * I }
} ;

CMUL(cmul, _Complex double, _Complex double, _Complex double);
CMULS(csqr, _Complex double, _Complex double);
CDIV(cdiv, _Complex double, _Complex double, _Complex double);

int main(void)
{
  int i;
  int items;

  // CMUL
  items = sizeof(refmul)/sizeof(0[refmul]);
  for(i=0; i<items; ++i) {
    if (cmul (refmul[i].x, refmul[i].y) != refmul[i].z) {
      abort();
    }
  }

  // CSQR
  items = sizeof(refsqr)/sizeof(0[refsqr]);
  for(i=0; i<items; ++i) {
    if (csqr (refsqr[i].x) != refsqr[i].z) {
      abort();
    }
  }

  //CDIV
  items = sizeof(refdiv)/sizeof(0[refdiv]);
  for(i=0; i<items; ++i) {
    if (cdiv (refdiv[i].x, refdiv[i].y) != refdiv[i].z) {
      abort();
    }
  }

  return 0;
}

/* { dg-do compile } */
/* { dg-options "-fcx-limited-range -fcx-accurate-limited-range=on -ffp-contract=off" } */

#include "operations.h"

CMUL(cmul,_Complex float, _Complex float, _Complex float);
CMULC(cmulc,_Complex float, _Complex float);
CMULS(cmuls,_Complex float, _Complex float);
CDIV(cdiv,_Complex float, _Complex float, _Complex float);
CDIVI(cdivi,_Complex float, _Complex float);

CMUL(cmuld,_Complex double, _Complex double, _Complex double);
CMULC(cmulcd,_Complex double, _Complex double);
CMULS(cmulsd,_Complex double, _Complex double);
CDIV(cdivd,_Complex double, _Complex double, _Complex double);
CDIVI(cdivid,_Complex double, _Complex double);

CMUL(cmull,_Complex long double, _Complex long double, _Complex long double);
CMULC(cmulcl,_Complex long double, _Complex long double);
CMULS(cmulsl,_Complex long double, _Complex long double);
CDIV(cdivl,_Complex long double, _Complex long double, _Complex long double);
CDIVI(cdivil,_Complex long double, _Complex long double);

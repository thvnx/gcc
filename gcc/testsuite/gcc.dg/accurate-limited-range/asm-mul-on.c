/* Verify that at least one fma instruction/call is generated.  */
/* { dg-do compile } */
/* { dg-options "-fcx-limited-range -fcx-accurate-limited-range=on" } */
/* { dg-final { scan-assembler "fma|fmadd|fmsub|fnmsub|fnmadd" } } */

#include "operations.h"

CMUL(cmul,_Complex double, _Complex double, _Complex double);

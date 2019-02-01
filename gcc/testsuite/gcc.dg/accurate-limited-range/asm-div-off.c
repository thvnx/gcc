/* Verify that no fma instruction/call is generated.  */
/* { dg-do compile } */
/* { dg-options "-fcx-limited-range -fcx-accurate-limited-range=off" } */
/* { dg-final { scan-assembler-not "fma|fmadd|fmsub|fnmsub|fnmadd" } } */

#include "operations.h"

CDIV(cdiv,_Complex double, _Complex double, _Complex double);

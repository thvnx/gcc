/* Test to verify that the vec_extract from a vector of
   signed chars remains signed.  */
/* { dg-do run } */
/* { dg-options "-ansi -mcpu=power8 " } */
/* { dg-require-effective-target powerpc_p8vector_ok } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */

#include <altivec.h>
#include <stdio.h>
#include <stdlib.h>

int test1(signed char sc) {
  int sce;

  vector signed char v = vec_splats(sc);
  sce = vec_extract(v,0);

  if (sce != sc)
    abort();
  return 0;
}

int main()
{
  test1 (0xf6);
  test1 (0x76);
  test1 (0x06);
  return 0;
}

/* Test to verify that the vec_extract from a vector of
   signed shorts remains signed.  */
/* { dg-do run } */
/* { dg-options "-ansi -mcpu=power8 " } */
/* { dg-require-effective-target powerpc_p8vector_ok } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */

#include <altivec.h>
#include <stdio.h>
#include <stdlib.h>

int test1(signed short ss) {
  int sse;

  vector signed short v = vec_splats(ss);
  sse = vec_extract(v,0);

  if (sse != ss)
    abort();
  return 0;
}

int main()
{
  test1 (0xf600);
  test1 (0x7600);
  test1 (0x0600);
  return 0;
}

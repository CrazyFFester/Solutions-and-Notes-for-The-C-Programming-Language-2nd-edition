#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  printf("=============================================\n");
  printf(" Ranges of unsigned and signed data types\n");
  printf("=============================================\n\n");

  printf("Signed types:\n");
  printf("---------------------------------------------\n");
  printf("Char\t: %d to %d\n", CHAR_MIN, CHAR_MAX);
  printf("Short\t: %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("Int\t: %d to %d\n", INT_MIN, INT_MAX);
  printf("Long\t: %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("\n");

  printf("Unsigned types:\n");
  printf("---------------------------------------------\n");
  printf("Char\t: 0 to %u\n", UCHAR_MAX);
  printf("Short\t: 0 to %u\n", USHRT_MAX);
  printf("Int\t: 0 to %u\n", UINT_MAX);
  printf("Long\t: 0 to %lu\n", ULONG_MAX);
  printf("\n");

  printf("=============================================\n");
  printf(" Floating-point types range\n");
  printf("=============================================\n\n");

  printf("Float\t\t: %e to %e\n", FLT_MIN, FLT_MAX);
  printf("Double\t\t: %e to %e\n", DBL_MIN, DBL_MAX);
  printf("Long double\t: %e to %e\n", LDBL_MIN, LDBL_MAX);

  return 0;
}

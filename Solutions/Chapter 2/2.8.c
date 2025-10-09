#include <limits.h>
#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
  unsigned int num = 211; // 11010011
  int rotate_by = 3;

  // Expected result after rotating 11010011 right by 3: 01111010 (122)
  unsigned int result = rightrot(num, rotate_by);

  printf("Original: %u (11010011)\n", num);
  printf("Rotated:  %u (01111010)\n", result);

  return 0;
}

/**
 * @brief Rotates an unsigned integer x to the right by n bit positions.
 * @param x The unsigned integer to rotate.
 * @param n The number of positions to rotate right.
 * @return The rotated value of x.
 */
unsigned int rightrot(unsigned int x, int n) {
  // Determine the total number of bits in the type to make the code portable.
  const int WORD_SIZE = sizeof(unsigned int) * CHAR_BIT;

  // Handle cases where n is larger than the word size.
  n = n % WORD_SIZE;

  // 1. Isolate the n rightmost bits that will become the new leftmost bits.
  unsigned int tail_mask = (1 << n) - 1;
  unsigned int tail = x & tail_mask;

  // 2. Shift the main body of the number to the right.
  unsigned int shifted_x = x >> n;

  // 3. Reposition the isolated tail to the far left.
  unsigned int positioned_tail = tail << (WORD_SIZE - n);

  // 4. Combine the shifted body with the repositioned tail.
  return shifted_x | positioned_tail;
}

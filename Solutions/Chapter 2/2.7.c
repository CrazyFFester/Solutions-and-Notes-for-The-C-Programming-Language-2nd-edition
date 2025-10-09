#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);
unsigned int get_field_mask(int p, int n);

int main() {
  // Test case: invert 3 bits starting at position 4.
  unsigned int x = 181; // 10110101
  int p = 4;
  int n = 3;

  // Original segment (bits 4,3,2): 101
  // Expected inverted segment: 010
  // Expected result: 10101001 (169)

  printf("Original: %u (10110101)\n", x);

  unsigned int result = invert(x, p, n);

  printf("Inverted: %u (10101001)\n", result);

  return 0;
}

/**
 * @brief Inverts n bits in x, starting at position p.
 * @param x The original number.
 * @param p The position of the field (from right, 0-indexed).
 * @param n The width of the field in bits.
 * @return The number with the bit-field inverted.
 */
unsigned int invert(unsigned int x, int p, int n) {
  // Create a mask with 1s at the positions to be inverted (e.g., 0011100).
  unsigned int field_mask = get_field_mask(p, n);

  // The XOR (^) operator inverts the bits in x where the mask bit is 1
  // and leaves all other bits unchanged. This is the most efficient way.
  return x ^ field_mask;
}

/**
 * @brief Creates a mask with n ones, starting at position p.
 * @return A mask in the form of ...000111000...
 */
unsigned int get_field_mask(int p, int n) {
  // Create n ones in the least significant bits (e.g., 00000111).
  unsigned int n_ones = (1 << n) - 1;

  // Shift the ones to the correct position.
  int shift_amount = p - n + 1;

  return n_ones << shift_amount;
}

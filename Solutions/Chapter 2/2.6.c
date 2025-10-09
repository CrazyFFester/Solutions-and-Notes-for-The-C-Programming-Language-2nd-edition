#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int create_clearing_mask(int p, int n);
unsigned int prepare_y_bits(int p, int n, unsigned int y);

int main() {
  unsigned int x = 181; // 10110101
  int p = 4;
  int n = 3;
  unsigned int y = 230; // 11100110

  printf("Original x: %u (10110101)\n", x);
  printf("Original y: %u (11100110)\n", y);

  unsigned int result = setbits(x, p, n, y);

  // Expected result: 185 (10111001)
  printf("  Result:   %u (10111001)\n", result);

  return 0;
}

/**
 * @brief Replaces n bits in x, starting from position p, with the rightmost n
 * bits of y.
 * @param x The original number to modify.
 * @param p The starting position (from right, 0-indexed) for the replacement.
 * @param n The number of bits to replace.
 * @param y The source number from which to take the bits.
 * @return The modified number.
 */
unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
  unsigned int clearing_mask = create_clearing_mask(p, n);
  unsigned int cleared_x = x & clearing_mask;
  unsigned int y_segment = prepare_y_bits(p, n, y);

  // Since the target area in cleared_x is all zeros, the OR operation acts as
  // an insertion.
  return cleared_x | y_segment;
}

/**
 * @brief Creates a mask to clear n bits starting at position p.
 * @return A mask with zeros in the target n-bit field and ones everywhere else.
 */
unsigned int create_clearing_mask(int p, int n) {
  // This is a classic trick to generate n ones: `1 << n` creates `10...0`,
  // and subtracting 1 flips all the lower bits to `011...1`.
  unsigned int n_ones = (1 << n) - 1;

  // To position a block of n bits starting at p, its rightmost edge must be
  // at position (p - n + 1). This is the required shift amount.
  int shift_amount = p - n + 1;
  unsigned int positioned_ones = n_ones << shift_amount;

  return ~positioned_ones;
}

/**
 * @brief Extracts the rightmost n bits from y and shifts them to align with
 * position p.
 * @return The bits from y, ready for insertion.
 */
unsigned int prepare_y_bits(int p, int n, unsigned int y) {
  unsigned int extraction_mask = (1 << n) - 1;
  unsigned int extracted_bits = y & extraction_mask;
  int shift_amount = p - n + 1;

  return extracted_bits << shift_amount;
}

///
/// prng32.cxx
///
/// PRNG32 - 32 bit pseudo-random number generator implementation
///

#include "prng32.h"

// PRNG32 constructor: creates a PRNG with default seed
PRNG32::PRNG32() {
  seed_ = 0x0123ABC789456DEF;
};

// PRNG32 constructor: creates a PRNG with user-provided seed
PRNG32::PRNG32(uint64_t seed) {
  seed_ = seed;
};

// PRNG32 'next' function implementation
uint32_t PRNG32::next() {
  seed_ = 997 * seed_;
  uint32_t random32 = (seed_ >> 8) & 0xFFFFFFFF;
  random32 ^= (rand() & 0x000000FF);
  random32 ^= (rand() & 0x000000FF) <<  8;
  random32 ^= (rand() & 0x000000FF) << 16;
  random32 ^= (rand() & 0x000000FF) << 24;
  return random32;
}

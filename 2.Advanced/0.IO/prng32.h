///
/// prng32.h
///
/// PRNG32 - 32 bit pseudo-random number generator interface
///

#pragma once

#include <cstdint>
#include <cstdlib>

class PRNG32 {
public:
  // creates a PRNG with default seed
  PRNG32();

  // creates a PRNG with user-provided seed
  PRNG32(uint64_t seed);

  // returns a pseudo-random 32 bit unsigned integer
  uint32_t next();

private:
  uint64_t seed_;
};

///
/// Hex string to number experiment
///

#include <cstdio>
#include <cstdint>

///
/// Converts a hexadecimal string representation to a uint32_t
/// The hexadecimal string can be prefixed, or not, with "0X" or "0x"
/// Returns the largest uint32_t if the hexadecimal string is not valid
/// Returns 0 is the string is empty
///
uint32_t hexstrtoui32(const char *hexstr) {

  // index used to traverse the hexadecimal string
  int idx = 0;

  // skip the "0X" or "0x" at the beginning of the hex string, if present
  if (hexstr[0] == '0' && (hexstr[1] == 'X' || hexstr[1] == 'x')) {
    idx += 2;
  }

  uint32_t result = 0;

  for (;;) {
    char c = hexstr[idx];
    if (c == 0) {
      break; // this is the ideal happy ending!
    }

    // exploit the positional math, as long as 'c' is a valid digit
    if ('0' <= c && c <= '9') {
      // we have a "decimal digit" [0-9] "hexadecimal digit" :-)
      result = 16 * result + (c - '0');
    } else if ('A' <= c && c <= 'F') {
      // we have an uppercase [A-F] "hexadecimal digit" ;-)
      result = 16 * result + (c - 'A' + 10);
    } else if ('a' <= c && c <= 'f') {
      // we have a lowercase "hexadecimal digit" :O
      result = 16 * result + (c - 'a' + 10);
    } else {
      // bad news: we don't have a valid "hexadecimal digit"
      // the caller "cheated" on us - return the largest uint32_t
      result = 0xffffffff;
      break; // this is the unhappy ending
    }
    ++idx; // ... and keep going
  }

  return result;
}

// Internal tests

const char *hexs[] = {
  "",
  "0",
  "1",
  "64",
  "A0",
  "a0",
  "0x0",
  "0x1",
  "0x10",
  "0x100",
  "0x1000",
  "0x10000",
  "0x100000",
  "0x1000000",
  "0x10000000",
  "0X0BADBEEF",
  "0x0BadBeef",
  "0x0badbeef",
  "0xMALOMALO",
  "0x!N0T!N0T",
  "0xFFFFFFFF",
  "0xffffffff",
  "0x00000043",
  "0x0000002A",
  "0x0043",
  "0x002A",
  "0x43",
  "0x2A"
};

void internal_tests() {
  // number of tests
  const int NT = sizeof(hexs) / sizeof(hexs[0]);

  for (int i = 0; i < NT; ++i) {
    const char *hexstr = hexs[i];
    uint32_t result = hexstrtoui32(hexstr);
    fprintf(stdout, "%12s ==> %12u\n", hexstr, result);
  }
}

// Main program

int main(int argc, const char *argv[]) {
  // Check the number of arguments in the command line
  if (2 < argc) {
    fprintf(stderr, "Usage: %s <hex string>", argv[0]);
    return 404;
  }

  if (argc == 1) {
    internal_tests(); // no arguments provided - run internal test
    return 0;
  }
 
  // argv[1] should be (we hope) a hexadecimal string
  const char *hexstr = argv[1];

  // Convert the hexstr to an unsigned integer
  uint32_t result = hexstrtoui32(hexstr);

  // Print the result
  fprintf(stdout, "%s ==> %u\n", hexstr, result);

  return 0;
}

/*
  alpha_test.h
  
  a small header to assist writing tests

  author: sombrerosheep
  version: 0.0.1
  license: MIT
  last updated: june 8, 2020

  changelog:
  june  8, 2020: initial version
  sept 19, 2020: add this heading.
*/

#ifndef _ALPHA_TEST
#define _ALPHA_TEST

#include <stdio.h>

typedef int ALPHA_BOOL;
#define ALPHA_TRUE 1
#define ALPHA_FALSE 0

static int num_passed = 0;
static int num_failed = 0;

#define TEST_SUITE(name) \
  alpha_test_suite(name);

#define TEST(name) \
  alpha_test(name);

#define ASSERT_EQUAL(actual, expected) \
  if ((actual) == (expected)) \
      alpha_assert_equal_passed(__FILE__, __LINE__, #actual, #expected); \
  else \
    alpha_assert_equal_failed(__FILE__, __LINE__, #actual, #expected)

#define ASSERT_NOT_EQUAL(actual, expected) \
  if ((actual) != (expected)) \
    alpha_assert_not_equal_passed(__FILE__, __LINE__, #actual, #expected); \
  else \
    alpha_assert_not_equal_failed(__FILE__, __LINE__, #actual, #expected)

#define ASSERT(expr) \
  if (expr) \
     alpha_assert_passed(__FILE__, __LINE__, #expr); \
  else \
    alpha_assert_failed(__FILE__, __LINE__, #expr)

#define ASSERT_NOT(expr) \
  if (!(expr)) \
    alpha_assert_not_passed(__FILE__, __LINE__, #expr); \
  else \
    alpha_assert_not_failed(__FILE__, __LINE__, #expr)


void update_counts(ALPHA_BOOL failed) {
  if (failed == ALPHA_TRUE) {
    num_failed++;
  } else {
    num_passed++;
  }
}

void alpha_test_suite(const char *name) {
  printf("Suite::%s\n", name);
}

void alpha_test(const char *name) {
  printf("  Test::%s\n", name);
}

void alpha_assert_not_equal_failed(const char *file, int line, const char *actual, const char *expected) {
  printf("   --> Failed: expected \"%s\" not to equal \"%s\" (%s:%i)\n", actual, expected, file, line);

  update_counts(ALPHA_TRUE);
}

void alpha_assert_not_equal_passed(const char *file, int line, const char *actual, const char *expected) {
  #if ALPHA_PRINT_PASS
  printf("   --> Passed: \"%s\" != \"%s\" (%s:%i)\n", actual, expected, file, line);
  #endif

  update_counts(ALPHA_FALSE);
}

void alpha_assert_equal_failed(const char *file, int line, const char *actual, const char *expected) {
  printf("   --> Failed: expected \"%s\" to equal \"%s\" (%s:%i)\n", actual, expected, file, line);

  update_counts(ALPHA_TRUE);
}

void alpha_assert_equal_passed(const char *file, int line, const char *actual, const char *expected) {
  #if ALPHA_PRINT_PASS
  printf("   --> Passed: \"%s\" == \"%s\" (%s:%i)\n", actual, expected, file, line);
  #endif

  update_counts(ALPHA_FALSE);
}

void alpha_assert_failed(const char *file, int line, const char *assertion) {
  printf("   --> Failed: \"%s\" (%s:%i)\n", assertion, file, line);

  update_counts(ALPHA_TRUE);
}

void alpha_assert_passed(const char *file, int line, const char *assertion) {
  #if ALPHA_PRINT_PASS
  printf("   --> Passed: \"%s\" (%s:%i)\n", assertion, file, line);
  #endif

  update_counts(ALPHA_FALSE);
}

void alpha_assert_not_failed(const char *file, int line, const char *assertion) {
  printf("   --> Failed: \"%s\" (%s:%i)\n", assertion, file, line);

  update_counts(ALPHA_TRUE);
}

void alpha_assert_not_passed(const char *file, int line, const char *assertion) {
  #if ALPHA_PRINT_PASS
  printf("   --> Passed: \"%s\" (%s:%i)\n", assertion, file, line);
  #endif

  update_counts(ALPHA_FALSE);
}

void print_report() {
  printf("\n===========================\n");
  printf("Tests complete.\n");
  printf("  %d of %d Tests passed\n", num_passed, num_passed + num_failed);
  printf("===========================\n");
}

#endif // _ALPHA_TEST
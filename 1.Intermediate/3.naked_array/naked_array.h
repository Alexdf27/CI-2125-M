///
/// naked_array.h
///

#pragma once

// Creates an array of integer numbers
// The array is initialized with zeroes
// Parameters:
// int n: specifies the size of the array
int *int_array(int n);

// Creates an array of integer numbers
// The array is initialized with random integer values
// Parameters:
// int n: specifies the size of the array
// int lo: specifies the (included) lowest random value
// int hi: specifies the (included) highest random value
//         each element k in the array satisfies lo <= k <= hi
int *random_int_array(int n, int lo, int hi);

// Shows the elements in an array of integer numbers
// Parameters:
// int n: size of the array
// int a[]: the array
void show_int_array(int n, int a[]);

// Computes the sum of the elements in an array of integers
// Parameters:
// int n: size of the array
// int a[]: the array of integer values
int sum_int_array(int n, int a[]);

// Finds the position (index) of the minimum element in an array range
// Parameters:
// int lb: lower bound (index) of the range (included  in  the range)
// int ub: upper bound (index) of the range (included  in  the range)
// int a[]: the array of integer values
//
// Preconditions: the function assumes 0 <= lb < ub <= N,
// where N is the number of elements in the array
int min_int_array(int lb, int ub, int a[]);

// Sorts an array of integers in ascending order
// Parameters:
// int n: size of the array
// int a[]: the array
void sort_int_array(int n, int a[]);

// Creates an array of double precision numbers
// The array is initialized with zeroes
// Parameters:
// int n: specifies the size of the array
double *double_array(int n);

// Creates an array of double precision numbers
// The array is initialized with uniformly distributed random numbers
// each element x in the array satisfies 0 < x < 1
// Parameters:
// int n: specifies the size of the array
double *random_uniform_array(int n);

// Creates an array of double precision numbers
// The array is initialized with normally distributed random numbers
// Parameters:
// int n: specifies the size of the array
double *random_normal_array(int n);

// Shows the elements in an array of doubles
// Parameters:
// int n: size of the array
// double a[]: the array
void show_double_array(int n, double a[]);

// Computes the sum of the elements in an array of doubles
// int n: size of the array
// double a[]: the array of double values
double sum_double_array(int n, double a[]);

// Computes the variance of the elements in an array of doubles
// Parameters:
// int n: size of the array
// double a[]: the array of double values
double var_double_array(int n, double a[]);

// Finds the position (index) of the minimum element in an array range
// Parameters:
// int lb: lower bound (index) of the range (included  in  the range)
// int ub: upper bound (index) of the range (included  in  the range)
// double a[]: the array of double values
//
// Preconditions: the function assumes 0 <= lb < ub <= N,
// where N is the number of elements in the array
int min_double_array(int lb, int ub, double a[]);

// Sorts an array of doubles in ascending order
// Parameters:
// int n: size of the array
// double a[]: the array of double values
void sort_double_array(int n, double a[]);

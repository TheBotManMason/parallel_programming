/* Maximum kernels for int and double arrays.
 * The _if variants use form A; the _ternary variants use form B.
 */
#include <float.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Find the maximum value in an integer array. Type A.
 * @param a The input array.
 * @param n The number of elements in the array.
 * @return The maximum value in the array.
 */
int array_max_int_if(const int *a, size_t n)
{
	int m = INT_MIN;

	for (size_t i = 0; i < n; ++i) {
		/* A */
		if (a[i] > m)
			m = a[i];
	}
	return m;
}

/**
 * Find the maximum value in an integer array. Type B.
 * @param a The input array.
 * @param n The number of elements in the array.
 * @return The maximum value in the array.
 */
int array_max_int_ternary(const int *a, size_t n)
{
	int m = INT_MIN;

	for (size_t i = 0; i < n; ++i) {
		/* B */
		m = (a[i] > m) ? a[i] : m;
	}
	return m;
}

/**
 * Find the maximum value in a double array. Type A.
 * @param a The input array.
 * @param n The number of elements in the array.
 * @return The maximum value in the array.
 */
double array_max_double_if(const double *a, size_t n)
{
	double m = -DBL_MAX;

	for (size_t i = 0; i < n; ++i) {
		/* A */
		if (a[i] > m)
			m = a[i];
	}
	return m;
}

/**
 * Find the maximum value in a double array. Type B.
 * @param a The input array.
 * @param n The number of elements in the array.
 * @return The maximum value in the array.
 */
double array_max_double_ternary(const double *a, size_t n)
{
	double m = -DBL_MAX;

	for (size_t i = 0; i < n; ++i) {
		/* B */
		m = (a[i] > m) ? a[i] : m;
	}
	return m;
}

int main(void)
{
	int finder;
	int order;
	size_t n;

	printf("Choose a maximum finder:\n");
	printf("1. Integer (if)\n2. Integer (ternary)\n");
	printf("3. Double (if)\n4. Double (ternary)\n> ");
	if (scanf("%d", &finder) != 1 || finder < 1 || finder > 4) {
		fprintf(stderr, "Invalid maximum finder.\n");
		return EXIT_FAILURE;
	}

	printf("Enter the array size: ");
	if (scanf("%zu", &n) != 1 || n == 0) {
		fprintf(stderr, "Invalid array size.\n");
		return EXIT_FAILURE;
	}

	printf("Choose the array order:\n");
	printf("1. Sorted\n2. Reverse sorted\n3. Random\n> ");
	if (scanf("%d", &order) != 1 || order < 1 || order > 3) {
		fprintf(stderr, "Invalid array order.\n");
		return EXIT_FAILURE;
	}

	srand((unsigned)time(NULL));

	if (finder <= 2) {
		int *a = malloc(n * sizeof(*a));
		if (a == NULL) {
			fprintf(stderr, "Unable to allocate the array.\n");
			return EXIT_FAILURE;
		}
		for (size_t i = 0; i < n; ++i) {
			size_t index = order == 2 ? n - i - 1 : i;
			a[index] = order == 3 ? rand() : (int)i;
		}
		int maximum = finder == 1 ? array_max_int_if(a, n)
						 : array_max_int_ternary(a, n);
		printf("Maximum: %d\n", maximum);
		free(a);
	} else {
		double *a = malloc(n * sizeof(*a));
		if (a == NULL) {
			fprintf(stderr, "Unable to allocate the array.\n");
			return EXIT_FAILURE;
		}
		for (size_t i = 0; i < n; ++i) {
			size_t index = order == 2 ? n - i - 1 : i;
			a[index] = order == 3 ? (double)rand() / RAND_MAX : (double)i;
		}
		double maximum = finder == 3 ? array_max_double_if(a, n)
							 : array_max_double_ternary(a, n);
		printf("Maximum: %f\n", maximum);
		free(a);
	}

	return EXIT_SUCCESS;
}




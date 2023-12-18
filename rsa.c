#include <stdio.h>

/**
 * is_prime - Check if a number is prime.
 * @num: The number to check.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int is_prime(long num) {
    if (num < 2) {
        return 0; /* Not prime */
    }
    for (long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; /* Not prime */
        }
    }
    return 1; /* Prime */
}

/**
 * factorize - Factorize an RSA number into two prime numbers.
 * @num: The RSA number to factorize.
 */
void factorize(long num) {
    for (long i = 2; i <= num / 2; i++) {
        if (is_prime(i) && is_prime(num / i)) {
            printf("%ld=%ld*%ld\n", num, i, num / i);
            return;
        }
    }
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    long num;
    if (fscanf(file, "%ld", &num) != 1) {
        fprintf(stderr, "Error reading number from file\n");
        fclose(file);
        return 1;
    }

    factorize(num);

    fclose(file);
    return 0;
}


#include <stdio.h>

/**
 * isPrime - Check if a number is prime.
 * @num: The number to check.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int isPrime(int num) {
    if (num < 2) {
        return 0; /* Not prime */
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; /* Not prime */
        }
    }
    return 1; /* Prime */
}

/**
 * factorize - Factorize a number into two smaller numbers.
 * @num: The number to factorize.
 */
void factorize(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num / i)) {
            printf("%d=%d*%d\n", num, i, num / i);
            return;
        }
    }
    printf("%d=%d*%d\n", num, num, 1);
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

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        factorize(num);
    }

    fclose(file);
    return 0;
}


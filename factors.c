#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num < 2) {
        return 0; // Not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}

// Function to factorize a number
void factorize(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num / i)) {
            printf("%d=%d*%d\n", num, i, num / i);
            return;
        }
    }
    printf("%d=%d*%d\n", num, num, 1);
}

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


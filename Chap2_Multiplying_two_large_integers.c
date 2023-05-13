#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int resultSize = len1 + len2;
    int* result = (int*)calloc(resultSize, sizeof(int));

    // Perform the multiplication
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + product;

            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    // Convert the result array to a string
    char* finalResult = (char*)malloc((resultSize + 1) * sizeof(char));
    int index = 0;
    int leadingZeros = 0;
    
    // Skip leading zeros in the result
    while (index < resultSize && result[index] == 0) {
        leadingZeros++;
        index++;
    }

    // Copy the remaining digits to the final result
    for (int i = index; i < resultSize; i++) {
        finalResult[i - index] = result[i] + '0';
    }
    finalResult[resultSize - index] = '\0';

    // Handle the case when the result is zero
    if (leadingZeros == resultSize) {
        finalResult[0] = '0';
        finalResult[1] = '\0';
    }

    free(result);

    return finalResult;
}

int main() {
    char* num1 = "123456789";
    char* num2 = "987654321";
    char* result = multiply(num1, num2);

    printf("Multiplication Result: %s\n", result);

    free(result);

    return 0;
}

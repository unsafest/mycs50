#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNumber;


    // Promt user for number
    do {
       cardNumber = get_long("Number: ");
    } while (cardNumber < 0);

    long temp = cardNumber;
    int sum1, sum2;

    // Luhn's algorithm
    while (temp > 0) {
        int secondLast = ((temp / 10) % 10) * 2;                // Multiply every other digit by 2, starting with the number’s second-to-last digit
        sum1 = sum1 + (secondLast / 10) + (secondLast % 10);    // Add those products’ digits together
        temp = temp / 100;                                      // Devide by 100, moving 2 decimals, until reaching 0 and exiting the loop
    }
    temp = cardNumber;     // Reset cardNumber in temp
    while (temp > 0) {
        int lastDigit = temp % 10;  // Get last number
        sum2 = sum2 + lastDigit;    // Add last numbers together
        temp = temp / 100;          // Devide by 100, moving 2 decimals, until 0, then exiting the loop
    }
    // Add the sum to the sum of the digits that weren’t multiplied by 2
    int luhnSum = sum1 + sum2;


    // Find prompted number's length
    temp = cardNumber;
    int length = 0;

    while (temp != 0) {
        temp = temp / 10;
        length++;
    }
    // Find first number
    long first = cardNumber;
    while (first >= 10) {
        first /= 10;
    }
    // Find first 2 number
    long firstTwo = cardNumber;
    while (firstTwo >= 100) {
        firstTwo /= 10;
    }


    // Checksum & card number type check
    if ((luhnSum % 10) == 0) {
        if (first == 4 && (length == 13 || length == 16)) {
            printf("VISA\n");
        }
        else if (length == 15 && (firstTwo == 34 || firstTwo == 37)) {
            printf("AMEX\n");
        }
        else if (length == 16 && (firstTwo > 50 && firstTwo < 56)) {
            printf("MASTERCARD\n");
        }
        else {
            printf("INVALID\n");
        }

    } else {
        printf("INVALID\n");
    }
}
#include <stdio.h>
#include <cs50.h>

int main()
{
    long long card_number;
    int total;
    do
    {
        card_number = get_long_long("Enter your credit card number (without dash)");
    }
    while(card_number < 0);
    
    long int temp = card_number;
    int multiply_total = 0, not_multiplied = 0, digit_number = 0;
    while(temp > 0)
    {
        not_multiplied += (temp % 10);
        digit_number++;
        temp = temp / 10;
        if(2 * (temp % 10) >= 10)
        {
            multiply_total += ((2 * (temp % 10)) % 10) + ((2 * (temp % 10)) / 10);
        }
        else
        {
            multiply_total += 2 * (temp % 10);
        }
        if(temp > 0)
        {
            digit_number++;
        }
        temp = temp / 10;
    }
    total = not_multiplied + multiply_total;

    if(card_number >= 5100000000000000 && card_number < 5600000000000000 && total % 10 == 0 && digit_number == 16)
    {
        printf("MASTERCARD\n");
    }
    else if(((card_number >= 340000000000000 && card_number < 350000000000000) || (card_number >= 370000000000000
    && card_number < 380000000000000)) && (total % 10 == 0) && digit_number == 15)
    {
         printf("AMEX\n");
    }
    else if(((card_number >= 4000000000000000 && card_number < 5000000000000000)
    || (card_number >= 400000000000000 && card_number < 500000000000000) ||
    (card_number >= 40000000000000 && card_number < 50000000000000) || 
    (card_number >= 4000000000000 && card_number < 5000000000000)) && (total % 10 == 0)
    && (digit_number <= 16 || digit_number >= 13))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    } 
}


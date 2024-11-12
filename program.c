// Perfect Exponentiality Test

#include <stdio.h>
#include <math.h>

int find_binary_logarithm(int number)
{
    int binary_logarithm = 1;
    
    while (number >>= 1) binary_logarithm++;
    
    return binary_logarithm;
}

int exponentiate(int base, int index)
{
    if (base == 0) return 0;
    if (index == 0) return 1;
    if (index == 1) return base;

    int power = 1;
    
    while (index > 0)
    {
        if (index & 1) power *= base;
        
        base *= base;
        index >>= 1;
    }
    
    return power;    
}

int test_perfect_exponentiality(int perfect_power_candidate)
{
    for (int base = 2; base <= perfect_power_candidate; base++)
    {
        for (int index = 2; index <= find_binary_logarithm(perfect_power_candidate); index++)
        {
            int power = exponentiate(base, index);
            
            if (power > perfect_power_candidate) break;
            else if (power == perfect_power_candidate) return 1;
        }
    }
    
    return 0;
}

int main()
{
    int perfect_power_candidate;

    for (;;)
    {    
        printf("Enter a perfect power candidate to test perfect exponentiality: ");
        
        // integer input validation
        // https://jackstromberg.com/2013/02/how-to-validate-numeric-integer-input-in-c/
        
        int input, status, buffer;

    	status = scanf("%d", & input);
    	
    	while (status != 1)
    	{
            while ((buffer = getchar()) != EOF && buffer != '\n');
            
            printf("Invalid input.");
            printf("\n\n");
            printf("Enter a perfect power candidate to test for perfect exponentiality: ");
            
            status = scanf("%d", & input);
    	}
    
    	perfect_power_candidate = input;
    	
    	if (test_perfect_exponentiality(perfect_power_candidate)) printf("%d is a perfect power.", perfect_power_candidate);
        else printf("%d is not a perfect power.", perfect_power_candidate);
        
        printf("\n\n");
    }
}

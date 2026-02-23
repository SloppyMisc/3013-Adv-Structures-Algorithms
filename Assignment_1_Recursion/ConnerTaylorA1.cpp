#include <iostream>
using namespace std;

/*
    Function: Product
    Definition: Recursively calculates the product of all even integers from 1 to n1.
    Only even numbers are multiplied. Odd numbers are skipped.
*/
long long Product(long long n1)
{
    // Base case: stop when 1 or below
    if (n1 <= 1)
        return 1;

    // If n1 is odd, ignore it
    if (n1 % 2 == 1)
        return Product(n1 - 1);

    // Multiply even number and call the function
    return n1 * Product(n1 - 2);
}

/*
    Function: BaseExponent
    Definition: Recursively calculates base raised to exponent (base^exponent)
*/
long double BaseExponent(long double base, long long exponent)
{
    // Base case: stop when exponent = 0
    if (exponent == 0)
        return 1;

    // handles if the exponent is negative
    if (exponent < 0)
        return 1 / BaseExponent(base, -exponent);

    // Multiply base by the recursive call
    return base * BaseExponent(base, exponent - 1);
}

/*
    Function: Summation
    Definition: Recursively computes the sum of all odd integers from 1 to n1.
*/
long long Summation(long long n1)
{
    // Base Case: stop when n1 is less than or equal to 0.
    if (n1 <= 0)
        return 0;

    // skips if even
    if (n1 % 2 == 0)
        return Summation(n1 - 1);

    // Sums up n1 with the recursive call
    return n1 + Summation(n1 - 2);
}

int main()
{
    long long n1;
    long double base;
    long long exponent;

    // -------- PRODUCT --------
    do {
        cout << "Enter a positive integer n1 greater than 0 to compute the PRODUCT of all EVEN numbers from 1 to n1: ";
        cin >> n1;
    } while (n1 <= 0);

    cout << "\nThe product of all even integers between 1 and " << n1 << " is: " << Product(n1) << endl;

    // -------- BASE EXPONENT --------
    cout << "\nEnter the base value: ";
    cin >> base;

    cout << "Enter the exponent value: ";
    cin >> exponent;

    cout << "\nThe value of " << base << "^" << exponent << " is: " << BaseExponent(base, exponent) << endl;


    // -------- SUMMATION --------
    do {
        cout << "\nEnter a positive integer n1 greater than 0 to compute the SUM of all ODD numbers from 1 to n1: ";
        cin >> n1;
    } while (n1 <= 0);

    cout << "\nThe summation of all odd integers between 1 and " << n1 << " is: " << Summation(n1) << endl;

    return 0;
}
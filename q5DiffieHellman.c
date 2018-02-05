/* This program calculates the Key for two persons using the Diffie-Hellman Key exchange algorithm */

#include<stdio.h>
#include<math.h>

// Power function to return value of a ^ b mod P

long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
        return a;

    else
        return (((long long int)pow(a, b)) % P);
}

//Driver program
int main()
{
        long long int P, G, x, a, y, b, ka, kb;

        // Both the persons will be agreed upon the public keys G and P

        printf("Enter the public keys:\nThe value of P = ");
        scanf("%lld",&P); // A prime number P is taken

        printf("The value of G = ");
        scanf("%lld",&G);  // A primitve root for P, G is taken

        // Person A will choose the private key a
        printf("The private key a for Person A = "); // a is the chosen private key
        scanf("%lld",&a);

        // Person B will choose the private key b
        printf("The private key b for Person B = "); // b is the chosen private key
        scanf("%lld",&b);

        x = power(G, a, P); // gets the generated key x
        y = power(G, b, P); // gets the generated key y

        // Generating the secret key after the exchange of keys

        ka = power(y, a, P); // Secret key for Person A
        kb = power(x, b, P); // Secret key for Person B

        printf("Secret key for the Person A is : %lld\n", ka);
        printf("Secret Key for the Person B is : %lld\n", kb);

        printf("\nCommmon Secret key : %lld\n\n", ka);
        return 0;
}

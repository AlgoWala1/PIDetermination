#include<math.h>
#include<stdio.h>
#include<conio.h>
#define Precision 40
#define Half 0.5
// A program for the numeric calculation of the value of PI upto ten or so decimal places using Newton's Method
//Take value of the power of 1/2 and return its integrated term's value
double Integral(int power);
double Integral(int power)
{
    return pow(Half,power+1)/(power+1);
}
double fac(int num)
{
    if(num!=1)
    {
        return num*fac(num-1);
    }
    return 1.0;
}
//Returns the sum of the Binomial series to void main
double Summation();
double Summation()
{
    double sum=Half;//the zeroeth term in summation that is 1/2
    double prod;
    int j;
    for(int i = 0;i<Precision;i++)//The term, for eg. x^2/6 is first term (i = 0)
    {
        prod = Half;//Start with 1/2 in Binomial coefficients
        for(j = 1;j<=i;j++)
        {
            prod *= Half - (double)j;//To attain n(n-1)(n-2).... so on for respective term
        }
        prod = prod/fac(i+1);

        if(i%2==0){sum -= Integral(2*i+2) * prod ;}
        else{ sum += Integral(2*i+2) * prod;}
    }
    return sum;
}

void main()
{
    double PI;
    PI = 12 * (Summation() - sqrt(3)/8);
    printf("The value of PI is %Lf",PI);
    getche();
}

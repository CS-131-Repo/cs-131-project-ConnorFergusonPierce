#include <iostream>
#include <math.h>
using namespace std;

/*
Example input (How many hashes do we need to reach 0.01% (10^-2) to have a collision using 256bit Hash?)
-2 256
Running Birthday Attack...
4.82442e+37
Running Birthday Estimate...
4.81232e+37

Birthday Attack uses the full formula to determine the answer,
but computational limitations still make the answer only an estimate.

Birthday Estimate only uses an estimation, but has a similar degree of
error due to the aforementioned limitations.

This is a good example of how it can be challenging to interact with 
very large or small numbers while coding.

*/

void BirthdayAttack(long, long);
/*
BirthdayAttack(p, H)
Answers n = (p, H),
10^p is our desired probability
2^H is the number of possible hashes
Should give a relatively accurate approximation of n = sqrt(2H * ln(1/p-1))
*/

void BirthdayEstimate(long, long);
/*
BirthdayEstimate(p, m)
Answers n aprox= sqrt(2*(2^m)*(10^p))
Can give much faster approximations compared to BirthdayAttack
*/

int main()
{
    long input1, input2;
    cin >> input1 >> input2;
    
    BirthdayAttack(input1, input2);
    BirthdayEstimate(input1, input2);
}

void BirthdayAttack(long p, long H)
{
    cout << "Running Birthday Attack..." << endl;
    cout << sqrt(2.0 * pow(2, H) * -log1p(-pow(10, p))) << endl;
}

void BirthdayEstimate(long p, long m)
{
    cout << "Running Birthday Estimate..." << endl;
    cout << sqrt(2*pow(2, m)*pow(10, p)) << endl;
}

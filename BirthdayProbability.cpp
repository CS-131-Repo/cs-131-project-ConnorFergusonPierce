#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void SimpleBirthdayAttack(int n, int k);
/*
Answers the classic Birthday Attack question,
looking for the percent chance of a collision
between n possibilities and k objects.

Example input (What is the chance that two or more people have the same birthday out of 10 people?)
365 10
There is a 11.6948% chance of collision.

Example input (What is the chance that two or more people have the same birthday out of 23 people?)
365 23
There is a 50.7297% chance of collision.

Example input (What is the chance that two or more people have the same birthday out of 70 people?)
365 70
There is a 99.916% chance of collision.

Example input (If there 180 pigeonholes, what is the probability two pigeons are in the same hole out of 11 pigeons?)
180 11
There is a 26.7781% chance of collision.

Example input (If there 180 pigeonholes, what is the probability two pigeons are in the same hole out of 40 pigeons?)
180 40
There is a 99.0817% chance of collision.
*/

int main()
{
    int input1, input2;
    cin >> input1 >> input2;
    
    SimpleBirthdayAttack(input1, input2);
}

void SimpleBirthdayAttack(int n, int k)
{
    double count = n;
    double answer = 1;
    
    for(int i = 0; i < k; i++)
    {
        answer = answer * count;
        count--;
    }
    
    cout << "There is a " << (1 - (answer / pow(n, k)))*100 << '%' << " chance of collision." << endl;
}
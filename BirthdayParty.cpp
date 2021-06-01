#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
using namespace std;

void BirthdayParty (int n);
/*
Throws a party with n people attending (up to 100 people)
Each has a randomly selected birthday shown on the screen
If there are any matching birthdays the function tells you
*/

double SimpleBirthdayAttack(int n, int k);

int main()
{
    int n;
    cin >> n;
    BirthdayParty(n);
}

void BirthdayParty (int n)
{
    srand(time(NULL));
    int party[n];
    int duplicates[n/2];
    int temp;
    
    //Fills birthday array with random birthdays
    for (int i = 0; i < n; i++)
    {
        party[i] = rand() % 365 + 1;
        cout << endl << "Person " << i+1 << "'s birthday is " << party[i] << ".";
    }

    cout << endl << endl;
    
    //Sorts birthday array
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(party[i] > party[j])
            {
                temp = party[i];
                party[i] = party[j];
                party[j] = temp;
            }
        }
    }
    
    //Finds birthday collisions
    cout << "Duplicate birthdays are: ";
    temp = 0;
    for(int i = 0; i < n; i++)
    {
        if(party[i] == party[i+1]) 
        {
            duplicates[temp++] = party[i];
            cout << party[i] << " ";
            while(party[i] == party[i + 1]) i++;
        }
    }
    
    cout << endl << endl << "The probability of a collision was " << SimpleBirthdayAttack(365, n) << "." << endl;
}

double SimpleBirthdayAttack(int n, int k)
{
    double count = n;
    double answer = 1;
    
    for(int i = 0; i < k; i++)
    {
        answer = answer * count;
        count--;
    }
    
    return (1 - (answer / pow(n, k)))*100;
}

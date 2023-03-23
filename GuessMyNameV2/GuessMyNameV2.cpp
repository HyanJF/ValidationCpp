#include <iostream>
#include<cstdlib> //Trabaja con números random
using namespace std;
int AskNumber(string question, int high, int low = 1);
int main()
{

    srand(static_cast<unsigned int>(time(0)));
    //srand(time(NULL));
    int randomNumber = rand();
    int secretNumber = (randomNumber % 100) + 1;
    int guess;
    int tries = 0;
    int veryClose;

    cout << "GUESS MY NUMBER" << endl;
    cout << "Adivina el número en el menor número de intentos posible." << endl;

    //Depurar
    cout << secretNumber;
    do
    {
        guess = AskNumber("\nAdivina un numero", 300);
        tries++;

        veryClose = secretNumber - guess;

        if (veryClose <= 5 && veryClose >= -5 && veryClose != 0)
        {
            cout << "Muy cerca!!\n";
        }
        if (guess > secretNumber) {
            cout << "Muy Alto\n\n";
        }
        else if (guess < secretNumber) {
            cout << "Muy Bajo\n\n";
        }
        else {
            cout << "Excelente lo hiciste en -- " << tries << "-- intentos";

        }
    } while (guess != secretNumber);
}

int AskNumber(string question, int high, int low) {
    int Number = 0;

    do {
        cout << question << "entre " << low << " y " << high << endl;
        cin >> Number;

    } while (Number > high || Number < low);

    return Number;
}
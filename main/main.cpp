/************************
* File: main.cpp
* Calculator program
* By: Diego Estrada
************************/

#include <iostream>
using namespace std;

/****************************
* Main
* Prints the results 
****************************/
int main()
{

   // Welcome message.
   cout << "Welcome to the one and only calculator \n" << endl;
   
   // Menu
   cout << "1. Addition" << endl;
   cout << "2. Subtraction" << endl;
   cout << "3. Multiplication" << endl;
   cout << "4. Division" << endl;
   cout << "5. Modulus" << endl;
   cout << "6. Exponentiation" << endl;
   cout << "7. Square Root" << endl;
   cout << "8. Cube Root" << endl;
   cout << "9. Factorial \n" << endl;
   
   // User input
   cout << "What do you want to work on today? " << endl;
   int choice;
   cin >> choice;

	return 0;
}
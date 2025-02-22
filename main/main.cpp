#include <iostream>   // For input/output
#include <cmath>      // For mathematical functions
#include <vector>     // For STL vector
#include <fstream>    // For file handling
#include <string>     // For getline() and to_string()
#include <limits>     // For numeric_limits

using namespace std;

// Helper function to format a double value
// If the value is nearly an integer, it returns an integer string.
// Otherwise, it returns the double as a string.
string formatResult(double value) {
   if (fabs(value - round(value)) < 1e-9) {
      return to_string((int)round(value));
   }
   return to_string(value);
}

// Calculator class to store history
class Calculator {
private:
   vector<string> history;
public:
   void addToHistory(const string& entry) {
      history.push_back(entry);
   }
   void saveHistory() {
      ofstream file("history.txt");
      if (file.is_open()) {
         for (const auto& entry : history) {
            file << entry << endl;
         }
         file.close();
      }
      else {
         cout << "Error: Unable to save history to file!" << endl;
      }
   }
   void loadHistory() {
      ifstream file("history.txt");
      if (file.is_open()) {
         string line;
         while (getline(file, line)) {
            history.push_back(line);
         }
         file.close();
      }
      else {
         cout << "No previous history found." << endl;
      }
   }
   void printHistory() {
      if (history.empty()) {
         cout << "No calculations yet." << endl;
         return;
      }
      cout << "Calculation History:" << endl;
      for (const auto& entry : history) {
         cout << entry << endl;
      }
   }
};

// Function to calculate factorial
unsigned long long factorial(int n) {
   if (n < 0) return 0; // Factorial is undefined for negative numbers
   unsigned long long result = 1;
   for (int i = 1; i <= n; ++i) {
      result *= i;
   }
   return result;
}

/****************************
* Main
* Prints the results
****************************/
int main()
{
   Calculator calc;
   calc.loadHistory(); // Load previous history

   // Welcome message.
   cout << "Welcome to the one and only calculator!\n" << endl;

   while (true) {
      // Menu
      cout << "1. Addition" << endl;
      cout << "2. Subtraction" << endl;
      cout << "3. Multiplication" << endl;
      cout << "4. Division" << endl;
      cout << "5. Modulus" << endl;
      cout << "6. Exponentiation" << endl;
      cout << "7. Square Root" << endl;
      cout << "8. Cube Root" << endl;
      cout << "9. Factorial" << endl;
      cout << "10. View History" << endl;
      cout << "11. Exit\n" << endl;

      // User input
      cout << "What do you want to work on today? " << endl;
      int choice;
      cin >> choice;

      // Check if the input failed
      if (cin.fail()) {
         cin.clear(); // Clear error flags
         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
         cout << "Invalid input! Please enter a number between 1 and 11.\n" << endl;
         continue;
      }

      if (choice == 11) {
         calc.saveHistory(); // Save history before exiting
         cout << "Goodbye!" << endl;
         break;
      }

      double num1, num2;
      int intNum1;
      string result;

      switch (choice) {
      case 1: // Addition
      {
         cout << "Enter two numbers: ";
         cin >> num1 >> num2;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter valid numbers.\n" << endl;
            continue;
         }
         double sum = num1 + num2;
         result = "Result: " + formatResult(sum);
         break;
      }
      case 2: // Subtraction
      {
         cout << "Enter two numbers (minuend and subtrahend): ";
         cin >> num1 >> num2;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter valid numbers.\n" << endl;
            continue;
         }
         double diff = num1 - num2;
         result = "Result: " + formatResult(diff);
         break;
      }
      case 3: // Multiplication
      {
         cout << "Enter two numbers: ";
         cin >> num1 >> num2;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter valid numbers.\n" << endl;
            continue;
         }
         double prod = num1 * num2;
         result = "Result: " + formatResult(prod);
         break;
      }
      case 4: // Division
      {
         cout << "Enter two numbers (dividend and divisor): ";
         cin >> num1 >> num2;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter valid numbers.\n" << endl;
            continue;
         }
         if (num2 != 0) {
            double quot = num1 / num2;
            result = "Result: " + formatResult(quot);
         }
         else {
            result = "Error: Division by zero!";
         }
         break;
      }
      case 5: // Modulus
      {
         cout << "Enter two numbers (dividend and divisor): ";
         cin >> num1 >> num2;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter valid numbers.\n" << endl;
            continue;
         }
         if (num2 != 0) {
            double modResult = fmod(num1, num2);
            result = "Result: " + formatResult(modResult);
         }
         else {
            result = "Error: Modulus by zero!";
         }
         break;
      }
      case 6: // Exponentiation
      {
         cout << "Enter base and exponent: ";
         cin >> num1 >> num2;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter valid numbers.\n" << endl;
            continue;
         }
         double power = pow(num1, num2);
         result = "Result: " + formatResult(power);
         break;
      }
      case 7: // Square Root
      {
         cout << "Enter a number: ";
         cin >> num1;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n" << endl;
            continue;
         }
         if (num1 >= 0) {
            double sqrtVal = sqrt(num1);
            result = "Result: " + formatResult(sqrtVal);
         }
         else {
            result = "Error: Cannot take the square root of a negative number!";
         }
         break;
      }
      case 8: // Cube Root
      {
         cout << "Enter a number: ";
         cin >> num1;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n" << endl;
            continue;
         }
         double cbrtVal = cbrt(num1);
         result = "Result: " + formatResult(cbrtVal);
         break;
      }
      case 9: // Factorial
      {
         cout << "Enter a non-negative integer: ";
         cin >> intNum1;
         if (cin.fail() || intNum1 < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a non-negative integer.\n" << endl;
            continue;
         }
         result = "Result: " + to_string(factorial(intNum1));
         break;
      }
      case 10: // View History
         calc.printHistory(); // Display history
         cout << endl;
         continue; // Skip adding to history
      default:
         cout << "Invalid choice! Please select a number between 1 and 11.\n" << endl;
         continue;
      }

      cout << result << "\n" << endl;
      calc.addToHistory(result); // Save result to history
      // Clear input buffer after each operation
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }

   return 0;
}

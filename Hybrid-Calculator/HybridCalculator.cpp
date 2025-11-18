#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;
/*
Create 2 classes:
    1. SimpleCalculator
        - Takes input of 2 numbers using a utility function and performs +, -, *, /
          and displays the result using another function
    2.ScientificCalculator
        - Takes input of 2 number using a utility function and performs any four scientific operation
          of your choice and displays the results using another function.

    Create another class HybridCalculator and inherit it using these 2 classes:
    Q1. What type of inheritance are you using?
        --> Multiple inheritance

    Q2. Which mode of inheritance are you using?
        --> Public for both classes

    Q4. How is code reusability implemented?
        --> The classes SimpleCalculator and ScientificCalculator are written once but used again inside HybridCalculator.
            This is how code reusability is achieved through inheritance.
*/

class SimpleCalculator // This will perform simple calculations like addition, subtraction, multiplication, and division
{
protected:
  int SimNum1, SimNum2;
  int add;
  int subtract;
  int multiply;
  double divide;

public:
  void setNumSimple(int a, int b)
  {
    SimNum1 = a;
    SimNum2 = b;
  }

  void SimpleCalculate()
  {
    add = SimNum1 + SimNum2;
    subtract = SimNum1 - SimNum2;
    multiply = SimNum1 * SimNum2;
    if (SimNum2 == 0) // Edge case for dividing with 0
    {
      cout << "Division with 0 is not allowed!" << endl;
    }
    else
    {
      divide = (double)SimNum1 / (double)SimNum2; // Division can give results in floating point so double is used for more precision
    }
  }

  void SimpleDisplay()
  {
    cout << "Addition: " << SimNum1 << " + " << SimNum2 << " = " << add << endl;
    cout << "Subtraction: " << SimNum1 << " - " << SimNum2 << " = " << subtract << endl;
    cout << "Multiplication: " << SimNum1 << " * " << SimNum2 << " = " << multiply << endl;
    cout << "Division: " << SimNum1 << " / " << SimNum2 << " = " << fixed << setprecision(2) << divide << endl;
  }
};

class ScientificCalculator
{
protected:
  double SciNum1, SciNum2;
  double Square1, Square2;
  double Cube1, Cube2;
  double NaturalLog1, NaturalLog2, base10Log1, base10Log2;

public:
  void setNumsScientific(int a, int b)
  {
    SciNum1 = a;
    SciNum2 = b;
  }

  void ScientificCalculate()
  {
    Square1 = pow(SciNum1, 2);
    Square2 = pow(SciNum2, 2);
    Cube1 = pow(SciNum1, 3);
    Cube2 = pow(SciNum2, 3);
    NaturalLog1 = log(SciNum1);
    NaturalLog2 = log(SciNum2);
    base10Log1 = log10(SciNum1);
    base10Log2 = log10(SciNum2);
  }

  void DisplayScientific()
  {
    cout << "Square: " << endl
         << SciNum1 << " = " << Square1 << endl
         << SciNum2 << " = " << Square2 << endl;
    cout << "Cube: " << endl
         << SciNum1 << " = " << Cube1 << endl
         << SciNum2 << " = " << Cube2 << endl;
    cout << "Natural log (base e): " << endl
         << SciNum1 << " = " << NaturalLog1 << endl
         << SciNum2 << " = " << NaturalLog2 << endl;
    cout << "Log base 10: " << endl
         << SciNum1 << " = " << base10Log1 << endl
         << SciNum2 << " = " << base10Log2 << endl;
  }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator
{
  int n1, n2;

public:
  void setNumsHybrid(int x, int y)
  {
    n1 = x;
    n2 = y;
    setNumSimple(n1, n2);
    SimpleCalculate();
    SimpleDisplay();

    setNumsScientific(n1, n2);
    ScientificCalculate();
    DisplayScientific();
  }
};

int main()
{
  HybridCalculator s;
  int ch, p, q;

  while (ch != 4)
  {
    cout << "\n1. Simple Calculation\n2. Scientific Calculation\n3. Hybrid Calculation\n4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      cout << "\nEnter two numbers:\n";
      cin >> p >> q;
      cout << "******************** SIMPLE CALCULATION START ********************" << endl;
      s.setNumSimple(p, q);
      s.SimpleCalculate();
      s.SimpleDisplay();
      cout << "******************** SIMPLE CALCULATION END ********************" << endl;
      break;

    case 2:
      cout << "\nEnter two numbers:\n";
      cin >> p >> q;
      cout << "******************** SCIENTIFIC CALCULATION START ********************" << endl;
      s.setNumsScientific(p, q);
      s.ScientificCalculate();
      s.DisplayScientific();
      cout << "******************** SCIENTIFIC CALCULATION END ********************" << endl;
      break;

    case 3:
      cout << "\nEnter two numbers:\n";
      cin >> p >> q;
      cout << "******************** HYBRID CALCULATION START ********************" << endl;
      s.setNumsHybrid(p, q);
      cout << "******************** HYBRID CALCULATION END ********************" << endl;
      break;

    case 4:
      cout << "---------- Program exited successfully ----------" << endl;
      exit(0);
    default:
      cout << "Wrong Choice!!" << endl;
    }
  }
  return 0;
}
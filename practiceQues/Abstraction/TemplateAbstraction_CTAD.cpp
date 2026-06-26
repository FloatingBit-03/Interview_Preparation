/*
1. CTAD = Class Template Argument Deduction, available since C++17.
2. It lets you write Abstraction obj1(10); instead of Abstraction<int> obj1(10); 
   — the compiler looks at the constructor and the argument you passed to figure out T on its own.
3. This deduction is purely a compile-time decision. Once compiled, obj1 and obj2 are fully concrete,
   separate types (Abstraction<int>, Abstraction<double>) — there's no leftover "genericness" or deduction machinery at runtime.
4. That's why obj1.add(10, 20) returns 30 (int arithmetic) and obj2.add(10.2, 20.3) returns 30.5 (double arithmetic)
    — each object is calling methods on its own instantiated class.
*/

#include<iostream>

// Template class — T is a placeholder type, decided later by the compiler
template<typename T>
    
class Abstraction{
    private:
        T value;
    public:
    // Constructor takes a T — compiler uses THIS to deduce T
    // when no explicit <type> is given at the call site (CTAD)
        Abstraction(T v): value(v) 
        { }

        T add(T a, T b){
            return a+b;
        }

        T getValue() const {
            return value;
        }
};

int main(){
 // ----- Step 1 -----
    // Compiler sees: Abstraction obj1(10);
    // No <int> specified! This is CTAD in action.
    // Constructor is Abstraction(T value); argument 10 is an int.
    // => Compiler deduces T = int
    // => Treated internally as: Abstraction<int> obj1(10);
    Abstraction obj1(10);

    // ----- Step 2 -----
    // Compiler sees: Abstraction obj2(10.2);
    // 10.2 is a double.
    // => Compiler deduces T = double
    // => Treated internally as: Abstraction<double> obj2(10.2);
    Abstraction obj2(10.2);

    // ----- Step 3: Template Instantiation (compile-time) -----
    // The compiler now generates two SEPARATE concrete classes
    // behind the scenes, roughly equivalent to:
    //
    //   class Abstraction_int {
    //   public:
    //       Abstraction_int(int value) {}
    //       int add(int a, int b) { return a + b; }
    //   };
    //
    //   class Abstraction_double {
    //   public:
    //       Abstraction_double(double value) {}
    //       double add(double a, double b) { return a + b; }
    //   };
    //
    // This all happens at COMPILE TIME. No deduction happens at runtime —
    // by the time the program runs, obj1 is already a fixed
    // Abstraction<int>, and obj2 is already a fixed Abstraction<double>

    std::cout << obj1.getValue()<< obj1.add(10,20) << "\n";
    std::cout << obj2.getValue()<< obj2.add(10.2,20.3) << "\n";

    return 0;
}
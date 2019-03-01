#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class  Fruit { 
  public :
    Fruit(string name,  bool  peel,  int  seeds) {  
      this -> name = name;
      this -> peel = peel; 
      this -> seeds = seeds; 
    }
    string GetName() { return  name; }

    string HasPeel() { 
      return  peel ?  "has"  :  "has no"; 
    }  
    int  GetSeeds() { return  seeds; }

  private :
    string name;  
    bool  peel;
    int  seeds;
};


int main() {
  cout << "Question 1: Pointers" << endl;
  //Define an  int  called  zero  set to 0.
  int zero = 0;

  //Define an  int  called  i1  set to 2.
  int i1 = 2;

  //Define an  int  called  i2  set to 5.
  int i2 = 5;

  //Define an  int pointer  set to  i1. 
  int* p = &i1;
  cout << *p << endl;

  //Define an  int pointer  set to  i2 .
  int* p2 = &i2;
  cout << *p2 << endl;

  //Define an  int pointer  called  sum  set to zero.
  int* sum = &zero;
  cout << *sum << endl;

  //Using  pointers only , add i1 and i2 and place the results into  sum . Print the  sum  to the console.
  *sum = *p + *p2;
  cout << *sum << endl;

  //Define an  int pointer  called  product  set to zero.
  int* product = &zero;
  cout << *product << endl;

  //Using  pointers only , multiply i1 by i2 and return the result into the  product .
  *product = (*p * *p2);
  cout << *product << endl;

  cout << "Question 2: References" << endl;
  //Declare a  reference  called  r1  for  int i1 .
  int &r1 = i1;
  cout << r1 << endl;

  //Declare a  reference  called  r2  for  int i2 .
  int &r2 = i2;
  cout << r2 << endl;

  //Using  references and pointers , add the squares of i1 and i2 and place the result in sum .
  *sum = (r1 * r1) + (r2 * r2);

  //Print the ‘sum of the squares’.
  cout << "Sum of Squares: " << *sum << endl;
  
  cout << "Question 3: Iterators and Vectors" << endl;
  //Write a  for-loop  using a vector  iterator  that prints a line displaying:

  
  vector<string> v;
  v.push_back("Apple");
  v.push_back("Mango");
  v.push_back("Strawberry");

  for (auto start = v.begin(); start < v.end(); start++) {
    const char * fruit = start -> c_str();
    unsigned long length = strlen(fruit);
    printf("\nFruit is: %s, Fruit Ptr is: %p, Fruit Length is: %lu", fruit, start.base(), length);
  }


  //  ● Write any observations you notice from the addresses vs the length of each fruit string? 

  // The addresses in memory are 20 bits apart consistently while the length of the fruit name changes. 
  // Each fruit was made and stored very logically in this example.

  cout << "Question 4: Heap Instances" << endl;
  
  Fruit *apple = new Fruit("Apple", "has", 4);
  Fruit *mango = new Fruit("Mango", "has", 2);
  Fruit *strawb = new Fruit("Strawberry", "has", 20);
  vector <Fruit*> tutti_frutti = {apple, mango, strawb};
  //tutti_frutti.push_back(apple);
  //tutti_frutti.push_back(mango);
  //tutti_frutti.push_back(strawb);
  // ^ both of these methods work

  for (Fruit* fruit : tutti_frutti) {
    Fruit f = *fruit;
    printf("\nAt %p, the %s %s peel and has %d seeds.", fruit, f.GetName().c_str(), f.HasPeel().c_str(), f.GetSeeds());
  }

  //Write any  observations  you notice about the addresses of the  Fruit  instances as comments in your code.

  // The addresses of these fruits come off the heap, so the slots are a bit more random (as opposed to the 
  // neat order of the Q3). You can't immediately observe the equivalence in size of these heap allocations.

  //Write a  for-each  loop that uses the  delete  operator to free each of the  Fruit instances. 

  for (Fruit* fruit : tutti_frutti) {
    delete(fruit);
  }
  
  //Why is the  delete  operator needed here for the  tutti_frutti  vector but not for  fruits  vector?
  
  // The items in the fruits vector were creating on the stack, so they are disposed of automatically by 
  // C++ when they are no longer in the scope of the program/being used. The fruits in tutti_frutti were 
  // all instantiated with the "new" keyword, meaning they used the heap which isn't included in that auto 
  // garbage collecting that C++ so kindly does. These fruits from the heap will remain in memory until 
  // manually deleted, which has high potential to crash programs as they scale up and run out of space.

  //Clear  tutti_frutti  and print its  size  (which should be zero).

  tutti_frutti.clear();
  cout << endl << "TF Size is: " << tutti_frutti.size();


}

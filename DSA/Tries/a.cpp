#include <iostream>
using namespace std;

class Test {
   public:
      //this is a public class member variable
      string testString;

      //non-static member function
      void setData(string testString) {

         //this is refering to the class member variable
         this->testString = testString;
      }
      
      void getAndPrint(string str) {
         //accessing both member variables and functions using this pointer
         this->setData(str);
         cout << "The string is: " << this->testString << endl;
      }
      
      void delObject() {
         //accessing the current object and deleting it
         delete this;
      }
      
};
int main() {
   //create the object
   Test test;

   //call the member function
   test.getAndPrint("This is a test for accessing objects!");
   test.delObject();
   test.getAndPrint("This is a test for accessing objects!");
   return 0;
}
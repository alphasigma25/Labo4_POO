#include <iostream>
#include "Field.h"
#include "Displayer/TerminalDisplay.h"

using namespace std;

int main() {
   Field f(10,20,5,3);

   TerminalDisplay td(&f);

   cout << "hello" << endl;
   while(f.stillRunning()){
      td.display();
      f.nextTurn();
   }

   return 0;
}

#include <iostream>
#include "Field.h"
#include "Displayer/TerminalDisplay.h"

using namespace std;

int simulate(Field& f);

int main() {
   Field f(10,20,5,3);

   TerminalDisplay td(&f);

   int turn = 0;
   bool running = true;

   while(f.stillRunning() && running){
      td.display();

      string cmd;
      cout << "[" << turn << "]" << endl;
      getline(cin, cmd);

      switch(*cmd.begin()){
         case 'q' :
            running = false;
            break;
         case 's' :
            simulate(f);
            break;
         case 'n':
         default :
            turn = f.nextTurn();
            break;
      }
   }


   if(f.isBuffyVictory()){
      cout << "Buffy wins !" << endl;
   }
   else{
      cout << "Vampires State Building wins T-T" << endl;
   }
   return 0;
}

int simulate(Field& f){
   //TODO
   return 0;
}

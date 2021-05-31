#include <iostream>
#include "Field.h"
#include "Displayer/TerminalDisplay.h"

using namespace std;

double simulate(size_t height, size_t width, size_t nbHumans, size_t nbVampires);

int main(int argc, char** argv) {
   if (argc < 5){
      cout << "Usage: height, width, nbHumans, nbVampires";
      return 0;
   }
   size_t height = stoi(argv[1]);
   size_t width = stoi(argv[2]);
   size_t nbHumans = stoi(argv[3]);
   size_t nbVampires = stoi(argv[4]);
   Field f(height, width, nbHumans, nbVampires);

   TerminalDisplay td(&f);

   int turn = 0;
   bool running = true;

   while(f.stillRunning() && running){
      td.display();

      string cmd;
      double ratio = 0;
      cout << "[" << turn << "] q)uit s)tatistics n)ext:" << endl;
      getline(cin, cmd);

      switch(*cmd.begin()){
         case 'q' :
            running = false;
            break;
         case 's' :
            ratio = simulate(height, width, nbHumans, nbVampires);
            cout << "ratio : " << ratio * 100 << "% de réussite " << endl;
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

double simulate(size_t height, size_t width, size_t nbHumans, size_t nbVampires) {
   size_t buffyVictory = 0;
   for(int i = 0; i < 10000; ++i){
      Field f(height, width, nbHumans, nbVampires);
      while(f.stillRunning()){
         f.nextTurn();
      }
      if(f.isBuffyVictory()) ++buffyVictory;
   }
   return buffyVictory/10000.;
}

#include <iostream>
#include "Problems.h"

int main()
{
   Problems p;

   while (1)
   {
      std::string input;
      std::cout << "Enter Problem to Run: ";
      std::cin >> input;
      std::cout << "\n\n";

      p.Run(input);
   }
   return 1;
}

#ifndef PROBLEMS_H
#define PROBLEMS_H

#include "sloppyMath.h"

#include <map>

enum ProblemEnum
{
   pND,
   p1_3,
   p1_5,
   p1_6,
   p1_7,
   p1_8
};

struct Problems
{
   Problems();

   void Run(std::string probString);
   void p1_3();
   void p1_5();
   void p1_6();
   void p1_7();
   void p1_8();

   std::map<std::string, ProblemEnum> stringMap;
};
#endif

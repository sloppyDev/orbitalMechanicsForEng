#include "Problems.h"

Problems::Problems()
{
   stringMap["1.3"] = ProblemEnum::p1_3;
   stringMap["1.5"] = ProblemEnum::p1_5;
   stringMap["1.6"] = ProblemEnum::p1_6;
   stringMap["1.7"] = ProblemEnum::p1_7;
   stringMap["1.8"] = ProblemEnum::p1_8;
}

void Problems::Run(std::string probString)
{
   switch(stringMap[probString])
   {
      case ProblemEnum::p1_3:
         p1_3();
         break;
      case ProblemEnum::p1_5:
         p1_5();
         break;
      case ProblemEnum::p1_6:
         p1_6();
         break;
      case ProblemEnum::p1_7:
         p1_7();
         break;
      case ProblemEnum::p1_8:
         p1_8();
         break;
      case ProblemEnum::pND:
         std::cout << "Problem Number '" << probString << "' Not Defined" << std::endl;
   }
}

void Problems::p1_3()
{
   // Initializing Values
   Vector A({8.0, 9.0, 12.0});
   Vector B({9.0, 6.0, 1.0});
   Vector C({3.0, 5.0, 10.0});

   // Get Normal to AB plane
   Vector Cnorm = Norm(Cross(A, B));

   // Get Portion of C in Normal Direction
   double normCmag = Dot(C, Cnorm);

   // Pythagoras to get Projection
   // side1^2 + side2^2 = hyp^2
   double cMag = Mag(C);
   double answer = sqrt(cMag*cMag - normCmag*normCmag);

   std::cout << "Problem 1.3 Answer: " << answer << std::endl;
}

void Problems::p1_5()
{
   // x = sin3t, y = cost, z = sin2t
   double t = 3.0; // seconds
   Vector P({sin(3*t), cos(t), sin(2*t)});

   std::cout << "Problem 1.5 Answers" << std::endl;
   // a
   // Vel: vx = 3cos3t, vy = -sint, vz = 2cos2t
   Vector V({3*cos(3*t), -sin(t), 2*cos(2*t)});

   std::cout << "A:" << std::endl;
   V.print();

   // b
   std::cout << "B:" << std::endl;
   std::cout << Mag(V) << std::endl;

   // c
   Vector uT = Norm(V);
   std::cout << "C:" << std::endl;
   uT.print();

   // d
   double xAng, yAng, zAng;
   xAng = acos(uT.vals[0]);
   yAng = acos(uT.vals[1]);
   zAng = acos(uT.vals[2]);

   std::cout << "D:" << std::endl;
   std::cout << "\u03b8 X: " << xAng*180.0/3.14159 << 
               " \u03b8 Y: " << yAng*180.0/3.14159 << 
               " \u03b8 Z: " << zAng*180.0/3.14159 << std::endl;

   // e
   // Acc: ax = -9sin3t, ay = -cost, az = -4sin2t
   Vector A({-9*sin(3*t), -cos(t), -4*sin(2*t)});

   std::cout << "E:" << std::endl;
   A.print();

   // f
   Vector VxA = Cross(V,A);
   Vector uB = Norm(VxA);

   std::cout << "F:" << std::endl;
   uB.print();

   // g
   Vector uN = Cross(uB,uT);

   std::cout << "G:" << std::endl;
   uN.print();

   // h
   Vector aNorm = Norm(A);
   xAng = acos(aNorm.vals[0]);
   yAng = acos(aNorm.vals[1]);
   zAng = acos(aNorm.vals[2]);

   std::cout << "H:" << std::endl;
   std::cout << "\u03c6 X: " << xAng*180.0/3.14159 << 
               " \u03c6 Y: " << yAng*180.0/3.14159 << 
               " \u03c6 Z: " << zAng*180.0/3.14159 << std::endl;

   // i
   double aT = Dot(A, uT);

   std::cout << "I:" << std::endl;
   std::cout << aT << std::endl;

   // j
   double aN = Dot(A, uN);

   std::cout << "J:" << std::endl;
   std::cout << aN << std::endl;

   // k
   double vMag = Mag(V);
   double rho = (vMag*vMag)/aN;

   std::cout << "K:" << std::endl;
   std::cout << "\u03c1: " << rho << std::endl;

   // l
   Vector r_p2c = uN*rho;
   Vector rC = P + r_p2c;

   std::cout << "L:" << std::endl;
   rC.print();
}

void Problems::p1_6()
{}
void Problems::p1_7()
{}
void Problems::p1_8()
{}

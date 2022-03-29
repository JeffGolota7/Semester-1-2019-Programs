#include <iostream>
#include <array>
using namespace std;


double PyramidVolume(double baseLength, double baseWidth, double pyramidHeight) {
   double volume;
   double baseArea;
   double oneThird;
   
   oneThird = 1/3;
   baseArea = baseLength * baseWidth;
   volume = oneThird * (baseArea * pyramidHeight);
   return volume;
}

int main() {
   double userLength;
   double userWidth;
   double userHeight;

   cin >> userLength;
   cin >> userWidth;
   cin >> userHeight;

   cout << "Volume: " << PyramidVolume(userLength, userWidth, userHeight) << endl;

   return 0;
}


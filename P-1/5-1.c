#include <math.h>
#include <stdio.h>

double distance(double x1, double y1, double x2, double y2)
{
  double dx = x1 - x2;
  double dy = y1 - y2;
  double dsquared = dx * dx + dy *dy;
  double result = sqrt(dsquared);
  
  return result;
}

int main(void)
{
  printf("distance is %f\n", distance(1.0, 2.0, 4.0, 6.0));
  return 0;
}

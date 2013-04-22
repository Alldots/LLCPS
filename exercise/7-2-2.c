#include <stdio.h>

struct rational {
  int a; /* numerator */
  int b; /* denominator */
};

int euclid(int a, int b)
{
  while (b != 0) {
    int m = a % b;
    a = b;
    b = m;
  }

  return a;
}   

struct rational make_rational(int a, int b)
{
  int gcd = euclid(a, b);
  struct rational r;
  r.a = a / gcd;
  r.b = b / gcd;

  if (r.b < 0) {
    r.a = -r.a;
    r.b = -r.b;
  }
 
  return r;
}

struct rational add_rational(struct rational r1, struct rational r2)
{
  return make_rational(r1.a*r2.b + r2.a*r1.b, r1.b*r2.b);
}

struct rational sub_rational(struct rational r1, struct rational r2)
{
  return make_rational(r1.a*r2.b - r2.a*r1.b, r1.b*r2.b);
}

struct rational mul_rational(struct rational r1, struct rational r2)
{
  return make_rational(r1.a*r2.a, r1.b*r2.b);
}

struct rational div_rational(struct rational r1, struct rational r2)
{
  return make_rational(r1.a*r2.b, r1.b*r2.a);
}

void print_rational(struct rational r)
{
  printf("%d/%d\n", r.a, r.b);
}

int main(void)
{
  struct rational a = make_rational(1, 8);
  struct rational b = make_rational(-1, 8);
  print_rational(add_rational(a, b));
  print_rational(sub_rational(a, b));
  print_rational(mul_rational(a, b));
  print_rational(div_rational(a, b));

  return 0;
}


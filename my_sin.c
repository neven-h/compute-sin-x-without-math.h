#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EPSILON 0.000000001
#define Y 6.150444064011
#define UNITCIRCLE 360
#define DEGREESINRAD 57.29577951308232087684636434419109775

/* my abslute value function */
double my_abs(double x)
{
  if (x >= 0)
    return x; /* if x is positive, return x as is */
  else
    return (-x); /*if x is negetive, change it to be positive */
}

/*Converts the inputs to the first 365 degrees, to avoid aritmetic overflow*/
double convert_input_to_range(double x)
{
  double y = 1 / DEGREESINRAD;      /*y is the number of radians in 1 degree*/
  double z = y * UNITCIRCLE; /*z is the number of radians in 360 degrees*/
  while (my_abs(x) >= z)         /*Converts the input to the first 360 degrees, to avoid stack overflow*/
  {
    if (x < 0)
      x += z;
    if (x > 0)
      x -= z;
  }
  return x;
}

/*the function my_sin */
double my_sin(double x)
{
  /*declations: */
  double term, total_so_far, b, c;
  term = x; /* First term in the expansion.*/
  total_so_far = 0.00;
  b = 0.0, c = 1.0;

  /*if the last term in the sum is smaller then EPSILON, return the result */
  while (my_abs(term / 2) >= EPSILON)
  {
    /* Add current term to sum. */
    total_so_far = total_so_far + term;
    /* Compute next term from the current one. */
    b += 2;
    c = b + 1;
    term *= (-(x * x) / (b) / (b + 1));
  }
  return total_so_far;
}

int main(void)
{
  /*declations: */
  double x, res_my_sin, res_system_sin;
  double my_sin(double x);
  double my_abs(double x);
  double convert_input_to_range(double x);

  printf("Please wnter a value in the range [-25.0,25,0] which you'd like to be computed: ");
  scanf("%lf", &x);
  x = convert_input_to_range(x); /* converts the input to avoid mistakes in calculation as a result of arithmetic overflow*/
  res_my_sin = my_sin(x); /* assigning a variable to the function as we don't want to call the function directly*/
  printf("Using my_sin function sin(%f) =  %f\n", x, res_my_sin);
  res_system_sin = sin(x);/* assigning a variable to the function as we don't want to call the function directly*/
  printf("\nUsing the C library function sin(%f) = %f\n", x, res_system_sin);

  return 0;
}

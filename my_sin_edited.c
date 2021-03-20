/* this one is working when the input is in radians*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
#define EPSILON 0.000000001

/* my abslute value function */
double myabs(double x){
    if(x>= 0) return x; /* if x is positive, return x as is */
    else
    return (-x); /*if x is negetive, change it to be positive */
}

/*the function my_sin */
  double my_sin(double x) {
  /*declations: */
  double term, total_so_far,a, b, c;
  term = x;  /* First term in the expansion.*/
  total_so_far = 0.00;
  a = 1, b=0.0, c=1.0;
  
  /*if the last term in the sum is smaller then EPSILON, return the result */
  while(myabs(term)> EPSILON){
    /* Add current term to sum. */
    total_so_far = total_so_far + term;
    /* Compute next term from the current one. */
    b += 2;
    c = b + 1;
    term *= (-(x * x) / (b) / (b + 1));
  }
  return total_so_far;
}

int main(void) {
  double x,res_my_sin, res_system_sin;
  double my_sin(double x);

    printf("Please wnter a value in the range [-25.0,25,0] which you'd like to be computed: ");
    scanf("%lf", &x);
    if(myabs(x)>25.0){
    printf("the value you entered is not in the legel range, please try again");
    }
    res_my_sin = my_sin(x);
    /* if x is in the legal values of [-25,25], then sin(x) will be bounded by -1 and 1*/
    if(myabs(res_my_sin) <= 1){
    printf("Using my_sin function sin(%f) is %f\n", x, res_my_sin);
    res_system_sin = sin(x);
    printf("\nUsing the C library function sin(%f) = %f\n", x, res_system_sin);
    }
    /* if x is not in legel values */
  else {
    printf("the value you entered is not in the legel range, please try again");
  }
  return 0;
}
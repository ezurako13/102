#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w);

char dt1a(double pl, double pw, double sl, double sw);
char dt1b(double pl, double pw, double sl, double sw);

double dt2a(double x1, double x2, double x3, int x4, int x5);
double dt2b(double x1, double x2, double x3, int x4, int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
int dt3a(double oy, double my, int yzm, int ys, int ak);
int dt3b(double oy, double my, int yzm, int ys, int ak);

#endif /* _UTIL_H_ */
# s21_math  

Implementation of your own version of the math.h library (Linux).

The library was developed:
1. [baharevil](https://github.com/baharevil)
2. [netzen86](https://github.com/netzen86)
3. [Bloodislav](https://github.com/Bloodislav)


## Contents
C mathematical operations are a group of functions in the standard library of the C programming language implementing basic mathematical functions. All functions use floating-point numbers in one manner or another. Different C standards provide different, albeit backwards-compatible, sets of functions. Any functions that operate on angles use radians as the unit of angle.

### Overview of some "math.h" functions

| No. | Function | Description |
| --- | -------- | ----------- |
| 1 | `int abs(int x)` | computes absolute value of an integer value |
| 2 | `long double acos(double x)` | computes arc cosine |
| 3 | `long double asin(double x)` | computes arc sine |
| 4 | `long double atan(double x)` | computes arc tangent |
| 5 | `long double ceil(double x)` | returns the nearest integer not less than the given value |
| 6 | `long double cos(double x)` | computes cosine |
| 7 | `long double exp(double x)` | returns e raised to the given power |
| 8 | `long double fabs(double x)` | computes absolute value of a floating-point value |
| 9 | `long double floor(double x)` | returns the nearest integer not greater than the given value |
| 10 | `long double fmod(double x, double y)` | remainder of the floating-point division operation |
| 11 | `long double log(double x)` | computes natural logarithm |
| 12 | `long double pow(double base, double exp)` | raises a number to the given power |
| 13 | `long double sin(double x)` | computes sine |
| 14 | `long double sqrt(double x)` | computes square root |
| 15 | `long double tan(double x)` | computes tangent |  


The functions of the math.h library (described in the table [above](#overview-of-some-mathh-functions)) are implemented:

- The library is developed in the C language of the C11 standard using the gcc compiler
- The library code is in the src folder on the develop branch
- Google code style
- Formatted as a static library (with header file s21_math.h).
- Prepared full code coverage of library functions unit tests with Check library. The unit tests check the results of the implementation by comparing them with the implementation of the standard library math.h. Unit tests should cover at least 80% of each function (checked with gcov)
- Make-file for building the library and tests (with targets all, clean, test, s21_math.a, gcov_report)

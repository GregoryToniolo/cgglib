
# Cgglib

A single header minimalist graphics/opengl math library with a focus on simplicity, speed and efficiency through the use of complex numbers instead of matrices for graphics  calculations written in pure c99.
## Installation

Simply clone the github repo and copy the header file to your project directory.
Note: there are no external dependencies needed. Only a c99 capable compiler is required.

```bash
    git clone https://github.com/GregoryToniolo/cgglib 
```
## API Reference

### cplex_add 
#### Takes two complex numbers and returns the sum.

### cplex_sub 
#### Takes two complex numbers and returns the difference.

### cplex_mul 
#### Takes two complex numbers and returns the product.

### cplex_div 
#### Takes two complex numbers and returns the quotient.

###  cplex_scale 
#### Scales a complex number by a scalar and returns the result.

###  cplex_sqr 
#### Takes a complex number and returns its square.

###  cplex_conj 
#### Takes a complex number and returns its conjugate.

###  cplex_abs 
#### Takes a complex number and returns its absolute value (norm). Requires a function to be defined for the square root.

###  cplex_abs2 
#### Takes a complex number and returns its absolute value (norm) squared.

### cplex_arg
#### Takes a complex number and returns the angle it forms with the positive real axis.  Requires a function to be defined for the arctangent of a vector (atan2).

###  cplex_inv 
#### Takes a complex number and returns its multiplicative inverse.

### cplex_norm 
#### Takes a complex number and normalizes it..Requires a function to be defined for the square root.

### cplex_euler
#### Takes an angle and returns euler's formula for that angle. Requires functions to be defined for sine and cosine.

### cplex_rot
#### Takes an angle, and a complex number and returns the complex number rotated by the angle. Requires functions to be defined for sine and cosine.

### cplex_rotv
#### Takes an angle, a source vector, a destination vector and 2 axes and rotates the  2 axes of the source vector by the angle and stores the result in the destination vector. Requires functions to be defined for sine and cosine. Works for any n-dimensional vectors and is more efficient than matrix multiplication.

### cplex_rotv2
#### Same as cplex_rotv but it takes a complex number as an argument instead of aa angle and rotates the source vector by that complex number. Requires functions to be defined for sine and cosine. Works for any n-dimensional vectors and is more efficient than matrix multiplication.

### cplex_projv
#### Takes a source vector and 2 axes and projects those axes onto a complex number through orthogonal projection. Works for any n-dimensional vector.

### cplex_projv2
#### Takes a source vector and 2 axes plus a division axis and performs perspective division on the two axes and projects the result onto a complex number.

### cplex_addv
#### Takes a source vector, a destination vector, a complex number and 2 axes and translates the 2 axes of the source vector by the complex number and stores the result in the destination vector. Works for any n-dimensional vectors and is more efficient than matrix multiplication.

### cplex_subv
#### Same as cplex_addv but subtracts the complex number instead of adding it. Works for any n-dimensional vectors and is more efficient than matrix multiplication.

### d_dx
#### Takes a point, a function and a precision value (h),  computes derivative of a single real variable function at a point using the provided value of h for precision.

### defint
#### Takes a starting point, an ending point, and a function, integrates the function from the starting point to the ending point.
## FAQ

#### Can i use it with cglm for more efficient operations?

Yes, it has been developed to work together with cglm not against it and to provide more optimized versions certain operations.
For 2d vectors and matrices this uses complex numbers as a full replacement for cglm. For higher dimensional vectors it simply
provides more optimized versions of some operations.

#### Does it work with n-dimensional vectors?

Yes, the functions with v at the end of their name are meant to work with n-dimensional vectors, not just cglm's vec2, vec3 and vec4 type. As long as your implementation of n-dimensional vectors uses them as arrays of float32s then it should work.

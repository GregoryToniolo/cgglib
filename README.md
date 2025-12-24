
# Cgglib

A single header minimalist graphics/opengl math library with a focus on simplicity, speed and efficiency through the use of complex numbers instead of matrices for graphics  calculations written in pure c99.
## Installation

Simply clone the github repo and copy the header file to your project directory.
Note: there are no external dependencies needed. Only a c99 capable compiler is required.

```bash
    git clone https://github.com/GregoryToniolo/cgglib 
```
## FAQ

#### Can i use it with cglm for more efficient operations?

Yes, it has been developed to work together with cglm not against it and to provide more optimized versions certain operations.
For 2d vectors and matrices this uses complex numbers as a full replacement for cglm. For higher dimensional vectors it simply
provides more optimized versions of some operations.

#### Does it work with n-dimensional vectors?

Yes, the functions with v at the end of their name are meant to work with n-dimensional vectors, not just cglm's vec2, vec3 and vec4 type. As long as your implementation of n-dimensional vectors uses them as arrays of float32s then it should work.

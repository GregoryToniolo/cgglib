typedef struct { 
    float r, i;
}cplex;

//(a+bi)+(c+di)
static inline cplex cplex_add(const cplex a, const cplex b)
{
    return (cplex){a.r+b.r,a.i+b.i};
}

//(a+bi)-(c+di)
static inline cplex cplex_sub(const cplex a, const cplex b)
{
    return (cplex){a.r-b.r,a.i-b.i};
}

//(a+bi)(c+di)
static inline cplex cplex_mul(const cplex a, const cplex b)
{
    return (cplex){a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r};
}

//(a+bi)/(c+di)
static inline cplex cplex_div(const cplex a, const cplex b)
{
    const float abs2 = b.r*b.r+b.i*b.i;
    return (cplex){(a.r*b.r+a.i*b.i)/abs2, (a.r*b.i-a.i*b.r)/abs2};
}

//s(a+bi)
static inline cplex cplex_scale(const cplex c, const float s)
{
    return (cplex){c.r*s, c.i*s};
}

//c^2
static inline cplex cplex_sqr(const cplex c)
{
    return (cplex){c.r*c.r-c.i*c.i,2*c.r*c.i};
}

//~(a+bi)=a-bi
static inline cplex cplex_conj(const cplex c)
{
    return (cplex){c.r,-c.i};
}

//|c|
static inline float cplex_abs(const cplex c, float(*sqrtf_ptr)(float))
{
    return sqrtf_ptr(c.r*c.r+c.i*c.i);
}

//|c|^2
static inline float cplex_abs2(const cplex c)
{
    return c.r*c.r+c.i*c.i;
}

// distance between 2 complex numbers
static inline float cplex_dist(const cplex a, const cplex b, float(*sqrtf_ptr)(float))
{
    float xc = a.r - b.r, yc = a.i - b.i;
    return sqrtf_ptr(xc*xc+yc*yc);
}

//angle of a complex number
static inline float cplex_arg(const cplex c, float(*atan2_ptr)(float, float))
{
    return atan2_ptr(c.i, c.r);
}

//inverse of a complex number
static inline cplex cplex_inv(const cplex c)
{
    const float abs2 = c.r*c.r+c.i*c.i;
    return (cplex){c.r/abs2, -c.i/abs2};
}

//normalize complex number
static inline cplex cplex_norm(const cplex c, float(*sqrtf_ptr)(float))
{
    const float abs = sqrtf_ptr(c.r*c.r+c.i*c.i);
    return (cplex){c.r/abs, c.i/abs};
}

//e^it
static inline cplex cplex_euler(const float theta, float(*cosf_ptr)(float), float(*sinf_ptr)(float))
{
    return (cplex){cosf_ptr(theta), sinf_ptr(theta)};
}

//rotate complex number by an angle theta
//(cos(theta)+isin(theta))(a+bi)
static inline cplex cplex_rot(const float theta, const cplex c, float(*cosf_ptr)(float), float(*sinf_ptr)(float))
{
    float costheta = cosf_ptr(theta), sintheta = sinf_ptr(theta);
    return (cplex){costheta*c.r-sintheta*c.i,costheta*c.i+sintheta*c.r};
}

//rotate a vector by an angle theta
//works in n dimensions
static inline void cplex_rotv(const float theta, const float * restrict src, float * restrict dst, const unsigned int axis1, const unsigned int axis2, float(*cosf_ptr)(float), float(*sinf_ptr)(float))
{
    float costheta = cosf_ptr(theta), sintheta = sinf_ptr(theta);
    dst[axis1]=src[axis1]*costheta-src[axis2]*sintheta;
    dst[axis2]=src[axis1]*sintheta+src[axis2]*costheta;
}

//rotate a vector by a complex number
static inline void cplex_rotv2(const cplex c, const float * restrict src, float * restrict dst, const unsigned int axis1, const unsigned int axis2)
{
    dst[axis1]=c.r*src[axis1]-c.i*src[axis2];
    dst[axis2]=c.i*src[axis1]+c.r*src[axis2];
}

//project a vector onto a complex number
//orthogonal projection
static inline cplex cplex_projv(const float * restrict v, const unsigned int axis1, const unsigned int axis2)
{
    return (cplex){v[axis1], v[axis2]};
}

//project a vector onto a complex number
//perspective projection
//performs perspective division
static inline cplex cplex_projv2(const float * restrict v, const unsigned int axis1, const unsigned int axis2, const unsigned int axisdiv)
{
    return (cplex){v[axis1]/v[axisdiv], v[axis2]/v[axisdiv]};
}

//translate a vector by a complex number
static inline void cplex_addv(const cplex c, const float * restrict src, float * restrict dst, const unsigned int axis1, const unsigned int axis2)
{
    dst[axis1]=c.r+src[axis1];
    dst[axis2]=c.i+src[axis2];
}

//subtract a complex number from a vector
static inline void cplex_subv(const cplex c, const float * restrict src, float * restrict dst, const unsigned int axis1, const unsigned int axis2)
{
    dst[axis1]=src[axis1]-c.r;
    dst[axis2]=src[axis2]-c.i;
}

//d/dx(f(x))
static inline float d_dx(const float x, float(*f)(float), const float h)
{
    return (f(x+h)-f(x-h))/(2*h);
}

//definite integral from a to b of f(x) dx
//DONT USE THIS FOR NATURAL LOG OR OTHER FUNCTIONS
//uses gauss-legendre 2 point formula
static inline float defint(const float a, const float b, float(*f)(float))
{
    float mid = (a+b)/2,offset=(b-a)*0.28867513459;//1/(2sqrt3)
    return ((b-a)/2)*(f(mid+offset)+f(mid-offset));
}

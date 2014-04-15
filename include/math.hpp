#ifndef MATH_HPP_
#define MATH_HPP_

namespace spaceships
{
namespace math
{
const double EULER      = 2.7182818284590452;
const double GOLDEN     = 1.6180339887498948;
const double PI         = 3.1415926535897932;
const double EPSILON    = 10e-5;

inline float fast_inv_sqrt(float value);

template<typename A, typename B>
bool flags(const A var, B flags);

template<typename T>
T deg_to_rad(const T degrees);

template<typename T>
T rad_to_deg(const T radians);

template<typename T>
bool nan(const T value);

template<typename T>
T clamp(const T& value, const T& min, const T& max);

template<typename T>
bool compare(const T& var1, const T& var2, const T& tolerance = EPSILON);

template<typename T>
T round(const T& value);

template<typename T>
T limit_angle(const T& value, const T& max = 360.0, const T& min = 0.0);

template<typename T>
bool power_of_two(const T& value);
}
}

#include "math/vector.hpp"

namespace spaceships
{
namespace math
{
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;
typedef vec2<int> vec2i;
typedef vec2<unsigned> vec2u;

typedef vec3<float> vec3f;
typedef vec3<double> vec3d;
typedef vec3<int> vec3i;
typedef vec3<unsigned> vec3u;
}
}

#include "math.inl"

#endif // MATH_HPP_

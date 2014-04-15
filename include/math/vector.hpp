#ifndef MATH_VECTOR_HPP_
#define MATH_VECTOR_HPP_

#include <string>
#include "math.hpp"

namespace spaceships
{
namespace math
{

template<typename T> struct mat3;
template<typename T> struct mat4;

template<typename T>
struct vec2
{
    union
    {
        struct
        {
            union { T x, u, a; };
            union { T y, v, b; };
        };
        T ptr[2];
    };

    vec2();
    explicit vec2(const T x, const T y);
    explicit vec2(const T xy);
    explicit vec2(const vec2<T>& vec);

    vec2<T>& set(const T x, const T y);
    vec2<T>& zero();
    vec2<T>& clamp(const T min, const T max);
    vec2<T>& clamp(const vec2<T>& min, const vec2<T>& max);
    vec2<T>& angle_clamp(const T min = 0.0, const T max = 360.0);
    vec2<T>& angle_clamp(const vec2<T>& min, const vec2<T>& max);
    vec2<T>& truncate(const T length);
    vec2<T>& maximize(const vec2<T>& max);
    vec2<T>& minimize(const vec2<T>& min);
    vec2<T> normalized(const bool fast = false) const;
    vec2<T>& normalize(const bool fast = false);
    vec2<T>& rotate(const double degrees);
    T distance(const vec2<T>& vec) const;
    T dot_product(const vec2<T>& vec) const;
    T length(const bool squared = false) const;
    T angle(const vec2<T>& vec) const;
    std::string str() const;

    vec2<T> operator-() const;
    vec2<T> operator+(const T value) const;
    vec2<T> operator+(const vec2<T>& vec) const;
    vec2<T> operator-(const T value) const;
    vec2<T> operator-(const vec2<T>& vec) const;
    vec2<T> operator*(const T value) const;
    vec2<T> operator*(const vec2<T>& vec) const;
    vec2<T> operator/(const T value) const;
    vec2<T> operator/(const vec2<T>& vec) const;

    vec2<T>& operator=(const vec2<T>& vec);
    vec2<T>& operator+=(const T value);
    vec2<T>& operator+=(const vec2<T>& vec);
    vec2<T>& operator-=(const T value);
    vec2<T>& operator-=(const vec2<T>& vec);
    vec2<T>& operator*=(const T value);
    vec2<T>& operator*=(const vec2<T>& vec);
    vec2<T>& operator/=(const T value);
    vec2<T>& operator/=(const vec2<T>& vec);

    bool operator<(const vec2<T>& vec) const;
    bool operator<=(const vec2<T>& vec) const;
    bool operator>(const vec2<T>& vec) const;
    bool operator>=(const vec2<T>& vec) const;
    bool operator==(const vec2<T>& vec) const;
    bool operator!=(const vec2<T>& vec) const;
    bool compare(const vec2<T>& vec) const;
    bool compare(const vec2<T>& vec, const T epsilon) const;
};

template<typename T>
struct vec3
{
    union
    {
        struct
        {
            union { T x, u, r; };
            union { T y, v, g; };
            union { T z, w, b; };
        };
        T ptr[3];
    };

    vec3();
    explicit vec3(const T x, const T y, const T z);
    explicit vec3(const T xyz);
    explicit vec3(const vec3<T>& vec);

    vec3<T>& set(const T x, const T y, const T z);
    vec3<T>& zero();
    vec3<T>& clamp(const T min, const T max);
    vec3<T>& clamp(const vec3<T>& min, const vec3<T>& max);
    vec3<T>& angle_clamp(const T min = 0.0, const T max = 360.0);
    vec3<T>& angle_clamp(const vec3<T>& min, const vec3<T>& max);
    vec3<T>& truncate(const T length);
    vec3<T>& maximize(const vec3<T>& max);
    vec3<T>& minimize(const vec3<T>& min);
    vec3<T> normalized(const bool fast = false) const;
    vec3<T>& normalize(const bool fast = false);
    vec3<T>& rotate_x(const double degrees);
    vec3<T>& rotate_y(const double degrees);
    vec3<T>& rotate_z(const double degrees);
    vec3<T> cross_product(const vec3<T>& vec) const;
    T distance(const vec3<T>& vec) const;
    T dot_product(const vec3<T>& vec) const;
    T length(const bool squared = false) const;
    T angle(const vec3<T>& vec) const;
    std::string str() const;

    vec3<T> operator-() const;
    vec3<T> operator+(const T value) const;
    vec3<T> operator+(const vec3<T>& vec) const;
    vec3<T> operator-(const T value) const;
    vec3<T> operator-(const vec3<T>& vec) const;
    vec3<T> operator*(const T value) const;
    vec3<T> operator*(const vec3<T>& vec) const;
    vec3<T> operator*(const mat3<T>& mat) const;
    vec3<T> operator*(const mat4<T>& mat) const;
    vec3<T> operator/(const T value) const;
    vec3<T> operator/(const vec3<T>& vec) const;
    vec3<T> operator/(const mat3<T>& mat) const;
    vec3<T> operator/(const mat4<T>& mat) const;

    vec3<T>& operator=(const vec3<T>& vec);
    vec3<T>& operator+=(const T value);
    vec3<T>& operator+=(const vec3<T>& vec);
    vec3<T>& operator-=(const T value);
    vec3<T>& operator-=(const vec3<T>& vec);
    vec3<T>& operator*=(const T value);
    vec3<T>& operator*=(const vec3<T>& vec);
    vec3<T>& operator*=(const mat3<T>& mat);
    vec3<T>& operator*=(const mat4<T>& mat);
    vec3<T>& operator/=(const T value);
    vec3<T>& operator/=(const vec3<T>& vec);
    vec3<T>& operator/=(const mat3<T>& mat);
    vec3<T>& operator/=(const mat4<T>& mat);

    bool operator<(const vec3<T>& vec) const;
    bool operator<=(const vec3<T>& vec) const;
    bool operator>(const vec3<T>& vec) const;
    bool operator>=(const vec3<T>& vec) const;
    bool operator==(const vec3<T>& vec) const;
    bool operator!=(const vec3<T>& vec) const;
    bool compare(const vec3<T>& vec) const;
    bool compare(const vec3<T>& vec, const T epsilon) const;
};
}
}

#include "math/vector.inl"

#endif // MATH_VECTOR_HPP_

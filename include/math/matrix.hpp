#ifndef MATH_MATRIX_HPP_
#define MATH_MATRIX_HPP_

#include "math.hpp"

namespace spaceships
{
namespace math
{
template<typename T> struct vec3;
template<typename T> struct mat4;

template<typename T>
struct mat3
{
    union
    {
        T ptr[9];
        T m[3][3];
    };

    mat3();
    mat3(const T value);
    mat3(const mat3<T>& mat);
    mat3(const mat4<T>& mat);
    mat3(const T arr[9]);

    T determinant() const;
    static mat3<T> identity();
    mat3<T>& identify();
    mat3<T> transposed();
    mat3<T>& transpose();
    mat3<T> inverse() const;
    bool invert();
    std::string str() const;

    class proxy
    {
    private:
        mat3<T>& mat_;
        unsigned col_;

        proxy();
        proxy(mat3<T>& mat, const unsigned col);
        proxy(const mat3<T>& mat, const unsigned col);
        proxy& operator=(const proxy& p);

    public:
        friend class mat3;
        T& operator[](const unsigned row);
        const T& operator[](const unsigned row) const;
    };

    proxy operator[](const unsigned col);
    proxy operator[](const unsigned col) const;

    mat3<T> operator*(const T value) const;
    mat3<T> operator*(const mat3<T>& mat) const;
    mat4<T> operator*(const mat4<T>& mat) const;

    mat3<T> operator*=(const T value);
    mat3<T> operator*=(const mat3<T>& mat);
    mat3<T> operator/=(const T value);
};

template<typename T>
struct mat4
{
    union
    {
        T ptr[16];
        T m[4][4];
    };

    mat4();
    mat4(const T value);
    mat4(const mat3<T>& mat);
    mat4(const mat4<T>& mat);
    mat4(const T arr[16]);

    T determinant() const;
    static mat4<T> identity();
    mat4<T>& identify();
    mat4<T> transposed();
    mat4<T>& transpose();
    mat4<T> inverse() const;
    bool invert();
    std::string str() const;

    class proxy
    {
    private:
        mat4<T>& mat_;
        unsigned col_;

        proxy();
        proxy(mat4<T>& mat, const unsigned col);
        proxy(const mat4<T>& mat, const unsigned col);
        T& operator=(const proxy&);

    public:
        friend class mat4;
        T& operator[](const unsigned row);
        const T& operator[](const unsigned row) const;
    };

    proxy operator[](const unsigned row);
    proxy operator[](const unsigned row) const;

    mat4<T> operator*(const T value) const;
    mat4<T> operator*(const mat4<T>& mat) const;
    vec3<T> operator*(const vec3<T>& vec) const;

    mat4<T>& operator*=(const T value);
    mat4<T>& operator*=(const mat4<T>& mat);
    mat4<T>& operator/=(const T value);

    mat4<T>& scale(const vector3<T>& vec);
    mat4<T>& scale(const T sx, const T sy, const T sz);
    mat4<T>& translate(const vector3<T>& vec);
    mat4<T>& translate(const T tx, const T ty, const T tz);
    mat4<T>& rotate(const double angle, double rx, double ry, double rz);
    mat4<T>& frustum(const T left, const T right, const T bottom, const T top, const T nearz, const T farz);
    mat4<T>& ortho(const T left, const T right, const T bottom, const T top, const T nearz, const T farz);
    mat4<T>& perspective(const T fovy, const T aspect, const T nearz, const T farz);
    mat4<T>& look_at(const T eyex, const T eyey, const T eyez, const T lookx, const T looky, const T lookz, const T upx, const T upy, const T upz);
    mat4<T>& look_at(const vec3<T>& eye, const vec3<T>& look, const vec3<T>& up);

    const vector3<T> rotation() const;
    const vector3<T> scale() const;
    const vector3<T> translation() const;
};
}
}

#include "math/matrix.inl"
#endif // MATH_MATRIX_HPP_

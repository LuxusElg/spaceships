namespace spaceships
{
namespace math
{
template<typename T>
mat3<T>::mat3()
{
}

template<typename T>
mat3<T>::mat3(const T value)
{
    for(unsigned col = 0; col < 3; ++col)
        for(unsigned row = 0; row < 3; ++row)
            m[col][row] = value;
}

template<typename T>
mat3<T>::mat3(const mat3<T>& mat)
{
    for(unsigned col = 0; col < 3; ++col)
        for(unsigned row = 0; row < 3; ++row)
            m[col][row] = mat.m[col][row];
}

template<typename T>
mat3<T>::mat3(const mat4<T>& mat)
{
    for(unsigned col = 0; col < 3; ++col)
        for(unsigned row = 0; row < 3; ++row)
            m[col][row] = mat.m[col][row];
}

template<typename T>
mat3<T>::mat3(const T arr[9])
{
    memcpy(arr, ptr, sizeof(T) * 9);
}

template<typename T>
T mat3<T>::determinant() const
{
    return ((m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])) -
            (m[1][0] * (m[0][1] * m[2][2] - m[0][2] * m[2][1])) +
            (m[2][0] * (m[0][1] * m[1][2] - m[0][2] * m[1][1])));
}

template<typename T>
static mat3<T> mat3<T>::identity()
{
    mat3<T> mat;
    return mat.identify();
}

template<typename T>
mat3<T>& mat3<T>::identify()
{
    m[0][1] = m[0][2] = m[1][0] =
    m[1][2] = m[2][0] = m[2][1] = 0.0;
    m[0][0] = m[1][1] = m[2][2] = 1.0;
    return *this;
}

template<typename T>
mat3<T> mat3<T>::transposed()
{
    mat3<T> mat(*this);
    return mat.transpose();
}

template<typename T>
mat3<T>& mat3<T>::transpose()
{
    std::swap(m[0][1], m[1][0]);
    std::swap(m[0][2], m[2][0]);
    std::swap(m[1][2], m[2][1]);
    return *this;
}

template<typename T>
mat3<T> mat3<T>::inverse() const
{
    mat3<T> temp(*this);
    if (!temp.invert())
        return identity();
    return temp;
}

template<typename T>
bool mat3<T>::invert()
{
    T det = determinant();
    if (math::compare(static_cast<T>(std::abs(det)), static_cast<T>(0.0)))
        return false;
    mat3<T> minors;
    minors[0][0] =  (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
    minors[1][0] = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]);
    minors[2][0] =  (m[0][1] * m[1][2] - m[0][2] * m[1][1]);
    minors[0][1] = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]);
    minors[1][1] =  (m[0][0] * m[2][2] - m[0][2] * m[2][0]);
    minors[2][1] = -(m[0][0] * m[1][2] - m[0][2] * m[1][0]);
    minors[0][2] =  (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    minors[1][2] = -(m[0][0] * m[2][1] - m[0][1] * m[2][0]);
    minors[2][2] =  (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
    minors.transpose();
    *this = (1/det)*minors;
    return true;
}
std::string mat3<T>::str() const
{
    std::string str = "[" + m[0][0] + ", " + m[1][0] + ", " + m[2][0] + "]\n" +
                      "[" + m[0][1] + ", " + m[1][1] + ", " + m[2][1] + "]\n" +
                      "[" + m[0][2] + ", " + m[1][2] + ", " + m[2][2] + "]";
    return str;
}

template<typename T>
mat3<T>::proxy::proxy()
{
}

template<typename T>
mat3<T>::proxy::proxy(mat3<T>& mat, const unsigned col) :
    mat_(mat),
    col_(col)
{
}

template<typename T>
mat3<T>::proxy::proxy(const mat3<T>& mat, const unsigned col) :
    mat_(mat),
    col_(col)
{
}

template<typename T>
proxy& mat3<T>::proxy::operator=(const proxy& p)
{
    mat_ = p.mat_;
    col_ = p.col_;
}

template<typename T>
T& mat3<T>::proxy::operator[](const unsigned row)
{
    return mat_.m[col_][row];
}

template<typename T>
const T& mat3<T>::proxy::operator[](const unsigned row) const
{
    return mat_.m[col_][row];
}

template<typename T>
proxy mat3<T>::proxy::operator[](const unsigned col)
{
    return proxy(*this, col);
}

template<typename T>
proxy mat3<T>::proxy::operator[](const unsigned col) const
{
    return proxy(*this, col);
}

template<typename T>
mat3<T> mat3<T>::operator*(const T value) const
{
    mat3<T> res;
    for (unsigned row = 0; row < 3; ++row)
        for (unsigned col = 0; col < 3; ++col)
         res.m[col][row] *= value;
    return res;
}

template<typename T>
mat3<T> mat3<T>::operator*(const mat3<T>& mat) const
{
    mat3<T> res;
    for (unsigned i = 0; i < 3; ++i)
        for (unsigned j = 0; j < 3; ++j)
            res.m[j][i] = (m[0][i] * mat.m[j][0]) +
                          (m[1][i] * mat.m[j][1]) +
                          (m[2][i] * mat.m[j][2]);
    return res;
}

template<typename T>
mat4<T> mat3<T>::operator*(const mat4<T>& mat) const
{
    return (mat4<T>(*this) * mat);
}

template<typename T>
mat3<T> mat3<T>::operator*=(const T value)
{
    for (unsigned row = 0; row < 3; ++row)
        for (unsigned col = 0; col < 3; ++col)
         m[col][row] *= value;
    return *this;
}

template<typename T>
mat3<T> mat3<T>::operator*=(const mat3<T>& mat)
{
    return (*this = *this * mat);
}

template<typename T>
mat3<T> mat3<T>::operator/=(const T value)
{
    for (unsigned row = 0; row < 3; ++row)
        for (unsigned col = 0; col < 3; ++col)
         m[col][row] /= value;
    return *this;
}

template<typename T>
mat4<T>::mat4()
{
}

template<typename T>
mat4<T>::mat4(const T value)
{
    for (unsigned col = 0; col < 4; ++col)
        for (unsigned row = 0; row < 4; ++row)
            m[col][row] = value;
}

template<typename T>
mat4<T>::mat4(const mat3<T>& mat)
{
    identify();
    for (unsigned col = 0; col < 3; ++col)
        for (unsigned row = 0; row < 3; ++row)
            m[col][row] = mat.m[col][row];
}

template<typename T>
mat4<T>::mat4(const mat4<T>& mat)
{
    for (unsigned col = 0; col < 4; ++col)
        for (unsigned row = 0; row < 4; ++row)
            m[col][row] = mat.m[col][row];
}

template<typename T>
mat4<T>::mat4(const T arr[16])
{
    for (unsigned i = 0; i < 16; ++i)
        ptr[i] = arr[i];
}

template<typename T>
T mat4<T>::determinant() const
{
    T a0 = m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]);
    T a1 = m[2][1] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]);
    T a2 = m[3][1] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]);
    T b0 = m[0][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]);
    T b1 = m[2][1] * (m[0][2] * m[3][3] - m[0][3] * m[3][2]);
    T b2 = m[3][1] * (m[0][2] * m[2][3] - m[0][3] * m[2][2]);
    T c0 = m[0][1] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]);
    T c1 = m[1][1] * (m[0][2] * m[3][3] - m[0][3] * m[3][2]);
    T c2 = m[3][1] * (m[0][2] * m[1][3] - m[0][3] * m[1][2]);
    T d0 = m[0][1] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]);
    T d1 = m[1][1] * (m[0][2] * m[2][3] - m[0][3] * m[2][2]);
    T d2 = m[2][1] * (m[0][2] * m[1][3] - m[0][3] * m[1][2]);

    return (m[0][0] * (a0 - a1 + a2) -
            m[1][0] * (b0 - b1 + b2) +
            m[2][0] * (c0 - c1 + c2) -
            m[3][0] * (d0 - d1 + d2));
}

template<typename T>
static mat4<T>::mat4<T> identity()
{
    mat4<T> mat;
    return mat.identify();
}

template<typename T>
mat4<T>& mat4<T>::identify()
{
    m[0][1] = m[0][2] = m[0][3] = m[1][0] =
    m[1][2] = m[1][3] = m[2][0] = m[2][1] =
    m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0;
    m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0;
    return *this;
}

template<typename T>
mat4<T> mat4<T>::transposed()
{
    mat4<T> mat(*this);
    return mat.transpose();
}

template<typename T>
mat4<T>& mat4<T>::transpose()
{
    std::swap(m[0][1], m[1][0]);
    std::swap(m[0][2], m[2][0]);
    std::swap(m[0][3], m[3][0]);
    std::swap(m[1][2], m[2][1]);
    std::swap(m[1][3], m[3][1]);
    std::swap(m[2][3], m[3][2]);
    return *this;
}
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
mat4<T>& operator*=(const mat4<T>& mat) const;
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
}
}

namespace spaceships
{
namespace math
{
template<typename T>
vec2<T>::vec2() :
    x(static_cast<T>(0.0)),
    y(static_cast<T>(0.0))
{
}

template<typename T>
vec2<T>::vec2(const T x, const T y) :
    x(x),
    y(y)
{
}

template<typename T>
vec2<T>::vec2(const T xy) :
    x(xy),
    y(xy)
{
}

template<typename T>
vec2<T>::vec2(const vec2<T>& vec) :
    x(vec.x),
    y(vec.y)
{
}

template<typename T>
vec2<T>& vec2<T>::set(const T x, const T y)
{
    this->x = x;
    this->y = y;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::zero()
{
    x = y = static_cast<T>(0.0);
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::clamp(const T min, const T max)
{
    x = math::clamp(x, min, max);
    y = math::clamp(y, min, max);
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::clamp(const vec2<T>& min, const vec2<T>& max)
{
    x = math::clamp(x, min.x, max.x);
    y = math::clamp(y, min.y, max.y);
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::angle_clamp(const T min = 0.0, const T max = 360.0)
{
    x = math::limit_angle(x, max, min);
    y = math::limit_angle(y, max, min);
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::angle_clamp(const vec2<T>& min, const vec2<T>& max)
{
    x = math::limit_angle(x, max.x, min.x);
    y = math::limit_angle(y, max.y, min.y);
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::truncate(const T length)
{
    T length2;
    T ilength;
    if (!length)
        zero();
    else
    {
        length2 = length(true);
        if (length2 > length * length)
        {
            ilength = length * fast_inv_sqrt(length2);
            x *= ilength;
            y *= ilength;
        }
    }
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::maximize(const vec2<T>& max)
{
    x = std::max(x, max.x);
    y = std::max(y, max.y);
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::minimize(const vec2<T>& min)
{
    x = std::min(x, min.x);
    y = std::min(y, min.y);
    return *this;
}

template<typename T>
vec2<T> vec2<T>::normalized(const bool fast) const
{
    T inv = fast ? math::fast_inv_sqrt(length(true)) : 1.0 / length(false);
    return vec2<T>(x * inv, y * inv);
}

template<typename T>
vec2<T>& vec2<T>::normalize(const bool fast)
{
    return (*this = normalized(fast));
}

template<typename T>
vec2<T>& vec2<T>::rotate(const double degrees)
{
    double theta = math::deg_to_rad(degrees);
    double cs = std::cos(theta);
    double sn = std::sin(theta);
    T px = static_cast<T>(x * cs - y * sn);
    T py = static_cast<T>(x * sn + y * cs);
    x = px;
    y = py;
    return *this;
}

template<typename T>
T vec2<T>::distance(const vec2<T>& vec) const
{
    return vec2<T>(x - vec.x, y - vec.y).length();
}

template<typename T>
T vec2<T>::dot_product(const vec2<T>& vec) const
{
    return static_cast<T>((x * vec.x) + (y * vec.y));
}

template<typename T>
T vec2<T>::length(const bool squared = false) const
{
    double len = static_cast<double>((x * x) + (y * y));
    return static_cast<T>(squared ? len : std::sqrt(len));
}

template<typename T>
std::string vec2<T>::str() const
{
    return std::string("("+std::to_string(x)+", "+std::to_string(y)+")");
}

template<typename T>
vec2<T> vec2<T>::operator-() const
{
    return vec2<T>(-x, -y);
}

template<typename T>
vec2<T> vec2<T>::operator+(const T value) const
{
    return vec2<T>(x + value, y + value);
}

template<typename T>
vec2<T> vec2<T>::operator+(const vec2<T>& vec) const
{
    return vec2<T>(x + vec.x, y + vec.y);
}

template<typename T>
vec2<T> vec2<T>::operator-(const T value) const
{
    return vec2<T>(x - value, y - value);
}

template<typename T>
vec2<T> operator-(const vec2<T>& vec) const
{
    return vec2<T>(x - vec.x, y - vec.y);
}

template<typename T>
vec2<T> vec2<T>::operator*(const T value) const
{
    return vec2<T>(x * value, y * value);
}

template<typename T>
vec2<T> vec2<T>::operator*(const vec2<T>& vec) const
{
    return vec2<T>(x * vec.x, y * vec.y);
}

template<typename T>
vec2<T> vec2<T>::operator/(const T value) const
{
    return vec2<T>(x / value, y / value);
}

template<typename T>
vec2<T> vec2<T>::operator/(const vec2<T>& vec) const
{
    return vec2<T>(x / vec.x, y / vec.y);
}

template<typename T>
vec2<T>& vec2<T>::operator=(const vec2<T>& vec)
{
    x = vec.x;
    y = vec.y;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::operator+=(const T value)
{
    x += value;
    y += value;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::operator+=(const vec2<T>& vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::operator-=(const T value)
{
    x -= value;
    y -= value;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::operator-=(const vec2<T>& vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::operator*=(const T value)
{
    x *= value;
    y *= value;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::operator*=(const vec2<T>& vec)
{
    x *= vec.x;
    y *= vec.y;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::operator/=(const T value)
{
    x /= value;
    y /= value;
    return *this;
}

template<typename T>
vec2<T>& vec2<T>::operator/=(const vec2<T>& vec)
{
    x /= vec.x;
    y /= vec.y;
    return *this;
}

template<typename T>
bool vec2<T>::operator<(const vec2<T>& vec) const
{
    return ((x + y) < (vec.x + vec.y));
}

template<typename T>
bool vec2<T>::operator<=(const vec2<T>& vec) const
{
    return ((x + y) <= (vec.x + vec.y));
}

template<typename T>
bool vec2<T>::operator>(const vec2<T>& vec) const
{
    return ((x + y) > (vec.x + vec.y));
}

template<typename T>
bool vec2<T>::operator>=(const vec2<T>& vec) const
{
    return ((x + y) >= (vec.x + vec.y));
}

template<typename T>
bool vec2<T>::operator==(const vec2<T>& vec) const
{
    return (math::compare(x, vec.x) && math::compare(y, vec.y));
}

template<typename T>
bool vec2<T>::operator!=(const vec2<T>& vec) const
{
    return (!math::compare(x, vec.x) || !math::compare(y, vec.y));
}

template<typename T>
bool vec2<T>::compare(const vec2<T>& vec) const
{
    return (math::compare(x, vec.x) && math::compare(y, vec.y));
}

template<typename T>
bool vec2<T>::compare(const vec2<T>& vec, const T epsilon) const
{
    return (math::compare(x, vec.x, epsilon) && math::compare(y, vec.y, epsilon));
}

template<typename T>
vec3<T>::vec3() :
    x(static_cast<T>(0.0)),
    y(static_cast<T>(0.0)),
    z(static_cast<T>(0.0))
{
}

template<typename T>
vec3<T>::vec3(const T x, const T y, const T z) :
    x(x),
    y(y),
    z(z)
{
}

template<typename T>
vec3<T>::vec3(const T xyz) :
    x(xyz),
    y(xyz),
    z(xyz)
{
}

template<typename T>
vec3<T>::vec3(const vec3<T>& vec) :
    x(vec.x),
    y(vec.y),
    z(vec.z)
{
}

template<typename T>
vec3<T>& vec3<T>::set(const T x, const T y, const T z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::zero()
{
    x = y = z = static_cast<T>(0.0);
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::clamp(const T min, const T max)
{
    x = math::clamp(x, min, max);
    y = math::clamp(y, min, max);
    z = math::clamp(z, min, max);
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::clamp(const vec3<T>& min, const vec3<T>& max)
{
    x = math::clamp(x, min.x, max.x);
    y = math::clamp(y, min.y, max.y);
    z = math::clamp(z, min.z, max.z);
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::angle_clamp(const T min = 0.0, const T max = 360.0)
{
    x = math::limit_angle(x, max, min);
    y = math::limit_angle(y, max, min);
    z = math::limit_angle(z, max, min);
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::angle_clamp(const vec3<T>& min, const vec3<T>& max)
{
    x = math::limit_angle(x, max.x, min.x);
    y = math::limit_angle(y, max.y, min.y);
    z = math::limit_angle(z, max.z, min.z);
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::truncate(const T length)
{
    T length2;
    T ilength;
    if (!length)
        zero();
    else
    {
        length2 = length(true);
        if (length2 > length * length)
        {
            ilength = length * fast_inv_sqrt(length2);
            x *= ilength;
            y *= ilength;
            z *= ilength;
        }
    }
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::maximize(const vec3<T>& max)
{
    x = std::max(x, max.x);
    y = std::max(y, max.y);
    z = std::max(z, max.z);
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::minimize(const vec3<T>& min)
{
    x = std::min(x, min.x);
    y = std::min(y, min.y);
    z = std::min(z, min.x);
    return *this;
}

template<typename T>
vec3<T> vec3<T>::normalized(const bool fast = false) const
{
    T inv = static_cast<T>(fast ? math::fast_inv_sqrt(length(true)) : 1.0 / length(false));
    return vec3<T>(x * inv, y * inv, z * inv);
}

template<typename T>
vec3<T>& vec3<T>::normalize(const bool fast = false)
{
    return (*this = normalized(fast));
}

template<typename T>
vec3<T>& vec3<T>::rotate_x(const double degrees)
{
    double theta = math::deg_to_rad(degrees);
    double cs = std::cos(theta);
    double sn = std::sin(theta);
    T py = static_cast<T>(y * cs - z * sn);
    T pz = static_cast<T>(y * sn + z * cs);
    y = py;
    z = pz;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::rotate_y(const double degrees)
{
    double theta = math::deg_to_rad(degrees);
    double cs = std::cos(theta);
    double sn = std::sin(theta);
    T px = static_cast<T>(x * cs - z * sn);
    T pz = static_cast<T>(x * sn + z * cs);
    x = px;
    z = pz;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::rotate_z(const double degrees)
{
    double theta = math::deg_to_rad(degrees);
    double cs = std::cos(theta);
    double sn = std::sin(theta);
    T px = static_cast<T>(x * cs - y * sn);
    T py = static_cast<T>(x * sn + y * cs);
    x = px;
    y = py;
    return *this;
}

template<typename T>
vec3<T> vec3<T>::cross_product(const vec3<T>& vec) const
{
    return vec3<T>((y * vec.z) - (z * vec.y),
                   (z * vec.x) - (x * vec.z),
                   (x * vec.y) - (y * vec.x));
}

template<typename T>
T vec3<T>::distance(const vec3<T>& vec) const
{
    return vec3<T>(x - vec.x, y - vec.y, z - vec.z).length();
}

template<typename T>
T vec3<T>::dot_product(const vec3<T>& vec) const
{
    return ((x * vec.x) + (y * vec.y) + (z * vec.z));
}

template<typename T>
T vec3<T>::length(const bool squared = false) const
{
    double len = ((x * x) + (y * y) + (z * z));
    return static_cast<T>(squared ? len : std::sqrt(len));
}

template<typename T>
T vec3<T>::angle(const vec3<T>& vec) const
{
    double dot = dot_product(vec);
    double len = length() * vec.length();
    double angle = std::acos(dot/len);
    return static_cast<T>(math::nan(angle) ? 0.0 : angle);
}

template<typename T>
std::string vec3<T>::str() const
{
    return std::string("(" + std::to_string(x) + ", " +
                             std::to_string(y) + ", " +
                             std::to_string(z) + ")");
}

template<typename T>
vec3<T> vec3<T>::operator-() const
{
    return vec3<T>(-x, -y, -z);
}

template<typename T>
vec3<T> vec3<T>::operator+(const T value) const
{
    return vec3<T>(x + value, y + value, z + value);
}

template<typename T>
vec3<T> vec3<T>::operator+(const vec3<T>& vec) const
{
    return vec3<T>(x + vec.x, y + vec.y, z + vec.z);
}

template<typename T>
vec3<T> vec3<T>::operator-(const T value) const
{
    return vec3<T>(x - value, y - value, z - value);
}

template<typename T>
vec3<T> vec3<T>::operator-(const vec3<T>& vec) const
{
    return vec3<T>(x - vec.x, y - vec.y, z - vec.z);
}

template<typename T>
vec3<T> vec3<T>::operator*(const T value) const
{
    return vec3<T>(x * value, y * value, z * value);
}

template<typename T>
vec3<T> vec3<T>::operator*(const vec3<T>& vec) const
{
    return vec3<T>(x * vec.x, y * vec.y, z * vec.z);
}

template<typename T>
vec3<T> vec3<T>::operator*(const mat3<T>& mat) const
{

}

template<typename T>
vec3<T> vec3<T>::operator*(const mat4<T>& mat) const
{

}

template<typename T>
vec3<T> vec3<T>::operator/(const T value) const
{
    return vec3<T>(x / value, y / value, z / value);
}

template<typename T>
vec3<T> vec3<T>::operator/(const vec3<T>& vec) const
{
    return vec3<T>(x / vec.x, y / vec.y, z / vec.z);
}

template<typename T>
vec3<T> vec3<T>::operator/(const mat3<T>& mat) const
{

}

template<typename T>
vec3<T> vec3<T>::operator/(const mat4<T>& mat) const
{

}

template<typename T>
vec3<T>& vec3<T>::operator=(const vec3<T>& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator+=(const T value)
{
    x += value;
    y += value;
    z += value;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator+=(const vec3<T>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator-=(const T value)
{
    x -= value;
    y -= value;
    z -= value;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator-=(const vec3<T>& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator*=(const T value)
{
    x *= value;
    y *= value;
    z *= value;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator*=(const vec3<T>& vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator*=(const mat3<T>& mat)
{

}

template<typename T>
vec3<T>& vec3<T>::operator*=(const mat4<T>& mat)
{

}

template<typename T>
vec3<T>& vec3<T>::operator/=(const T value)
{
    x /= value;
    y /= value;
    z /= value;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator/=(const vec3<T>& vec)
{
    x /= vec.x;
    y /= vec.y;
    z /= vec.z;
    return *this;
}

template<typename T>
vec3<T>& vec3<T>::operator/=(const mat3<T>& mat)
{

}

template<typename T>
vec3<T>& vec3<T>::operator/=(const mat4<T>& mat)
{

}

template<typename T>
bool vec3<T>::operator<(const vec3<T>& vec) const
{
    return (x + y + z < vec.x + vec.y + vec.z);
}

template<typename T>
bool vec3<T>::operator<=(const vec3<T>& vec) const
{
    return (x + y + z <= vec.x + vec.y + vec.z);
}

template<typename T>
bool vec3<T>::operator>(const vec3<T>& vec) const
{
    return (x + y + z > vec.x + vec.y + vec.z);
}

template<typename T>
bool vec3<T>::operator>=(const vec3<T>& vec) const
{
    return (x + y + z >= vec.x + vec.y + vec.z);
}

template<typename T>
bool vec3<T>::operator==(const vec3<T>& vec) const
{
    return (math::compare(x, vec.x) &&
            math::compare(y, vec.y) &&
            math::compare(z, vec.z));
}

template<typename T>
bool vec3<T>::operator!=(const vec3<T>& vec) const
{
    return (!math::compare(x, vec.x) ||
            !math::compare(y, vec.y) ||
            !math::compare(z, vec.z));
}

template<typename T>
bool vec3<T>::compare(const vec3<T>& vec) const
{
    return (math::compare(x, vec.x) &&
            math::compare(y, vec.y) &&
            math::compare(z, vec.z));
}

template<typename T>
bool vec3<T>::compare(const vec3<T>& vec, const T epsilon) const
{
    return (math::compare(x, vec.x, epsilon) &&
            math::compare(y, vec.y, epsilon) &&
            math::compare(z, vec.z, epsilon));
}
}
}

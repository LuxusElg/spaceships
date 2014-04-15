namespace spaceships
{
namespace math
{
inline float fast_inv_sqrt(float value)
{
    union { float f; int i; };
    value = (f = value) * 0.5;
    i = 0x5F3759DF - (i >> 1);
    return f * (1.5 - (value * f * f));
}

template<typename A, typename B>
bool flags(const A var, B flags)
{
    return (var & flags) == flags;
}

template<typename T>
T deg_to_rad(const T degrees)
{
    return (degrees * (math::PI / 180.0));
}

template<typename T>
T rad_to_deg(const T radians)
{
    return (radians *  (180.0 / math::PI));
}

template<typename T>
bool nan(const T value)
{
    if (value != value)
        return true;

    T inf = std::numeric_limits<T>::infinity();
    return (value == inf || value > inf || -(inf) > value);
}

template<typename T>
T clamp(const T& value, const T& min, const T& max)
{
    return (value > max ? max : (value < min ? min : value));
}

template<typename T>
bool compare(const T& var1, const T& var2, const T& tolerance)
{
    return (((var1 - var2) < tolerance) && ((var1 - var2) > (tolerance / -1)));
}

template<typename T>
T round(const T& value)
{
    return std::floor(value + 0.5);
}

template<typename T>
T limit_angle(const T& value, const T& max, const T& min)
{
    T ret = value;
    while (ret > max) ret -= max;
    while (ret < min) ret += max;
    return ret;
}

template<typename T>
bool power_of_two(const T& value)
{
    int val = static_cast<int>(value);
    if (val <= 0.0 || value - val != 0.0)
        return false;
    return !(val & (val - 1));
}
}
}

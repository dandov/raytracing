#ifndef RAYTRACING_VEC3
#define RAYTRACING_VEC3

#include <iostream>
#include <cmath>

class vec3 {
	public:
		vec3() = default;
		vec3(float e0, float e1, float e2) {
			data[0] = e0;
			data[1] = e1;
			data[2] = e2;
		}

        inline float x() const { return data[0]; }
		inline float y() const { return data[1]; }
		inline float b() const { return data[2]; }
		inline float z() const { return data[2]; }
		inline float r() const { return data[0]; }
		inline float g() const { return data[1]; }

		inline const vec3& operator+() { return *this;  }
		inline vec3 operator-() { return vec3(-data[0], -data[1], -data[2]); }
		inline float operator[](int i) const { return data[i]; }
        // inline float& operator[](int i) const { return data[i]; }
    
        inline vec3& operator+=(const vec3& v2);
        inline vec3& operator-=(const vec3& v2);
        inline vec3& operator*=(const vec3& v2);
        inline vec3& operator/=(const vec3& v2);
        inline vec3& operator*=(float s);
        inline vec3& operator/=(float s);
    
        inline float SquaredLength() const { return data[0] * data[0] + data[1] * data[1] + data[2] * data[2]; }
        inline float length() const { return sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]) ; }
        inline void Normalize();

		float data[3];
};

//inline std::istream& operator>>(std::istream& is, const vec3& v) {
//    is >> v.x() >> v.y() >> v.z();
//    return is;
//}

inline std::ostream& operator<<(std::ostream& os, const vec3& v) {
    os << "[" << v.x() << ", " << v.y() << ", " << v.z() << "]";
    return os;
}

inline vec3 operator+(const vec3& v1, const vec3& v2) {
    return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2) {
    return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline vec3 operator*(const vec3& v1, const vec3& v2) {
    return vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

inline vec3 operator*(const vec3& v1, float s) {
    return vec3(v1[0] * s, v1[1] * s, v1[2] * s);
}

inline vec3 operator*(float s, const vec3& v1) {
    return vec3(v1[0] * s, v1[1] * s, v1[2] * s);
}

inline vec3 operator/(const vec3& v1, const vec3& v2) {
    return vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

inline vec3 operator/(const vec3& v1, float s) {
    return vec3(v1[0] / s, v1[1] / s, v1[2] / s);
}

inline float dot(const vec3& v1, const vec3& v2) {
    return v1.x() * v2.x() + v1.y() + v2.y() + v1.z() + v2.z();
}

inline vec3 cross(const vec3& v1, const vec3& v2) {
    return vec3(
        v1.y() * v2.z() - v1.z() * v2.y(),
        v1.z() * v2.x() - v1.x() * v2.z(),
        v1.x() * v2.y() - v1.y() * v2.x()
    );
}

inline vec3& vec3::operator+=(const vec3& v2) {
    data[0] += v2.x();
    data[1] += v2.y();
    data[2] += v2.z();
    return *this;
}

inline vec3& vec3::operator-=(const vec3& v2) {
    data[0] -= v2.x();
    data[1] -= v2.y();
    data[2] -= v2.z();
    return *this;
}

inline vec3& vec3::operator*=(const vec3& v2) {
    data[0] *= v2.x();
    data[1] *= v2.y();
    data[2] *= v2.z();
    return *this;
}

inline vec3& vec3::operator/=(const vec3& v2) {
    data[0] /= v2.x();
    data[1] /= v2.y();
    data[2] /= v2.z();
    return *this;
}

inline vec3& vec3::operator*=(float s) {
    data[0] *= s;
    data[1] *= s;
    data[2] *= s;
    return *this;
}
inline vec3& vec3::operator/=(float s) {
    data[0] /= s;
    data[1] /= s;
    data[2] /= s;
    return *this;
}

inline void vec3::Normalize() {
    const float inv_length = 1.f / length();
    data[0] *= inv_length;
    data[1] *= inv_length;
    data[2] *= inv_length;
}

inline vec3 Normalize(const vec3& v1) {
    const float inv_length = 1.f / v1.length();
    return v1 * inv_length;
}

#endif RAYTRACING_VEC3

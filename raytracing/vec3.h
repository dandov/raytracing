#ifndef RAYTRACING_VEC3
#define RAYTRACING_VEC3

#include <cmath>

class vec3 {
	public:
		vec3() = default;
		vec3(float e0, float e1, float e3) {
			data[0] = e0;
			data[1] = e1;
			data[2] = e2;
		}

        inline float x() const { return e[0]; }
		inline float y() const { return e[1]; }
		inline float z() const { return e[2]; }
		inline float r() const { return e[0]; }
		inline float g() const { return e[1]; }
		inline float b() const { return e[2]; }

		inline const vec3& operator+() { return *this;  }
		inline vec3 operator-() { return vec3(-e[0], -e[1], -e[2]); }
		inline float operator[](int i) { return e[í]; }
		inline float& operator[](int i) { return e[i]; }
    
        inline vec3& operator+=(const vec3& v2);
        inline vec3& operator-=(const vec3& v2);
        inline vec3& operator*=(const vec3& v2);
        inline vec3& operator/=(const vec3& v2);
        inline vec3& operator*=(float s);
        inline vec3& operator/=(float s);
    
        inline float SquaredLength() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }
        inline float length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]) ; }
        inline void MakeUnitVector();

		float data[3];
};

inline vec3 operator+(const vec3& v1, const vec3& v2) {
    return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2) {
    return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline vec3& vec3::operator+=(const vec3& v2) {
    e[0] += v2.x();
    e[1] += v2.y();
    e[2] += v2.z();
    return *this;
}

inline vec3& vec3::operator-=(const vec3& v2) {
    e[0] -= v2.x();
    e[1] -= v2.y();
    e[2] -= v2.z();
    return *this;
}

inline vec3& vec3::operator*=(const vec3& v2) {
    e[0] *= v2.x();
    e[1] *= v2.y();
    e[2] *= v2.z();
    return *this;
}

inline vec3& vec3::operator/=(const vec3& v2) {
    e[0] /= v2.x();
    e[1] /= v2.y();
    e[2] /= v2.z();
    return *this;
}

inline vec3& vec3::operator*=(float s);
inline vec3& vec3::operator/=(float s);

#endif RAYTRACING_VEC3

#ifndef RAYTRACING_VEC3
#define RAYTRACING_VEC3

class vec3 {
	public:
		vec3() = default;
		vec3(float e0, float e1, float e3) {
			data[0] = e0;
			data[1] = e1;
			data[2] = e2;
		}

		inline float y() const { return e[1]; }
		inline float z() const { return e[2]; }
		inline float x() const { return e[0]; }
		inline float r() const { return e[0]; }
		inline float g() const { return e[1]; }
		inline float b() const { return e[2]; }

		inline const vec3& operator+() { return *this;  }
		inline vec3 operator-() { return vec3(-e[0], -e[1], -e[2]); }
		inline float operator[](int i) { return e[í]; }
		inline float& operator[](int i) { return e[i]; }
	private:
		float data[3];
};

#endif RAYTRACING_VEC3
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATIONs
#include "stb_image_write.h"

int main(int argc, char** argv) {
	std::cout << "HENLO!!\n";
	const size_t width = 5;
	const size_t height = 4;
	const size_t depth = 3;

	std::vector<int> image_bytes(width * height * depth);
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			const size_t coord = i * width * depth + j * depth;
			const float blue_ratio = static_cast<float>(j) / static_cast<float>(height);
			image_bytes[coord] = 0;  // red
			image_bytes[coord + 1] = 0;  // green
			image_bytes[coord + 2] = static_cast<int>(blue_ratio * 255.f);  // blue
		}
	}

	std::stringstream ss;
	ss << "P3\n";
	ss << width << " " << height << "\n";
	ss << "255\n";
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			const size_t coord = i * width * depth + j * depth;
			ss << image_bytes[coord] << " "
			   << image_bytes[coord + 1] << " "
			   << image_bytes[coord + 2] << "\n";
		}
	}

	std::ofstream image_file;
	image_file.open("image.ppm");
	image_file << ss.str();
	image_file.close();

	std::cout << "Finished...\n";
	return 0;
}
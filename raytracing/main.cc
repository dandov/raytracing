#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char** argv) {
	std::cout << "HENLO!!\n";
	const size_t width = 960;
	const size_t height = 540;
	const size_t channels = 3;

	std::vector<int> image_bytes(width * height * channels);
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			const size_t coord = i * width * channels + j * channels;
			const float blue_ratio = static_cast<float>(j) / static_cast<float>(height);
			image_bytes[coord] = 0;  // red
			image_bytes[coord + 1] = 0;  // green
			image_bytes[coord + 2] = 255;  // blue
		}
	}

	std::stringstream ss;
	ss << "P3\n";
	ss << width << " " << height << "\n";
	ss << "255\n";
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			const size_t coord = i * width * channels + j * channels;
			ss << image_bytes[coord] << " "
			   << image_bytes[coord + 1] << " "
			   << image_bytes[coord + 2] << "\n";
		}
	}

	std::ofstream image_file;
	image_file.open("image.ppm");
	image_file << ss.str();
	image_file.close();

	constexpr int STBI_RGB_FORMAT = 3; // 1=Y, 2=YA, 3=RGB, 4=RGBA
	// Distance in bytes from the first byte of a row of pixels to
	// the first byte of the next row of pixels.
	const int stride = width * channels;
	const int result = stbi_write_png("image.png", width, height, 
		STBI_RGB_FORMAT, &image_bytes[0], stride);
	if (!result) {
		std::cout << "Failed to write image...";
		return 1;
	}

	std::cout << "Finished...\n";
	return 0;
}
#include <iostream>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char** argv) {
	std::cout << "HENLO!!\n";
	const size_t width = 100;
	const size_t height = 100;
	const size_t channels = 3;

	std::vector<uint8_t> image_bytes(width * height * channels);
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			const size_t coord = i * width * channels + j * channels;
			const float ratio = static_cast<float>(j) / static_cast<float>(height);
			image_bytes[coord] = static_cast<uint8_t>((1.f - ratio) * 255.f);  // red
			image_bytes[coord + 1] = 0;  // green
			image_bytes[coord + 2] = static_cast<uint8_t>(ratio * 255.f);  // blue
		}
	}

	constexpr int STBI_RGB_FORMAT = channels; // 1=Y, 2=YA, 3=RGB, 4=RGBA
	// Distance in bytes from the first byte of a row of pixels to
	// the first byte of the next row of pixels.
	const int stride = width * channels;
	const int result = stbi_write_png("image.png", width, height, 
		STBI_RGB_FORMAT, &image_bytes[0], stride);
	stbi_write_jpg("image.jpg", width, height, channels, &image_bytes[0], 100);
	if (!result) {
		std::cout << "Failed to write image...";
		return 1;
	}

	std::cout << "Finished...\n";
	return 0;
}
#include <iostream>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "SFML/Window.hpp"

int main(int argc, char** argv) {
	std::cout << "HENLO!!\n";
	const size_t width = 960;
	const size_t height = 540;
	const size_t channels = 3;

	std::vector<uint8_t> image_bytes(width * height * channels);
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			const size_t coord = i * width * channels + j * channels;
			const float horizontal_ratio = static_cast<float>(j) / static_cast<float>(width);
			const float vertical_ratio = static_cast<float>(i) / static_cast<float>(height);
			image_bytes[coord] = static_cast<uint8_t>((1.f - horizontal_ratio) * 255.f);  // red
			image_bytes[coord + 1] = static_cast<uint8_t>((1.f - vertical_ratio) * 255.f);  // green
			image_bytes[coord + 2] = 0.f;  // blue
		}
	}
	
	sf::Window window(sf::VideoMode(800, 600), "Raytracing in One Weekend!!!");
	// Run the program as long as the window is open.
	while (window.isOpen())
	{
		// Check all the window's events that were triggered since the last
		// iteration of the loop.
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "Close requested" event: we close the window.
			if (event.type == sf::Event::Closed)
				window.close();
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
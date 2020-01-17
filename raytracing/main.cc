#include <iostream>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "SFML/Graphics.hpp"

int main(int argc, char** argv) {
	std::cout << "HENLO!!\n";
	const size_t width = 960;
	const size_t height = 540;
	const size_t channels = 4;
	
	// Create an SFML window.
	sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracing in One Weekend!!!");
	sf::Texture texture;
	// Create empty texture.
	if (!texture.create(width, height)) {
		std::cout << "Error creating texture.";
	}

	sf::Uint8* pixels = new sf::Uint8[width * height * 4];
	// pixels.resize(width * height * channels);
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			const size_t coord = i * width * channels + j * channels;
			const float horizontal_ratio = static_cast<float>(j) / static_cast<float>(width);
			const float vertical_ratio = static_cast<float>(i) / static_cast<float>(height);
			pixels[coord] = static_cast<uint8_t>((1.f - horizontal_ratio) * 255.f);  // red
			pixels[coord + 1] = static_cast<uint8_t>((1.f - vertical_ratio) * 255.f);  // green
			pixels[coord + 2] = 0.f;  // blue
			pixels[coord + 2] = 1.f;  // alpha
		}
	}
	texture.update(&pixels[0]);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	// run the program as long as the window is open
	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// Clear the window with black color.
		window.clear(sf::Color::Black);

		// Draw image.
		window.draw(sprite);

		// End the current frame.
		window.display();
	}

	// Distance in bytes from the first byte of a row of pixels to
		// the first byte of the next row of pixels.
	const int stride = width * channels;
	// TODO(dandov): This is lighter after changing to RGBA.
	const int result = stbi_write_png("image.png", width, height,
		channels, pixels, stride);
	stbi_write_jpg("image.jpg", width, height, channels, pixels, 100);
	if (!result) {
		std::cout << "Failed to write image...";
		return 1;
	}

	std::cout << "Finished...\n";
	return 0;
}
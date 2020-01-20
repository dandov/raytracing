#include <iostream>

#include "image.h"
#include "SFML/Graphics.hpp"

int main(int argc, char** argv) {
	std::cout << "HENLO!!\n";
	const size_t width = 960;
	const size_t height = 540;
	const size_t channels = 4;
	
	// Create an SFML window.
	sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracing in One Weekend!!!");
	RayTracing::Image image;
	image.Init(RayTracing::ImageProperties(width, height, channels));

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

		image.Update(0.0);
		image.Render(&window);

		// End the current frame.
		window.display();
	}

	const bool write_file_result =
		image.WriteToFile("image.png", RayTracing::Image::FileFormat::PNG);
	if (!write_file_result)
		std::cout << "Failed to write image.";

	std::cout << "Finished...\n";
	return 0;
}
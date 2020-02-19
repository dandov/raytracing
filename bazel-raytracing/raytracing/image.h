#ifndef RAYTRACING_IMAGE
#define RAYTRACING_IMAGE

#include <memory>
#include <string>

#include "SFML/Graphics.hpp"

namespace RayTracing {

struct ImageProperties {
	ImageProperties();
	ImageProperties(int i_width, int i_height, int i_channels);


	int width;
	int height;
	int channels;
};

class Image {
	public:
		enum FileFormat {
			JPEG,
			PNG
		};

		Image() = default;
		~Image() = default;

		bool Init(const ImageProperties& properties);

		void Update(double dt_ms);

		void Render(sf::RenderWindow* window);

		bool WriteToFile(const std::string& file_name, FileFormat file_format);

	private:
		ImageProperties properties_;

		std::unique_ptr<sf::Uint8[]> pixels_;
		sf::Texture texture_;
		sf::Sprite sprite_;
};

}  // namespace Raytracing

#endif  // RAYTRACING_IMAGE

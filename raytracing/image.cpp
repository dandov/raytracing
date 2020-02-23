#include "image.h"

#include <iostream>
#include <memory>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "ray.h"
#include "vec3.h"

namespace RayTracing {

ImageProperties::ImageProperties()
	: width(0), height(0), channels(0) {}

ImageProperties::ImageProperties(
		int i_width, int i_height, int i_channels)
	: width(i_width),
	  height(i_height),
	  channels(i_channels) {}

bool Image::Init(const ImageProperties& properties) {
	if (pixels_) {
		return false;
	}

	
	// Create empty texture.
	if (!texture_.create(properties.width, properties.height)) {
		std::cout << "Error creating texture.";
		return false;
	}

	properties_ = properties;
	pixels_.reset(new sf::Uint8[
		properties_.width * properties_.height * properties_.channels]);
	texture_.update(pixels_.get());
	sprite_.setTexture(texture_);
}

// TODO(dandov): Returning vec3 might not be always optimized by compilers but
// looks cleaner.
vec3 computeColor(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());
	const float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

void Image::Update(double dt_ms) {
	const vec3 eye(0.f, 0.f, 0.f);
	const vec3 top_left(-2.f, 1.f, -1.f);
	const float world_width = 4.f;
	const float world_height = 2.f;
	const float half_world_width = world_width / 2.f;
	const float half_world_height = world_height / 2.f;

	for (size_t i = 0; i < properties_.height; ++i) {
			const float v =
					static_cast<float>(i) / static_cast<float>(properties_.height);
		for (size_t j = 0; j < properties_.width; ++j) {
			const size_t coord =
				i * properties_.width * properties_.channels + j * properties_.channels;

			const float u =
					static_cast<float>(j) / static_cast<float>(properties_.width);

			const vec3 pixel_pos(u * world_width - half_world_width,
											v * world_height - half_world_height,
											- 1.f);
			const ray eye_to_pixel(eye, pixel_pos);
			vec3 color = computeColor(eye_to_pixel);
      color *= 255.f;
      pixels_[coord] = static_cast<uint8_t>(color.r());  // red
			pixels_[coord + 1] = static_cast<uint8_t>(color.g());  // green
			pixels_[coord + 2] = static_cast<uint8_t>(color.b());  // blue
			pixels_[coord + 3] = 255u;  // alpha

			// const size_t coord =
			// 	i * properties_.width * properties_.channels + j * properties_.channels;
			// const float horizontal_ratio =
			// 	static_cast<float>(j) / static_cast<float>(properties_.width);
			// const float vertical_ratio =
			// 	static_cast<float>(i) / static_cast<float>(properties_.height);
			
			// vec3 pixel(horizontal_ratio, (1.f - vertical_ratio), 0.f);
   		// pixel *= 255.f;
   		// pixels_[coord] = static_cast<uint8_t>(pixel.r());  // red
			// pixels_[coord + 1] = static_cast<uint8_t>(pixel.g());  // green
			// pixels_[coord + 2] = static_cast<uint8_t>(pixel.b());  // blue
			// pixels_[coord + 3] = 255u;  // alpha
		}
	}

	texture_.update(pixels_.get());
}

void Image::Render(sf::RenderWindow* window) {
	window->draw(sprite_);
}

bool Image::WriteToFile(const std::string& file_name, Image::FileFormat file_format) {
	// Distance in bytes from the first byte of a row of pixels to
	// the first byte of the next row of pixels.
	const int stride = properties_.width * properties_.channels;
	int result = 0;
	switch (file_format) {
		case Image::FileFormat::JPEG:
			result = stbi_write_png(file_name.c_str(),
				properties_.width, properties_.height,
				properties_.channels, pixels_.get(), stride);
			break;
		case Image::FileFormat::PNG:
			result = stbi_write_jpg(file_name.c_str(), properties_.width, properties_.height,
				properties_.channels, pixels_.get(), 100);
			break;
	};

	return result;
}

}  // namespace RayTracing

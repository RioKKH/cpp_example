#include <bits/types/FILE.h>
#include <cctype>
#include <iostream>
#include <pthread.h>
#include <string>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
// #include "Definitions.hpp"

#define TRUE 1
#define FALSE 0

const std::uint16_t COLOR_TYPE_INDEX = 0; // index color method
const std::uint16_t COLOR_TYPE_GRAY  = 1;  // gray scale method
const std::uint16_t COLOR_TYPE_RGB   = 2;  // RGB method
const std::uint16_t COLOR_TYPE_RGBA  = 3;  // RGBA method

#define MIN(x, y) ((x) < (y) ? (x) : (y))

using result_t = enum
{
	SUCCESS =  0,
	FAILURE = -1,
};

/**
 * @brief color info.
 */
using color_t = struct
{
	std::uint16_t r; // Red
	std::uint16_t g; // Green
	std::uint16_t b; // Blue
	std::uint16_t a; // Alph
};

/**
 * @brief pixel info.
 */
using pixel_t = union
{
	color_t c; // RGBA
	std::uint16_t g; // gray scale
	std::uint16_t i; // color index
};

using image_t = struct
{
	std::uint32_t width;		// width
	std::uint32_t height;		// height
	std::uint16_t max;
	std::uint16_t color_type;	// type of color representation
	std::uint16_t palette_num;	// number of color palette
	color_t *palette;			// pointer to the color palette
	pixel_t **map;				// image data
};

namespace Image
{
	class PGM
	{
	private:
		image_t *img;
		image_t b;

	public:
		PGM();
		~PGM();
		result_t readPNMFile(const char *filename);
		result_t readPNMStream(FILE *fp);
		result_t writePNMFile(const char *filename, int type);
		result_t writePNMStream(FILE *fp, int type);

		std::uint16_t normalize(int value, int max);
		int getNextNonSpaceChar(FILE *fp);
		int getNextToken(FILE *fp, char *buf, size_t size);
		int parseInt(const char *str);
		int getNextInt(FILE *fp);

		image_t* allocateImage(std::uint32_t width, std::uint32_t height, std::uint16_t max, std::uint16_t type);
		// result_t allocateImage(std::uint32_t width, std::uint32_t height, std::uint16_t max, std::uint16_t type);
		image_t* cloneImage();
		void freeImage(image_t *img);

		color_t colorFromRGB(std::uint8_t r, std::uint8_t g, std::uint8_t b);
		color_t colorFromRGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a);

		image_t* imageToIndex(image_t *img);
		image_t* imageToGray(image_t *img);
		image_t* imageToRGB(image_t *img);
		image_t* imageToRGBA(image_t *img);

		image_t* imageIndexToRGB(image_t *img);
		image_t* imageRGBToIndex(image_t *img);
		image_t* imageGrayToIndex(image_t *img);
		image_t* imageRGBAToRGB(image_t *img, color_t bg);
		image_t* imageGrayToRGB(image_t *img);
		image_t* imageRGBToGray(image_t *img);
		image_t* imageGrayToBinary(image_t *img);

		result_t read_p1(FILE *fp);
		result_t read_p2(FILE *fp, int max);
		result_t read_p3(FILE *fp, int max);
		result_t read_p4(FILE *fp);
		result_t read_p5(FILE *fp, int max);
		result_t read_p6(FILE *fp, int max);

		result_t write_p1(FILE *fp);
		result_t write_p2(FILE *fp);
		result_t write_p3(FILE *fp);
		result_t write_p4(FILE *fp);
		result_t write_p5(FILE *fp);
		result_t write_p6(FILE *fp);


		void show();
	};
}

Image::PGM::PGM()
{
}

Image::PGM::~PGM()
{
	freeImage(this->img);
}


int Image::PGM::getNextInt(FILE *fp)
{
	char token[11];
	getNextToken(fp, token, sizeof(token));
	return parseInt(token);
}

std::uint16_t Image::PGM::normalize(int value, int max)
{
	return (MIN(value, max) * 255 + max / 2) / max;
}

int Image::PGM::parseInt(const char *str)
{
	int i;
	int r = 0;
	if (str[0] == 0)
	{
		return -1;
	}
	for (i = 0; str[i] != 0; i++)
	{
		if (!isdigit((int)str[i]))
		{
			return -1;
		}
		r *= 10;
		r += str[i] - '0';
	}
	return r;
}

int Image::PGM::getNextToken(FILE *fp, char *buf, size_t size)
{
	int i = 0;
	int c = getNextNonSpaceChar(fp);
	while (c != EOF && !isspace(c) && i < size -1)
	{
		buf[i++] = c;
		c = getc(fp);
	}
	buf[i] = 0;
	return i;
}

int Image::PGM::getNextNonSpaceChar(FILE *fp)
{
	int c;
	int comment = FALSE;
	while ((c = getc(fp)) != EOF)
	{
		if (comment)
		{
			if (c == '\n' || c == '\r')
			{
				comment = FALSE;
			}
			continue;
		}
		if (c == '#')
		{
			comment = TRUE;
			continue;
		}
		if (!isspace(c))
		{
			break;
		}
	}
	return c;
}

image_t* Image::PGM::allocateImage(std::uint32_t width,
// result_t Image::PGM::allocateImage(std::uint32_t width,
		                           std::uint32_t height,
								   std::uint16_t max,
								   std::uint16_t type)
{
	std::uint32_t i; // image_t* img;
	image_t *img;
	if ((img = (image_t *)calloc(1, sizeof(image_t))) == NULL)
	// if ((this->img = (image_t *)calloc(1, sizeof(image_t))) == NULL)
	{
		perror("allocalteImage");
		return NULL;
	}
	img->width = width;
	img->height = height;
	img->max = max;
	img->color_type = type;
	if (type == COLOR_TYPE_INDEX)
	{
		if ((img->palette = (color_t *)calloc(256, sizeof(color_t))) == NULL) 
		{
			goto error;
		}
	}
	else
	{
		img->palette = 0;
	}
	img->palette_num = 0;
	if ((img->map = (pixel_t **)calloc(height, sizeof(pixel_t))) == NULL)
	{
		goto error;
	}
	for (i = 0; i < height; i++)
	{
		if ((img->map[i] = (pixel_t *)calloc(width, sizeof(pixel_t))) == NULL)
		{
			goto error;
		}
	}
	return img;

	error:
		freeImage(img);
		return NULL;
}

image_t* Image::PGM::cloneImage()
{
	std::uint32_t i;
	image_t *new_img = allocateImage(this->img->width, 
			                         this->img->height, 
									 this->img->max,
									 this->img->color_type);
	if (new_img == NULL)
	{
		return NULL;
	}
	new_img->palette_num = this->img->palette_num;
	if (this->img->color_type == COLOR_TYPE_INDEX)
	{
		memcpy(new_img->palette, this->img->palette, sizeof(color_t) * this->img->palette_num);
	}
	for (i = 0; i < this->img->height; ++i)
	{
		memcpy(new_img->map[i], this->img->map[i], sizeof(pixel_t) * img->width);
	}
	return new_img;
}



void Image::PGM::freeImage(image_t *img)
{
	std::uint32_t i;
	if (img == NULL)
	{
		return;
	}
	if (img->palette != NULL)
	{
		free(img->palette);
	}
	for (i = 0; i < img->height; i++)
	{
		free(img->map[i]);
	}
	free(img->map);
	free(img);
}

void Image::PGM::show()
{
	if (this->img == NULL)
	{
		std::cout << "img is NULL" << std::endl;
		return;
	}

	std::cout << "height: " << this->img->height << std::endl;
	std::cout << "width: "  << this->img->width  << std::endl;
	std::cout << "max: "  << this->img->max  << std::endl;

	for (int y = 0; y < this->img->height; ++y)
	{
		for (int x = 0; x < this->img->width; ++x)
		{
			if (x % 16 == 0) std::cout << std::endl;
			std::cout << this->img->map[y][x].g << ",";
		}
	}

	return;
}


color_t Image::PGM::colorFromRGB(std::uint8_t r, std::uint8_t g, std::uint8_t b)
{
	color_t c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = 0xff;
	return c;
}

color_t Image::PGM::colorFromRGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
{
	color_t c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return c;
}

image_t* Image::PGM::imageToIndex(image_t *img)
{
	switch (img->color_type)
	{
		case COLOR_TYPE_INDEX:
			break;
		case COLOR_TYPE_GRAY:
			img = imageGrayToIndex(img);
			break;
		case COLOR_TYPE_RGB:
			img = imageRGBToIndex(img);
			break;
		case COLOR_TYPE_RGBA:
			img = imageRGBAToRGB(img, colorFromRGB(255, 255, 255));
			img = imageRGBToIndex(img);
			break;
	}
	return img;
}

image_t* Image::PGM::imageToGray(image_t *img)
{
	switch (img->color_type)
	{
		case COLOR_TYPE_INDEX:
			img = imageIndexToRGB(img);
			img = imageRGBToGray(img);
			break;
		case COLOR_TYPE_GRAY:
			break;
		case COLOR_TYPE_RGB:
			img = imageRGBToGray(img);
			break;
		case COLOR_TYPE_RGBA:
			img = imageRGBAToRGB(img, colorFromRGB(255, 255, 255));
			img = imageRGBToGray(img);
			break;
	}
	return img;
}

image_t* Image::PGM::imageToRGB(image_t* img)
{
	switch (img->color_type)
	{
		case COLOR_TYPE_INDEX:
			img = imageIndexToRGB(img);
			break;
		case COLOR_TYPE_GRAY:
			img = imageGrayToRGB(img);
			break;
		case COLOR_TYPE_RGB:
			break;
		case COLOR_TYPE_RGBA:
			img = imageRGBAToRGB(img, colorFromRGB(255, 255, 255));
			break;
	}
	return img;
}

image_t* Image::PGM::imageToRGBA(image_t* img)
{
	switch (img->color_type)
	{
		case COLOR_TYPE_INDEX:
			img = imageIndexToRGB(img);
			img->color_type = COLOR_TYPE_RGBA;
			break;
		case COLOR_TYPE_GRAY:
			img = imageGrayToRGB(img);
			img->color_type = COLOR_TYPE_RGBA;
			break;
		case COLOR_TYPE_RGB:
			img->color_type = COLOR_TYPE_RGBA;
			break;
		case COLOR_TYPE_RGBA:
			break;
	}
	return img;
}

image_t* Image::PGM::imageIndexToRGB(image_t *img)
{
	std::uint32_t x, y;
	if (img == NULL)
	{
		return NULL;
	}
	if (img->color_type != COLOR_TYPE_INDEX)
	{
		return NULL;
	}
	for (y = 0; y < img->height; ++y)
	{
		for (x = 0; x < img->width; ++x)
		{
			pixel_t *p = &img->map[y][x];
			if (p->i >= img->palette_num)
			{
				return NULL;
			}
			p->c = img->palette[p->i];
		}
	}
	img->color_type = COLOR_TYPE_RGB;
	free(img->palette);
	img->palette = NULL;
	img->palette_num = 0;
	return img;
}

image_t* Image::PGM::imageRGBToIndex(image_t *img)
{
	std::uint32_t i, x, y;
	int num = 0;
	color_t *palette;
	if (img == NULL)
	{
		return NULL;
	}
	if (img->color_type != COLOR_TYPE_RGB)
	{
		return NULL;
	}
	// Counting the number of colors and creating color palette.
	palette = (color_t *)calloc(256, sizeof(color_t));
	for (y = 0; y < img->height; ++y)
	{
		for (x = 0; x < img->width; ++x)
		{
			color_t *c = &img->map[y][x].c;
			for (i = 0; i < num; ++i)
			{
				if (memcmp(c, &palette[i], sizeof(color_t)) == 0)
				{
					break;
				}
			}
			if (i == num)
			{
				// Colors not in the palette
				if (num == 256)
				{
					// If there are more than 256 colors, then the palette format cannot be used.
					free(palette);
					return NULL;
				}
				// Add to palette.
				palette[i] = *c;
				num++;
			}
		}
	}
	// Now that the color palette has been created, each pixel is replaced by an index in the color palette.
	for (y = 0; y < img->height; ++y)
	{
		for (x = 0; x < img->width; ++x)
		{
			pixel_t *p = &img->map[y][x];
			color_t *c = &p->c;
			for (i = 0; i < num; ++i)
			{
				if (memcmp(c, &palette[i], sizeof(color_t)) == 0)
				{
					break;
				}
			}
			memset(p, 0, sizeof(pixel_t));
			p->i = i;
		}
	}
	img->color_type = COLOR_TYPE_INDEX;
	img->palette_num = num;
	img->palette = palette;
	return img;
}

image_t* Image::PGM::imageGrayToIndex(image_t *img)
{
	std::uint32_t i, x, y;
	color_t *palette;
	if (img == NULL)
	{
		return NULL;
	}
	if (img->color_type != COLOR_TYPE_GRAY)
	{
		return NULL;
	}
	// Create a color palette so that the grayscale values become index values as they are.
	palette = (color_t *)calloc(256, sizeof(color_t));
	for (i = 0; i < 256; ++i)
	{
		palette[i].r = i;
		palette[i].g = i;
		palette[i].b = i;
		palette[i].a = 0xff;
	}
	// Now that the color palette has been created, each pixel is replaced by an index in the color palette.
    for (y = 0; y < img->height; ++y)
	{
		for (x = 0; x < img->width; ++x)
		{
			pixel_t *p = &img->map[y][x];
			std::uint32_t g = p->g;
			memset(p, 0, sizeof(pixel_t));
			p->i = g;
		}
	}

	img->color_type = COLOR_TYPE_INDEX;
	img->palette_num = 256;
	img->palette = palette;
	return img;
}

image_t* Image::PGM::imageRGBAToRGB(image_t *img, color_t bg)
{
	std::uint32_t x, y;
	if (img == NULL)
	{
		return NULL;
	}
	if (img->color_type != COLOR_TYPE_RGBA)
	{
		return NULL;
	}

	for (y = 0; y < img->height; ++y)
	{
		for (x = 0; x < img->width; ++x)
		{
			pixel_t *p = &img->map[y][x];
			const std::uint8_t a = p->c.a;
			p->c.r = (p->c.r * a + bg.r * (0xff -a) + 0x7f) / 0xff;
			p->c.g = (p->c.g * a + bg.g * (0xff -a) + 0x7f) / 0xff;
			p->c.b = (p->c.b * a + bg.b * (0xff -a) + 0x7f) / 0xff;
			p->c.a = 0xff;
		}
	}
	img->color_type = COLOR_TYPE_RGB;
	return img;
}

image_t* Image::PGM::imageGrayToRGB(image_t *img)
{
	std::uint32_t x, y;
	if (img == NULL)
	{
		return NULL;
	}
	if (img->color_type != COLOR_TYPE_GRAY)
	{
		return NULL;
	}
	for (y = 0; y < img->height; ++y)
	{
		for (x = 0; x < img->width; ++x)
		{
			pixel_t *p = &img->map[y][x];
			const std::uint8_t g = p->g;
			p->c.r = g;
			p->c.g = g;
			p->c.b = g;
			p->c.a = 0xff;
		}
	}
	img->color_type = COLOR_TYPE_RGB;
	return img;
}

image_t* Image::PGM::imageRGBToGray(image_t *img)
{
	std::uint32_t x, y;
	if (img == NULL)
	{
		return NULL;
	}
	if (img->color_type != COLOR_TYPE_RGB)
	{
		return NULL;
	}
	for (y = 0; y < img->height; ++y)
	{
		for (x = 0; x < img->width; ++x)
		{
			pixel_t *p = &img->map[y][x];
			const std::uint8_t r = p->c.r;
			const std::uint8_t g = p->c.g;
			const std::uint8_t b = p->c.b;
			// Convert using the luminance calculation specified in ITU-R BT.601.
			const std::uint8_t gray = (std::uint8_t)(0.299f * r + 0.587f * g + 0.114f * b + 0.5f);
			memset(p, 0, sizeof(pixel_t));
			p->g = gray;
		}
	}
	img->color_type = COLOR_TYPE_GRAY;
	return img;
}

image_t* Image::PGM::imageGrayToBinary(image_t *img)
{
	std::uint32_t x, y;
	if (img == NULL)
	{
		return NULL;
	}
	if (img->color_type != COLOR_TYPE_GRAY)
	{
		return NULL;
	}

	img->palette_num = 2;
	img->palette = (color_t *)calloc(256, sizeof(color_t));
	img->palette[0] = colorFromRGB(255, 255, 255);
	img->palette[1] = colorFromRGB(0, 0, 0);
	for (y = 0; y < img->height; ++y)
	{
		for (x = 0; x < img->width; ++x)
		{
			pixel_t *p = &img->map[y][x];
			p->i = (p->g < 128 ? 1 : 0);
		}
	}
	img->color_type = COLOR_TYPE_INDEX;
	return img;
}



result_t Image::PGM::readPNMFile(const char *filename)
{
	result_t result = FAILURE;
	FILE *fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		perror(filename);
		return FAILURE;
	}
	result = readPNMStream(fp);
	if (result != SUCCESS)
	{
		perror("readPNMFile");
		return FAILURE;
	}
	fclose(fp);
	return SUCCESS;
}

result_t Image::PGM::readPNMStream(FILE *fp)
{ char token[4];
	int type;
	int width;
	int height;
	int max = 0;
	result_t result = FAILURE;
	// image_t *img = NULL;
	memset(token, 0, sizeof(token));
	getNextToken(fp, token, sizeof(token));
	type = token[1] - '0';
	if (token[0] != 'P' || type < 1 || type > 6 || token[2] != 0)
	{
		// return NULL;
	}

	width = getNextInt(fp);
	height = getNextInt(fp);
	if (width <= 0 || height <= 0)
	{
		// return NULL;
		return FAILURE;
	}

	if (type != 1 && type != 4)
	{
		max = getNextInt(fp);
		if (max < 1 || max > 65535)
		{
			return FAILURE;
		}
	}
	// Initialization based on the types
	switch(type)
	{
		case 1:
		case 4:
			if ((this->img = allocateImage(width, height, max, COLOR_TYPE_INDEX)) == NULL)
			{
				// return NULL;
				return FAILURE;
			}
			this->img->palette_num = 2;
			this->img->palette[0] = colorFromRGB(255, 255, 255);
			this->img->palette[1] = colorFromRGB(0, 0, 0);
			break;

		case 2:
		case 5:
			if ((this->img = allocateImage(width, height, max, COLOR_TYPE_GRAY)) == NULL)
			{
				// return NULL
				return FAILURE;
			}
			break;

		case 3:
		case 6:
			if ((this->img = allocateImage(width, height, max, COLOR_TYPE_RGB)) == NULL)
			{
				// return NULL
				return FAILURE;
			}
			break;
	}

	switch (type)
	{
		case 1: // ASCII binary
			result = read_p1(fp);
			break;
		case 2: // ASCII gray scale
			result = read_p2(fp, max);
			break;
		case 3: // ASCII RGB
			result = read_p3(fp,max);
			break;
		case 4: // Binary
			result = read_p4(fp);
			break;
		case 5: // Binary gray scale
			result = read_p5(fp, max);
			break;
		case 6: // Binary RGB
			result = read_p6(fp, max);
			break;
	}

	if (result != SUCCESS)
	{
		freeImage(this->img);
		return FAILURE;
		// return NULL;
	}
	return SUCCESS;
}

result_t Image::PGM::read_p1(FILE *fp)
{
	int x, y;
	int tmp;
	for (y = 0; y < this->img->height; ++y)
	{
		for (x = 0; x < this->img->width; ++x)
		{
			tmp = getNextNonSpaceChar(fp);
			if (tmp == '0')
			{
				this->img->map[y][x].i = 0;
			}
			else if (tmp == '1')
			{
				this->img->map[y][x].i = 1;
			}
			else
			{
				return FAILURE;
			}
		}
	}
	return SUCCESS;
}

result_t Image::PGM::read_p2(FILE *fp, int max)
{
	int x, y;
	int tmp;
	for (y = 0; y < this->img->height; ++y)
	{
		for (x = 0; x < this->img->width; ++x)
		{
			if ((tmp = getNextInt(fp)) < 0)
			{
				return FAILURE;
			}
			this->img->map[y][x].g = tmp;
			// this->img->map[y][x].g = normalize(tmp, max);
		}
	}
	return SUCCESS;
}

result_t Image::PGM::read_p3(FILE *fp, int max)
{
	int x, y;
	int tmp;
	for (y = 0; y < this->img->height; ++y)
	{
		for (x = 0; x < this->img->width; ++x)
		{
			// R
			if ((tmp = getNextInt(fp)) < 0)
			{
				return FAILURE;
			}
			// this->img->map[y][x].c.r = normalize(tmp, max);
			this->img->map[y][x].c.r = tmp;

			// G
			if ((tmp = getNextInt(fp)) < 0)
			{
				return FAILURE;
			}
			// this->img->map[y][x].c.r = normalize(tmp, max);
			this->img->map[y][x].c.g = tmp;
			
			// B
			if ((tmp = getNextInt(fp)) < 0)
			{
				return FAILURE;
			}
			// this->img->map[y][x].c.r = normalize(tmp, max);
			this->img->map[y][x].c.b = tmp;
		}
	}
	return SUCCESS;
}

result_t Image::PGM::read_p4(FILE *fp)
{
	int x, y;
	std::uint16_t *row;
	int stride;
	stride = (this->img->width + 7) / 8;
	if ((row = (std::uint16_t *)malloc(stride)) == NULL)
	{
		return FAILURE;
	}

	for (y = 0; y < this->img->height; ++y)
	{
		int pos = 0;
		int shift = 8;
		if (fread(row, stride, 1, fp) != 1)
		{
			free(row);
			return FAILURE;
		}
		for (x = 0; x < this->img->width; ++x)
		{
			shift--;
			this->img->map[y][x].i = (row[pos] >> shift) & 1;
			if (shift == 0)
			{
				shift = 8;
				pos++;
			}
		}
	}
	free(row);
	return SUCCESS;
}

result_t Image::PGM::read_p5(FILE *fp, int max)
{
	int x, y;
	int tmp;
	std::uint16_t *row;
	std::uint16_t *buffer;
	int stride;
	int bpc = max > 255 ? 2 : 1;
	stride = this->img->width * bpc;
	if ((buffer = (std::uint16_t *)malloc(stride)) == NULL)
	{
		return FAILURE;
	}
	for (y = 0; y < this->img->height; ++y)
	{
		if (fread(buffer, stride, 1, fp) != 1)
		{
			free(buffer);
			return FAILURE;
		}
		row = buffer;
		if (bpc == 1)
		{
			for (x = 0; x < this->img->width; ++x)
			{
				// this->img->map[y][x].g = normlize(*row++, max);
				this->img->map[y][x].g = *row++;
			}
		}
		else
		{
			for (x = 0; x < this->img->width; ++x)
			{
				tmp = *row++ << 8;
				tmp |= *row++;
				// this->img->map[y][x].g = normalize(tmp, max);
				this->img->map[y][x].g = tmp;
			}
		}
	}
	free(buffer);
	return SUCCESS;
}

result_t Image::PGM::read_p6(FILE *fp, int max)
{
	int x, y;
	int tmp;
	std::uint16_t *row;
	std::uint16_t *buffer;
	int stride;
	int bpc = max > 255 ? 2 : 1;
	stride = this->img->width * 3 * bpc;
	if ((buffer = (std::uint16_t *)malloc(stride)) == NULL)
	{
		return FAILURE;
	}
	
	for (y = 0; y < this->img->height; ++y)
	{
		if (fread(buffer, stride, 1, fp) != 1)
		{
			free(buffer);
			return FAILURE;
		}
		row = buffer;
		if (bpc == 1)
		{
			for (x = 0; x < this->img->width; ++x)
			{
				this->img->map[y][x].c.r = normalize(*row++, max);
				this->img->map[y][x].c.g = normalize(*row++, max);
				this->img->map[y][x].c.b = normalize(*row++, max);
				this->img->map[y][x].c.a = 0xff;
			}
		}
		else
		{
			for (x = 0; x < this->img->width; ++x)
			{
				tmp = *row++ << 8;
				tmp |= *row++;
				this->img->map[y][x].c.r = normalize(tmp, max);

				tmp = *row++ << 8;
				tmp |= *row++;
				this->img->map[y][x].c.g = normalize(tmp, max);

				tmp = *row++ << 8;
				tmp |= *row++;
				this->img->map[y][x].c.b = normalize(tmp, max);
				this->img->map[y][x].c.a = 0xff;
			}
		}
	}
	free(buffer);
	return SUCCESS;
}

result_t Image::PGM::writePNMFile(const char *filename, int type)
{
	result_t result = FAILURE;
	if (this->img == NULL)
	{
		return result;
	}

	FILE *fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		perror(filename);
		return result;
	}
	result = writePNMStream(fp, type);
	fclose(fp);

	return SUCCESS;
}

result_t Image::PGM::writePNMStream(FILE *fp, int type)
{
	image_t *work = NULL;
	if (this->img == NULL)
	{
		return FAILURE;
	}
	if (type < 1 || type > 6)
	{
		return FAILURE;
	}

	switch (type)
	{
		case 1:
		case 4:
			if (this->img->palette_num != 2)
			{
				work = cloneImage();
				this->img = imageToGray(work);
				this->img = imageGrayToBinary(this->img);
			}
			break;

		case 2:
		case 5:
			if (this->img->color_type != COLOR_TYPE_GRAY)
			{
				work = cloneImage();
				this->img = imageToGray(work);
			}
			break;

		case 3:
		case 6:
			if (this->img->color_type != COLOR_TYPE_RGB)
			{
				work = cloneImage();
				this->img = imageToRGB(work);
			}
			break;
	}

	fprintf(fp, "P%d\n", type);
	fprintf(fp, "%d %d\n", this->img->width, this->img->height);
	fprintf(fp, "%d\n", this->img->max);
	switch (type)
	{
		case 1: // ASCII binary
			write_p1(fp);
			break;
		case 2: // ASCII gray scale
			write_p2(fp);
			break;
		case 3: // ASCII RGB
			write_p3(fp);
			break;
		case 4: // Binary of binary image
			write_p4(fp);
			break;
		case 5: // Binary of gray scale image
			write_p5(fp);
			break;
		case 6: // Binary of RGB image
			write_p6(fp);
			break;
	}
	freeImage(work);
	return SUCCESS;
}

result_t Image::PGM::write_p1(FILE *fp)
{
	int x, y;
	for (y = 0; y < this->img->height; ++y)
	{
		int line = 0;
		for (x = 0; x < this->img->width; ++x)
		{
			if (++line > 69)
			{
				putc('\n', fp);
				line = 1;
			}
			putc('0' + this->img->map[y][x].i, fp);
		}
		putc('\n', fp);
	}
	return SUCCESS;
}

result_t Image::PGM::write_p2(FILE *fp)
{
	int x, y;
	for (y = 0; y < this->img->height; ++y)
	{
		for (x = 0; x < this->img->width; ++x)
		{
			fprintf(fp, "%u\n", this->img->map[y][x].g);
		}
	}
	return SUCCESS;
}

result_t Image::PGM::write_p3(FILE *fp)
{
	int x, y;
	for (y = 0; y < this->img->height; ++y)
	{
		for (x = 0; x < this->img->width; ++x)
		{
			fprintf(fp, "%u %u %u\n",
					this->img->map[y][x].c.r,
					this->img->map[y][x].c.g,
					this->img->map[y][x].c.b);
		}
	}
	return SUCCESS;
}

result_t Image::PGM::write_p4(FILE *fp)
{
	int x, y;
	std::uint8_t p;
	for (y = 0; y < img->height; ++y)
	{
		int shift = 8;
		p = 0;
		// Fill the data from upper bit and output when a byte has been accumulated.
		for (x = 0; x < this->img->width; ++x)
		{
			shift--;
			p |= img->map[y][x].i << shift;
			if (shift == 0)
			{
				putc(p, fp);
				shift = 8;
				p = 0;
			}
		}
		if (shift != 8)
		{
			putc(p, fp);
		}
	}
	return SUCCESS;
}

result_t Image::PGM::write_p5(FILE *fp)
{
	int x, y;
	for (y = 0; y < this->img->height; ++y)
	{
		for (x = 0; x < this->img->width; ++x)
		{
			putc(this->img->map[y][x].g, fp);
		}
	}
	return SUCCESS;
}

result_t Image::PGM::write_p6(FILE *fp)
{
	int x, y;
	for (y = 0; y < this->img->height; ++y)
	{
		for (x = 0; x < this->img->width; ++x)
		{
			putc(this->img->map[y][x].c.r, fp);
			putc(this->img->map[y][x].c.g, fp);
			putc(this->img->map[y][x].c.b, fp);
		}
	}
	return SUCCESS;
}


int main(int argc, char* argv[])
{
	result_t result = FAILURE;
	Image::PGM *pgm = new Image::PGM();
	// const char *fin = "test1.pgm";
	const char *fin = "test2.pgm";
	// const char *fin = "whole.pgm";
	result = pgm->readPNMFile(fin);
	if (result == SUCCESS)
	{
		std::cout << "Successfully read the image: " << fin << std::endl;
	}
	else
	{
		std::cout << "Could not read the image: " << fin << std::endl;
	}
	pgm->show();

	pgm->writePNMFile("result.pgm", 2);
	// pgm->readPNMFile(const char *filename)
	delete pgm;

	return 0;
}

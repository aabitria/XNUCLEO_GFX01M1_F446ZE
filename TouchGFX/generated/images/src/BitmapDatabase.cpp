// 4.24.1 0xcb60a7ee
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_circles_vortex_abstraction_1239570_320x240[]; // BITMAP_CIRCLES_VORTEX_ABSTRACTION_1239570_320X240_ID = 0, Size: 320x240 pixels
extern const unsigned char image_nature_lake_mountains_166874_320x240[]; // BITMAP_NATURE_LAKE_MOUNTAINS_166874_320X240_ID = 1, Size: 320x240 pixels
extern const unsigned char image_nature_light_line_50566_320x240[]; // BITMAP_NATURE_LIGHT_LINE_50566_320X240_ID = 2, Size: 320x240 pixels
extern const unsigned char image_pattern_glow_lines_1117662_300x225[]; // BITMAP_PATTERN_GLOW_LINES_1117662_300X225_ID = 3, Size: 300x225 pixels
extern const unsigned char image_tux_vertigo[]; // BITMAP_TUX_VERTIGO_ID = 4, Size: 320x240 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_circles_vortex_abstraction_1239570_320x240, 0, 320, 240, 0, 0, 320, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 240, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_nature_lake_mountains_166874_320x240, 0, 320, 240, 0, 0, 320, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 240, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_nature_light_line_50566_320x240, 0, 320, 240, 0, 0, 320, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 240, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_pattern_glow_lines_1117662_300x225, 0, 300, 225, 0, 0, 300, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 225, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_tux_vertigo, 0, 320, 240, 0, 0, 320, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 240, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
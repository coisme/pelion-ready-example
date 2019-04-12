#include "WS2812.h"
#include "PixelArray.h"

#define WS2812_BUF 8
#define NUM_COLORS 8
#define NUM_LEDS_PER_COLOR 8
#define H0 8
#define L0 32
#define H1 17
#define L1 32

enum ws2812_color {
    WS2812_BLACK = 0,
    WS2812_RED,
    WS2812_YELLOW,
    WS2812_GREEN,
    WS2812_CYAN,
    WS2812_BLUE,
    WS2812_PURPLE,
    WS2812_WHITE
};

static DigitalOut LEDPower(PE_8, 1);
static PixelArray px(WS2812_BUF);
static WS2812 ws(PB_1, WS2812_BUF, H0, L0, H1, L1);

static const int colorbuf[NUM_COLORS] = {0x000000, 0x2f0000,0x2f2f00,0x002f00,0x002f2f,0x00002f,0x2f002f, 0x2f2f2f};

void setColor(ws2812_color color)
{
    px.Set(0, colorbuf[color]);
    px.SetI(0, 0x80);
    ws.write_offsets(px.getBuf(), 0, 0, 0);
}


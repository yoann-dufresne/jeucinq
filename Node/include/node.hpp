#include <FastLED.h>


#ifndef NODE_H
#define NODE_H


static const String color_names[] = {"red", "green", "blue"};
static const int colors[][3] = {
        {15, 0, 0},
        {0, 15, 0},
        {0, 0, 15}
    };


class Node
{public:
    static const int NUM_LEDS_STRIP = 24;
    static const int NUM_LEDS_RING = 12;

    static const int dataPinTop = 16;
    static const int dataPinRight = 17;
    static const int dataPinRing = 5;

    // Define the array of leds
    CRGB leds_top[NUM_LEDS_STRIP];
    CRGB leds_right[NUM_LEDS_STRIP];
    CRGB leds_ring[NUM_LEDS_RING];

    Node ()
    {
        FastLED.addLeds<NEOPIXEL, dataPinTop>(leds_top, NUM_LEDS_STRIP);
        FastLED.addLeds<NEOPIXEL, dataPinRight>(leds_right, NUM_LEDS_STRIP);
        FastLED.addLeds<NEOPIXEL, dataPinRing>(leds_ring, NUM_LEDS_RING);
    };

    void color_led(const String &device, const int num, const int colorid){
        // Device choice
        CRGB * device_array = nullptr;
        if (device=="ring") { device_array = leds_ring; }
        else if (device == "top") { device_array = leds_top; }
        else { device_array = leds_right; }

        // Color choice
        int r = colors[colorid % sizeof(colors)][0];
        int g = colors[colorid % sizeof(colors)][1];
        int b = colors[colorid % sizeof(colors)][2];

        // Filling
        device_array[num].r = r; device_array[num].g = g; device_array[num].b = b;
    }


    void show()
    {
        FastLED.show();
    }


    void color_all(int r, int g, int b)
    {
        // Color rows
        for (size_t i=0 ; i<NUM_LEDS_STRIP ; i++)
        {
            leds_top[i].r = r; leds_top[i].g = g; leds_top[i].b = b;
            leds_right[i].r = r; leds_right[i].g = g; leds_right[i].b = b;
        }

        // Color ring
        for (size_t i=0 ; i<NUM_LEDS_RING ; i++)
        {
            leds_ring[i].r = r; leds_ring[i].g = g; leds_ring[i].b = b;
        }

        // Show status
        FastLED.show();
    };
};

#endif

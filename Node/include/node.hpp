#include <FastLED.h>


#ifndef NODE_H
#define NODE_H


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

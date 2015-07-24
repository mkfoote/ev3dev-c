
/*  ev3_light.c was generated by yup.py (yupp) 0.8b7
    out of ev3_light.yu-c at 2015-07-24 16:49
 *//**
 *  \file  ev3_light.c (ev3_light.yu-c)
 *  \brief  EV3 Lights (GREEN and RED LEDs at once).
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#define EV3_LIGHT_IMPLEMENT

#include <stdio.h>
#include "ev3.h"
#include "ev3_led.h"
#include "ev3_light.h"

#define LIT_DELAY_DEFAULT  500

static const uint8_t __LED_GREEN[ LIT__LOC__ ] = { EV3_LEFT_GREEN, EV3_RIGHT_GREEN };
static const uint8_t __LED_RED[ LIT__LOC__ ] = { EV3_LEFT_RED, EV3_RIGHT_RED };
static const uint8_t __LED_GREEN_STATE  [ LIT__COL__ ] = { 0, 255, 0, 255 };
static const uint8_t __LED_RED_STATE    [ LIT__COL__ ] = { 0, 0, 255, 255 };
static const uint8_t __LED_GREEN_TRIGGER[ LIT__COL__ ] = { 1, 1, 0, 1 };
static const uint8_t __LED_RED_TRIGGER  [ LIT__COL__ ] = { 1, 0, 1, 1 };

void set_light( uint8_t loc, uint8_t col )
{
	if (( loc >= LIT__LOC__ ) || ( col >= LIT__COL__ )) return;

	set_light_trigger( loc, col, TRIGGER_NONE );
	set_led_brightness( __LED_GREEN[ loc ], __LED_GREEN_STATE[ col ]);
	set_led_brightness( __LED_RED[ loc ], __LED_RED_STATE[ col ]);
}

uint8_t get_light( uint8_t loc )
{
	uint8_t val;
	uint8_t green, red;

	if ( loc >= LIT__LOC__ ) return ( LIT__COL__ );

	if ( get_led_brightness( __LED_GREEN[ loc ], &val ) == 0 ) return ( LIT__COL__ );
	green = ( val ) ? 255 : 0;
	if ( get_led_brightness( __LED_RED[ loc ], &val ) == 0 ) return ( LIT__COL__ );
	red = ( val ) ? 255 : 0;
	for ( val = 0; val < LIT__COL__; val++ ) {
		if (( green == __LED_GREEN_STATE[ val ]) && ( red == __LED_RED_STATE[ val ])) return ( val );
	}
	return ( LIT__COL__ );
}

void set_light_trigger( uint8_t loc, uint8_t col, uint8_t trigger )
{
	if (( loc >= LIT__LOC__ ) || ( col >= LIT__COL__ )) return;

	if ( __LED_GREEN_TRIGGER[ col ]) set_led_trigger_inx( __LED_GREEN[ loc ], trigger );
	if ( __LED_RED_TRIGGER[ col ]) set_led_trigger_inx( __LED_RED[ loc ], trigger );
}

uint8_t get_light_trigger( uint8_t loc, uint8_t col )
{
	uint8_t green = TRIGGER__COUNT_, red = TRIGGER__COUNT_;

	if (( loc >= LIT__LOC__ ) || ( col >= LIT__COL__ )) return ( TRIGGER__COUNT_ );

	if ( __LED_GREEN_TRIGGER[ col ]) {
		green = get_led_trigger_inx( __LED_GREEN[ loc ]);
		if ( !__LED_RED_TRIGGER[ col ]) return ( green );
	}
	if ( __LED_RED_TRIGGER[ col ]) {
		red = get_led_trigger_inx( __LED_RED[ loc ]);
		if ( !__LED_GREEN_TRIGGER[ col ]) return ( red );
	}
	return (( green == red ) ? green : TRIGGER__COUNT_ );
}

void set_light_blink( uint8_t loc, uint8_t col, int delay_on, int delay_off )
{
	set_light_trigger( loc, col, TRIGGER_TIMER );

	if ( __LED_GREEN_TRIGGER[ col ]) {
		/* if you try to write 500 - timer will be off... (bug?) */
		if ( delay_on != LIT_DELAY_DEFAULT ) set_led_delay_on( __LED_GREEN[ loc ], delay_on );
		if ( delay_off != LIT_DELAY_DEFAULT ) set_led_delay_off( __LED_GREEN[ loc ], delay_off );
	}
	if ( __LED_RED_TRIGGER[ col ]) {
		if ( delay_on != LIT_DELAY_DEFAULT ) set_led_delay_on( __LED_RED[ loc ], delay_on );
		if ( delay_off != LIT_DELAY_DEFAULT ) set_led_delay_off( __LED_RED[ loc ], delay_off );
	}
}

bool get_light_blink( uint8_t loc, uint8_t col )
{
	return ( get_light_trigger( loc, col ) == TRIGGER_TIMER );
}

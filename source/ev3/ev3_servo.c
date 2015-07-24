
/*  ev3_servo.c was generated by yup.py (yupp) 0.8b7
    out of ev3_servo.yu-c at 2015-07-24 16:50
 *//**
 *  \file  ev3_servo.c (ev3_servo.yu-c)
 *  \brief  EV3 Servo Motors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#define EV3_SERVO_IMPLEMENT

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modp_numtoa.h"
#include "ev3.h"
#include "ev3_port.h"
#include "ev3_servo.h"

#define PATH_PREF_LEN  28
#define _ID_SPOT  "///"

#define PATH_COMMAND  "/sys/class/servo-motor/motor" _ID_SPOT "command"
#define PATH_DRIVER_NAME  "/sys/class/servo-motor/motor" _ID_SPOT "driver_name"
#define PATH_MAX_PULSE_SP  "/sys/class/servo-motor/motor" _ID_SPOT "max_pulse_sp"
#define PATH_MID_PULSE_SP  "/sys/class/servo-motor/motor" _ID_SPOT "mid_pulse_sp"
#define PATH_MIN_PULSE_SP  "/sys/class/servo-motor/motor" _ID_SPOT "min_pulse_sp"
#define PATH_POLARITY  "/sys/class/servo-motor/motor" _ID_SPOT "polarity"
#define PATH_PORT_NAME  "/sys/class/servo-motor/motor" _ID_SPOT "port_name"
#define PATH_POSITION_SP  "/sys/class/servo-motor/motor" _ID_SPOT "position_sp"
#define PATH_RATE_SP  "/sys/class/servo-motor/motor" _ID_SPOT "rate_sp"
#define PATH_STATE  "/sys/class/servo-motor/motor" _ID_SPOT "state"

size_t get_servo_command( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_COMMAND;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_servo_command( uint8_t sn, char *value )
{
	char s[] = PATH_COMMAND;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_servo_driver_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_DRIVER_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_servo_max_pulse_sp( uint8_t sn, int *buf )
{
	char s[] = PATH_MAX_PULSE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_int( s, buf );
}

size_t set_servo_max_pulse_sp( uint8_t sn, int value )
{
	char s[] = PATH_MAX_PULSE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_int( s, value );
}

size_t get_servo_mid_pulse_sp( uint8_t sn, int *buf )
{
	char s[] = PATH_MID_PULSE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_int( s, buf );
}

size_t set_servo_mid_pulse_sp( uint8_t sn, int value )
{
	char s[] = PATH_MID_PULSE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_int( s, value );
}

size_t get_servo_min_pulse_sp( uint8_t sn, int *buf )
{
	char s[] = PATH_MIN_PULSE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_int( s, buf );
}

size_t set_servo_min_pulse_sp( uint8_t sn, int value )
{
	char s[] = PATH_MIN_PULSE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_int( s, value );
}

size_t get_servo_polarity( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_POLARITY;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_servo_polarity( uint8_t sn, char *value )
{
	char s[] = PATH_POLARITY;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_servo_port_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_PORT_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_servo_position_sp( uint8_t sn, int *buf )
{
	char s[] = PATH_POSITION_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_int( s, buf );
}

size_t set_servo_position_sp( uint8_t sn, int value )
{
	char s[] = PATH_POSITION_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_int( s, value );
}

size_t get_servo_rate_sp( uint8_t sn, int *buf )
{
	char s[] = PATH_RATE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_int( s, buf );
}

size_t set_servo_rate_sp( uint8_t sn, int value )
{
	char s[] = PATH_RATE_SP;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_int( s, value );
}

size_t get_servo_state( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_STATE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

const char *ev3_servo_type( inx_t type_inx )
{
	switch ( type_inx ) {
	case SERVO_MOTOR:
		return "servo-motor";

	}
	return ( STR_unknown_ );
}

inx_t get_servo_type_inx( uint8_t sn )
{
	char buf[ 64 ];

	if ( !get_servo_driver_name( sn, buf, sizeof( buf ))) return ( SERVO_TYPE__NONE_ );

	if ( strcmp( buf, "servo-motor" ) == 0 ) return SERVO_MOTOR;

	return ( SERVO_TYPE__UNKNOWN_ );
}

size_t get_servo_desc( uint8_t sn, EV3_SERVO *desc )
{
	uint8_t addr;
	char buf[ 32 ];

	desc->type_inx = get_servo_type_inx( sn );
	if ( desc->type_inx == SERVO_TYPE__NONE_ ) return ( 0 );

	if ( !get_servo_port_name( sn, buf, sizeof( buf ))) return ( 0 );

	ev3_parse_port_name( buf, &desc->port, &desc->extport, &addr );
	desc->addr = addr;

	return ( sizeof( EV3_SERVO ));
}

EV3_SERVO *ev3_servo_desc( uint8_t sn )
{
	if ( sn >= SERVO_DESC__LIMIT_) sn = SERVO_DESC__LIMIT_ - 1;
	return ( ev3_servo + sn );
}

inx_t ev3_servo_desc_type_inx( uint8_t sn )
{
	return ( ev3_servo_desc( sn )->type_inx );
}

uint8_t ev3_servo_desc_port( uint8_t sn )
{
	return ( ev3_servo_desc( sn )->port );
}

uint8_t ev3_servo_desc_extport( uint8_t sn )
{
	return ( ev3_servo_desc( sn )->extport );
}

uint8_t ev3_servo_desc_addr( uint8_t sn )
{
	return ( ev3_servo_desc( sn )->addr );
}

char *ev3_servo_port_name( uint8_t sn, char *buf )
{
	return ( ev3_port_name( ev3_servo_desc( sn )->port, ev3_servo_desc( sn )->extport, ev3_servo_desc( sn )->addr, buf ));
}

bool ev3_search_servo( inx_t type_inx, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < SERVO_DESC__LIMIT_) {
		if ( ev3_servo[ _sn ].type_inx == type_inx ) {
			*sn = _sn;
			return ( true );
		}
		++_sn;
	}
	*sn = SERVO__NONE_;
	return ( false );
}

bool ev3_search_servo_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < SERVO_DESC__LIMIT_) {
		if ( ev3_servo[ _sn ].port == port ) {
			if ( extport ) {
				if ( ev3_servo[ _sn ].extport == extport ) {
					*sn = _sn;
					return ( true );
				}
			} else {
				*sn = _sn;
				return ( true );
			}
		}
		++_sn;
	}
	*sn = SERVO__NONE_;
	return ( false );
}

const char *ev3_servo_command( inx_t command_inx )
{
	switch ( command_inx ) {
	case SERVO_MOTOR_RUN:
		return "run";
	case SERVO_MOTOR_FLOAT:
		return "float";

	}
	return ( STR_unknown_ );
}

inx_t get_servo_command_inx( uint8_t sn, inx_t type_inx )
{
	char buf[ 64 ];

	if ( !get_servo_command( sn, buf, sizeof( buf ))) return ( SERVO_COMMAND__NONE_ );

	switch ( type_inx ) {
			
	case SERVO_MOTOR:
		if ( strcmp( buf, "run" ) == 0 ) return SERVO_MOTOR_RUN;
		if ( strcmp( buf, "float" ) == 0 ) return SERVO_MOTOR_FLOAT;

		break;

	}
	return ( SERVO_COMMAND__UNKNOWN_ );
}

size_t set_servo_command_inx( uint8_t sn, inx_t command_inx )
{
	return set_servo_command( sn, ( char* ) ev3_servo_command( command_inx ));
}

size_t get_servo_state_flags( uint8_t sn, flags_t *flags )
{
	char buf[ 64 ];
	size_t result;

	result = get_servo_state( sn, buf, sizeof( buf ));
	if ( result == 0 ) return ( 0 );

	*flags = SERVO_STATE__NONE_;
	if ( result == 1 ) return ( 1 );

	if ( strstr( buf, "running" )) *flags |= SERVO_RUNNING;

	return ( result );
}

int ev3_servo_init( void )
{
	char list[ 256 ];
	char *p;
	uint32_t sn;
	int cnt = 0;

	memset( ev3_servo, 0, sizeof( ev3_servo ));

	if ( !ev3_listdir( "/sys/class/servo-motor", list, sizeof( list ))) return ( -1 );

	p = strtok( list, " " );
	while ( p ) {
		if (( ev3_string_suffix( "motor", &p, &sn ) == 1 ) && ( sn < SERVO_DESC__LIMIT_)) {
			get_servo_desc( sn, ev3_servo + sn );
			++cnt;
		}
		p = strtok( NULL, " " );
	}
	return ( cnt );
}


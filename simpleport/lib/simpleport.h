/*
 * Copyright (C) 2007 Benedikt Sauter 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#define VID 0x1781
#define PID 0x0c62

#define UNKOWN_COMMAND  0x00
#define PORT_DIRECTION  0x01
#define PORT_SET        0x02
#define PORT_GET        0x03
#define PORT_SETPIN     0x04
#define PORT_GETPIN     0x05
#define PORT_SETPINDIR  0x06


#define TRADITIONALDLL_EXPORTS
#ifdef TRADITIONALDLL_EXPORTS
   #define TRADITIONALDLL_API __declspec(dllexport)
#else
   #define TRADITIONALDLL_API __declspec(dllimport)
#endif

#pragma pack(push, 8)
struct simpleport
{
 //struct usb_dev_handle* usb_handle;
 void * usb_handle;
};
#pragma pack(pop)

extern "C" {
TRADITIONALDLL_API void __stdcall simpleport_open(struct simpleport *tmp);
TRADITIONALDLL_API void simpleport_close(struct simpleport *simpleport);
TRADITIONALDLL_API unsigned char simpleport_message(struct simpleport *simpleport, char *msg, int msglen, int answerlen);


TRADITIONALDLL_API void simpleport_set_direction(struct simpleport *simpleport, unsigned char direction);
TRADITIONALDLL_API void simpleport_set_port(struct simpleport *simpleport,unsigned char value, unsigned char mask);
TRADITIONALDLL_API unsigned char simpleport_get_port(struct simpleport *simpleport);
TRADITIONALDLL_API void simpleport_set_pin(struct simpleport *simpleport,int pin, int value);
TRADITIONALDLL_API void simpleport_set_pin_dir(struct simpleport *simpleport,int pin, int value);
TRADITIONALDLL_API int simpleport_get_pin(struct simpleport *simpleport, int pin);

}

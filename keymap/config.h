/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once

#define USE_SERIAL

// @see https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-eeprom
#define EE_HANDS
#define SPLIT_USB_DETECT


// Lighting
#define WS2812_DI_PIN D1
#define RGBLED_NUM 18
#define RGBLED_SPLIT { 9, 9 }
#define RGBLIGHT_DEFAULT_HUE 85
#define RGBLIGHT_SPLIT
#define RGBLIGHT_SLEEP


// Mouse settings

// undef values from the keyboard
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_WHEEL_DELAY

// @see https://docs.qmk.fm/#/feature_mouse_keys?id=inertia-mode
#define MOUSEKEY_INERTIA
#define MOUSEKEY_DELAY       150
#define MOUSEKEY_INTERVAL    16
#define MOUSEKEY_MAX_SPEED   16
#define MOUSEKEY_TIME_TO_MAX 16
#define MOUSEKEY_FRICTION    40
#define MOUSEKEY_MOVE_DELTA  4

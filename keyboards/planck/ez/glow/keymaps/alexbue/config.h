/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define COMBO_ONLY_FROM_LAYER 0

#ifdef AUDIO_ENABLE
// #define STARTUP_SONG SONG(PLANCK_SOUND)
#define STARTUP_SONG SONG(NO_SOUND)

#define DEFAULT_LAYER_SONGS \
  { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define MIDI_BASIC
#define ENCODER_RESOLUTION 4

// Tapping Term Control
#define TAPPING_TERM_PER_KEY

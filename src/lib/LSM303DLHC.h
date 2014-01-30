/*
The MIT License (MIT)

Copyright (c) 2014 Erik Regla Torres

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * LSM303DLHC.h
 *
 *  Created on: Jan 30, 2014
 *  Author: jvarred
 */

#ifndef LSM303DLHC_H_
#define LSM303DLHC_H_

namespace std {

#define MAGNETOMETER_ADDRESS	0x1E
#define ACCELEROMETER_ADDRESS	0x19

#define LSM303DLHC_CRA_REG_M 0x00
#define LSM303DLHC_CRB_REG_M 0x01
#define LSM303DLHC_MR_REG_M 0x02

#define LSM303DLHC_OUTPUT_RATE_1 0x00
#define LSM303DLHC_OUTPUT_RATE_2 0x01
#define LSM303DLHC_OUTPUT_RATE_3 0x02
#define LSM303DLHC_OUTPUT_RATE_4 0x03
#define LSM303DLHC_OUTPUT_RATE_5 0x04
#define LSM303DLHC_OUTPUT_RATE_6 0x05
#define LSM303DLHC_OUTPUT_RATE_7 0x06
#define LSM303DLHC_OUTPUT_RATE_8 0x07

#define LSM303DLHC_INPUT_GAIN_1 0x00
#define LSM303DLHC_INPUT_GAIN_2 0x01
#define LSM303DLHC_INPUT_GAIN_3 0x02
#define LSM303DLHC_INPUT_GAIN_4 0x03
#define LSM303DLHC_INPUT_GAIN_5 0x04
#define LSM303DLHC_INPUT_GAIN_6 0x05
#define LSM303DLHC_INPUT_GAIN_7 0x06
#define LSM303DLHC_INPUT_GAIN_8 0x07

#define LSM303DLHC_CONTINOUS_MODE 0b00000000
#define LSM303DLHC_SINGLE_MODE 0b00000001
#define LSM303DLHC_SLEEP_MODE_1 0b00000010
#define LSM303DLHC_SLEEP_MODE_2 0b00000011

#define LSM303DLHC_OUT_X_H_M 0x03
#define LSM303DLHC_OUT_X_L_M 0x04
#define LSM303DLHC_OUT_Y_H_M 0x07
#define LSM303DLHC_OUT_Y_L_M 0x08
#define LSM303DLHC_OUT_Z_H_M 0x05
#define LSM303DLHC_OUT_Z_L_M 0x06

#define LSM303DLHC_TEMP_OUT_H_M 0x31
#define LSM303DLHC_TEMP_OUT_L_M 0x32

typedef struct lsm303_t {
		int16_t x;
		int16_t y;
		int16_t z;
} magdata_t;

class LSM303DLHC {
	public:

		int i2c_magnetometer_handler;
		int i2c_accelerometer_handler;

		int set_device(int bus_handler, int deviceAddress);

		int init_magnetometer(int speed = LSM303DLHC_OUTPUT_RATE_5, int gain = LSM303DLHC_INPUT_GAIN_2, int conversion = LSM303DLHC_CONTINOUS_MODE);

		int readAddress(int bus, int address);
		int writeAddress(int bus, int address, int value);

		LSM303DLHC();
		LSM303DLHC(const char *bus_path);
		int read_magnetometer(lsm303_t *target);
		~LSM303DLHC();
};

} /* namespace std */

#endif /* LSM303DLHC_H_ */

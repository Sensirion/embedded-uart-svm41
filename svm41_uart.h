/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * SHDLC-Generator: 0.8.2
 * Yaml Version: 0.8.1
 * Template Version: 0.7.0-92-g227c1e2
 */
/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SVM41_UART_H
#define SVM41_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"

/**
 * svm41_start_measurement() - Starts continuous measurement in polling mode.
 *
 * @note This command is only available in idle mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_start_measurement(void);

/**
 * svm41_stop_measurement() - Stops the measurement mode and returns to idle
 * mode.
 *
 * @note This command is only available in measurement mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_stop_measurement(void);

/**
 * svm41_read_measured_values_as_integers() - Returns the new measurement
 * results as integers.
 *
 * @note This command is only available in measurement mode. The firmware
 * updates the measurement values every second. Polling data with a faster
 * sampling rate will return the same values. The first measurement is available
 * 1 second after the start measurement command is issued. Any readout prior to
 * this will return zero initialized values.
 *
 * @param humidity Compensated ambient humidity in % RH with a scaling factor of
 * 100.
 *
 * @param temperature Compensated ambient temperature in degrees celsius with a
 * scaling of 200.
 *
 * @param voc_index VOC index with a scaling value of 10.
 *
 * @param nox_index NOx index with a scaling value of 10.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_read_measured_values_as_integers(int16_t* humidity,
                                               int16_t* temperature,
                                               int16_t* voc_index,
                                               int16_t* nox_index);

/**
 * svm41_read_measured_raw_values() - Returns the measured raw values.
 *
 * @note This command is only available in measurement mode. The firmware
 * updates the measurement values every second. Polling data with a faster
 * sampling rate will return the same values. The first measurement is available
 * 1 second after the start measurement command is issued. Any readout prior to
 * this will return zero initialized values.
 *
 * @param raw_humidity Uncompensated raw humidity in % RH as read from the SHT40
 * with a scaling factor of 100.
 *
 * @param raw_temperature Uncompensated raw temperature in degrees celsius as
 * read from the SHT40 with a scaling of 200.
 *
 * @param raw_voc_ticks Raw VOC output ticks as read from the SGP sensor.
 *
 * @param raw_nox_ticks Raw NOx output ticks as read from the SGP sensor.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_read_measured_raw_values(int16_t* raw_humidity,
                                       int16_t* raw_temperature,
                                       uint16_t* raw_voc_ticks,
                                       uint16_t* raw_nox_ticks);

/**
 * svm41_get_temperature_offset_for_rht_measurements() - Gets the T-Offset for
 * the temperature compensation of the RHT algorithm.
 *
 * @param t_offset Temperature offset which is used for the RHT measurements.
 * Values are in degrees celsius with a scaling of 200.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_temperature_offset_for_rht_measurements(int16_t* t_offset);

/**
 * svm41_get_voc_tuning_parameters() - Gets the currently set parameters for
 * customizing the VOC algorithm.
 *
 * @param voc_index_offset VOC index representing typical (average) conditions.
 *
 * @param learning_time_offset_hours Time constant to estimate the VOC algorithm
 * offset from the history in hours. Past events will be forgotten after about
 * twice the learning time.
 *
 * @param learning_time_gain_hours Time constant to estimate the VOC algorithm
 * gain from the history in hours. Past events will be forgotten after about
 * twice the learning time.
 *
 * @param gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high VOC index signal). Set to zero to disable
 * the gating.
 *
 * @param std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations.
 *
 * @param gain_factor Gain factor to amplify or to attenuate the VOC index
 * output.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_voc_tuning_parameters(int16_t* voc_index_offset,
                                        int16_t* learning_time_offset_hours,
                                        int16_t* learning_time_gain_hours,
                                        int16_t* gating_max_duration_minutes,
                                        int16_t* std_initial,
                                        int16_t* gain_factor);

/**
 * svm41_get_nox_tuning_parameters() - Gets the currently set parameters for
 * customizing the NOx algorithm.
 *
 * @param nox_index_offset VOC index representing typical (average) conditions.
 *
 * @param learning_time_offset_hours Time constant to estimate the NOx algorithm
 * offset from the history in hours. Past events will be forgotten after about
 * twice the learning time.
 *
 * @param learning_time_gain_hours Time constant to estimate the NOx algorithm
 * gain from the history in hours. Past events will be forgotten after about
 * twice the learning time. Note that this value is not relevant for NOx
 * algorithm type.
 *
 * @param gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high NOx index signal). Set to zero to disable
 * the gating.
 *
 * @param std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations. Note that this value is not relevant for NOx
 * algorithm type.
 *
 * @param gain_factor Gain factor to amplify or to attenuate the NOx index
 * output.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_nox_tuning_parameters(int16_t* nox_index_offset,
                                        int16_t* learning_time_offset_hours,
                                        int16_t* learning_time_gain_hours,
                                        int16_t* gating_max_duration_minutes,
                                        int16_t* std_initial,
                                        int16_t* gain_factor);

/**
 * svm41_store_nv_data() - Stores all algorithm parameters to the non-volatile
 * memory.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_store_nv_data(void);

/**
 * svm41_set_temperature_offset_for_rht_measurements() - Sets the T-Offset for
 * the temperature compensation of the RHT algorithm.
 *
 * @note Execute the store command after writing the parameter to store it in
 * the non-volatile memory of the device otherwise the parameter will be reset
 * upton a device reset.
 *
 * @param t_offset Temperature offset in degrees celsius with a scaling of 200.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_temperature_offset_for_rht_measurements(int16_t t_offset);

/**
 * svm41_set_voc_tuning_parameters() - Sets parameters to customize the VOC
 * algorithm. This command is only available in idle mode.
 *
 * @note Execute the store command after writing the parameter to store it in
 * the non-volatile memory of the device otherwise the parameter will be reset
 * upton a device reset.
 *
 * @param voc_index_offset VOC index representing typical (average) conditions.
 * Allowed values are in range 1..250. The default value is 100.
 *
 * @param learning_time_offset_hours Time constant to estimate the VOC algorithm
 * offset from the history in hours. Past events will be forgotten after about
 * twice the learning time. Allowed values are in range 1..1000. The default
 * value is 12 hours.
 *
 * @param learning_time_gain_hours Time constant to estimate the VOC algorithm
 * gain from the history in hours. Past events will be forgotten after about
 * twice the learning time. Allowed values are in range 1..1000. The default
 * value is 12 hours.
 *
 * @param gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high VOC index signal). Set to zero to disable
 * the gating. Allowed values are in range 0..3000. The default value is 180
 * minutes.
 *
 * @param std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations. Allowed values are in range 10..5000. The
 * default value is 50.
 *
 * @param gain_factor Gain factor to amplify or to attenuate the VOC index
 * output. Allowed values are in range 1..1000. The default value is 230.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_voc_tuning_parameters(int16_t voc_index_offset,
                                        int16_t learning_time_offset_hours,
                                        int16_t learning_time_gain_hours,
                                        int16_t gating_max_duration_minutes,
                                        int16_t std_initial,
                                        int16_t gain_factor);

/**
 * svm41_set_nox_tuning_parameters() - Sets parameters to customize the NOx
 * algorithm. This command is only available in idle mode.
 *
 * @note Execute the store command after writing the parameter to store it in
 * the non-volatile memory of the device otherwise the parameter will be reset
 * upton a device reset.
 *
 * @param nox_index_offset NOx index representing typical (average) conditions.
 * Allowed values are in range 1..250. The default value is 1.
 *
 * @param learning_time_offset_hours Time constant to estimate the NOx algorithm
 * offset from the history in hours. Past events will be forgotten after about
 * twice the learning time. Allowed values are in range 1..1000. The default
 * value is 12 hours.
 *
 * @param learning_time_gain_hours Time constant to estimate the NOx algorithm
 * gain from the history in hours. Past events will be forgotten after about
 * twice the learning time. Allowed values are in range 1..1000. The default
 * value is 12 hours. Note that this value is not relevant for NOx algorithm
 * type.
 *
 * @param gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high NOx index signal). Set to zero to disable
 * the gating. Allowed values are in range 0..3000. The default value is 720
 * minutes.
 *
 * @param std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations. Allowed values are in range 10..5000. The
 * default value is 50. Note that this value is not relevant for NOx algorithm
 * type.
 *
 * @param gain_factor Gain factor to amplify or to attenuate the NOx index
 * output. Allowed values are in range 1..1000. The default value is 230.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_nox_tuning_parameters(int16_t nox_index_offset,
                                        int16_t learning_time_offset_hours,
                                        int16_t learning_time_gain_hours,
                                        int16_t gating_max_duration_minutes,
                                        int16_t std_initial,
                                        int16_t gain_factor);

/**
 * svm41_get_voc_state() - Gets the current VOC algorithm state. Retrieved
 * values can be used to set the VOC algorithm state to resume operation after a
 * short interruption, skipping initial learning phase. This command is only
 * available during measurement mode.
 *
 * @note Retrieved values can only be used after at least 3 hours of continuous
 * operation. Restoring the state by calling set voc state should not be done
 * after interruptions of more than 10 minutes.
 *
 * @param state Current VOC algorithm state.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_voc_state(uint8_t* state, uint8_t state_size);

/**
 * svm41_set_voc_state() - Set previously retrieved VOC algorithm state to
 * resume operation after a short interruption, skipping initial learning phase.
 * This command is only available in idle mode.
 *
 * @note This feature should not be used after interruptions of more than 10
 * minutes.
 *
 * @param state Current VOC algorithm state.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_voc_state(const uint8_t* state, uint8_t state_size);

/**
 * svm41_get_product_type() - Gets the product type from the device.
 *
 * @param product_type String containing the product type.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_product_type(unsigned char* product_type,
                               uint8_t product_type_size);

/**
 * svm41_get_product_name() - Gets the product name from the device.
 *
 * @param product_name String containing the product name.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_product_name(unsigned char* product_name,
                               uint8_t product_name_size);

/**
 * svm41_get_serial_number() - Gets the serial number from the device.
 *
 * @param serial_number String containing the serial number.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_serial_number(unsigned char* serial_number,
                                uint8_t serial_number_size);

/**
 * svm41_get_version() - Gets the version information for the hardware, firmware
 * and SHDLC protocol.
 *
 * @param firmware_major Firmware major version number.
 *
 * @param firmware_minor Firmware minor version number.
 *
 * @param firmware_debug Firmware debug state. If the debug state is set, the
 * firmware is in development.
 *
 * @param hardware_major Hardware major version number.
 *
 * @param hardware_minor Hardware minor version number.
 *
 * @param protocol_major Protocol major version number.
 *
 * @param protocol_minor Protocol minor version number.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_version(uint8_t* firmware_major, uint8_t* firmware_minor,
                          bool* firmware_debug, uint8_t* hardware_major,
                          uint8_t* hardware_minor, uint8_t* protocol_major,
                          uint8_t* protocol_minor);

/**
 * svm41_device_reset() - Executs a reset on the device.
 *
 * @note The device will reply before executing the reset. If the command is
 * send with broadcast, the reset is done directly after the reception of the
 * command.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_device_reset(void);

/**
 * svm41_get_system_up_time() - Get the system up time of the device.
 *
 * @param system_up_time The time since the last power-on or device reset in
 * seconds.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_system_up_time(uint32_t* system_up_time);

#ifdef __cplusplus
}
#endif

#endif /* SVM41_UART_H */

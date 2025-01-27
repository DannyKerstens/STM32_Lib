/*
 *  @file: 24FCxxT-I.hpp
 *
 *  @Date: Jan 25, 2025
 *  @Author: D. Kerstens
 *
 */

#ifndef EEPROM_24FCXXT_I_HPP_
#define EEPROM_24FCXXT_I_HPP_

#include "eeprom.hpp"

#define READ_COMMAND    0xA1
#define WRITE_COMMAND   0xA0

const eepromCfg cfg_24FC16T = {
    .pageSize = 16,   // 16 bytes per page
    .pageAmount = 128,  //
    .blockSize = 256,   // 256 bytes per block
    .blockAmount = 8, // 8 blocks
};


class _24FCxxT: public eeprom
{
public:
  _24FCxxT(I2C_HandleTypeDef *hi2c, eepromCfg config);

  /* Write Functions */
  void WriteByte(const uint32_t address, uint8_t data);
  void WriteSequential(const uint32_t address, uint8_t *data, size_t size);
  void WritePage(const uint16_t page, const uint16_t offset, uint8_t *data, size_t size);

  /* Read Functions */
  uint8_t ReadByte(const uint32_t address);
  void ReadSequential(const uint32_t address, uint8_t *data, size_t size);
  void ReadPage(const uint16_t page, const uint16_t offset, uint8_t *data, size_t size);

private:
  I2C_HandleTypeDef *_handle;
};

#endif /* EEPROM_24FCXXT_I_HPP_ */

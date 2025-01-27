/*
 *  @file: 24FCxxT-I.cpp
 *
 *  @Date: Jan 25, 2025
 *  @Author: D. Kerstens
 *
 */
#include "main.h"
#include "24FCxxT-I.hpp"

#define I2C_TIMEOUT       1000

_24FCxxT::_24FCxxT(I2C_HandleTypeDef *hi2c, eepromCfg config)
{
  _handle = hi2c;
  _pageSize = config.pageSize;
  _pageAmount = config.pageAmount;
  _blockSize = config.blockSize;
  _blockAmount = config.blockAmount;
}

void _24FCxxT::WriteByte(const uint32_t address, uint8_t data)
{
  uint8_t command = WRITE_COMMAND + ((address & 0x0F00) >> 7);

  HAL_I2C_Mem_Write(_handle, command, (address & 0xFF), 1, &data, 1, I2C_TIMEOUT);
}
void _24FCxxT::WriteSequential(const uint32_t address, uint8_t *data, size_t size)
{
  uint8_t command = WRITE_COMMAND + ((address & 0x0F00) >> 7);

  HAL_I2C_Mem_Write(_handle, command, (address & 0xFF), 1, data, size, I2C_TIMEOUT);
}
void _24FCxxT::WritePage(const uint32_t page, const uint32_t address, uint8_t *data, size_t size)
{
  /* Exit if size is too small or too large */
  if(size <= 0 || size > _pageSize)
    return;

  /* Calculate the size */
  size = size - (address % _pageSize);
  uint8_t command = WRITE_COMMAND + ((address & 0x0F00) >> 7);

  HAL_I2C_Mem_Write(_handle, command, (address & 0xFF), 1, data, size, I2C_TIMEOUT);
}

uint8_t _24FCxxT::ReadByte(const uint32_t address)
{
  uint8_t regValue;
  uint8_t command = READ_COMMAND + ((address & 0x0F00) >> 7);

  HAL_I2C_Mem_Read(_handle, command, (address & 0xFF), 1, &regValue, 1, I2C_TIMEOUT);

  return regValue;
}

void _24FCxxT::ReadSequential(const uint32_t address, uint8_t *data, size_t size)
{
  uint8_t command = READ_COMMAND + ((address & 0x0F00) >> 7);
}
void _24FCxxT::ReadPage(const uint32_t page, const uint32_t address, uint8_t *data, size_t size)
{
  uint8_t command = READ_COMMAND + ((address & 0x0F00) >> 7);
}

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
  /* Add block address to write command */
  uint8_t command = WRITE_COMMAND + ((address & 0x0F00) >> 7);

  /* Write data to memory */
  HAL_I2C_Mem_Write(_handle, command, (address & 0xFF), 1, &data, 1, I2C_TIMEOUT);
}

void _24FCxxT::WriteSequential(const uint32_t address, uint8_t *data, size_t size)
{
  WritePage(address / _pageSize, address % _pageSize, data, size);
}

void _24FCxxT::WritePage(const uint16_t page, const uint16_t offset, uint8_t *data, size_t size)
{
  /* Check if given page and size are valid */
  if ((size <= 0) || (size > _pageSize) || (page > _pageAmount - 1))
    return;

  /* Calculate the size */
  if ((size + offset) > _pageSize)
    size = _pageSize - offset;

  /* Add block address to write command */
  uint32_t address = (page * _pageSize) + offset;
  uint8_t command = WRITE_COMMAND + ((address & 0x0F00) >> 7);

  /* Write data to memory */
  HAL_I2C_Mem_Write(_handle, command, (address & 0xFF), 1, data, size, I2C_TIMEOUT);
}

uint8_t _24FCxxT::ReadByte(const uint32_t address)
{
  /* Add block address to read command */
  uint8_t memoryValue;
  uint8_t command = READ_COMMAND + ((address & 0x0F00) >> 7);

  /* Read page from memory */
  HAL_I2C_Mem_Read(_handle, command, (address & 0xFF), 1, &memoryValue, 1, I2C_TIMEOUT);

  /* Return memory value */
  return memoryValue;
}

void _24FCxxT::ReadSequential(const uint32_t address, uint8_t *data, size_t size)
{
  ReadPage(address / _pageSize, address % _pageSize, data, size);
}

void _24FCxxT::ReadPage(const uint16_t page, const uint16_t offset, uint8_t *data, size_t size)
{
  /* Check if given page and size are valid */
  if ((size <= 0) || (size > _pageSize) || (page > _pageAmount - 1))
    return;

  /* Calculate the size */
  if ((size + offset) > _pageSize)
    size = _pageSize - offset;

  /* Add block address to read command */
  uint32_t address = (page * _pageSize) + offset;
  uint8_t command = READ_COMMAND + ((address & 0x0F00) >> 7);

  /* Read page from memory */
  HAL_I2C_Mem_Read(_handle, command, address, 1, data, size, I2C_TIMEOUT);
}

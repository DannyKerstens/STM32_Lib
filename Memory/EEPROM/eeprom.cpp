/*
 *  @file: eeprom.cpp
 *
 *  @Date: Jan 25, 2025
 *  @Author: D. Kerstens
 *
 */

#include "main.h"
#include "eeprom.hpp"
#include <string.h>

void eeprom::Write16Bits(const uint32_t address, uint16_t data)
{
  uint8_t writeBuffer[2];
  writeBuffer[0] = (data & 0xFF00) >> 8;
  writeBuffer[1] = (data & 0x00FF);

  WriteSequential(address, writeBuffer, 2);
}

void eeprom::Write32Bits(const uint32_t address, uint32_t data)
{
  uint8_t writeBuffer[4];
  writeBuffer[0] = (data & 0xFF000000) >> 24;
  writeBuffer[1] = (data & 0x00FF0000) >> 16;
  writeBuffer[2] = (data & 0x0000FF00) >> 8;
  writeBuffer[3] = (data & 0x000000FF);

  WriteSequential(address, writeBuffer, 4);
}

uint16_t eeprom::Read16Bits(const uint32_t address)
{
  uint8_t readBuffer[2];
  ReadSequential(address, readBuffer, 2);

  return (readBuffer[0] << 8) | readBuffer[1];
}
uint32_t eeprom::Read32Bits(const uint32_t address)
{
  uint8_t readBuffer[4];
  ReadSequential(address, readBuffer, 4);
  return (readBuffer[0] << 24) | (readBuffer[1] << 16) | (readBuffer[2] << 8) | readBuffer[3];
}

void eeprom::EraseByte(const uint32_t address)
{
  WriteByte(address, 0xFF);
}

void eeprom::ErasePage(const uint32_t page)
{
  /* Initialize buffer with 0xFF*/
  uint8_t buffer[_pageSize];
  memset(buffer, 0xFF, _pageSize);

  /*Erase full page */
  WritePage(page, 0x00, buffer, _pageSize);
}

void eeprom::EraseAll(void)
{
  /* Erase all page for page */
  for (int page = 0; page < _pageAmount; page++)
  {
    ErasePage(page);
  }
}

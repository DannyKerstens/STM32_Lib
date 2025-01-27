/*
 *  @file: eeprom.hpp
 *
 *  @Date: Jan 25, 2025
 *  @Author: Danny Kerstens
 *
 */

#ifndef EEPROM_EEPROM_HPP_
#define EEPROM_EEPROM_HPP_

typedef struct
{
  uint16_t pageSize;
  uint16_t pageAmount;
  uint16_t blockSize;
  uint16_t blockAmount;
}eepromCfg;

class eeprom
{
public:
  /* Write Functions */
  virtual void WriteByte(const uint32_t address, uint8_t data) = 0;
  virtual void WriteSequential(const uint32_t address, uint8_t *data, size_t size) = 0;
  virtual void WritePage(const uint32_t page, const uint32_t address, uint8_t *data, size_t size) = 0;

  void Write16Bits(const uint32_t address, uint16_t data);
  void Write32Bits(const uint32_t address, uint32_t data);

  /* Read Functions */
  virtual uint8_t ReadByte(const uint32_t address) = 0;
  virtual void ReadSequential(const uint32_t address, uint8_t *data, size_t size) = 0;
  virtual void ReadPage(const uint32_t page, const uint32_t address, uint8_t *data, size_t size) = 0;

  uint16_t Read16Bits(const uint32_t address);
  uint32_t Read32Bits(const uint32_t address);

  void EraseByte(const uint32_t address);
  void ErasePage(const uint32_t page);
  void EraseAll(void);

protected:
  uint16_t _pageSize;   // Bytes per page
  uint16_t _pageAmount; // Amount of pages
  uint16_t _blockSize;  // Bytes per block
  uint16_t _blockAmount;// Amount of blocks
};

#endif /* EEPROM_EEPROM_HPP_ */

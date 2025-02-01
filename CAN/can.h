/*
 *  @File: can.h
 *
 *  @Date: Jan 29, 2025
 *  @Author: Danny
 */

#ifndef CAN_CAN_H_
#define CAN_CAN_H_


class CAN_Interface {
public:
  CAN_Interface(CAN_HandleTypeDef *hcan, uint32_t nodeID);
  virtual ~CAN_Interface();

  void Start();
  void Stop();
  void Transmit(uint32_t nodeID, uint8_t *data, uint8_t lenght);

private:
  CAN_HandleTypeDef *_handle;
  uint32_t _nodeID;
};


#endif /* CAN_CAN_H_ */

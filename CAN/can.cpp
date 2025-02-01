/*
 *  @File: can.cpp
 *
 *  @Date: Jan 29, 2025
 *  @Author: Danny
 */

#include "main.h"
#include "can.h"

static CAN_RxHeaderTypeDef RxHeader;
static uint8_t RxData[8];

CAN_Interface::CAN_Interface(CAN_HandleTypeDef *hcan, uint32_t nodeID)
{
  /* Store private variables */
  _handle = hcan;
  _nodeID = nodeID;

  /* Setup CAN Bus filter */
  CAN_FilterTypeDef canfilter;
  canfilter.FilterBank = 0; // which filter bank to use from the assigned ones
  canfilter.FilterMode = CAN_FILTERMODE_IDMASK;
  canfilter.FilterFIFOAssignment = CAN_RX_FIFO0;
  canfilter.FilterIdHigh = _nodeID; // Only check for the node ID in bit 16-29. Max address is 8192
  canfilter.FilterMaskIdHigh = 0x0000;
  canfilter.FilterIdLow = 0;
  canfilter.FilterMaskIdLow = 0xFFFF; // Ignore bits 0-15. This is used for command codes
  canfilter.FilterScale = CAN_FILTERSCALE_32BIT;
  canfilter.FilterActivation = CAN_FILTER_ENABLE;
  canfilter.SlaveStartFilterBank = 14; // how many filters to assign to the CAN1 (master can)
  HAL_CAN_ConfigFilter(_handle, &canfilter);
}

void CAN_Interface::Start()
{
  /* Enable receive interrup */
  if(HAL_CAN_ActivateNotification(_handle, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
  {
    return;
  }

  /* Start the CAN interface */
  HAL_CAN_Start(_handle);
}

void CAN_Interface::Stop()
{
  /* Stop the CAN interface */
  HAL_CAN_Stop(_handle);
}

void CAN_Interface::Transmit(uint32_t nodeID, uint8_t *data, uint8_t lenght)
{
  CAN_TxHeaderTypeDef TxHeader;
  uint32_t TxMailbox;

  assert_param(lenght >= 8);

  /* Fill in CAN Tx Header */
  TxHeader.IDE = CAN_ID_EXT;
  TxHeader.ExtId = nodeID;
  TxHeader.RTR = CAN_RTR_DATA;
  TxHeader.DLC = lenght;

  /* Add message to transmit mailbox */
  if(HAL_CAN_AddTxMessage(_handle, &TxHeader, data, &TxMailbox) != HAL_OK)
  {
    return;
  }
}

/* Rx Callback */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
  {
    Error_Handler();
  }
}

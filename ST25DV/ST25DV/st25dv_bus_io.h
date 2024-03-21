#ifndef ST25DV_BUS_IO_H
#define ST25DV_BUS_IO_H
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>
#include <stdio.h>
#include <stdint.h>
#include <zephyr/logging/log.h>
#include "st25dv.h"
NFCTAG_StatusTypeDef ST25DV_IO_Init(void);
NFCTAG_StatusTypeDef ST25DV_IO_MemWrite(const uint8_t *const pData, const uint8_t DevAddr, const uint16_t TarAddr, const uint16_t Size);
NFCTAG_StatusTypeDef ST25DV_IO_Write(const uint8_t *const pData, const uint8_t DevAddr, const uint16_t Size);
NFCTAG_StatusTypeDef ST25DV_IO_MemRead(uint8_t *const pData, const uint8_t DevAddr, const uint16_t TarAddr, const uint16_t Size);
NFCTAG_StatusTypeDef ST25DV_IO_Read(uint8_t *const pData, const uint8_t DevAddr, const uint16_t Size);
uint8_t ST25DV_IO_IsNacked(void);
NFCTAG_StatusTypeDef ST25DV_IO_IsDeviceReady(const uint8_t DevAddr, const uint32_t Trials);

#endif
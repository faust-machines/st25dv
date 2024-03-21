#include "st25dv_bus_io.h"
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>
#include <stdio.h>
#include <stdint.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(st25dv_bus_io, LOG_LEVEL_WRN);

#define DT_DRV_COMPAT st_st25dv

struct i2c_dt_spec st25dv_i2c = I2C_DT_SPEC_GET(DT_NODELABEL(st25dv));

NFCTAG_StatusTypeDef ST25DV_IO_Init(void) {
    if (!device_is_ready(st25dv_i2c.bus)) {
        LOG_ERR("I2C device is not ready");
        return NFCTAG_ERROR;
    }
    return NFCTAG_OK;
}

// Écriture mémoire
NFCTAG_StatusTypeDef ST25DV_IO_MemWrite(const uint8_t *const pData, const uint8_t DevAddr, const uint16_t TarAddr, const uint16_t Size) {
    uint8_t addr_buf[2] = {TarAddr >> 8, TarAddr & 0xFF};
    struct i2c_msg msgs[2] = {
        {.buf = addr_buf, .len = 2, .flags = I2C_MSG_WRITE},
        {.buf = (uint8_t *)pData, .len = Size, .flags = I2C_MSG_WRITE | I2C_MSG_STOP}
    };
    st25dv_i2c.addr = DevAddr;
    // k_sleep(K_MSEC(1)); // Slow down the I2C communication
    k_sleep(K_MSEC(1));
    if (i2c_transfer_dt(&st25dv_i2c, msgs, 2) == 0) {
        return NFCTAG_OK;
    }
    LOG_ERR("I2C transfer failed");
    return NFCTAG_ERROR;
}

// Écriture simple
NFCTAG_StatusTypeDef ST25DV_IO_Write(const uint8_t *const pData, const uint8_t DevAddr, const uint16_t Size) {
    struct i2c_msg msg = {
        .buf = (uint8_t *)pData,
        .len = Size,
        .flags = I2C_MSG_WRITE | I2C_MSG_STOP
    };
    st25dv_i2c.addr = DevAddr;
    // k_sleep(K_MSEC(1)); // Slow down the I2C communication
    if (i2c_transfer_dt(&st25dv_i2c, &msg, 1) == 0) {
        return NFCTAG_OK;
    }
    LOG_ERR("I2C transfer failed");
    return NFCTAG_ERROR;
}

// Lecture mémoire
NFCTAG_StatusTypeDef ST25DV_IO_MemRead(uint8_t *const pData, const uint8_t DevAddr, const uint16_t TarAddr, const uint16_t Size) {
    LOG_DBG("ST25DV_IO_MemRead");
    uint8_t addr_buf[2] = {TarAddr >> 8, TarAddr & 0xFF};

    struct i2c_msg msgs[2] = {
        {.buf = addr_buf, .len = 2, .flags = I2C_MSG_WRITE},
        {.buf = pData, .len = Size, .flags = I2C_MSG_READ | I2C_MSG_RESTART | I2C_MSG_STOP}
    };
    st25dv_i2c.addr = DevAddr;

    int ret;
    // k_sleep(K_MSEC(1)); // Slow down the I2C communication
    ret = i2c_transfer_dt(&st25dv_i2c, msgs, 2);
    if (ret < 0) {
        LOG_ERR("I2C transfer failed: %d", ret);
        return NFCTAG_ERROR;
    }
    return NFCTAG_OK;
}

// Simple Read
NFCTAG_StatusTypeDef ST25DV_IO_Read(uint8_t *const pData, const uint8_t DevAddr, const uint16_t Size) {
    LOG_DBG("ST25DV_IO_Read");
    struct i2c_msg msg = {
        .buf = pData,
        .len = Size,
        .flags = I2C_MSG_READ | I2C_MSG_STOP
    };
    st25dv_i2c.addr = DevAddr;
    // k_sleep(K_MSEC(1)); // Slow down the I2C communication
    if (i2c_transfer_dt(&st25dv_i2c, &msg, 1) == 0) {
        return NFCTAG_OK;
    }
    return NFCTAG_ERROR;
}

uint8_t ST25DV_IO_IsNacked(void) {
    LOG_WRN("ST25DV_IO_IsNacked function is not implemented.");
    return 0;
}

NFCTAG_StatusTypeDef ST25DV_IO_IsDeviceReady(const uint8_t DevAddr, const uint32_t Trials) {
    LOG_DBG("ST25DV_IO_IsDeviceReady");
    uint8_t dummy;
    struct i2c_msg msg = {
        .buf = &dummy, // Not used
        .len = 0,
        .flags = I2C_MSG_WRITE | I2C_MSG_STOP
    };
    st25dv_i2c.addr = DevAddr;
    for (uint32_t i = 0; i < Trials; i++) {
        if (i2c_transfer_dt(&st25dv_i2c, &msg, 1) == 0) {
            return NFCTAG_OK; // Dispositif prêt
        }
        k_sleep(K_MSEC(1));
    }
    return NFCTAG_ERROR; // Dispositif non prêt après plusieurs tentatives
}
//外部EEPROM, 用于在手表MCU掉电时保存手表设置信息，通过I2C和MCU通信（这里的i2c是用软件模拟的）
#include "BL24C02.h"

#define BL_CLK_ENABLE __HAL_RCC_GPIOA_CLK_ENABLE()

iic_bus_t BL_bus = 
{
	.IIC_SDA_PORT = GPIOA,
	.IIC_SCL_PORT = GPIOA,
	.IIC_SDA_PIN  = GPIO_PIN_11,
	.IIC_SCL_PIN  = GPIO_PIN_12,
};


void BL24C02_Write(uint8_t addr,uint8_t length,uint8_t buff[])
{
	IIC_Write_Multi_Byte(&BL_bus, BL_ADDRESS, addr, length, buff);
}


void BL24C02_Read(uint8_t addr, uint8_t length, uint8_t buff[])
{
	IIC_Read_Multi_Byte(&BL_bus, BL_ADDRESS, addr, length, buff);
}


void BL24C02_Init(void)
{
	BL_CLK_ENABLE;
	IICInit(&BL_bus);
}

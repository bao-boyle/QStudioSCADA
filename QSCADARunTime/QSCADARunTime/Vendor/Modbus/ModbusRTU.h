﻿#ifndef MODBUSRTU_H
#define MODBUSRTU_H

#include <QString>
#include <QObject>

#include "../../Public/public.h"
#include "Modbus.h"
#include "IVendor.h"
#include "ComPort.h"
#include "IPort.h"


class ModbusRTU : public Modbus
{
public:
    ModbusRTU();
    ~ModbusRTU();

public:
    unsigned short CRC16(unsigned char *pbuf, int len);
    bool MessageCheck(unsigned char *inBuf,short bufLen);

    // 0x00
    ResultType ReadCoils(int addDev, int addCol, int num, unsigned char *pbuf=0);
    ResultType WriteCoil(int addDev, int addCol, int value);
    ResultType WriteMultipleCoils(int addDev, int addCol, int num, int cntByte, unsigned char *pbuf=0);

    // 0x10001
    ResultType ReadDiscreteInputs(int addDev, int addinput, int num, unsigned char *pbuf=0);

    // 0x30001
    ResultType ReadReadInputRegister(int addDev, int addReg, int num, unsigned char *pbuf=0);

    // 0x40001
    ResultType ReadHoldingRegister(int addDev, int addReg, int num, unsigned char *pbuf=0);
    ResultType WriteHoldingRegister(int addDev, int addReg, unsigned short data);
    ResultType WriteMultipleHoldingRegister(int addDev, int addReg, int num, unsigned char *pbuf=0);
    ResultType WriteIntToHoldingRegister(int addDev, int addReg, int data);
    ResultType WriteUIntToHoldingRegister(int addDev, int addReg, unsigned int data);
    ResultType WriteFloatToHoldingRegister(int addDev, int addReg, float data);

};




#endif // MODBUSRTU_H






#include "gpio.h"
#include <QDebug>
#include <QFile>
#include <QCoreApplication>
#include <QThread>
#include <QProcess>
#include <QVariant>

#define MCC_NODE_M4 2

#define STATE_BLANK     (10)
#define STATE_NEWMSG          (11)



#ifdef Q_WS_QWS
#include <linux/mcc_config.h>
#include <linux/mcc_common.h>
#include <linux/mcc_linux.h>
extern "C" {
#include <mcc_api.h>
}
#include <stdint.h>


#define MCC_NODE_A5 1


MCC_ENDPOINT endpoint_a5 = {0,0,MCC_NODE_A5};
MCC_ENDPOINT endpoint_m4 = {1,0,MCC_NODE_M4};

int send_msg(msg_t *msg)
{
    int retval;

    retval = mcc_send(&endpoint_m4, msg, sizeof(msg_t), 0xffffffff);
    if(retval)
        qDebug("mcc_send failed, result = 0x%x", retval);

    return retval;
}

int receive_msg(msg_t *msg, int timeout)
{
    int retval, num_of_received_bytes;

    retval = mcc_recv_copy(&endpoint_a5, msg, sizeof(msg_t), (MCC_MEM_SIZE *)&num_of_received_bytes, timeout);
    if(retval)
        qDebug("mcc_recv_copy failed, result = 0x%x",  retval);
    return retval;
}






int GpioOnOff::initmcc()
{
    MCC_INFO_STRUCT info_data;
    int retval = 0;
    uint32_t node_num = endpoint_a5.node;

    retval = mcc_initialize(node_num);
    if(retval)
        return retval;

    retval = mcc_get_info(node_num, &info_data);
    if(retval)
        return retval;

    qDebug("mcc version: %s", info_data.version_string);

    return 0;
}
#else
int GpioOnOff::initmcc()
{
    qDebug("no mcc");

    return 0;
}

#endif

uint32_t GpioOnOff::getData2() const
{
    return data2;
}

void GpioOnOff::setData2(const uint32_t &value)
{
    data2 = value;
}

uint32_t GpioOnOff::getData3() const
{
    return data3;
}

void GpioOnOff::setData3(const uint32_t &value)
{
    data3 = value;
}

uint32_t GpioOnOff::getData4() const
{
    return data4;
}

void GpioOnOff::setData4(const uint32_t &value)
{
    data4 = value;
}
uint32_t GpioOnOff::getData1() const
{
    return data1;
}

void GpioOnOff::setData1(const uint32_t &value)
{
    data1 = value;
}

void GpioOnOff::sleep(long iSleepTime)
{
    QThread::msleep(iSleepTime);
}




void GpioOnOff::mccsendstart(uint32_t data1, uint32_t data2, uint32_t data3, uint32_t data4)
{
    int retval;

    msg.status = STATE_NEWMSG;
    msg.data1 = data1;
    msg.data2 = data2;
    msg.data3 = data3;
    msg.data4 = data4;
#ifdef Q_WS_QWS
    retval = send_msg(&msg);
    if (retval)
        qDebug() << "Error on mcc send start";
#endif
}


void GpioOnOff::run()
{
    qDebug("Inicializando Thread GPIO");
    int retval;

    data1 = 50;
    data2 = 50;
    data3 = 50;
    data4 = 50;

    data1LocalData = data1;
    data2LocalData = data2;
    data3LocalData = data3;
    data4LocalData = data4;

#ifdef Q_WS_QWS

//    qDebug("Loading eCos firmware...");
//    QProcess processMqx;
//    processMqx.start("mqxboot /home/root/Robo.bin 0x8f000400 0x0f000411");
//    if (!processMqx.waitForFinished())
//        qWarning() << "mqxboot failed";
#endif

    retval = initmcc();
    if (retval) {
        qDebug("Error during mcc_get_info, result = %d", retval);
    }


    while(1)
    {
        int send =0;
        if(data1 != data1LocalData)
        {
            data1LocalData =data1;
            send =1;
        }
        if(data2 != data2LocalData)
        {
            data2LocalData =data2;
            send =1;
        }
        if(data3 != data3LocalData)
        {
            data3LocalData =data3;
            send =1;
        }
        if(data4 != data4LocalData)
        {
            data4LocalData =data4;
            send =1;
        }

        if(send)
        {
#ifdef Q_WS_QWS
        mccsendstart(data1, data2, data3, data4);
            qDebug("teste 7");
        qDebug("Data1 = %d | Data2 = %d | Data3 = %d | Data4 = %d", data1, data2, data3, data4);
#endif
        }
        sleep(100);
    }
}

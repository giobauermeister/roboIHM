#ifndef GPIOONOFF_H
#define GPIOONOFF_H
#include <QThread>
#include <stdint.h>

typedef struct msg_s
{
    uint32_t     data1;
    uint32_t     data2;
    uint32_t     data3;
    uint32_t     data4;
    uint32_t     status;
} msg_t;

class GpioOnOff : public QThread
{
    Q_OBJECT
public:
    uint32_t     data1;
    uint32_t     data2;
    uint32_t     data3;
    uint32_t     data4;
    uint32_t     data1LocalData;
    uint32_t     data2LocalData;
    uint32_t     data3LocalData;
    uint32_t     data4LocalData;
    /* Is this accepted in C++? Probably not :-) */
    uint32_t getData1() const;
    void setData1(const uint32_t &value);

    uint32_t getData2() const;
    void setData2(const uint32_t &value);

    uint32_t getData3() const;
    void setData3(const uint32_t &value);

    uint32_t getData4() const;
    void setData4(const uint32_t &value);

private:
    msg_t msg, rcv_msg;
    int servo_state;

    bool end;
    int initmcc();
    void run();
    void mccsendstart(uint32_t data1, uint32_t data2, uint32_t data3, uint32_t data4);
    void sleep(long iSleepTime);
signals:

public slots:
};

#endif // GPIOONOFF_H

#ifndef BATTERYICON_HPP
#define BATTERYICON_HPP

#ifdef DEBUG_EN
#include <QDebug>
#endif

#include <QObject>
#include <cstdint>
#include <unordered_map>

extern "C"
{
#include "INA219.h"
}

#define BI_MAX_ARR_SIZE 30
#define LOWEST_BATT_INA 17035                                   // Lowest value from INA219 before PiRacer die out
#define ONE_PERCENT_INA ((65535 - LOWEST_BATT_INA) / 100)


class BatteryIcon : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint8 isPercent READ isPercent WRITE setPercent NOTIFY isPercentChanged)

public:
    explicit BatteryIcon(QObject *parent = nullptr);
    ~BatteryIcon();

    /********* getters *********/
    uint8_t     isPercent() const;

    /********* setters *********/
    void        setPercent(uint8_t & _percent);


signals:
    void        isPercentChanged();

protected:
    void    timerEvent(QTimerEvent *event);
    void    refreshPercent();

private:
    uint8_t     _percent;           // Battery status converted to output in percentage, ready to be displayed to user

    int         _battTimerId;                   // used for the interval timer
    uint16_t    _rawBattData[BI_MAX_ARR_SIZE];  // array holding the 16 bit data representing Voltage as retrieved directly from the INA219 chip
    uint8_t     _count;                         // For counting the size of _rawBattData
};

#endif // BATTERYICON_HPP

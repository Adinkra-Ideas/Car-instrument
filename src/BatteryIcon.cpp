#include "BatteryIcon.hpp"

BatteryIcon::BatteryIcon(QObject *parent) :
                                QObject{parent},
                                _percent{0},
                                _battTimerId{0},
                                _count{0},
                                _fd{0}

{
    // start the timer
    _battTimerId = startTimer(2000);

    // init half-duplex transmission between I2C Bus and INA219
    if ( ina219_begin_txv() ) {
        #ifdef DEBUG_EN
        qDebug() << "Failed to initialize INA219";
        #endif
    }

    // open the file for storing last known battery charge
    _fd = open("lastKnownCharge", O_RDWR | O_CREAT, 0640);

    // get the last known charge if exist
    if (_fd != -1) {
        read(_fd, &_percent, 1);
    }
}

BatteryIcon::~BatteryIcon() {
    // close the timer
    killTimer(_battTimerId);

    // close the fd
    close(_fd);
}


        // **************************************
        //          GETTER METHODS BEGINS       *
        // **************************************
uint8_t BatteryIcon::isPercent() const {
    return _percent;
}
        // **************************************
        //          GETTER METHODS ENDS         *
        // **************************************


        // **************************************
        //          SETTER METHODS BEGINS       *
        // **************************************
void BatteryIcon::setPercent(uint8_t & percent) {
    _percent = percent;

    emit isPercentChanged();
}
        // **************************************
        //          SETTER METHODS ENDS         *
        // **************************************


/**
  * Just a timerEvent
  * @param as Specified by MAN
  * @returns void
  */
void BatteryIcon::timerEvent(QTimerEvent *event) {
    refreshPercent();
}

/**
  * Gets the most occuring element from * arr. If
  * more than 1, takes the element with lower value
  * @param *arr pointer to the array
  * @param len length of the array
  * @param cutOff any element whose value is lower
  ** than cutOff will not be considered.
  * @returns uint16_t most occuring element
  */
static uint16_t getLowestMostOccuring(uint16_t * arr, uint8_t len, uint16_t cutOff) {
    // Insert all elements in hash Table
    // using format element=>frequency
    // Also, filter out junks using cutOff
    std::unordered_map<uint16_t, uint8_t> myHash;
    for (uint8_t i = 0; i < len; i++) {
        if(arr[i] >= cutOff) {
            myHash[arr[i]]++;
        }
    }

    // find the max frequency.
    // Take element with lower val if max freq more than 1
    uint8_t max_count = 0;
    uint16_t res = 0;
    for (auto j : myHash) {
        if (max_count < j.second) {
            res = j.first;
            max_count = j.second;
        } else if (max_count == j.second && res > j.first) {
            res = j.first;
        }
    }

    return res;
}

/**
  * Converts the output parameter to a percentage value.
  * @param the 16bit value read from INA219 as bus voltage.
  * @returns uint8_t the output converted to percentage.
  */
static uint8_t outputToPercent(uint16_t output) {
    return (output - LOWEST_BATT_INA > 0) ?
               (output - LOWEST_BATT_INA) / ONE_PERCENT_INA : 0;
}

/**
  * Does the Heart of the Task
  * @param
  * @returns void
  */
void BatteryIcon::refreshPercent() {
    qDebug() << "_count: " << _count;
    // Check if _rawBattData[] is filled.
    // Update the batt status for UI if yes
    if (_count >= BI_MAX_ARR_SIZE) {
        // Get the most occuring value from the 30 elements stored in _rawBattData
        uint16_t mostOccuringBattData = getLowestMostOccuring(_rawBattData,
                                                              BI_MAX_ARR_SIZE,
                                                              LOWEST_BATT_INA);

        // call functions to perform percentage calculation and store data to _percent
        _percent = outputToPercent(mostOccuringBattData);

        // store the last known charge
        if (_fd != -1) {
            write(_fd, &_percent, 1);
        }

        // reset count
        _count = 0;

        // #ifdef DEBUG_EN
        qDebug() << "mostOccuringBattData: " << mostOccuringBattData;
        // #endif
    }

    // retrieve one battery status data from ina219,
    // and store to _rawBattData[]
    if ( ! ina219_getRawBattData( &_rawBattData[_count] ) ) {
        ++_count;
    } else {
    #ifdef DEBUG_EN
        qDebug() << "failure to read voltage from INA219";
    #endif
    }

    // refresh the UI
    emit isPercentChanged();
}

#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H

#include <Flight.h>


class DomesticFlight
{
    int numOfFlight = 10;

    public :
    std::string flightNumber[10] = {"SA7001","SA7002","SA7003","SA7004","SA7005","SA7001","SA7002","SA7003","SA7004","SA7005"};
    std::string origin[10] = {"KUL-Kuala Lumpur","KUL-Kuala Lumpur","SZB-Subang","KBR-Kota Bahru","BKI-Kota Kinabalu",
                             "KCH-Kuching   ","PEN-Penang    ","JHB-JohorBahru","LGK-Langkawi","TGG-Kuala Terengganu"};
    std::string destination[10] = {"JHB-Johor Bahru\t","PEN-Penang    \t","\tKBR-Kota Bahru\t","\tLGK-Langkawi\t","KCH-Kuching   \t",
                                  "\tKUL-Kuala Lumpur","\tTGG-Kuala Terengganu","\tKUL-Kuala Lumpur","\tKCH-Kuching   \t","JHB-JohorBahru\t"};
    std::string departDate[10] = {"7/6","8/6","8/6","9/6","9/6","10/6","11/6","12/6","12/6","13/6"};
    std::string departTime[10] = {"0730","1400","1030","2200","0530","1100","1700","2330","2130","0900"};
    double dFare[10] = {145,120,133,129,112,278,158,117,265,290};
    void flight();
    void dTicket();
};

#endif // DOMESTICFLIGHT_H


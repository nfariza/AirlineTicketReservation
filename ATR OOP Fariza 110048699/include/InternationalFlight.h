#ifndef INTERNATIONALFLIGHT_H
#define INTERNATIONALFLIGHT_H

#include <Flight.h>

class InternationalFlight
{
    public :
    int numOfFlight = 10;
    std::string flightNumber[10] = {"SA7006","SA7007","SA7008","SA7009","SA7010","SA7006","SA7007","SA7008","SA7009","SA7010"};
    std::string origin[10] = {"KUL-Kuala Lumpur","KUL-Kuala Lumpur","KUL-Kuala Lumpur","NRT-Tokyo","ICN-Seoul\t","SYD-Sydney\t",
                             "AKL-Auckland\t","LHR-London\t","KUL-Kuala Lumpur","KUL-Kuala Lumpur"};
    std::string destination[10] = {"SYD-Sydney\t","LHR-London\t","AKL-Auckland\t","\tKUL-Kuala Lumpur","KUL-Kuala Lumpur",
                                  "KUL-Kuala Lumpur","KUL-Kuala Lumpur","KUL-Kuala Lumpur","NRT-Tokyo\t","ICN-Seoul\t"};
    std::string departDate[10] = {"9/6","10/6","11/6","11/6","13/6","14/6","14/6","15/6","16/6","16/6"};
    std::string departTime[10] = {"0430","1615","2300","2015","0930","1200","1345","1000","0630","1800"};


    double iFare[10] = {439,1497,571,443,385,429,518,1790,392,437};
    void flight();
    void iTicket();
};
#endif // INTERNATIONALFLIGHT_H

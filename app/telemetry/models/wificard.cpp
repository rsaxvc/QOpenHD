#include "wificard.h"

WiFiCard::WiFiCard(QObject *parent)
    : QObject{parent}
{

}

WiFiCard &WiFiCard::instance_gnd(int index)
{
    if(index==0){
        static WiFiCard gnd0{};
        return gnd0;
    }else if(index==1){
        static WiFiCard gnd1{};
        return gnd1;
    }else if(index==2){
        static WiFiCard gnd2{};
        return gnd2;
    }else if(index==3){
        static WiFiCard gnd3{};
        return gnd3;
    }
    assert(false);
}

WiFiCard &WiFiCard::instance_air()
{
    static WiFiCard air{};
    return air;
}

int WiFiCard::helper_get_gnd_curr_best_rssi()
{
    int best_rssi=-127;
    for(int i=0;i<4;i++){
        auto& card=instance_gnd(i);
        if(card.alive() && card.m_curr_rx_rssi_dbm>best_rssi){
            best_rssi=card.m_curr_rx_rssi_dbm;
        }
    }
    return best_rssi;
}


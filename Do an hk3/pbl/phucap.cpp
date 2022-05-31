#include "phucap.h"

//PHUCAP::PHUCAP(){

//}
PHUCAP::PHUCAP(QString mpc,  float hspc)
    :MPC(mpc), HSPC(hspc)
{

}

PHUCAP::~PHUCAP()
{

}

QString PHUCAP::getMPC()
{
    return this->MPC;
}


float PHUCAP::getHSPC()
{
    return this->HSPC;
}

void PHUCAP::setMPC(QString mpc)
{
    this->MPC = mpc;
}

void PHUCAP::setHSPC(float hspc)
{
    this->HSPC = hspc;
}


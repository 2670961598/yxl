#include "set.h"

set::set()
{

}

const QString set::gettext(){
    return this->area + "," + this->x + ","
+ this->y;
}
const QString set::getmaintext(){
    return this->area ;
}

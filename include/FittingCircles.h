#include "mystuff.h"
#include "data.h"
#include "circle.h"

int CircleFitByChernovHoussam(Data& data, Circle& circleIni, reals LambdaIni, Circle& circle);
int CircleFitByChernovLesort(Data& data, Circle& circleIni, reals LambdaIni, Circle& circle);
Circle CircleFitByHyper(Data& data);
Circle CircleFitByKasa(Data& data);
int CircleFitByLevenbergMarquardtFull(Data& data, Circle& circleIni, reals LambdaIni, Circle& circle);
int CircleFitByLevenbergMarquardtReduced(Data& data, Circle& circleIni, reals LambdaIni, Circle& circle);
Circle CircleFitByPratt(Data& data);
Circle CircleFitByTaubin(Data& data);
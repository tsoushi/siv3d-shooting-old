#include "Unit.h"

Unit::Unit(EntityRegion region, int32 hp)
	: Entity{ region }, Damageable { hp }
{

}

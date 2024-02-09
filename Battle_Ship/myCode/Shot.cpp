/*
 * Shot.cpp
 *
 *  Created on: 31 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#include "Shot.h"

Shot::Shot(GridPosition targetPosition): targetPosition(targetPosition)
{
}

GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}

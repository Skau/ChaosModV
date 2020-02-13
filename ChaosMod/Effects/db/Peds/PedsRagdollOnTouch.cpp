#include <stdafx.h>

static void OnStop()
{
	for (auto ped : GetAllPeds())
	{
		SET_PED_RAGDOLL_ON_COLLISION(ped, false);
	}
}

static void OnTick()
{
	for (auto ped : GetAllPeds())
	{
		SET_PED_RAGDOLL_ON_COLLISION(ped, true);
	}
}

static RegisterEffect registerEffect(EFFECT_PEDS_RAGDOLL_ON_TOUCH, nullptr, OnStop, OnTick);
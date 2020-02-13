#include <stdafx.h>

static void OnStart()
{
	auto playerPed = PLAYER_PED_ID();

	if (IS_PED_IN_ANY_VEHICLE(playerPed, false))
	{
		auto playerVeh = GET_VEHICLE_PED_IS_IN(playerPed, false);

		int seats = GET_VEHICLE_MODEL_NUMBER_OF_SEATS(GET_ENTITY_MODEL(playerVeh));

		std::vector<Ped> pedPool;
		for (auto ped : GetAllPeds())
		{
			if (!IS_PED_A_PLAYER(ped) && IS_PED_HUMAN(ped))
			{
				pedPool.push_back(ped);
			}
		}

		for (int i = -1; i < seats; i++)
		{
			if (pedPool.empty())
			{
				break;
			}
			if (IS_VEHICLE_SEAT_FREE(playerVeh, i, false))
			{
				int randomIndex = Random::GetRandomInt(0, pedPool.size() - 1);
				SET_PED_INTO_VEHICLE(pedPool[randomIndex], playerVeh, i);

				pedPool.erase(pedPool.begin() + randomIndex);
			}
		}
	}
}

static RegisterEffect registerEffect(EFFECT_VEH_TPRANDOMPEDS, OnStart);
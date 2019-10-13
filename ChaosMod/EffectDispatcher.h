#pragma once
#include "Effects.h"
#include <vector>

class EffectDispatcher
{
public:
	EffectDispatcher(int effectSpawnTime, int effectTimedDur, std::vector<EffectType> enabledEffects, int effectTimedShortDur,
		std::array<int, 3> timerColor, std::array<int, 3> textColor, std::array<int, 3> effectTimerColor);
	~EffectDispatcher();

public:
	void Draw();
	void UpdateTimer();
	void UpdateEffects();
	void DispatchEffect(EffectType effectType);
	void DispatchRandomEffect();
	void ClearEffects();
	void Reset();

private:
	const int m_effectSpawnTime;
	const int m_effectTimedDur;
	const std::vector<EffectType> m_enabledEffects;
	const int m_effectTimedShortDur;
	const std::array<int, 3> m_timerColor;
	const std::array<int, 3> m_textColor;
	const std::array<int, 3> m_effectTimerColor;

	float m_percentage;
	Effects* m_effects;

	struct ActiveEffect
	{
	public:
		ActiveEffect(EffectType effectType, const char* name, int timer) : EffectType(effectType), Name(name), Timer(timer),
			MaxTime(Timer) {}

	public:
		EffectType EffectType;
		const char* Name;
		int Timer;
		int MaxTime;
	};

	std::vector<ActiveEffect> m_activeEffects;
	DWORD64 m_timerTimer;
	int m_timerTimerRuns;
	DWORD64 m_effectsTimer;
};
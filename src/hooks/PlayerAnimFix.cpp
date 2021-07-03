#include "common.hpp"
#include "DetourHook.hpp"

namespace hacks::tf2::animfix
{
DetourHook frameadvance_detour{};
typedef float (*FrameAdvance_t)(IClientEntity *, float);

std::vector<float> previous_simtimes;

// Credits to Blackfire62 for telling me how this could be realized
float FrameAdvance_hook(IClientEntity *self, float flInterval)
{
    float newInterval = flInterval;

    // Check if the entity is valid
    if (self && IDX_GOOD(self->entindex()) && self->entindex() > 0 && self->entindex() <= (int) previous_simtimes.size())
    {
        // Check if they are an alive player
        CachedEntity *ent = ENTITY(self->entindex());
        // Set new interval based on their simtime
        if (CE_GOOD(ent) && ent->m_Type() == ENTITY_PLAYER && ent->m_bAlivePlayer())
        {
            float simtime = CE_FLOAT(ent, netvar.m_flSimulationTime);
            // Calculate the time we need to animate by
            float time_difference = simtime - previous_simtimes.at(ent->m_IDX - 1);
            if (time_difference > 0.0f)
                newInterval = time_difference;
            previous_simtimes.at(ent->m_IDX - 1) = simtime;
            // If the simtime didn't update we need to make sure that the original function also does not update
            if (newInterval == 0.0f)
                CE_FLOAT(ent, netvar.m_flAnimTime) = g_GlobalVars->curtime;
        }
    }

    FrameAdvance_t original = (FrameAdvance_t) frameadvance_detour.GetOriginalFunc();
    float return_value      = original(self, newInterval);
    frameadvance_detour.RestorePatch();
    return return_value;
}

void LevelInit()
{
    previous_simtimes.clear();
    previous_simtimes.resize(g_IEngine->GetMaxClients());
}

static InitRoutine init([]() {
    static auto FrameAdvance_signature = gSignatures.GetClientSignature("55 89 E5 57 56 53 83 EC 4C 8B 5D ? 80 BB ? ? ? ? 00 0F 85 ? ? ? ? 8B B3");
    frameadvance_detour.Init(FrameAdvance_signature, (void *) FrameAdvance_hook);
    EC::Register(EC::LevelInit, LevelInit, "levelinit_animfix");
    LevelInit();

    EC::Register(
        EC::Shutdown, []() { frameadvance_detour.Shutdown(); }, "shutdown_animfix");
});
} // namespace hacks::tf2::animfix

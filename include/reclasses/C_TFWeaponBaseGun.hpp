/*
 * C_TFWeaponBaseGun.hpp
 *
 *  Created on: Nov 23, 2017
 *      Author: nullifiedcat
 */

#pragma once

#include "reclasses.hpp"

namespace re
{

class C_TFWeaponBaseGun : public C_TFWeaponBase
{
public:
    inline static float GetProjectileSpeed(IClientEntity *self)
    {
        typedef float (*fn_t)(IClientEntity *);
        return vfunc<fn_t>(self, offsets::PlatformOffset(535, offsets::undefined, 535), 0)(self);
    }
    inline static float GetWeaponSpread(IClientEntity *self)
    {
        typedef float (*fn_t)(IClientEntity *);
        return vfunc<fn_t>(self, offsets::PlatformOffset(533, offsets::undefined, 533), 0)(self);
    }
    inline static float GetProjectileGravity(IClientEntity *self)
    {
        typedef float (*fn_t)(IClientEntity *);
        return vfunc<fn_t>(self, offsets::PlatformOffset(536, offsets::undefined, 536), 0)(self);
    }
    inline static int LaunchGrenade(IClientEntity *self)
    {
        typedef int (*fn_t)(IClientEntity *);
        return vfunc<fn_t>(self, offsets::PlatformOffset(549, offsets::undefined, 549), 0)(self);
    }
};
} // namespace re

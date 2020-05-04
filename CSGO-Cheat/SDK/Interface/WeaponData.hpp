#pragma once

#include "../Enums/WeaponType.hpp"
#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
    struct WeaponData
    {
        PAD(pad1, 20);
        int maxClip;
        PAD(pad2, 112);
        char* name;
        PAD(pad3, 60);
        Enum::WeaponType type;
        PAD(pad4, 16);
        float cycleTime;
        PAD(pad5, 12);
        bool fullAuto;
        PAD(pad6, 3);
        int damage;
        float armorRatio;
        int bullets;
        float penetration;
        PAD(pad7, 8);
        float range;
        float rangeModifier;
        PAD(pad8, 0x10);
        bool silencer;
        PAD(pad9, 15);
        float maxSpeed;
        float maxSpeedAlt;
        PAD(pad10, 100);
        float recoilMagnitude;
        float recoilMagnitudeAlt;
        PAD(pad11, 0x14);
        float recoveryTimeStand;
    };
}

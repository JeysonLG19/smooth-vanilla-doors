
#pragma once

#include <optional>

#include "mod/Config.h"

#include <pl/Mod.hpp>

namespace smooth_vanilla_doors {

class SmoothVanillaDoorsMod {
public:
    static SmoothVanillaDoorsMod &instance();

    SmoothVanillaDoorsMod();

    [[nodiscard]] ll::mod::NativeMod &getSelf() const {
        return mSelf;
    }

    bool load();
    bool enable();
    bool disable();
    bool unload();

private:
    ll::mod::NativeMod &mSelf;
    ModConfig mConfig;
    std::optional<pl::config::ConfigFile<ModConfig>> mConfigFile;
};

} // namespace smooth_vanilla_doors

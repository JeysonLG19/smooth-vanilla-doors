
#include "mod/MyMod.h"

#include <filesystem>

#include <pl/Mod.hpp>

namespace smooth_vanilla_doors {

SmoothVanillaDoorsMod &SmoothVanillaDoorsMod::instance() {
    static SmoothVanillaDoorsMod instance;
    return instance;
}

SmoothVanillaDoorsMod::SmoothVanillaDoorsMod()
    : mSelf(*ll::mod::NativeMod::current()) {
}

bool SmoothVanillaDoorsMod::load() {
    auto &self = getSelf();

    self.getLogger().debug("Loading Smooth Vanilla Doors...");

    std::error_code ec;

    std::filesystem::create_directories(
        self.getDataDir(), ec
    );

    if (ec) {
        self.getLogger().error(
            "Failed to create data directory: {}",
            ec.message()
        );
        return false;
    }

    std::filesystem::create_directories(
        self.getConfigDir(), ec
    );

    if (ec) {
        self.getLogger().error(
            "Failed to create config directory: {}",
            ec.message()
        );
        return false;
    }

    mConfigFile.emplace();

    if (!mConfigFile->load()) {
        self.getLogger().error(
            "Failed to load Smooth Vanilla Doors configuration"
        );
        return false;
    }

    mConfig = mConfigFile->value();

    self.getLogger().info(
        "Smooth Vanilla Doors loaded successfully"
    );

    return true;
}

bool SmoothVanillaDoorsMod::enable() {
    auto &self = getSelf();

    self.getLogger().debug(
        "Enabling Smooth Vanilla Doors..."
    );

    if (!mConfig.enabled) {
        self.getLogger().info(
            "Smooth Vanilla Doors is disabled in config"
        );
        return true;
    }

    self.getLogger().info(
        "Door animation setting: {}",
        mConfig.animateDoors
    );

    self.getLogger().info(
        "Trapdoor animation setting: {}",
        mConfig.animateTrapdoors
    );

    self.getLogger().info(
        "Animation duration: {} ms",
        mConfig.animationDurationMs
    );

    self.getLogger().warn(
        "Vanilla renderer hooks are not implemented yet."
    );

    return true;
}

bool SmoothVanillaDoorsMod::disable() {
    getSelf().getLogger().debug(
        "Disabling Smooth Vanilla Doors..."
    );

    return true;
}

bool SmoothVanillaDoorsMod::unload() {
    getSelf().getLogger().debug(
        "Unloading Smooth Vanilla Doors..."
    );

    mConfigFile.reset();

    return true;
}

} // namespace smooth_vanilla_doors

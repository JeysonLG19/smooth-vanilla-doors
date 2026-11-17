
#pragma once

#include <string_view>

#include <pl/Config.hpp>

namespace smooth_vanilla_doors {

struct ModConfig {
    int version = 1;

    bool enabled = true;

    bool animateDoors = true;

    bool animateTrapdoors = true;

    int animationDurationMs = 300;
};

nlohmann::json makeDefaultConfigJson();

nlohmann::json makeConfigSchemaJson();

} // namespace smooth_vanilla_doors

template <>
struct pl::config::Schema<smooth_vanilla_doors::ModConfig> {

    static constexpr std::string_view title =
        "Smooth Vanilla Doors";

    static constexpr std::string_view description =
        "Configuration for experimental vanilla door and trapdoor animations.";

    static constexpr FieldSchema field(std::string_view name) {

        if (name == "version")
            return {
                .title = "Version",
                .readOnly = true
            };

        if (name == "enabled")
            return {
                .title = "Enabled",
                .description = "Enables the mod."
            };

        if (name == "animateDoors")
            return {
                .title = "Animate Doors",
                .description = "Enables experimental door animation."
            };

        if (name == "animateTrapdoors")
            return {
                .title = "Animate Trapdoors",
                .description = "Enables experimental trapdoor animation."
            };

        if (name == "animationDurationMs")
            return {
                .title = "Animation Duration",
                .description = "Animation duration in milliseconds."
            };

        return {};
    }
};


#include "mod/Config.h"

namespace smooth_vanilla_doors {

nlohmann::json makeDefaultConfigJson() {
    return pl::config::defaultJson(ModConfig{});
}

nlohmann::json makeConfigSchemaJson() {
    return pl::config::schema(ModConfig{});
}

} // namespace smooth_vanilla_doors

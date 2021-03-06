#pragma once

#include "blackhole/factory.hpp"

namespace blackhole {
inline namespace v1 {
namespace sink {

class syslog_t;

}  // namespace sink

template<>
class factory<sink::syslog_t> : public factory<sink_t> {
    const registry_t& registry;

public:
    constexpr explicit factory(const registry_t& registry) noexcept :
        registry(registry)
    {}

    auto type() const noexcept -> const char* override;
    auto from(const config::node_t& config) const -> std::unique_ptr<sink_t> override;
};

}  // namespace v1
}  // namespace blackhole

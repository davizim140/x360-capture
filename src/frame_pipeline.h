#pragma once
#include <cstddef>
#include <cstdint>
namespace x360capture {
struct FrameView {
    const std::uint8_t* pixels = nullptr;
    std::size_t byte_count = 0;
    std::uint32_t width = 0, height = 0;
    std::uint64_t timestamp_us = 0;
};
bool valid_rgba_frame(const FrameView& frame) noexcept;
// Platform-specific implementations are intentionally not included in this stage.
class FrameSource {
public:
    virtual ~FrameSource() = default;
    virtual bool acquire(FrameView* out_frame) noexcept = 0;
};
class FrameSink {
public:
    virtual ~FrameSink() = default;
    virtual bool begin(std::uint32_t width, std::uint32_t height,
                       std::uint32_t frames_per_second) noexcept = 0;
    virtual bool write(const FrameView& frame) noexcept = 0;
    virtual bool finish() noexcept = 0;
};
}

#include "capture_core.h"
#include <limits>

namespace x360capture {
RecorderState RecorderCore::state() const noexcept { return state_; }
StartResult RecorderCore::start() noexcept {
    if (state_ == RecorderState::Recording) return StartResult::AlreadyRecording;
    state_ = RecorderState::Recording;
    return StartResult::Started;
}
StopResult RecorderCore::stop() noexcept {
    if (state_ == RecorderState::Idle) return StopResult::NotRecording;
    state_ = RecorderState::Idle;
    return StopResult::Stopped;
}
bool rgba_frame_size(std::uint32_t width, std::uint32_t height,
                     std::size_t* out_bytes) noexcept {
    if (out_bytes == nullptr || width == 0 || height == 0) return false;
    constexpr std::size_t bytes_per_pixel = 4;
    const std::size_t max_value = std::numeric_limits<std::size_t>::max();
    if (static_cast<std::size_t>(width) > max_value / bytes_per_pixel) return false;
    const std::size_t row_bytes = static_cast<std::size_t>(width) * bytes_per_pixel;
    if (static_cast<std::size_t>(height) > max_value / row_bytes) return false;
    *out_bytes = row_bytes * static_cast<std::size_t>(height);
    return true;
}
}

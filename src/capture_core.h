#pragma once
#include <cstddef>
#include <cstdint>

namespace x360capture {
enum class RecorderState : std::uint8_t { Idle, Recording };
enum class StartResult : std::uint8_t { Started, AlreadyRecording };
enum class StopResult : std::uint8_t { Stopped, NotRecording };

class RecorderCore {
public:
    RecorderState state() const noexcept;
    StartResult start() noexcept;
    StopResult stop() noexcept;
private:
    RecorderState state_ = RecorderState::Idle;
};

bool rgba_frame_size(std::uint32_t width, std::uint32_t height,
                     std::size_t* out_bytes) noexcept;
}

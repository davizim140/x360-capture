#pragma once
#include "frame_pipeline.h"
namespace x360capture {
// Resize an RGBA frame to the project's 640x480 target using nearest-neighbor sampling.
// The destination must point to at least 640*480*4 writable bytes.
constexpr std::uint32_t kOutputWidth = 640;
constexpr std::uint32_t kOutputHeight = 480;
constexpr std::size_t kOutputBytes = static_cast<std::size_t>(kOutputWidth) * kOutputHeight * 4;
bool resize_rgba_to_480p(const FrameView& source, std::uint8_t* destination,
                         std::size_t destination_bytes) noexcept;
}

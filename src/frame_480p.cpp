#include "frame_480p.h"
namespace x360capture {
bool resize_rgba_to_480p(const FrameView& source, std::uint8_t* destination,
                         std::size_t destination_bytes) noexcept {
    if (!valid_rgba_frame(source) || destination == nullptr ||
        destination_bytes < kOutputBytes) return false;
    for (std::uint32_t y = 0; y < kOutputHeight; ++y) {
        const std::uint32_t sy = static_cast<std::uint32_t>(
            (static_cast<std::uint64_t>(y) * source.height) / kOutputHeight);
        for (std::uint32_t x = 0; x < kOutputWidth; ++x) {
            const std::uint32_t sx = static_cast<std::uint32_t>(
                (static_cast<std::uint64_t>(x) * source.width) / kOutputWidth);
            const std::size_t src = (static_cast<std::size_t>(sy) * source.width + sx) * 4;
            const std::size_t dst = (static_cast<std::size_t>(y) * kOutputWidth + x) * 4;
            destination[dst] = source.pixels[src];
            destination[dst + 1] = source.pixels[src + 1];
            destination[dst + 2] = source.pixels[src + 2];
            destination[dst + 3] = source.pixels[src + 3];
        }
    }
    return true;
}
}

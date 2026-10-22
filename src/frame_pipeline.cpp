#include "frame_pipeline.h"
#include "capture_core.h"
namespace x360capture {
bool valid_rgba_frame(const FrameView& frame) noexcept {
    if (frame.pixels == nullptr) return false;
    std::size_t expected = 0;
    if (!rgba_frame_size(frame.width, frame.height, &expected)) return false;
    return frame.byte_count == expected;
}
}

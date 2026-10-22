#include "../src/frame_480p.h"
#include <cstdint>
#include <iostream>
#include <vector>
using namespace x360capture;
int main() {
    int passed = 0, failed = 0;
    const auto check = [&](bool ok, const char* label) {
        std::cout << (ok ? "PASS: " : "FAIL: ") << label << '\n';
        if (ok) ++passed; else ++failed;
    };
    std::vector<std::uint8_t> src(2 * 2 * 4, 0);
    // Distinct RGBA pixels; nearest-neighbor upscale should preserve the top-left pixel.
    src[0] = 11; src[1] = 22; src[2] = 33; src[3] = 255;
    FrameView frame{src.data(), src.size(), 2, 2, 0};
    std::vector<std::uint8_t> dst(kOutputBytes, 0);
    check(resize_rgba_to_480p(frame, dst.data(), dst.size()), "resize valid RGBA frame to 640x480");
    check(dst[0] == 11 && dst[1] == 22 && dst[2] == 33 && dst[3] == 255,
          "preserve sampled RGBA channel values");
    check(!resize_rgba_to_480p(frame, dst.data(), dst.size() - 1), "reject undersized destination");
    check(!resize_rgba_to_480p(frame, nullptr, dst.size()), "reject null destination");
    FrameView invalid{src.data(), src.size() - 1, 2, 2, 0};
    check(!resize_rgba_to_480p(invalid, dst.data(), dst.size()), "reject invalid source frame");
    std::cout << passed << '/' << (passed + failed) << " tests passed\n";
    return failed == 0 ? 0 : 1;
}

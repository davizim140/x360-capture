#include "../src/capture_core.h"
#include <cstddef>
#include <iostream>

using namespace x360capture;
int main() {
    int passed = 0;
    int failed = 0;
    const auto check = [&](bool ok, const char* name) {
        std::cout << (ok ? "PASS: " : "FAIL: ") << name << '\n';
        if (ok) ++passed; else ++failed;
    };
    RecorderCore recorder;
    check(recorder.state() == RecorderState::Idle, "initial state");
    check(recorder.start() == StartResult::Started && recorder.state() == RecorderState::Recording, "start recording");
    check(recorder.start() == StartResult::AlreadyRecording, "reject double start");
    check(recorder.stop() == StopResult::Stopped && recorder.state() == RecorderState::Idle, "stop recording");
    check(recorder.stop() == StopResult::NotRecording, "reject stop while idle");
    std::size_t bytes = 0;
    check(rgba_frame_size(640, 480, &bytes) && bytes == 1228800, "480p RGBA buffer size");
    check(!rgba_frame_size(0, 480, &bytes) && !rgba_frame_size(640, 0, &bytes) && !rgba_frame_size(640, 480, nullptr), "reject invalid dimensions");
    std::cout << passed << '/' << (passed + failed) << " tests passed\n";
    return failed == 0 ? 0 : 1;
}

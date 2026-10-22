# X360 Capture — Stage 4

Portable C++ groundwork for an Xbox 360 RGH/Aurora capture homebrew. Stage 4 adds a tested nearest-neighbor RGBA frame resize utility targeting 640x480 (480p).

This is still only a portable frame-processing component. Platform implementations are not included: the project does **not** yet capture another game's framebuffer, encode video, write recordings to USB, or produce a working `.xex`.

## Run tests

```sh
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp tests/test_capture_core.cpp -o capture-tests
./capture-tests
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp src/frame_pipeline.cpp tests/test_frame_pipeline.cpp -o frame-pipeline-tests
./frame-pipeline-tests
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp src/frame_pipeline.cpp src/frame_480p.cpp tests/test_frame_480p.cpp -o frame-480p-tests
./frame-480p-tests
```

GitHub Actions runs all three test suites on pushes and pull requests.

## Integration constraints

A platform-specific frame source and output sink must be implemented and verified with a real Xbox 360 toolchain. An independent homebrew cannot assume it can read the final framebuffer of another running title; demonstrate this capability on hardware or with a documented SDK capability before claiming gameplay capture works.

The 480p resize utility uses nearest-neighbor sampling for predictable, low-cost processing. It is not a video encoder and does not write to USB.

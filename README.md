# X360 Capture — Stage 3

Portable C++ groundwork for an Xbox 360 RGH/Aurora capture homebrew. This stage adds a validated RGBA `FrameView` contract and abstract `FrameSource`/`FrameSink` interfaces. Platform implementations are not included: this project does **not** yet capture another game's framebuffer, encode video, write to USB, or produce a working `.xex`.

## Run tests

```sh
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp tests/test_capture_core.cpp -o capture-tests
./capture-tests
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp src/frame_pipeline.cpp tests/test_frame_pipeline.cpp -o frame-pipeline-tests
./frame-pipeline-tests
```

GitHub Actions runs both suites on pushes and pull requests.

## Integration constraint

A platform-specific frame source and output sink must be implemented and verified with a real Xbox 360 toolchain. An independent homebrew cannot assume it can read the final framebuffer of another running title; demonstrate this capability on hardware or with a documented SDK capability before claiming gameplay capture works.

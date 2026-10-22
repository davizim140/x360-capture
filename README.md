# X360 Capture — Stage 5

Portable C++ groundwork for an Xbox 360 RGH/Aurora capture homebrew. The project has a recorder state machine, RGBA frame validation, abstract source/sink interfaces, and a tested nearest-neighbor resize utility targeting 640x480.

**SDK target:** [xenosworks/xsdk](https://github.com/xenosworks/xsdk), an open-source Xbox 360 homebrew SDK (MIT). This is not the proprietary Microsoft Xbox 360 XDK.

The project does **not** yet capture another game's framebuffer, encode video, write recordings to USB, or produce a verified working .xex.

## Tests

GitHub Actions compiles and runs the portable core, frame-contract, and 480p-resize tests. See [Actions](https://github.com/davizim140/x360-capture/actions).

For local reproduction:

```sh
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp tests/test_capture_core.cpp -o capture-tests
./capture-tests
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp src/frame_pipeline.cpp tests/test_frame_pipeline.cpp -o frame-pipeline-tests
./frame-pipeline-tests
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp src/frame_pipeline.cpp src/frame_480p.cpp tests/test_frame_480p.cpp -o frame-480p-tests
./frame-480p-tests
```

## Integration status

See [docs/xsdk-integration.md](docs/xsdk-integration.md) for the xSDK-specific plan and important distinction between a title rendering its own buffers and capturing another game's framebuffer.

The upstream xSDK build guide currently requires WSL 2 and substantial disk space. A GitHub Actions build is not yet configured or verified. Portable test success is not evidence of Xbox 360 compatibility.

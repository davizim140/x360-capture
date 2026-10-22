# X360 Capture — Stage 6

Portable C++ groundwork for an Xbox 360 RGH/Aurora capture homebrew. The project has a recorder state machine, RGBA frame validation, abstract source/sink interfaces, and a tested nearest-neighbor resize utility targeting 640x480.

**SDK target:** [xenosworks/xsdk](https://github.com/xenosworks/xsdk), an open-source Xbox 360 homebrew SDK (MIT). This is not the proprietary Microsoft Xbox 360 XDK.

## Current SDK build probe

A manual/cloud GitHub Actions workflow now builds the upstream xSDK at pinned commit `57b02f1e60667e37d22c3aa613d23d2486514ff8`, compiles a minimal smoke-test title, verifies the `.xex` file exists, records its SHA-256 and uploads it as a short-lived artifact. The first run is in progress; do not treat the XEX as available until the workflow succeeds and the artifact appears.

The smoke title tests create/write/flush/close/read-back in its `game:` launch folder. It does **not** prove USB device discovery, gameplay framebuffer capture, video encoding, or end-to-end recording. Console testing is still required.

## Portable tests

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

See [docs/xsdk-integration.md](docs/xsdk-integration.md) for the capture feasibility gates. No real gameplay capture or USB recording is claimed.

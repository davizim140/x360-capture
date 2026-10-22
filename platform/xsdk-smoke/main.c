#include <stdio.h>
#include <string.h>

#include "xsdk/log.h"

static int check_file_round_trip(const char *path, const char *marker)
{
    char buffer[96] = {0};
    const size_t marker_size = strlen(marker);

    if (marker_size >= sizeof buffer)
        return 1;

    FILE *file = fopen(path, "wb");
    if (file == NULL)
        return 1;

    const size_t written = fwrite(marker, 1, marker_size, file);
    const int flush_status = fflush(file);
    const int close_status = fclose(file);
    if (written != marker_size || flush_status != 0 || close_status != 0)
        return 1;

    file = fopen(path, "rb");
    if (file == NULL)
        return 1;

    const size_t read_count = fread(buffer, 1, marker_size, file);
    const int read_close_status = fclose(file);
    if (read_count != marker_size || read_close_status != 0 ||
        memcmp(buffer, marker, marker_size) != 0)
        return 1;

    return 0;
}

static int check_launch_folder(void)
{
    static const char path[] = "game:\\x360_capture_sdk_smoke.txt";
    static const char marker[] = "X360 Capture xSDK USB probe build v2\n";

    if (check_file_round_trip(path, marker) != 0) {
        xsdk_log_write("FAIL: launch-folder file round-trip");
        return 1;
    }
    xsdk_log_write("PASS: launch-folder create/write/read-back (build v2)");
    return 0;
}

static int check_usb_storage(void)
{
    static const char *const paths[] = {
        "Usb0:\\x360_capture_usb_probe.txt",
        "Usb1:\\x360_capture_usb_probe.txt",
        "Usb2:\\x360_capture_usb_probe.txt",
        "Usb3:\\x360_capture_usb_probe.txt"
    };
    static const char marker[] = "X360 Capture USB write/read-back probe v2\n";

    for (unsigned i = 0; i < sizeof paths / sizeof paths[0]; ++i) {
        if (check_file_round_trip(paths[i], marker) == 0) {
            xsdk_log_write("PASS: USB write/read-back succeeded at %s", paths[i]);
            return 0;
        }
        xsdk_log_write("INFO: USB probe path unavailable: %s", paths[i]);
    }

    xsdk_log_write("FAIL: no writable USB mount found at Usb0: through Usb3:");
    return 1;
}

static void write_visible_status(int usb_ok)
{
    static const char path[] = "game:\\x360_capture_usb_status.txt";
    const char *status = usb_ok
        ? "X360 Capture probe build v2\nUSB TEST: PASS\nFile write and read-back succeeded on a USB mount.\nThis is not gameplay video recording.\n"
        : "X360 Capture probe build v2\nUSB TEST: FAIL\nNo writable USB mount was found at Usb0: through Usb3:.\nCheck x360_capture_sdk_smoke.log for details.\nThis is not gameplay video recording.\n";

    FILE *file = fopen(path, "wb");
    if (file == NULL) {
        xsdk_log_write("FAIL: could not write visible USB status file");
        return;
    }
    fwrite(status, 1, strlen(status), file);
    fflush(file);
    fclose(file);
}

int main(void)
{
    unsigned passed = 0;
    unsigned failed = 0;
    xsdk_log_write("X360 Capture xSDK USB probe build v2 starting");

    if (check_launch_folder() == 0)
        ++passed;
    else
        ++failed;

    const int usb_ok = check_usb_storage() == 0;
    if (usb_ok)
        ++passed;
    else
        ++failed;

    write_visible_status(usb_ok);
    xsdk_log_write("checks: %u passed, %u failed", passed, failed);
    xsdk_log_write("NOTE: USB file I/O only; no gameplay capture or video recording yet");
    return failed == 0 ? 0 : 1;
}

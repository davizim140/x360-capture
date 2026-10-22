#include <stdio.h>
#include <string.h>

#include "xsdk/log.h"

static int check_file_round_trip(void)
{
    static const char path[] = "game:\\x360_capture_sdk_smoke.txt";
    static const char marker[] = "X360 Capture xSDK smoke test v1\n";
    char buffer[sizeof marker] = {0};

    FILE *file = fopen(path, "wb");
    if (file == NULL) {
        xsdk_log_write("FAIL: fopen write");
        return 1;
    }
    const size_t written = fwrite(marker, 1, sizeof marker - 1, file);
    const int flush_status = fflush(file);
    const int close_status = fclose(file);
    if (written != sizeof marker - 1 || flush_status != 0 || close_status != 0) {
        xsdk_log_write("FAIL: write/flush/close (written=%u flush=%d close=%d)",
                       (unsigned)written, flush_status, close_status);
        return 1;
    }

    file = fopen(path, "rb");
    if (file == NULL) {
        xsdk_log_write("FAIL: fopen read");
        return 1;
    }
    const size_t read_count = fread(buffer, 1, sizeof marker - 1, file);
    const int read_close_status = fclose(file);
    if (read_count != sizeof marker - 1 || read_close_status != 0 ||
        memcmp(buffer, marker, sizeof marker - 1) != 0) {
        xsdk_log_write("FAIL: file read-back mismatch");
        return 1;
    }

    xsdk_log_write("PASS: create/write/flush/close/read-back title-folder file");
    return 0;
}

int main(void)
{
    unsigned passed = 0;
    unsigned failed = 0;
    xsdk_log_write("X360 Capture xSDK smoke test starting");

    if (check_file_round_trip() == 0)
        ++passed;
    else
        ++failed;

    xsdk_log_write("checks: %u passed, %u failed", passed, failed);
    xsdk_log_write("NOTE: this tests the launch folder only, not USB device discovery or gameplay capture");
    return failed == 0 ? 0 : 1;
}

#include "../src/frame_pipeline.h"
#include <cstdint>
#include <iostream>
using namespace x360capture;
class TestSink final : public FrameSink {
public:
 bool begun=false, wrote=false, finished=false;
 bool begin(std::uint32_t w,std::uint32_t h,std::uint32_t fps) noexcept override { begun=(w==640&&h==480&&fps==30); return begun; }
 bool write(const FrameView& f) noexcept override { wrote=valid_rgba_frame(f); return wrote; }
 bool finish() noexcept override { finished=true; return true; }
};
int main(){
 int passed=0,failed=0;
 const auto check=[&](bool ok,const char* label){std::cout<<(ok?"PASS: ":"FAIL: ")<<label<<'\n';if(ok)++passed;else ++failed;};
 static std::uint8_t pixels[640*480*4]={};
 FrameView frame{pixels,sizeof(pixels),640,480,1234};
 check(valid_rgba_frame(frame),"accept valid 640x480 RGBA frame");
 FrameView null_pixels{nullptr,sizeof(pixels),640,480,1234}; check(!valid_rgba_frame(null_pixels),"reject null pixel pointer");
 FrameView wrong_size{pixels,sizeof(pixels)-1,640,480,1234}; check(!valid_rgba_frame(wrong_size),"reject incorrect frame byte count");
 FrameView zero_dimensions{pixels,sizeof(pixels),0,480,1234}; check(!valid_rgba_frame(zero_dimensions),"reject zero frame dimensions");
 TestSink sink; check(sink.begin(640,480,30),"sink begin lifecycle using test double");
 check(sink.write(frame),"sink accepts validated frame using test double");
 check(sink.finish()&&sink.finished,"sink finish lifecycle using test double");
 std::cout<<passed<<'/'<<(passed+failed)<<" tests passed\n"; return failed==0?0:1;
}

cmake_minimum_required(VERSION 3.16)
project(YoutubeLive)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)
find_package(Jwt REQUIRED)
set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")
find_package(PkgConfig REQUIRED)
pkg_check_modules(FFmpeg REQUIRED IMPORTED_TARGET
    libavdevice
    libavfilter
    libavformat
    libavcodec
    libswresample
    libswscale
    libavutil)

add_executable(jwt jwt/main.cpp)
target_link_libraries(jwt
  OpenSSL::Crypto
  OpenSSL::SSL
  Jwt::jwt)

foreach(_target
    avio_list_dir encode_audio filtering_video metadata resampling_audio vaapi_transcode
    avio_reading encode_video http_multiclient muxing scaling_video decode_audio extract_mvs
    hw_decode transcode_aac decode_video filter_audio transcoding demuxing_decoding
    filtering_audio remuxing vaapi_encode)
  add_executable(ffmpeg-${_target} "ffmpeg/${_target}.c")
  target_link_libraries(ffmpeg-${_target}
    PkgConfig::FFmpeg
    OpenSSL::SSL)
endforeach()

add_library(${PROJECT_NAME}
  src/Auth.cc
  src/Broadcast.cc
  src/Stream.cc)

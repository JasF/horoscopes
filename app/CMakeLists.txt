# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_definitions(-DANDROID -DWEBRTC_POSIX)
include_directories(../Horoscopes/Components/jsoncpp/include ../Horoscopes/src ../Horoscopes/webrtc/src)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp
              ../Horoscopes/src/base/horobase.cc
../Horoscopes/Components/jsoncpp/include/json_writer.cpp
#../Horoscopes/Components/jsoncpp/include/json_reader.cpp
../Horoscopes/Components/jsoncpp/src/lib_json/json_reader.cpp
../Horoscopes/Components/jsoncpp/src/lib_json/json_value.cpp
../Horoscopes/webrtc/src/rtc_base/file_posix_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/histogram_percentile_counter_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/optionsfile_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/socketstream_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/socketadapters_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/logging_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/flags_forxcode.cc
#../Horoscopes/webrtc/src/rtc_base/macifaddrs_converter_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/rtccertificate_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/unixfilesystem_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/bytebuffer_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/asynctcpsocket_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/messagehandler_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/ratelimiter_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/transformadapter_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/stream_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/socketaddresspair_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/proxyinfo_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/messagequeue_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/fileutils_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/crc32_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/socketaddress_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/event_tracer_forxcode.cc
#../Horoscopes/webrtc/src/rtc_base/string_to_number_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/bitrateallocationstrategy_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/filerotatingstream_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/location_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/timeutils_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/asyncinvoker_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/httpcommon_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/signalthread_forxcode.cc
#../Horoscopes/webrtc/src/rtc_base/platform_thread_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/stringencode_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/stringutils_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/physicalsocketserver_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/thread_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/sigslot_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/race_checker_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/logsinks_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/ipaddress_forxcode.cc
#../Horoscopes/webrtc/src/rtc_base/task_queue_libevent_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/asyncresolverinterface_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/platform_file_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/rate_statistics_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/criticalsection_forxcode.cc
#../Horoscopes/webrtc/src/rtc_base/nethelpers_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/rate_limiter_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/networkmonitor_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/thread_checker_impl_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/bitbuffer_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/base64_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/httpbase_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/file_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/asyncsocket_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/asyncudpsocket_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/ratetracker_forxcode.cc
#../Horoscopes/webrtc/src/rtc_base/timestampaligner_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/noop_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/asyncpacketsocket_forxcode.cc
#../Horoscopes/webrtc/src/rtc_base/network_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/copyonwritebuffer_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/random_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/cryptstring_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/ifaddrs_converter_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/nullsocketserver_forxcode.cc
#../Horoscopes/webrtc/src/rtc_base/checks_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/rtccertificategenerator_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/pathutils_forxcode.cc
../Horoscopes/webrtc/src/rtc_base/bufferqueue_forxcode.cc
              )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
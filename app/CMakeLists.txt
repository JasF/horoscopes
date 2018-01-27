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


../Horoscopes/Components/jsoncpp/include/json_writer.cpp
../Horoscopes/Components/jsoncpp/src/lib_json/json_reader.cpp
../Horoscopes/Components/jsoncpp/src/lib_json/json_value.cpp

../Horoscopes/src/android/Platform/platform.cc
../Horoscopes/src/android/Firestore/firestore.cc
../Horoscopes/src/android/Activities/PredictionScreen/predictionscreen.cc
../Horoscopes/src/android/ScreensManager/screensmanager.cc

../Horoscopes/src/database/databaseimpl.cc
../Horoscopes/src/viewmodels/helloscreenviewmodel/helloscreenviewmodelimpl.cc
../Horoscopes/src/viewmodels/notificationsscreenviewmodel/notificationsscreenviewmodelimpl.cc
../Horoscopes/src/viewmodels/predictionscreenviewmodel/predictionscreenviewmodelimpl.cc
../Horoscopes/src/viewmodels/friendsscreenviewmodel/friendsscreenviewmodelimpl.cc
../Horoscopes/src/viewmodels/pushtimescreenviewmodel/pushtimescreenviewmodelimpl.cc
../Horoscopes/src/viewmodels/menuscreenviewmodel/menuscreenviewmodelimpl.cc
../Horoscopes/src/viewmodels/accountscreenviewmodel/accountscreenviewmodelimpl.cc
../Horoscopes/src/managers/managers.cc
../Horoscopes/src/managers/settings/settings.cc
../Horoscopes/src/managers/persondao/persondaoimpl.cc
../Horoscopes/src/managers/viewmodelsimpl/viewmodelsimpls.cc
../Horoscopes/src/managers/viewmodelsimpl/viewmodelsimpl.cc
../Horoscopes/src/managers/serializer/serializerimpl.cc
../Horoscopes/src/managers/horoscopesservice/horoscopesserviceimpl.cc
../Horoscopes/src/managers/screensmanager/screensmanagerimpl.cc
../Horoscopes/src/managers/firestore/firestorefactoryimpl.cc
../Horoscopes/src/managers/firestore/firestoreimpl.cc
../Horoscopes/src/managers/modelsimpl/modelsimpl.cc
../Horoscopes/src/managers/webviewservice/webviewservicefactoryimpl.cc
../Horoscopes/src/managers/themesmanager/themesmanagerimpl.cc
../Horoscopes/src/managers/friendsproviderfactory/friendsproviderfactoryimpl.cc
../Horoscopes/src/managers/horoscopesparser/horoscopesparserimpl.cc
../Horoscopes/src/managers/ntp/ntpimpl.cc
../Horoscopes/src/managers/notificationcenter/notificationcenterimpl.cc
../Horoscopes/src/managers/timerfactory/timerfactoryimpl.cc
../Horoscopes/src/managers/loginmanager/loginmanagerfactoryimpl.cc
../Horoscopes/src/managers/loginmanager/facebookloginmanager.cc
../Horoscopes/src/managers/birthdaydetector/birthdaydetectorimpl.cc
../Horoscopes/src/managers/daofactory/daofactoryimpl.cc
../Horoscopes/src/managers/horoscopedao/horoscopedaoimpl.cc
../Horoscopes/src/managers/friendsmanager/friendsmanagerimpl.cc
../Horoscopes/src/managers/friendsprovider/facebookfriendsprovider.cc
../Horoscopes/src/managers/facebookmanager/facebookmanagerimpl.cc
../Horoscopes/src/managers/notifications/notificationsimpl.cc
../Horoscopes/src/managers/analytics/analyticsimpl.cc
../Horoscopes/src/models/corecomponents/corecomponents.cc
../Horoscopes/src/models/accountscreenmodel/accountscreenmodelimpl.cc
../Horoscopes/src/models/pushtimescreenmodel/pushtimescreenmodelimpl.cc
../Horoscopes/src/models/helloscreenmodel/helloscreenmodelimpl.cc
../Horoscopes/src/models/menuscreenmodel/menuscreenmodelimpl.cc
../Horoscopes/src/models/notificationsscreenmodel/notificationsscreenmodelimpl.cc
../Horoscopes/src/models/friendsscreenmodel/friendsscreenmodelimpl.cc
../Horoscopes/src/models/predictionscreenmodel/predictionscreenmodelimpl.cc
../Horoscopes/src/friends/htmlparser/facebook/facebookuserinformationparser.cc
../Horoscopes/src/friends/htmlparser/facebook/facebookfriendsparser.cc
../Horoscopes/src/friends/htmlparser/facebook/facebookfriendinformationparser.cc
../Horoscopes/src/friends/htmlparser/facebook/facebookuserdetailparser.cc
../Horoscopes/src/friends/htmlparser/facebook/facebookhomepageparser.cc
../Horoscopes/src/friends/htmlparserfactory/htmlparserfactoryimpl.cc
../Horoscopes/src/data/url.cc
../Horoscopes/src/data/datewrapper.cc
../Horoscopes/src/data/horoscopedto.cc
../Horoscopes/src/data/person.cc
../Horoscopes/src/data/zodiac.cc
../Horoscopes/src/data/color.cc
../Horoscopes/src/themes/lightthemeimpl/lightthemeimpl.cc
../Horoscopes/src/themes/darkthemeimpl/darkthemeimpl.cc
../Horoscopes/src/thirdparty/gumbo/string_buffer.c
../Horoscopes/src/thirdparty/gumbo/util.c
../Horoscopes/src/thirdparty/gumbo/vector.c
../Horoscopes/src/thirdparty/gumbo/attribute.c
../Horoscopes/src/thirdparty/gumbo/char_ref.c
../Horoscopes/src/thirdparty/gumbo/utf8.c
../Horoscopes/src/thirdparty/gumbo/error.c
../Horoscopes/src/thirdparty/gumbo/tag.c
../Horoscopes/src/thirdparty/gumbo/parser.c
../Horoscopes/src/thirdparty/gumbo/tokenizer.c
../Horoscopes/src/thirdparty/gumbo/string_piece.c
../Horoscopes/src/base/horobase.cc
../Horoscopes/src/base/coding.cc
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
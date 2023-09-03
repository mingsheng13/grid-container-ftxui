# Most likely, users of the library have already setup FTXUI:
if (TARGET ftxui::component)
  return()
endif()

# Fallback on the system manager:
find_package(ftxui QUIET)
if (ftuix_FOUND)
  return()
endif()

# Fallback on a specific version of FTXUI using FetchContent.
include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)

FetchContent_MakeAvailable(ftxui)

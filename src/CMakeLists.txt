####################################################################################################
### (c) 2019 - Valery Oshuev - oshuev.valery@yandex.ru
####################################################################################################

set(TARGET_NAME ${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON) # включаем автоматическую генерацию moc-файлов qt

add_executable(${TARGET_NAME})

set(PROJECT_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${PROJECT_INCLUDES})

file(GLOB_RECURSE TARGET_HDR ${PROJECT_INCLUDES}/*.h)
file(GLOB_RECURSE TARGET_SRC ${PROJECT_SOURCES}/*.cpp)


target_sources(${TARGET_NAME} PUBLIC ${TARGET_SRC} PUBLIC ${TARGET_HDR})
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Core Qt5::Network Qt5::Xml)



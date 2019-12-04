####################################################################################################
### (c) 2019 - Valery Oshuev - oshuev.valery@yandex.ru
####################################################################################################

set(TARGET_NAME ${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON) # включаем автоматическую генерацию moc-файлов qt
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(PROJECT_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${PROJECT_INCLUDES})

file(GLOB_RECURSE TARGET_HDR ${PROJECT_INCLUDES}/*.h)
file(GLOB_RECURSE TARGET_SRC ${PROJECT_SOURCES}/*.cpp)

set(RESOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/resources)
qt5_add_resources(QRC_RESOURCES ${RESOURCES_PATH}/qml.qrc)

add_executable(${TARGET_NAME})

target_sources(${TARGET_NAME} PUBLIC ${TARGET_SRC} PUBLIC ${TARGET_HDR} PUBLIC ${QRC_RESOURCES})
target_link_libraries(${TARGET_NAME} PUBLIC ymlcpp Qt5::Quick Qt5::QuickControls2 Qt5::Core Qt5::Network Qt5::Xml)

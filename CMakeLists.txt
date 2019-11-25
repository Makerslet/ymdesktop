####################################################################################################
### (c) 2019 - Valery Oshuev - oshuev.valery@yandex.ru
####################################################################################################

cmake_minimum_required(VERSION 3.11)
project(ymdesktop)

find_package(Qt5 COMPONENTS Core Network Xml REQUIRED CONFIG)

#add_subdirectory(libs)
add_subdirectory(src)


cmake_minimum_required(VERSION 3.20.0)

project(st25dv)

add_library(st25dv)
target_compile_options(st25dv PRIVATE -Wall -Wextra)
set_target_properties(st25dv PROPERTIES C_STANDARD 11)

target_include_directories(st25dv PUBLIC 
    src/BSP
    src/libNDEF
    src/ST25DV
)

target_sources(st25dv PRIVATE
    src/BSP/st25dv_nfctag.cpp
    src/libNDEF/lib_NDEF_AAR.c
    src/libNDEF/lib_NDEF_Bluetooth.c
    src/libNDEF/lib_NDEF_Email.c
    src/libNDEF/lib_NDEF_Geo.c
    src/libNDEF/lib_NDEF_Handover.c
    src/libNDEF/lib_NDEF_MyApp.c
    src/libNDEF/lib_NDEF_SMS.c
    src/libNDEF/lib_NDEF_Text.c
    src/libNDEF/lib_NDEF_URI.c
    src/libNDEF/lib_NDEF_Vcard.c
    src/libNDEF/lib_NDEF_Wifi.c
    src/libNDEF/lib_NDEF.c
    src/libNDEF/tagtype5_wrapper.c
    src/ST25DV/st25dv.c
)

file(CONFIGURE OUTPUT .gitignore
  NEWLINE_STYLE UNIX
  CONTENT "*")
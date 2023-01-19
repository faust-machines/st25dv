cmake_minimum_required(VERSION 3.20.0)

project(st25dv)

add_library(st25dv)
target_compile_options(st25dv PRIVATE -Wall -Wextra)
set_target_properties(st25dv PROPERTIES C_STANDARD 11)

target_include_directories(st25dv PUBLIC 
    .
)

target_sources(st25dv PRIVATE
    ST25DV/BSP/st25dv_nfctag.c
    ST25DV/libNDEF/lib_NDEF_AAR.c
    ST25DV/libNDEF/lib_NDEF_Bluetooth.c
    ST25DV/libNDEF/lib_NDEF_Email.c
    ST25DV/libNDEF/lib_NDEF_Geo.c
    ST25DV/libNDEF/lib_NDEF_Handover.c
    ST25DV/libNDEF/lib_NDEF_MyApp.c
    ST25DV/libNDEF/lib_NDEF_SMS.c
    ST25DV/libNDEF/lib_NDEF_Text.c
    ST25DV/libNDEF/lib_NDEF_URI.c
    ST25DV/libNDEF/lib_NDEF_Vcard.c
    ST25DV/libNDEF/lib_NDEF_Wifi.c
    ST25DV/libNDEF/lib_NDEF.c
    ST25DV/libNDEF/tagtype5_wrapper.c
    ST25DV/ST25DV/st25dv.c
)

file(CONFIGURE OUTPUT .gitignore
  NEWLINE_STYLE UNIX
  CONTENT "*")
if(CONFIG_LIBST25DV)
zephyr_interface_library_named(LIBST25DV)

zephyr_include_directories(.)

zephyr_library()
zephyr_library_sources(
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

zephyr_library_link_libraries(LIBST25DV)
target_link_libraries(LIBST25DV INTERFACE zephyr_interface)
endif()
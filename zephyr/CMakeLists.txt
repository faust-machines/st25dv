if(CONFIG_LIBST25DV)
  add_subdirectory(.. build)
  set_property(GLOBAL APPEND PROPERTY ZEPHYR_INTERFACE_LIBS st25dv)
  zephyr_include_directories(
    ..
    ../ST25DV/BSP
    ../ST25DV/libNDEF
    ../ST25DV/ST25DV
  )
  zephyr_library_sources(
    ../ST25DV/BSP/st25dv_nfctag.c
    ../ST25DV/libNDEF/lib_NDEF_AAR.c
    ../ST25DV/libNDEF/lib_NDEF_Bluetooth.c
    ../ST25DV/libNDEF/lib_NDEF_Email.c
    ../ST25DV/libNDEF/lib_NDEF_Geo.c
    ../ST25DV/libNDEF/lib_NDEF_Handover.c
    ../ST25DV/libNDEF/lib_NDEF_MyApp.c
    ../ST25DV/libNDEF/lib_NDEF_SMS.c
    ../ST25DV/libNDEF/lib_NDEF_Text.c
    ../ST25DV/libNDEF/lib_NDEF_URI.c
    ../ST25DV/libNDEF/lib_NDEF_Vcard.c
    ../ST25DV/libNDEF/lib_NDEF_Wifi.c
    ../ST25DV/libNDEF/lib_NDEF.c
    ../ST25DV/libNDEF/tagtype5_wrapper.c
    ../ST25DV/ST25DV/st25dv.c
  )
  # zephyr_interface_library_named(st25dv)
endif()
cmake_minimum_required(VERSION 3.10)

set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_ASM_COMPILER          "${SDCC_ASM_EXEC}")
set(SDCC_SDCC                   "${SDCC_EXEC}")
set(CMAKE_C_COMPILER            "${SDCC_EXEC}")

set(CMAKE_ASM_FLAGS             "${SDCC_ASM_FLAG}")
set(CMAKE_C_FLAGS               "")

set(CMAKE_USER_MAKE_RULES_OVERRIDE_ASM  "${PROJECT_SRC_ROOT}/CMake_Modules/sdcc8051.cmake")
set(CMAKE_USER_MAKE_RULES_OVERRIDE_C    "${PROJECT_SRC_ROOT}/CMake_Modules/sdcc8051.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY      "${PROJECT_BIN_ROOT}/ihx_output")

project(8051_test_code ASM)

function(add_ins INSTRUCTION)
    add_executable(${INSTRUCTION} asm/${INSTRUCTION}.asm)
    message("Added sample program `${INSTRUCTION}`")
endfunction()

function(add_sub_ins CATALOG INS_LIST)
    foreach( INSTRUCTION ${INS_LIST} )
        add_executable(${INSTRUCTION} asm/${CATALOG}/${INSTRUCTION}.asm)
        message("Added sample program ${CATALOG}/`${INSTRUCTION}`")
    endforeach()
endfunction()

if (${NOP_ENABLED})
    add_ins(nop)
endif ()

if (${MOV_ENABLED})
    set(MOV_INS_LIST
            mov_rn_data mov_a_rn mov_rn_a mov_a_data mov_a_direct mov_rn_direct
            mov_direct_a mov_direct_rn mov_direct_direct mov_direct_data mov_ri_data
            mov_a_ri mov_ri_a mov_ri_direct mov_direct_ri mov_dptr_data16 mov_c_bitaddr
            mov_bitaddr_c
            )
    add_sub_ins(mov "${MOV_INS_LIST}")
endif ()

if (${MOVC_ENABLED})
    set(MOVC_INS_LIST
            movc_a_a_dptr movc_a_a_pc
            )
    add_sub_ins(movc "${MOVC_INS_LIST}")
endif()

if (${MOVX_ENABLED})
    set(MOVX_INS_LIST
            movx_dptr_a movx_ri_a movx_a_dptr movx_a_ri
            )
    add_sub_ins(movx "${MOVX_INS_LIST}")
endif ()

if (${ACALL_ENABLED})
    set(ACALL_INS_LIST
            acall_page0 acall_page1 acall_page2 acall_page3 acall_page4
            acall_page5 acall_page6 acall_page7
            )
    add_sub_ins(acall "${ACALL_INS_LIST}")
endif ()

if (${LJMP_ENABLED})
    add_ins(ljmp)
endif ()


unset(CMAKE_USER_MAKE_RULES_OVERRIDE_ASM)
unset(CMAKE_C_COMPILER)
unset(CMAKE_ASM_COMPILER)
unset(CMAKE_ASM_FLAGS)

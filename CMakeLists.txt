cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "C51_emu")
set(PROJECT_VERSION "0.0.1")

project(${PROJECT_NAME})

set(EXTERNAL_LIBRARIES "")
set(PROJECT_SRC_ROOT ${PROJECT_SOURCE_DIR})
set(PROJECT_BIN_ROOT ${PROJECT_BINARY_DIR})
set(CMAKE_CXX_STANDARD 20)

include(CMake_Modules/func_def.cmake)

if ("X${CMAKE_BUILD_TYPE}" STREQUAL "XDebug")
    add_compile_definitions(CMAKE_BUILD_DEBUG=1)
endif()

add_compile_definitions("_FILE_OFFSET_BITS=64")
add_compile_definitions("PACKAGE_NAME=\"${PROJECT_NAME}\"")
add_compile_definitions("PACKAGE_VERSION=\"${PROJECT_VERSION}\"")
add_compile_definitions("COMPILED_WITH_SDCC=1")
add_compile_definitions("PROJECT_BINARY_DIR=\"${PROJECT_BINARY_DIR}\"")

# default definitions
string(TOUPPER ${PROJECT_NAME} MARCO_PREFIX)
default_definition(${MARCO_PREFIX}_PREFIX "\"(${PROJECT_NAME}) \"")

# SDCC Executables
default_marco(SDCC_EXEC         "sdcc-sdcc")
default_marco(SDCC_ASM_EXEC     "sdcc-sdas8051")
default_marco(SDCC_ASM_FLAG     "-plogsff")

# add external library
#set(SHA256SUM_SRC_FILES "")
#set(SHA256SUM_SRC_FILE_NO_PREFIX sha256sum.cpp)
#generate_ext_lib_files(${SHA256SUM_SRC_FILE_NO_PREFIX}
#        sha256sum SHA256SUM_SRC_FILES)
#add_ext_lib(sha256sum ${SHA256SUM_SRC_FILES})

# STEMPFS Static Library
add_library(${PROJECT_NAME} SHARED
        src/framwork/emu_error.cpp      src/include/emu_error.h
        src/framwork/debug.cpp          src/include/debug.h

        src/emulator/ihxstream.cpp      src/include/ihxstream.h
        src/emulator/memory.cpp src/include/c51_memory.h
        src/emulator/cpu.cpp            src/include/cpu.h
        )
target_include_directories(${PROJECT_NAME} PUBLIC src/include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTERNAL_LIBRARIES})

# Unit tests
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    enable_testing()
    default_marco(TEST_ENABLED_INSTRUCTIONS "AJMP")
                 #"NOP;MOV;MOVC;MOVX;ACALL;LJMP;LCALL;RET")
endif ()

foreach(__INSTRUCTION__ ${TEST_ENABLED_INSTRUCTIONS})
    set(${__INSTRUCTION__}_ENABLED TRUE)
    message("<-- Unit test for group ${__INSTRUCTION__} enabled -->")
endforeach()

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")

    _add_test(error                 "Error test")
    _add_test(debug                 "Debug test")
    _add_test(ihxstream             "Test for IHX data stream class")

    # NOP
    if (${NOP_ENABLED})
        _add_test(c51_cpu_nop           "C51 CPU test for instruction nop")
    endif()

    # MOV
    if (${MOV_ENABLED})
        c51_add_test(mov c51_cpu_mov_rn_data        "C51 CPU test for instruction MOV Rn, #data")
        c51_add_test(mov c51_cpu_mov_a_rn           "C51 CPU test for instruction MOV A, Rn")
        c51_add_test(mov c51_cpu_mov_rn_a           "C51 CPU test for instruction MOV Rn, A")
        c51_add_test(mov c51_cpu_mov_a_data         "C51 CPU test for instruction MOV A, #data")
        c51_add_test(mov c51_cpu_mov_a_direct       "C51 CPU test for instruction MOV A, direct")
        c51_add_test(mov c51_cpu_mov_rn_direct      "C51 CPU test for instruction MOV Rn, direct")
        c51_add_test(mov c51_cpu_mov_direct_a       "C51 CPU test for instruction MOV direct, A")
        c51_add_test(mov c51_cpu_mov_direct_rn      "C51 CPU test for instruction MOV direct, Rn")
        c51_add_test(mov c51_cpu_mov_direct_direct  "C51 CPU test for instruction MOV direct, direct")
        c51_add_test(mov c51_cpu_mov_direct_data    "C51 CPU test for instruction MOV direct, #data")
        c51_add_test(mov c51_cpu_mov_ri_data        "C51 CPU test for instruction MOV @Ri, #data")
        c51_add_test(mov c51_cpu_mov_a_ri           "C51 CPU test for instruction MOV A, @Ri")
        c51_add_test(mov c51_cpu_mov_ri_a           "C51 CPU test for instruction MOV @Ri, A")
        c51_add_test(mov c51_cpu_mov_ri_direct      "C51 CPU test for instruction MOV @Ri, direct")
        c51_add_test(mov c51_cpu_mov_direct_ri      "C51 CPU test for instruction MOV direct, @Ri")
        c51_add_test(mov c51_cpu_mov_dptr_data16    "C51 CPU test for instruction MOV DPTR, #data16")
        c51_add_test(mov c51_cpu_mov_c_bitaddr      "C51 CPU test for instruction MOV C, bitaddr")
        c51_add_test(mov c51_cpu_mov_bitaddr_c      "C51 CPU test for instruction MOV bitaddr, C")
    endif()

    # MOVC
    if (${MOVC_ENABLED})
        c51_add_test(movc c51_cpu_movc_a_a_dptr     "C51 CPU test for instruction MOVC A, @A+DPTR")
        c51_add_test(movc c51_cpu_movc_a_a_pc       "C51 CPU test for instruction MOVC A, @A+PC")
    endif()

    # MOVX
    if (${MOVX_ENABLED})
        c51_add_test(movx c51_cpu_movx_dptr_a       "C51 CPU test for instruction MOVX @DPTR, A")
        c51_add_test(movx c51_cpu_movx_ri_a         "C51 CPU test for instruction MOVX @Ri, A")
        c51_add_test(movx c51_cpu_movx_a_dptr       "C51 CPU test for instruction MOVX A, @DPTR")
        c51_add_test(movx c51_cpu_movx_a_ri         "C51 CPU test for instruction MOVX A, @Ri")
    endif()

    # LJMP
    if (${LJMP_ENABLED})
        _add_test(c51_cpu_ljmp                      "C51 CPU test for instruction LJMP addr16")
    endif()

    #ACALL
    if (${ACALL_ENABLED})
        c51_add_test(acall c51_cpu_acall_page0      "C51 CPU test for instruction ACALL page0")
        c51_add_test(acall c51_cpu_acall_page1      "C51 CPU test for instruction ACALL page1")
        c51_add_test(acall c51_cpu_acall_page2      "C51 CPU test for instruction ACALL page2")
        c51_add_test(acall c51_cpu_acall_page3      "C51 CPU test for instruction ACALL page3")
        c51_add_test(acall c51_cpu_acall_page4      "C51 CPU test for instruction ACALL page4")
        c51_add_test(acall c51_cpu_acall_page5      "C51 CPU test for instruction ACALL page5")
        c51_add_test(acall c51_cpu_acall_page6      "C51 CPU test for instruction ACALL page6")
        c51_add_test(acall c51_cpu_acall_page7      "C51 CPU test for instruction ACALL page7")
    endif()

    # LCALL
    if (${LCALL_ENABLED})
        _add_test(c51_cpu_lcall                     "C51 CPU test for instruction LCALL addr16")
    endif()

    # RET
    if (${RET_ENABLED})
        _add_test(c51_cpu_ret                       "C51 CPU test for instruction RET")
    endif()

    #AJMP
    if (${AJMP_ENABLED})
        c51_add_test(ajmp  c51_cpu_ajmp_page0      "C51 CPU test for instruction AJMP page0")
        c51_add_test(ajmp  c51_cpu_ajmp_page1      "C51 CPU test for instruction AJMP page1")
        c51_add_test(ajmp  c51_cpu_ajmp_page2      "C51 CPU test for instruction AJMP page2")
        c51_add_test(ajmp  c51_cpu_ajmp_page3      "C51 CPU test for instruction AJMP page3")
        c51_add_test(ajmp  c51_cpu_ajmp_page4      "C51 CPU test for instruction AJMP page4")
        c51_add_test(ajmp  c51_cpu_ajmp_page5      "C51 CPU test for instruction AJMP page5")
        c51_add_test(ajmp  c51_cpu_ajmp_page6      "C51 CPU test for instruction AJMP page6")
        c51_add_test(ajmp  c51_cpu_ajmp_page7      "C51 CPU test for instruction AJMP page7")
    endif()
endif()

# 8051 test code
add_subdirectory(tests/8051_test_code)

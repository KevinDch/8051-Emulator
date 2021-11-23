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

set(INSTRUCTION_LIST
        nop mov movc movx
        )

foreach( INSTRUCTION ${INSTRUCTION_LIST} )
    add_executable(${INSTRUCTION} asm/${INSTRUCTION}.asm)
    message("Added sample program `${INSTRUCTION}`")
endforeach()

unset(CMAKE_USER_MAKE_RULES_OVERRIDE_ASM)
unset(CMAKE_C_COMPILER)
unset(CMAKE_ASM_COMPILER)
unset(CMAKE_ASM_FLAGS)

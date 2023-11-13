# Function to check initialization of git submodules.
# Arguments:
# [IN]  check_git_submodules    Path to the directory containing submodules.
# [OUT] uninitialized_found     The variable is set to TRUE if uninitialized submodules
#                               are found, otherwise to FALSE.
function(check_git_submodules SUBMODULE_DIR IS_UNINITIALIZED_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule status
        WORKING_DIRECTORY ${SUBMODULE_DIR}
        OUTPUT_VARIABLE GIT_SUBMOD_STATUS
        RESULT_VARIABLE GIT_SUBMOD_STATUS_RES)

    if(GIT_SUBMOD_STATUS_RES EQUAL "0")
        string(REPLACE "\n" ";" GIT_SUBMOD_STATUS_LINES "${GIT_SUBMOD_STATUS}")
        foreach(SUBMODULE_LINE IN LISTS GIT_SUBMOD_STATUS_LINES)
            string(REGEX MATCH "^-" IS_UNINITIALIZED "${SUBMODULE_LINE}")
            if(IS_UNINITIALIZED)
                string(REGEX MATCH " [^ ]+$" SUBMODULE_PATH "${SUBMODULE_LINE}")
                message(WARNING "Uninitialized submodule: ${SUBMODULE_PATH}")
                set(IS_UNINITIALIZED_FOUND TRUE PARENT_SCOPE)
            endif()
        endforeach()
    endif()

endfunction()
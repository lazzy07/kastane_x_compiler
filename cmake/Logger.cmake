# This logger requires LOGGER_PREPEND to be set at the parent scope

# CMake Logger with STATUS
function(log_status MSG)
  if(NOT DEFINED LOGGER_PREPEND)
    set(LOGGER_PREPEND "" PARENT_SCOPE)
  endif()

  message(STATUS "${LOGGER_PREPEND}${MSG}")
endfunction()


function(log_warn MSG)
  if(NOT DEFINED LOGGER_PREPEND)
    set(LOGGER_PREPEND "" PARENT_SCOPE)
  endif()

  message(WARNING "${LOGGER_PREPEND}${MSG}")
endfunction()
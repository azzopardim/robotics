
if(NOT "/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp/sanitizers-gitinfo.txt" IS_NEWER_THAN "/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp/sanitizers-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp/sanitizers-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/arsenm/sanitizers-cmake" "sanitizers"
    WORKING_DIRECTORY "/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/arsenm/sanitizers-cmake'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout master --
  WORKING_DIRECTORY "/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp/sanitizers-gitinfo.txt"
    "/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp/sanitizers-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/media/michael/bach_SD_128GB/emo_ws/emo2.0/build/microxrcedds_agent/sanitizers/src/sanitizers-stamp/sanitizers-gitclone-lastrun.txt'")
endif()


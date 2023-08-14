# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "jointpublish: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ijointpublish:/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(jointpublish_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg" NAME_WE)
add_custom_target(_jointpublish_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "jointpublish" "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(jointpublish
  "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jointpublish
)

### Generating Services

### Generating Module File
_generate_module_cpp(jointpublish
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jointpublish
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(jointpublish_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(jointpublish_generate_messages jointpublish_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg" NAME_WE)
add_dependencies(jointpublish_generate_messages_cpp _jointpublish_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jointpublish_gencpp)
add_dependencies(jointpublish_gencpp jointpublish_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jointpublish_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(jointpublish
  "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/jointpublish
)

### Generating Services

### Generating Module File
_generate_module_eus(jointpublish
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/jointpublish
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(jointpublish_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(jointpublish_generate_messages jointpublish_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg" NAME_WE)
add_dependencies(jointpublish_generate_messages_eus _jointpublish_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jointpublish_geneus)
add_dependencies(jointpublish_geneus jointpublish_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jointpublish_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(jointpublish
  "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jointpublish
)

### Generating Services

### Generating Module File
_generate_module_lisp(jointpublish
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jointpublish
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(jointpublish_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(jointpublish_generate_messages jointpublish_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg" NAME_WE)
add_dependencies(jointpublish_generate_messages_lisp _jointpublish_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jointpublish_genlisp)
add_dependencies(jointpublish_genlisp jointpublish_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jointpublish_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(jointpublish
  "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/jointpublish
)

### Generating Services

### Generating Module File
_generate_module_nodejs(jointpublish
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/jointpublish
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(jointpublish_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(jointpublish_generate_messages jointpublish_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg" NAME_WE)
add_dependencies(jointpublish_generate_messages_nodejs _jointpublish_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jointpublish_gennodejs)
add_dependencies(jointpublish_gennodejs jointpublish_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jointpublish_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(jointpublish
  "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jointpublish
)

### Generating Services

### Generating Module File
_generate_module_py(jointpublish
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jointpublish
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(jointpublish_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(jointpublish_generate_messages jointpublish_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/charlie/catkin_ws/src/seniorthesis/jointpublish/msg/Hand.msg" NAME_WE)
add_dependencies(jointpublish_generate_messages_py _jointpublish_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(jointpublish_genpy)
add_dependencies(jointpublish_genpy jointpublish_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS jointpublish_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jointpublish)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/jointpublish
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(jointpublish_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/jointpublish)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/jointpublish
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(jointpublish_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jointpublish)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/jointpublish
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(jointpublish_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/jointpublish)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/jointpublish
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(jointpublish_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jointpublish)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jointpublish\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/jointpublish
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(jointpublish_generate_messages_py std_msgs_generate_messages_py)
endif()

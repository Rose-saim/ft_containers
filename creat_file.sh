#!/bin/bash
touch $1.hpp
first=${1^^}
 echo "#ifndef" $first"_HPP" >> $1.hpp
 echo "#define" $first"_HPP" >> $1.hpp
 echo "#endif" >> $1.hpp

#/bin/bash

# Copyright (C) 2024 Ju Yeong Kim
#
# This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License  
# version 3 as published by the Free Software Foundation.                                                                    
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied         
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     
# A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.
#
####################################################################################
# Name:
#     Ju Yeong Kim
#
#
# Course ID:                
#     CPSC 351
#
#
# Name of the program:      
#     Collatz-cached
#
#
# OS of the computer where the program was developed:
#     Ubuntu 22.04 WSL
#
#
# OS of the computer where the program was tested:
#     Ubuntu 22.04 WSL
####################################################################################

gcc -I headers/ src/*.c main.c -o collatz -Wall
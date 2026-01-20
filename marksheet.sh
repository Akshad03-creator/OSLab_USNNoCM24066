#!/bin/bash
# Script: marksheet.sh
# Purpose: Generate a student's marksheet for 3 subjects

echo "---------- STUDENT MARKSHEET ----------"

# Input student details
read -p "Enter Student Name: " name
read -p "Enter Roll Number: " roll

# Input marks for 3 subjects
read -p "Enter marks for Subject 1: " m1
read -p "Enter marks for Subject 2: " m2
read -p "Enter marks for Subject 3: " m3

# Calculate total and percentage
total=$((m1 + m2 + m3))
percentage=$((total / 3))

# Determine class
if [ $percentage -ge 75 ]; then
    class="Distinction"
elif [ $percentage -ge 60 ]; then
    class="First Class"
elif [ $percentage -ge 50 ]; then
    class="Second Class"
elif [ $percentage -ge 35 ]; then
    class="Pass"
else
    class="Fail"
fi

# Display marksheet
echo ""
echo "------------ MARKSHEET ------------"
echo "Name        : $name"
echo "Roll No     : $roll"
echo "Subject 1   : $m1"
echo "Subject 2   : $m2"
echo "Subject 3   : $m3"
echo "Total Marks : $total / 300"
echo "Percentage  : $percentage %"
echo "Class       : $class"
echo "----------------------------------"

#!/bin/bash

while true
do
    echo "-----------------------------"
    echo "        MENU PROGRAM         "
    echo "-----------------------------"
    echo "1. Display calendar of current month"
    echo "2. Display today's date and time"
    echo "3. Display usernames currently logged in"
    echo "4. Display your terminal number"
    echo "5. Exit"
    echo "-----------------------------"
    echo -n "Enter your choice: "

    read ch
    ch=$(echo "$ch" | tr -d '[:space:]')

    case "$ch" in
        1) date ;;
        2) date ;;
        3) whoami ;;
        4) tty ;;
        5) echo "Exiting..."; exit ;;
        *) echo "Invalid choice! Please try again." ;;
    esac
done


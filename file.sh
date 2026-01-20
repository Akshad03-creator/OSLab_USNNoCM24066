#!/bin/bash
# Script: file_menu.sh
# Purpose: Menu driven program for file handling operations

while true
do
    echo "--------------------------------------"
    echo "       FILE HANDLING MENU"
    echo "1. Create a file"
    echo "2. Write content to file"
    echo "3. Append content to file"
    echo "4. Delete file content"
    echo "5. Exit"
    echo "--------------------------------------"

    read -p "Enter your choice (1-5): " choice

    case $choice in
        1)
            read -p "Enter file name to create: " fname
            if [ -f "$fname" ]; then
                echo "File already exists."
            else
                touch "$fname"
                echo "File created successfully."
            fi
            ;;
        2)
            read -p "Enter file name to write: " fname
            if [ -f "$fname" ]; then
                echo "Enter content (Press CTRL+D to save):"
                cat > "$fname"
                echo "Content written successfully."
            else
                echo "File does not exist."
            fi
            ;;
        3)
            read -p "Enter file name to append: " fname
            if [ -f "$fname" ]; then
                echo "Enter content to append (Press CTRL+D to save):"
                cat >> "$fname"
                echo "Content appended successfully."
            else
                echo "File does not exist."
            fi
            ;;
        4)
            read -p "Enter file name to delete content: " fname
            if [ -f "$fname" ]; then
                > "$fname"
                echo "File content deleted successfully."
            else
                echo "File does not exist."
            fi
            ;;
        5)
            echo "Exiting... Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid choice! Please enter 1-5."
            ;;
    esac

    echo ""
    read -p "Press Enter to continue..." temp
done

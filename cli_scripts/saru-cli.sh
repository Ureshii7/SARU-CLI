#!/bin/bash

# Log file for debugging
LOG_FILE="saru-cli.log"

# Function on input.
echo "Welcome to Saru-CLI! Type your command in natural language (e.g., 'list files')" | tee -a "$LOG_FILE"

read user_input

# Log user input for debugging.
echo "$(date) - User input: $user_input" >> "$LOG_FILE"

# NLP pass.
response=$(python process_command.py "$user_input" 2>&1)

# Log response for debug.
echo "$(date) - Response from NLP: $response" >> "$LOG_FILE"

# Error no valid command.
if [[ "$response" == "Command not recognized!" ]]; then
    echo "Error: Command not recognized. Please try again with a different query." | tee -a "$LOG_FILE"
    exit 1
fi

# Output execution.
echo "$(date) - Executing command: $response" >> "$LOG_FILE"
eval "$response"

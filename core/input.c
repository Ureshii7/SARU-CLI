// input.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "session.h"

// Function declarations
void process_input(Session *session, const char *input);
void handle_command(Session *session, const char *command);

#define MAX_INPUT_LENGTH 256

// Function implementations
void process_input(Session *session, const char *input) {
    // Simple input parsing (update with NLP later)
    char command[MAX_INPUT_LENGTH];
    sscanf(input, "%s", command);

    handle_command(session, command);
}

void handle_command(Session *session, const char *command) {
    if (strcmp(command, "create_tab") == 0) {
        create_tab(session, "New Tab");
    } else if (strcmp(command, "create_window") == 0) {
        if (session->num_tabs > 0) {
            create_window(session, 0, "New Window");
        } else {
            printf("Error: No tabs exist.\n");
        }
    } else if (strcmp(command, "switch_tab") == 0) {
        if (session->num_tabs > 0) {
            switch_tab(session, 0);  // Switch to the first tab by default
        } else {
            printf("Error: No tabs exist.\n");
        }
    } else if (strcmp(command, "switch_window") == 0) {
        if (session->num_tabs > 0 && session->tabs[0].num_windows > 0) {
            switch_window(session, 0, 0);  // Switch to the first window in the first tab
        } else {
            printf("Error: No windows to switch.\n");
        }
    } else if (strcmp(command, "display") == 0) {
        display_session(session);
    } else {
        printf("Unknown command: %s\n", command);
    }
}
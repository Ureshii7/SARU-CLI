// session.h
#ifndef SESSION_H
#define SESSION_H

// Define constants for maximum tabs and windows
#define MAX_TABS 10
#define MAX_WINDOWS 10

// Structure Represent Window
typedef struct {
    char *title;
    int is_active;
} Window;

// Structure Tab Represent
typedef struct {
    char *name;
    Window windows[MAX_WINDOWS];
    int active_window;
    int num_windows;
} Tab;

// Structure Entire Session
typedef struct {
    Tab tabs[MAX_TABS];
    int active_tab;
    int num_tabs;
} Session;

// Function
void init_session(Session *session);
void create_tab(Session *session, const char *tab_name);
void switch_tab(Session *session, int tab_index);
void create_window(Session *session, int tab_index, const char *window_title);
void switch_window(Session *session, int tab_index, int window_index);
void display_session(Session *session);

#endif
//session.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "session.h"

//constants and structures
#define MAX_TABS 10
#define MAX_WINDOWS 10

typedef struct {
    char *title;
    int is_active;
} Window;

typedef struct {
    char *name;
    Window windows[MAX_WINDOWS];
    int active_window;
    int num_windows;
} Tab;

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

// Function implem.
void init_session(Session *session) {
    session->num_tabs = 0;
    session->active_tab = -1;
}

void create_tab(Session *session, const char *tab_name) {
    if (session->num_tabs < MAX_TABS) {
        Tab *new_tab = &session->tabs[session->num_tabs];
        new_tab->name = strdup(tab_name);
        new_tab->num_windows = 0;
        new_tab->active_window = -1;
        session->num_tabs++;
    } else {
        printf("Error: Max tabs reached.\n");
    }
}

void create_window(Session *session, int tab_index, const char *window_title) {
    if (tab_index < session->num_tabs) {
        Tab *tab = &session->tabs[tab_index];
        if (tab->num_windows < MAX_WINDOWS) {
            Window *new_window = &tab->windows[tab->num_windows];
            new_window->title = strdup(window_title);
            new_window->is_active = 0;
            tab->num_windows++;
        } else {
            printf("Error: Max windows in tab reached.\n");
        }
    } else {
        printf("Error: Tab does not exist.\n");
    }
}

void switch_tab(Session *session, int tab_index) {
    if (tab_index < session->num_tabs) {
        session->active_tab = tab_index;
        printf("Switched to tab: %s\n", session->tabs[tab_index].name);
    } else {
        printf("Error: Tab does not exist.\n");
    }
}

void switch_window(Session *session, int tab_index, int window_index) {
    if (tab_index < session->num_tabs) {
        Tab *tab = &session->tabs[tab_index];
        if (window_index < tab->num_windows) {
            tab->active_window = window_index;
            printf("Switched to window: %s\n", tab->windows[window_index].title);
        } else {
            printf("Error: Window does not exist.\n");
        }
    } else {
        printf("Error: Tab does not exist.\n");
    }
}

void display_session(Session *session) {
    for (int i = 0; i < session->num_tabs; i++) {
        Tab *tab = &session->tabs[i];
        printf("Tab %d: %s\n", i, tab->name);
        for (int j = 0; j < tab->num_windows; j++) {
            printf("\tWindow %d: %s\n", j, tab->windows[j].title);
        }
    }
}
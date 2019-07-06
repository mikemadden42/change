// https://developer.gnome.org/glib/stable/glib-compiling.html
// clang -Wall -Wextra -pedantic -std=c11 -O2 -march=native -o days days.c
// $(pkg-config --cflags --libs glib-2.0) clang -Wall -Wextra -pedantic -std=c11
// -O2 -march=native -o days days.c $(pkg-config --cflags --libs glib-2.0)
// -fsanitize=address

#include <stdio.h>
#include <time.h>

#include <glib.h>

int main() {
    GDate *start;
    GDate *end;
    int days = 0;
    time_t now;

    // Set the starting time.
    start = g_date_new_dmy(8, 4, 2019);

    // Get the current time.
    time(&now);
    struct tm *local = localtime(&now);
    end = g_date_new_dmy(local->tm_mday, local->tm_mon + 1,
                         local->tm_year + 1900);

    // Find the difference in days.
    days = g_date_days_between(start, end);
    printf("diff: %d days\n", days);

    g_date_free(start);
    g_date_free(end);

    return 0;
}

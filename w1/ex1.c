#include <stdio.h>

#ifdef _WIN32
#include <winuser.h>

void prt() {
    printf("This program is running on window\n");
}

void shutdown() {
    int c = 0;
    do {
        printf("\n1. Log off\n2. Shutdown\n3. Restart\n");
        scanf("%d", &c);
        if (0 < c && c < 4) break;
    } while (1);
    switch (c) {
        case 1:
            ExitWindowsEx(EWX_LOGOFF, 0);
            break;
        case 2:
            ExitWindowsEx(EWX_SHUTDOWN, 0);
            break;
        case 3:
            ExitWindowsEx(EWX_REBOOT, 0);
            break;
    }
}

#endif

#ifdef linux
#include <unistd.h>
#include <stdlib.h>

void prt() {
    printf("This program is running on unix\n");
}

void shutdown() {
    int c = 0;
    do {
        printf("\n1. Log off\n2. Shutdown\n3. Restart\n");
        scanf("%d", &c);
        if (0 < c && c < 4) break;
    } while (1);
    switch (c) {
        case 1:
            system("logout");
            break;
        case 2:
            system("shutdown -P now");
            break;
        case 3:
            system("shutdown -r now");
            break;
    }
}
#endif

int main() {
    prt();
    shutdown();
    return 0;
}
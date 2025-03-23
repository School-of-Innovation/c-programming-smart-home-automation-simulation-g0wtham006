/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

#define MAX_ROOMS 5

void initializeSystem(int lights[], int temperature[], int motion[], int security[], int rooms);
void displayMenu();
void controlLights(int lights[], int rooms);
void readTemperature(int temperature[], int rooms);
void detectMotion(int motion[], int rooms);
void securitySystem(int security[], int rooms);
void analyzeHouseStatus(int lights[], int temperature[], int motion[], int security[], int rooms);

int main() {
    int rooms;
    int lights[MAX_ROOMS], temperature[MAX_ROOMS], motion[MAX_ROOMS], security[MAX_ROOMS];

    printf("Enter the number of rooms (1-%d): ", MAX_ROOMS);
    scanf("%d", &rooms);
    if (rooms < 1 || rooms > MAX_ROOMS) {
        printf("Invalid number of rooms. Exiting...\n");
        return 1;
    }

    initializeSystem(lights, temperature, motion, security, rooms);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLights(lights, rooms);
                break;
            case 2:
                readTemperature(temperature, rooms);
                break;
            case 3:
                detectMotion(motion, rooms);
                break;
            case 4:
                securitySystem(security, rooms);
                break;
            case 5:
                analyzeHouseStatus(lights, temperature, motion, security, rooms);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeSystem(int lights[], int temperature[], int motion[], int security[], int rooms) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        temperature[i] = 22;
        motion[i] = 0;
        security[i] = 1;
    }
    printf("System initialized: Lights OFF, Doors Locked, No motion detected.\n");
}

void displayMenu() {
    printf("\nSmart Home Automation System Menu:\n");
    printf("1. Control Lights\n");
    printf("2. Read Temperature\n");
    printf("3. Detect Motion\n");
    printf("4. Security System (Lock/Unlock)\n");
    printf("5. Analyze House Status\n");
    printf("6. Exit\n");
}

void controlLights(int lights[], int rooms) {
    int roomNumber;
    printf("Enter room number (1-%d) to toggle lights: ", rooms);
    scanf("%d", &roomNumber);
    if (roomNumber < 1 || roomNumber > rooms) {
        printf("Invalid room number.\n");
        return;
    }
    roomNumber--;
    lights[roomNumber] = !lights[roomNumber];
    printf("Room %d lights are now %s.\n", roomNumber + 1, lights[roomNumber] ? "ON" : "OFF");
}

void readTemperature(int temperature[], int rooms) {
    int roomNumber;
    printf("Enter room number (1-%d) to read temperature: ", rooms);
    scanf("%d", &roomNumber);
    if (roomNumber < 1 || roomNumber > rooms) {
        printf("Invalid room number.\n");
        return;
    }
    roomNumber--;
    printf("Room %d temperature is %d°C.\n", roomNumber + 1, temperature[roomNumber]);
}

void detectMotion(int motion[], int rooms) {
    int roomNumber;
    printf("Enter room number (1-%d) to detect motion: ", rooms);
    scanf("%d", &roomNumber);
    if (roomNumber < 1 || roomNumber > rooms) {
        printf("Invalid room number.\n");
        return;
    }
    roomNumber--;
    if (motion[roomNumber] == 1) {
        printf("Motion detected in Room %d.\n", roomNumber + 1);
    } else {
        printf("No motion detected in Room %d.\n", roomNumber + 1);
    }
}

void securitySystem(int security[], int rooms) {
    int roomNumber, action;
    printf("Enter room number (1-%d) to lock/unlock: ", rooms);
    scanf("%d", &roomNumber);
    if (roomNumber < 1 || roomNumber > rooms) {
        printf("Invalid room number.\n");
        return;
    }
    roomNumber--;
    printf("Enter 1 to lock, 0 to unlock: ");
    scanf("%d", &action);
    if (action != 1 && action != 0) {
        printf("Invalid action.\n");
        return;
    }
    security[roomNumber] = action;
    printf("Room %d is now %s.\n", roomNumber + 1, security[roomNumber] ? "Locked" : "Unlocked");
}

void analyzeHouseStatus(int lights[], int temperature[], int motion[], int security[], int rooms) {
    printf("\nHouse Status Report:\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Lights %s, Temperature %d°C, Motion %s, Door %s\n", 
               i + 1, 
               lights[i] ? "ON" : "OFF", 
               temperature[i], 
               motion[i] ? "Detected" : "Not Detected", 
               security[i] ? "Locked" : "Unlocked");
    }
}

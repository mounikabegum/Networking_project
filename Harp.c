#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 50

/* Vehicle structure */
typedef struct {
    int id;
    float x;
    float y;
    float speed;
} Vehicle;

/* Route structure */
typedef struct {
    int source;
    int destination;
    float distance;
    float stability;
} Route;

/* Global arrays */
Vehicle vehicles[MAX_NODES];
Route routes[MAX_NODES];

/* Counters */
int nodeCount = 0;
int routeCount = 0;

/* Function to calculate distance */
float calculateDistance(Vehicle a, Vehicle b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

/* Function to calculate link stability */
float linkStability(Vehicle a, Vehicle b) {
    float speedDiff = fabs(a.speed - b.speed);
    float distance = calculateDistance(a, b);
    return 1.0 / (1.0 + speedDiff + distance);
}

/* Add vehicle */
void addVehicle(int id, float x, float y, float speed) {
    vehicles[nodeCount].id = id;
    vehicles[nodeCount].x = x;
    vehicles[nodeCount].y = y;
    vehicles[nodeCount].speed = speed;
    nodeCount++;
}

/* Discover route */
void discoverRoute(int src, int dest) {

    float bestStability = 0;
    int bestNode = -1;

    for (int i = 0; i < nodeCount; i++) {

        if (i == src)
            continue;

        float stability = linkStability(vehicles[src], vehicles[i]);

        if (stability > bestStability) {
            bestStability = stability;
            bestNode = i;
        }
    }

    if (bestNode != -1) {

        routes[routeCount].source = src;
        routes[routeCount].destination = dest;
        routes[routeCount].distance = calculateDistance(vehicles[src], vehicles[bestNode]);
        routes[routeCount].stability = bestStability;

        routeCount++;

        printf("Route Found via Node %d\n", bestNode);
        printf("Link Stability: %f\n", bestStability);
    }
}

/* Print routing table */
void printRoutes() {

    printf("\nRouting Table\n");

    for (int i = 0; i < routeCount; i++) {

        printf("Source: %d -> Destination: %d | Distance: %.2f | Stability: %.4f\n",
               routes[i].source,
               routes[i].destination,
               routes[i].distance,
               routes[i].stability);
    }
}

/* Main function */
int main() {

    /* Add vehicles */
    addVehicle(0, 10, 20, 60);
    addVehicle(1, 15, 25, 62);
    addVehicle(2, 30, 40, 55);
    addVehicle(3, 35, 45, 58);

    /* Discover route */
    discoverRoute(0, 3);

    /* Print routing table */
    printRoutes();

    return 0;
}
